/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 * Description:
 * Author:
 * Create: 2018-12-22
 */
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/gfp.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/vmalloc.h>
#include <linux/uaccess.h>

#include "devdrv_user_common.h"
#include "npu_stream.h"
#include "npu_shm.h"
#include "drv_log.h"

int devdrv_stream_list_init(u8 dev_id)
{

	struct devdrv_dev_ctx *cur_dev_ctx = NULL;
	struct devdrv_stream_sub_info *stream_sub_tmp = NULL;
	struct devdrv_stream_info *stream_tmp = NULL;
	unsigned long size;
	u32 streams = DEVDRV_MAX_NON_SINK_STREAM_ID;
	u32 i;

	if (dev_id >= NPU_DEV_NUM) {
		devdrv_drv_err("illegal npu dev id\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(dev_id);
	if (cur_dev_ctx == NULL) {
		devdrv_drv_err("cur_dev_ctx %d is null\n", dev_id);
		return -1;
	}

	INIT_LIST_HEAD(&cur_dev_ctx->stream_available_list);
	cur_dev_ctx->stream_num = 0;
	if (!list_empty_careful(&cur_dev_ctx->stream_available_list)) {
		devdrv_drv_err("available stream list not empty.\n");
		return -1;
	}

	size = (long)(unsigned)sizeof(*stream_sub_tmp) * streams;
	stream_sub_tmp = vmalloc(size);
	if (stream_sub_tmp == NULL) {
		devdrv_drv_err("no sys mem to alloc stream list \n");
		return -ENOMEM;
	}
	cur_dev_ctx->stream_sub_addr = (void *)stream_sub_tmp;

	for (i = 0; i < streams; i++) {
		stream_tmp = devdrv_calc_stream_info(dev_id, i);
		stream_tmp->id = i;
		stream_tmp->devid = cur_dev_ctx->devid;
		stream_tmp->cq_index = (u32) DEVDRV_CQSQ_INVALID_INDEX;
		stream_tmp->sq_index = (u32) DEVDRV_CQSQ_INVALID_INDEX;
		stream_tmp->stream_sub = (void *)(stream_sub_tmp + i);
		stream_sub_tmp[i].proc_ctx = NULL;
		stream_sub_tmp[i].id = stream_tmp->id;
		list_add_tail(&stream_sub_tmp[i].list,
			      &cur_dev_ctx->stream_available_list);
		cur_dev_ctx->stream_num++;
	}
	devdrv_drv_debug("cur dev %d own %d streams \n", dev_id,
			 cur_dev_ctx->stream_num);
	return 0;
}

int devdrv_alloc_stream_id(u8 dev_id)
{

	struct devdrv_stream_sub_info *sub_stream = NULL;
	struct devdrv_dev_ctx *cur_dev_ctx = NULL;

	if (dev_id >= NPU_DEV_NUM) {
		devdrv_drv_err("illegal npu dev id\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(dev_id);
	if (cur_dev_ctx == NULL) {
		devdrv_drv_err("cur_dev_ctx %d is null\n", dev_id);
		return -1;
	}

	spin_lock(&cur_dev_ctx->spinlock);
	if (list_empty_careful(&cur_dev_ctx->stream_available_list)) {
		spin_unlock(&cur_dev_ctx->spinlock);
		devdrv_drv_err("cur dev %d available stream list empty,"
			       "left stream_num = %d !!!\n", dev_id,
			       cur_dev_ctx->stream_num);
		return -1;
	}

	sub_stream = list_first_entry(&cur_dev_ctx->stream_available_list,
				      struct devdrv_stream_sub_info, list);
	list_del(&sub_stream->list);
	cur_dev_ctx->stream_num--;
	spin_unlock(&cur_dev_ctx->spinlock);
	devdrv_drv_debug("cur dev %d left %d stream\n", dev_id,
			 cur_dev_ctx->stream_num);

	return sub_stream->id;
}

int devdrv_free_stream_id(u8 dev_id, u32 stream_id)
{
	struct devdrv_stream_sub_info *stream_sub_info = NULL;
	struct devdrv_stream_info *stream_info = NULL;
	struct devdrv_dev_ctx *cur_dev_ctx = NULL;

	if (dev_id >= NPU_DEV_NUM) {
		devdrv_drv_err("illegal npu dev id %d\n", dev_id);
		return -1;
	}

	if (stream_id >= DEVDRV_MAX_NON_SINK_STREAM_ID) {
		devdrv_drv_err("illegal npu stream id %d\n", stream_id);
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(dev_id);
	if (cur_dev_ctx == NULL) {
		devdrv_drv_err("cur_dev_ctx %d is null\n", dev_id);
		return -1;
	}
	spin_lock(&cur_dev_ctx->spinlock);
	stream_info = devdrv_calc_stream_info(dev_id, stream_id);
	stream_sub_info =
	    (struct devdrv_stream_sub_info *)stream_info->stream_sub;
	stream_sub_info->proc_ctx = NULL;
	list_add(&stream_sub_info->list, &cur_dev_ctx->stream_available_list);
	cur_dev_ctx->stream_num++;
	spin_unlock(&cur_dev_ctx->spinlock);

	devdrv_drv_debug("cur dev %d own %d stream\n", dev_id,
			 cur_dev_ctx->stream_num);
	return 0;
}

int devdrv_bind_stream_with_sq(u8 dev_id, u32 stream_id, u32 sq_id)
{
	struct devdrv_stream_info *stream_info = NULL;
	struct devdrv_dev_ctx *cur_dev_ctx = NULL;

	if (dev_id >= NPU_DEV_NUM) {
		devdrv_drv_err("illegal npu dev id\n");
		return -1;
	}

	if (stream_id >= DEVDRV_MAX_NON_SINK_STREAM_ID) {
		devdrv_drv_err("illegal npu stream id\n");
		return -1;
	}

	if (sq_id >= DEVDRV_MAX_SQ_NUM) {
		devdrv_drv_err("illegal sq id\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(dev_id);
	if (cur_dev_ctx == NULL) {
		devdrv_drv_err("cur_dev_ctx %d is null\n", dev_id);
		return -1;
	}
	spin_lock(&cur_dev_ctx->spinlock);
	stream_info = devdrv_calc_stream_info(dev_id, stream_id);
	stream_info->sq_index = sq_id;
	spin_unlock(&cur_dev_ctx->spinlock);

	return 0;
}

//called by alloc complete stream in service layer
int devdrv_bind_stream_with_cq(u8 dev_id, u32 stream_id, u32 cq_id)
{
	struct devdrv_stream_info *stream_info = NULL;
	struct devdrv_dev_ctx *cur_dev_ctx = NULL;

	if (dev_id >= NPU_DEV_NUM) {
		devdrv_drv_err("illegal npu dev id\n");
		return -1;
	}

	if (stream_id >= DEVDRV_MAX_NON_SINK_STREAM_ID) {
		devdrv_drv_err("illegal npu stream id\n");
		return -1;
	}

	if (cq_id >= DEVDRV_MAX_CQ_NUM) {
		devdrv_drv_err("illegal cq id\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(dev_id);
	if (cur_dev_ctx == NULL) {
		devdrv_drv_err("cur_dev_ctx %d is null\n", dev_id);
		return -1;
	}
	spin_lock(&cur_dev_ctx->spinlock);
	stream_info = devdrv_calc_stream_info(dev_id, stream_id);
	stream_info->cq_index = cq_id;
	spin_unlock(&cur_dev_ctx->spinlock);

	return 0;
}

int devdrv_stream_list_destroy(u8 dev_id)
{
	struct devdrv_stream_sub_info *stream_sub_info = NULL;
	struct devdrv_dev_ctx *cur_dev_ctx = NULL;
	struct list_head *pos = NULL;
	struct list_head *n = NULL;

	if (dev_id >= NPU_DEV_NUM) {
		devdrv_drv_err("illegal npu dev id\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(dev_id);
	if (cur_dev_ctx == NULL) {
		devdrv_drv_err("cur_dev_ctx %d is null\n", dev_id);
		return -1;
	}

	spin_lock(&cur_dev_ctx->spinlock);
	if (!list_empty_careful(&cur_dev_ctx->stream_available_list)) {
		list_for_each_safe(pos, n, &cur_dev_ctx->stream_available_list) {
			stream_sub_info =
			    list_entry(pos, struct devdrv_stream_sub_info, list);
			list_del(pos);
		}
	}
	spin_unlock(&cur_dev_ctx->spinlock);

	vfree(cur_dev_ctx->stream_sub_addr);
	cur_dev_ctx->stream_sub_addr = NULL;

	return 0;
}