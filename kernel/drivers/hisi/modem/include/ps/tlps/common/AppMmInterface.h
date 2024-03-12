/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2019. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __APPMMINTERFACE_H__
#define __APPMMINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include "AppNasComm.h"
#include "AppRrcInterface.h"

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 macro
*****************************************************************************/
#define APP_MAX_PLMN_NUM                37
#define APP_MAX_UEID_BUF_SIZE           10
#define APP_MS_NET_CAP_MAX_SIZE         9
/*add begin*/
#define APP_MM_MAX_EQU_PLMN_NUM         16  /* Э��涨EPlmn������*/
#define APP_MM_MAX_PLMN_NUM             64  /* PLMN�б������� */
#define APP_MM_MAX_TA_NUM               64  /* TA �б������� */
/*add end*/

#define APP_MM_CN_NAME_MAX_LEN         255          /* �������ֵ���󳤶� */

/*DT begin */
#define APP_EMM_IMSI_MAX_LEN           15

/*DT end */


/*APP->MM ��ͨ������Ϣǰ3���ֽں궨�� APP->MM*/
#define APP_MM_COMM_MSG_ID_HEADER                           PS_MSG_ID_APP_TO_EMM_BASE

/*MM->APP ��ͨ������Ϣǰ3���ֽں궨�� MM->APP*/
#define MM_APP_COMM_MSG_ID_HEADER                           PS_MSG_ID_EMM_TO_APP_BASE


/*MM->APP �ؼ��¼���Ϣǰ3���ֽں궨�� MM->APP*/
#define MM_APP_KEY_EVT_MSG_ID_HEADER                        PS_OMT_KEY_EVT_REPORT_IND

/*APP->MM ͸��������Ϣǰ3���ֽں궨�� APP->MM*/
#define APP_MM_TP_MSG_ID_HEADER                             OM_PS_TRANSPARENT_CMD_REQ

/*MM->APP ͸��������Ϣǰ3���ֽں궨�� MM->APP*/
#define MM_APP_TP_MSG_ID_HEADER                             OM_PS_TRANSPARENT_CMD_CNF

/*MM->APP �տ��ϱ���Ϣǰ3���ֽں궨�� MM->APP*/
#define MM_APP_AIR_MSG_ID_HEADER                            PS_OMT_AIR_MSG_REPORT_IND
/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4. Enum
*****************************************************************************/

/*****************************************************************************
 ö����    : APP_MM_MSG_TYPE_ENUM
 ö��˵��  : APP��MM��Ϣȡֵ
*****************************************************************************/
enum    APP_MM_MSG_TYPE_ENUM
{
    /* ��ͨ���� ������ѯ����Ϣ  0x30 ~ 0x4F*/
    ID_APP_MM_CMD_INQ_START             = 0x30+APP_MM_COMM_MSG_ID_HEADER,

    ID_APP_MM_INQ_UE_MODE_REQ           = 0x44 + APP_MM_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_UE_MODE_REQ_STRU */
    ID_APP_MM_INQ_UE_MODE_CNF           = 0x44 + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_UE_MODE_CNF_STRU */
    ID_APP_MM_INQ_LTE_CS_REQ            = 0x45 + APP_MM_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_LTE_CS_REQ_STRU */
    ID_APP_MM_INQ_LTE_CS_CNF            = 0x45 + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_LTE_CS_CNF_STRU */



    ID_APP_MM_CMD_INQ_END               = 0x4F+APP_MM_COMM_MSG_ID_HEADER,

    /* V7R2-DT GUTI IMSI EMM_STATE  2014/03/20  start*/
    /* DT begin */
    ID_APP_MM_INQ_LTE_GUTI_REQ          = 0x46 + APP_MM_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_LTE_GUTI_REQ_STRU */
    ID_APP_MM_INQ_LTE_GUTI_CNF          = 0x46 + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_LTE_GUTI_CNF_STRU */
    ID_APP_MM_INQ_LTE_GUTI_IND          = 0x47 + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_LTE_GUTI_IND_STRU */

    ID_APP_MM_INQ_IMSI_REQ              = 0x47 + APP_MM_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_IMSI_REQ_STRU */
    ID_APP_MM_INQ_IMSI_CNF              = 0x48 + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_IMSI_CNF_STRU */
    ID_APP_MM_INQ_IMSI_IND              = 0x49 + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_IMSI_IND_STRU */

    ID_APP_MM_INQ_EMM_STATE_REQ         = 0x48 + APP_MM_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_EMM_STATE_REQ_STRU */
    ID_APP_MM_INQ_EMM_STATE_CNF         = 0x4a + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_EMM_STATE_CNF_STRU */
    ID_APP_MM_INQ_EMM_STATE_IND         = 0x4b + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice APP_MM_INQ_EMM_STATE_IND_STRU */
    /* DT end */
    /* V7R2-DT GUTI IMSI EMM_STATE   2014/03/20  end*/

    /* add for ue cap display, 2017-02-03, begin */
    ID_APP_MM_UE_CAP_INFO_REQ           = 0x4c + APP_MM_COMM_MSG_ID_HEADER,   /* _H2ASN_MsgChoice APP_MM_UE_CAP_INFO_REQ_STRU */
    ID_MM_APP_UE_CAP_INFO_CNF           = 0x4c + MM_APP_COMM_MSG_ID_HEADER,   /* _H2ASN_MsgChoice MM_APP_UE_CAP_INFO_CNF_STRU */
    /* add for ue cap display, 2017-02-03, end */

    /* ��ͨ���� ��������Ϣ  0x50 ~ 0x8F*/
    /* Added for DT report, 2018-11-21, begin */
    ID_APP_MM_REG_STAT_REQ              = 0x5c + APP_MM_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice ID_APP_MM_REG_STAT_REQ_STRU */
    ID_APP_MM_REG_STAT_CNF              = 0x5c + MM_APP_COMM_MSG_ID_HEADER,    /* _H2ASN_MsgChoice ID_APP_MM_REG_STAT_CNF_STRU */
    /* Added for DT report, 2018-11-21, end */
    ID_APP_MM_REG_STAT_IND              = 0x5D+MM_APP_COMM_MSG_ID_HEADER,      /* _H2ASN_MsgChoice APP_MM_REG_STAT_IND_STRU */

    ID_APP_MM_MSG_TYPE_BUTT
};
typedef VOS_UINT32 APP_MM_MSG_TYPE_ENUM_UINT32;


/*****************************************************************************
 ö����    : APP_EMM_MAIN_STATE_ENUM
 ö��˵��  : EMM��״̬
*****************************************************************************/
enum    APP_EMM_MAIN_STATE_ENUM
{
    /*=================== EMM����״̬ ===================*/
    APP_EMM_MS_NULL                     = 0x0000,   /* ��״̬           */
    APP_EMM_MS_DEREG                    = 0x0001,   /* DETACH״̬       */
    APP_EMM_MS_REG_INIT                 = 0x0002,   /* ATTACH������״̬ */
    APP_EMM_MS_REG                      = 0x0003,   /* ATTACH״̬       */
    APP_EMM_MS_DEREG_INIT               = 0x0004,   /* DETACH������״̬ */
    APP_EMM_MS_TAU_INIT                 = 0x0005,   /* TAU������״̬    */
    APP_EMM_MS_SER_INIT                 = 0x0006,   /* SERVICE������״̬*/
    APP_EMM_MS_STATE_BUTT
};
typedef VOS_UINT16 APP_EMM_MAIN_STATE_ENUM_UINT16;

/*****************************************************************************
 ö����    : APP_EMM_SUB_STATE_ENUM
 ö��˵��  : EMM��״̬
*****************************************************************************/
enum    APP_EMM_SUB_STATE_ENUM
{

    /*=================== EMM����״̬ ===================*/
    APP_EMM_SS_NULL                       = 0x0000,  /* ����״̬ */
    /*========== APP_EMM_MS_DEREG�µ���״̬ ==============*/
    APP_EMM_SS_DEREG_NORMAL_SERVICE       = 0x0001,  /* δע����������״̬ */
    APP_EMM_SS_DEREG_LIMITED_SERVICE      = 0x0002,  /* δע�����Ʒ���״̬ */
    APP_EMM_SS_DEREG_ATTEMPT_TO_ATTACH    = 0x0003,  /* δע��ȴ�����ATTCH״̬*/
    APP_EMM_SS_DEREG_PLMN_SEARCH          = 0x0004,  /* δע������״̬ */
    APP_EMM_SS_DEREG_NO_IMSI              = 0x0005,  /* δע�Ῠ��Ч״̬ */
    APP_EMM_SS_DEREG_ATTACH_NEEDED        = 0x0006,  /* δע����Ҫ����ATTACH״̬ */
    APP_EMM_SS_DEREG_NO_CELL_AVAILABLE    = 0x0007,  /* δע��û�п���С��״̬ */

    /*========== APP_EMM_MS_REG�µ���״̬ ================*/
    APP_EMM_SS_REG_NORMAL_SERVICE         = 0x0011,  /* ע����������״̬ */
    APP_EMM_SS_REG_ATTEMPTING_TO_UPDATE   = 0x0012,  /* ע��ȴ�����TA����״̬ */
    APP_EMM_SS_REG_LIMITED_SERVICE        = 0x0013,  /* ע�����Ʒ���״̬ */
    APP_EMM_SS_REG_PLMN_SEARCH            = 0x0014,  /* ע������״̬ */
    APP_EMM_SS_REG_WAIT_ACCESS_GRANT_IND         = 0x0015,  /* ע����ҪTA����״̬ */
    APP_EMM_SS_REG_NO_CELL_AVAILABLE      = 0x0016,  /* ע��û�п���С��״̬ */
    APP_EMM_SS_REG_ATTEMPT_TO_UPDATE_MM   = 0x0017,  /* ����ע��ֻע��ɹ�EPS�����״̬ */
    APP_EMM_SS_REG_IMSI_DETACH_WAIT_CN_DETACH_CNF   = 0x0018,  /* IMSI DETACH�ȴ�����ظ�״̬ */
    APP_EMM_SS_REG_IMSI_DETACH_WAIT_RRC_REL_IND     = 0x0019,  /* IMSI DETACH�ȴ���·�ͷ�״̬ */
    APP_EMM_SS_BUTT
};
typedef VOS_UINT16  APP_EMM_SUB_STATE_ENUM_UINT16;
/*****************************************************************************
 ö����    : APP_EMM_UPDATE_STAT_ENUM
 ö��˵��  : EMM UPDATE״̬
*****************************************************************************/
enum    APP_EMM_UPDATE_STATE_ENUM
{
    APP_EMM_US_EU1_UPDATED                  = 0x00,   /* ����״̬       */
    APP_EMM_US_EU2_NOT_UPDATED              = 0x01,   /* δ����״̬     */
    APP_EMM_US_EU3_ROAMING_NOT_ALLOWED      = 0x02,   /* ���β�����״̬ */

    APP_EMM_US_BUTT
};
typedef VOS_UINT32  APP_EMM_UPDATE_STATE_ENUM_UINT32;

/*****************************************************************************
 ö����    : APP_EMM_REG_STATE_ENUM
 ö��˵��  : EMMע��״̬
*****************************************************************************/
enum APP_EMM_REG_STATE_ENUM
{
    APP_EMM_RS_NULL                          = 0x00,   /* ��״̬ */
    APP_EMM_RS_L1_UPDATED                    = 0x01,   /* ����״̬ */
    APP_EMM_RS_L2_IDLE_NO_IMSI               = 0x02,   /* ����Ч״̬ */
    APP_EMM_RS_L3_ROMING_NOT_ALLOW           = 0x03,   /* ���β�����״̬ */
    APP_EMM_RS_L4_NOT_UPDATED                = 0x04,   /* δ����״̬ */
    APP_EMM_RS_BUTT
};
typedef VOS_UINT32 APP_EMM_REG_STATE_ENUM_UINT32;

/*****************************************************************************
 ö����    : APP_EMM_SEL_MODE_ENUM
 ö��˵��  : ѡ��ģʽ
*****************************************************************************/
enum    APP_EMM_SEL_MODE_ENUM
{
    APP_EMM_PLMN_SEL_AUTO               = 0x00,    /* �Զ�����ѡ��ģʽ */
    APP_EMM_PLMN_SEL_MANUAL             = 0x01,    /* �ֶ�����ѡ��ģʽ */
    APP_EMM_PLMN_SEL_BUTT
};
typedef VOS_UINT32 APP_EMM_SEL_MODE_ENUM_UINT32;

/*****************************************************************************
 ö����    : APP_MM_LOCK_PLMN_TYPE_ENUM
 ö��˵��  : PLMN lock����
*****************************************************************************/
enum    APP_MM_LOCK_PLMN_TYPE_ENUM
{
    APP_MM_LOCK_PLMN_TYPE_LOCK          = 0x00,
    APP_MM_LOCK_PLMN_TYPE_UNLOCK        = 0x01,
    APP_MM_LOCK_PLMN_TYPE_BUTT
};
typedef VOS_UINT32   APP_MM_LOCK_PLMN_TYPE_ENUM_UINT32;

/*****************************************************************************
 ö����    : APP_EMM_SRV_STATE_ENUM
 ö��˵��  : ����״̬
*****************************************************************************/
enum APP_EMM_SRV_STATE_ENUM
{
    APP_EMM_SRV_STATUS_NO_SRV           = 0x00,    /* �޷���״̬ */
    APP_EMM_SRV_STATUS_LIMITED          = 0x01,    /* ���Ʒ���״̬ */
    APP_EMM_SRV_STATUS_SRV              = 0x02,    /* ����״̬ */
    APP_EMM_SRV_STATUS_LIMITED_REGIONAL = 0x03,    /* �������Ʒ���״̬ */
    APP_EMM_SRV_STATUS_BUTT
};
typedef VOS_UINT32 APP_EMM_SRV_STATE_ENUM_UINT32;

/*****************************************************************************
 ö����    : APP_MM_REPORT_MODE_ENUM
 ö��˵��  : �ϱ�ģʽ
*****************************************************************************/
enum APP_MM_REPORT_MODE_ENUM
{
    APP_MM_RM_ONE_TIME                  = 0x00,    /* �ϱ�һ�� */
    APP_MM_RM_AUTO                      = 0x01,    /* �����ϱ� */
    APP_MM_RM_PERIOD                    = 0x02,    /*�����ϱ� */
    APP_MM_RM_BUTT
};
typedef VOS_UINT32 APP_MM_REPORT_MODE_ENUM_UINT32;

/* DT begin */
/*****************************************************************************
 ö����    : NAS_DT_RPT_STATUS_ENUM_UINT32
 ö��˵��  : NASΪ·�������ϱ���״̬
*****************************************************************************/

enum NAS_DT_PRT_STAUTS_ENUM
{
    NAS_DT_RPT_STOP,        /*ֹͣ*/
    NAS_DT_RPT_START,       /*����*/
    NAS_DT_RPT_BUTT
};
typedef VOS_UINT32 NAS_DT_RPT_STATUS_ENUM_UINT32;
/*****************************************************************************
 ö����    : NAS_DT_REPORT_ITEM_ENUM_UINT32
 ö��˵��  : NASΪ·�������ϱ�������ö��
*****************************************************************************/
enum NAS_DT_REPORT_ITEM_ENUM
{
    NAS_DT_REPORT_TYPE_GUTI,
    NAS_DT_REPORT_TYPE_IMSI,
    NAS_DT_REPORT_TYPE_EMM_STATE,
    /* Added for DT report, 2018-11-21, begin */
    NAS_DT_REPORT_TYPE_EMM_REG_STATE,
    /* Added for DT report, 2018-11-21, end */
    NAS_DT_REPORT_TYPE_BUTT
};
typedef VOS_UINT32 NAS_DT_REPORT_ITEM_ENUM_UINT32;

/*****************************************************************************
 �ṹ��    : NAS_OM_RPT_TIMER_STRU
 �ṹ˵��  : NAS��·�������������ϱ�ʱ�Ķ�ʱ����Ϣ
*****************************************************************************/
typedef struct
{
    HTIMER                            pRptTimer; /*�����ϱ���ʱ�� */
    VOS_UINT32                        ulRptPeriod;/*�ϱ����� */
}NAS_DT_RPT_TIMER_STRU;
/*****************************************************************************
 �ṹ��    : APP_MM_DT_REPORT_CTRL_STRU
 �ṹ˵��  : NAS��·�������ϱ��Ŀ��ƽṹ
*****************************************************************************/

typedef struct
{
    NAS_DT_REPORT_ITEM_ENUM_UINT32    enDtRptItem;/*��Ҫ�ϱ�����Ŀ */
    NAS_DT_RPT_STATUS_ENUM_UINT32     enRptStatus; /*�Ƿ������ϱ� */
    APP_MM_REPORT_MODE_ENUM_UINT32    enRptType;  /*�ϱ����� */
    NAS_DT_RPT_TIMER_STRU             stRptTimer;/*�ϱ����ڶ�ʱ����Ϣ */
}APP_MM_DT_REPORT_CTRL_STRU;
/* DT end */

/*****************************************************************************
 ö����    : APP_PH_RA_MODE_ENUM
 ö��˵��  : ����ģʽ
*****************************************************************************/

enum APP_PH_RA_MODE_ENUM
{
    APP_PH_RAT_WCDMA                   = 0x00,
    APP_PH_RAT_GSM_GPRS                = 0x01,
    APP_PH_RAT_LTE_FDD                 = 0x02,
    APP_PH_RAT_LTE_TDD                 = 0x03,

    APP_PH_RAT_TYPE_BUTT
};
typedef VOS_UINT32  APP_PH_RA_MODE_ENUM_UINT32;


/*****************************************************************************
 ö����    : APP_PLMN_RESEL_MODE_TYPE_ENUM
 ö��˵��  : PLMN��ѡ����
*****************************************************************************/
enum APP_PLMN_RESEL_MODE_TYPE_ENUM
{
    APP_PLMN_RESELECTION_AUTO           = 0x00,             /* �Զ���ѡ */
    APP_PLMN_RESELECTION_MANUAL         = 0x01,             /* �ֶ���ѡ */

    APP_PLMN_RESEL_MODE_TYPE_BUTT
};
typedef VOS_UINT32 APP_PLMN_RESEL_MODE_TYPE_ENUM_UINT32;

/*****************************************************************************
 ö����    : APP_PLMN_STATUS_FLAG_ENUM
 ö��˵��  : PLMN״̬
*****************************************************************************/
enum APP_PLMN_STATUS_FLAG_ENUM
{
    APP_PLMN_STATUS_UNKNOWN             = 0x00,
    APP_PLMN_STATUS_AVAILABLE           = 0x01,
    APP_PLMN_STATUS_CURRENT             = 0x02,
    APP_PLMN_STATUS_FORBIDDEN           = 0x03,

    APP_PLMN_STATUS_FLAG_BUTT
};
typedef VOS_UINT32 APP_PLMN_STATUS_FLAG_ENUM_UINT32;

/*****************************************************************************
 ö����    : APP_PHONE_SERVICE_STATUS_ENUM
 ö��˵��  : ����״̬
*****************************************************************************/
enum APP_PHONE_SERVICE_STATUS_ENUM
{
    APP_NORMAL_SERVICE                  = 0x00,             /* ��������״̬   */
    APP_LIMITED_SERVICE                 = 0x01,             /* ���Ʒ���״̬   */
    APP_ATTEMPTING_TO_UPDATE            = 0x02,             /* ����״̬��     */
    APP_NO_IMSI                         = 0x03,             /* ������IMSI״̬ */
    APP_NO_SERVICE                      = 0x04,             /* �޷���״̬     */
    APP_DETACHED                        = 0x05,             /* ȥ����״̬     */
    APP_DISABLE                         = 0x06,             /* ���񲻿���״̬ */
    APP_DETACH_FAIL                     = 0x07,             /* ִ��ȥע��ʧ��*/

    APP_PHONE_SERVICE_STATUS_BUTT
};
typedef VOS_UINT32 APP_PHONE_SERVICE_STATUS_ENUM_UINT32;

/*****************************************************************************
 ö����    : APP_MM_ATTACH_TYPE_ENUM
 ö��˵��  : ATTACH TYPE
*****************************************************************************/
enum APP_MM_ATTACH_TYPE_ENUM
{
    APP_MM_ATTACH_TYPE_PS               = 0x01,
    APP_MM_ATTACH_TYPE_PS_CS            = 0x02,

    APP_MM_ATTACH_RST_BUTT
};
typedef VOS_UINT32   APP_MM_ATTACH_TYPE_ENUM_UINT32;


/*****************************************************************************
 ö����    : APP_MM_DETACH_TYPE_ENUM
 ö��˵��  : DETACH TYPE
*****************************************************************************/
enum    APP_MM_DETACH_TYPE_ENUM
{
    APP_MM_DETACH_TYPE_PS               = 0x01,
    APP_MM_DETACH_TYPE_CS               = 0x02,
    APP_MM_DETACH_TYPE_PS_CS            = 0x03,
    APP_MM_DETACH_TYPE_BUTT
};
typedef VOS_UINT32   APP_MM_DETACH_TYPE_ENUM_UINT32;


enum APP_EMM_SMC_CTRL_ENUM
{
    APP_EMM_SMC_OPEN                    = 0,
    APP_EMM_SMC_CLOSE                   = 1,

    APP_EMM_SMC_CTRL_BUTT
};
typedef VOS_UINT8 APP_EMM_SMC_CTRL_ENUM_UINT8;

enum APP_REG_STAT_ENUM
{
    APP_REG_STAT_NOT_REG_AND_NOT_SRCH_OPERATOR         = 0x00,
    APP_REG_STAT_REG_HPLMN                             ,
    APP_REG_STAT_NOT_REG_AND_SRCH_OPERATOR             ,
    APP_REG_STAT_REG_DENIED                            ,
    APP_REG_STAT_UNKNOWN                               ,
    APP_REG_STAT_REG_ROAMING                           ,
    APP_REG_STAT_BUTT
};
typedef VOS_UINT32 APP_REG_STAT_ENUM_UINT32;

enum APP_MM_SERVICE_DOMAIN_ENUM
{
    APP_MM_SERVICE_DOMAIN_NULL          = 0x00,
    APP_MM_SERVICE_DOMAIN_PS            ,
    APP_MM_SERVICE_DOMAIN_CS            ,
    APP_MM_SERVICE_DOMAIN_PS_CS         ,
    APP_MM_SERVICE_DOMAIN_BUTT
};
typedef VOS_UINT32 APP_MM_SERVICE_DOMAIN_ENUM_UINT32;


enum APP_MM_DETACH_ENTITY_ENUM
{
    APP_MM_DETACH_ENTITY_ME             = 0x01,
    APP_MM_DETACH_ENTITY_NW             = 0x02,
    APP_MM_DETACH_ENTITY_BUTT
};
typedef VOS_UINT32 APP_MM_DETACH_ENTITY_ENUM_UINT32;

enum APP_MM_PLMN_TYPE_ENUM
{
    APP_MM_PLMN_TYPE_RPLMN              = 0x01,
    APP_MM_PLMN_TYPE_EPLMN              ,
    APP_MM_PLMN_TYPE_FPLMN              ,
    APP_MM_PLMN_TYPE_UPLMN              ,
    APP_MM_PLMN_TYPE_OPLMN              ,
    APP_MM_PLMN_TYPE_BUTT
};
typedef VOS_UINT32 APP_MM_PLMN_TYPE_ENUM_UINT32;

enum APP_MM_SET_TYPE_ENUM
{
    APP_MM_SET_TYPE_SETTING             = 0x00,
    APP_MM_SET_TYPE_DELETE              ,
    APP_MM_SET_TYPE_BUTT
};
typedef VOS_UINT32 APP_MM_SET_TYPE_ENUM_UINT32;

enum APP_MM_DAYLIGHT_SAVE_TIME_ENUM
{
    APP_MM_DAYLIGHT_NO_ADJUST                         = 0,
    APP_MM_DAYLIGHT_1_HOUR_ADJUST                        ,
    APP_MM_DAYLIGHT_2_HOUR_ADJUST                        ,
    APP_MM_DAYLIGHT_BUTT
};
typedef VOS_UINT32  APP_MM_DAYLIGHT_SAVE_TIME_ENUM_UINT32;

enum APP_MM_TIMEZONE_ENUM
{
    APP_MM_TIMEZONE_POSITIVE                        = 0,
    APP_MM_TIMEZONE_NAGETIVE                           ,
    APP_MM_TIMEZONE_BUTT
};
typedef VOS_UINT8  APP_MM_TIMEZONE_ENUM_UINT8;

/* add for ue cap display, 2017-02-03, begin */
/*****************************************************************************
 ö����    : APP_MM_UE_CAP_INFO_RSLT_ENUM
 ö��˵��  : HIDS��ȡLNAS��IMSA���UE�����Ľ��,ֻҪLNAS��IMSA��һ�������ɹ���ȡ,
             �����Ϊ�ɹ�
*****************************************************************************/
enum APP_MM_UE_CAP_INFO_RSLT_ENUM
{
    APP_MM_UE_CAP_INFO_FAIL                        = 0,
    APP_MM_UE_CAP_INFO_SUCC                        = 1,
    APP_MM_UE_CAP_INFO_BUTT
};
typedef VOS_UINT32 APP_MM_UE_CAP_INFO_RSLT_ENUM_UINT32;
/* add for ue cap display, 2017-02-03, end */


/*****************************************************************************
  5. STRUCT
*****************************************************************************/


/* APP_MM_MSG_ID_UINT32����4����:

-----------------------------------------------------------
  �ֽڸ�λ                                      �ֽڵ�λ
-----------------------------------------------------------
| BYTE1��4λ + 0000 |  BYTE2    |   BYTE3    |    BYTE4   |
-----------------------------------------------------------
0000��Э��ģ�����Ϣ|  Դģ��� |  Ŀ��ģ���| ��Ϣ��0-255
-----------------------------------------------------------
0001��L2 LOG        |           |            |
-----------------------------------------------------------
0010���տ���Ϣ      |           |            |
-----------------------------------------------------------
0011����ͨ����      |           |            |
-----------------------------------------------------------
0100��ʵʱ�������  |           |            |
-----------------------------------------------------------
0101���ؼ��¼�      |           |            | ��������
-----------------------------------------------------------
*/
typedef VOS_UINT32  APP_MM_MSG_ID_UINT32;

/*****************************************************************************
 �ṹ��    : APP_PLMN_INFO_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    APP_PLMN_ID_STRU                    stPlmnId;           /* PLMN ID  */
    APP_PLMN_STATUS_FLAG_ENUM_UINT32    ulPlmnStatus;       /* PLMN״̬ */
    APP_PH_RA_MODE_ENUM_UINT32          ulAccessMode;       /* ���뷽ʽ */
} APP_PLMN_INFO_STRU;

/*****************************************************************************
 �ṹ��    : APP_PLMN_LIST_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulPlmnNum;
    APP_PLMN_INFO_STRU                  stPlmnInfo[APP_MAX_PLMN_NUM];
} APP_PLMN_INFO_LIST_STRU;

/*****************************************************************************
�ṹ����    :APP_GUTI_HEAD_STRU
ʹ��˵��    :APP_GUTI_HEAD_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucLenth;
    VOS_UINT8                           ucOeToi;
    VOS_UINT8                           aucRsv[2];
}APP_GUTI_HEAD_STRU;

/*****************************************************************************
�ṹ����    :APP_MME_GROUPID_STRU
ʹ��˵��    :APP_MME_GROUPID_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucGroupId;
    VOS_UINT8                           ucGroupIdCnt;
    VOS_UINT8                           aucRsv[2];
}APP_MME_GROUPID_STRU;

/*****************************************************************************
�ṹ����    :APP_MME_CODE_STRU
ʹ��˵��    :APP_MME_CODE_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucMmeCode;
    VOS_UINT8                           aucRsv[3];
}APP_MME_CODE_STRU;

/*****************************************************************************
�ṹ����    :APP_MTMSI_STRU
ʹ��˵��    :APP_MTMSI_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucMTmsi;
    VOS_UINT8                           ucMTmsiCnt1;
    VOS_UINT8                           ucMTmsiCnt2;
    VOS_UINT8                           ucMTmsiCnt3;
}APP_MTMSI_STRU;


/*****************************************************************************
�ṹ����    :APP_GUTI_STRU
ʹ��˵��    :APP_GUTI_STRU����ز���
*****************************************************************************/
typedef struct
{
    APP_GUTI_HEAD_STRU                  stGutiHead;
    APP_PLMN_ID_STRU                    stPlmn;
    APP_MME_GROUPID_STRU                stMmeGroupId;
    APP_MME_CODE_STRU                   stMmeCode;
    APP_MTMSI_STRU                      stMTmsi;
}APP_GUTI_STRU;


/*****************************************************************************
�ṹ����    : APP_MBMSSER_ID_STRU
ʹ��˵��    : 24.008 10.5.6.13
              MBMS Service ID (octet 3, 4 and 5)
              In the MBMS Service ID field bit 8 of octet 3 is the most
              significant bit and bit 1 of octet 5 the least significant bit.
              The coding of the MBMS Service ID is the responsibility of each
              administration. Coding using full hexadecimal representation may
              be used. The MBMS Service ID consists of 3 octets.
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulMbmsSerId;
}APP_MBMSSER_ID_STRU;
/*****************************************************************************
�ṹ����    :APP_TMGI_STRU
ʹ��˵��    :APP_TMGI_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpPlmn         :1; /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          bitSpare          :31;

    APP_MBMSSER_ID_STRU                 stMbmsSer;
    APP_PLMN_ID_STRU                    stPlmnId;
}APP_TMGI_STRU;

/*****************************************************************************
�ṹ����    :APP_TMGI_MBMS_HEAD_STRU
ʹ��˵��    :APP_TMGI_MBMS_HEAD_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucLenth;
    VOS_UINT8                           ucOeTi;
    VOS_UINT8                           aucRsv[2];
}APP_TMGI_MBMS_HEAD_STRU;
/*****************************************************************************
�ṹ����    :APP_TMGI_MBMS_STRU
ʹ��˵��    :APP_TMGI_MBMS_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpMbmsSesId  :1; /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          bitSpare        :31;

    APP_TMGI_MBMS_HEAD_STRU             stMsidHead;
    APP_TMGI_STRU                       stTmgi;
    VOS_UINT8                           ucMbmsSesId;
    VOS_UINT8                           aucRsv[3];
}APP_TMGI_MBMS_STRU;

/*****************************************************************************
�ṹ����    :APP_UEID_STRU
ʹ��˵��    :APP_UEID_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpImsi     :1; /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          bitOpImei     :1;
    VOS_UINT32                          bitOpImeisv   :1;
    VOS_UINT32                          bitOpTmsi     :1;
    VOS_UINT32                          bitOpPtmsi    :1;
    VOS_UINT32                          bitOpGuti     :1;
    VOS_UINT32                          bitOpTmgiMbms :1; /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          bitOpRsv      :25;


    VOS_UINT8                           aucImsi[APP_MAX_UEID_BUF_SIZE];
    VOS_UINT8                           aucReserved1[2];
    VOS_UINT8                           aucImei[APP_MAX_UEID_BUF_SIZE];
    VOS_UINT8                           aucReserved2[2];
    VOS_UINT8                           aucImeisv[APP_MAX_UEID_BUF_SIZE];
    VOS_UINT8                           aucReserved3[2];
    VOS_UINT8                           aucTmsi[APP_MAX_UEID_BUF_SIZE];
    VOS_UINT8                           aucReserved4[2];
    VOS_UINT8                           aucPtmsi[APP_MAX_UEID_BUF_SIZE];
    VOS_UINT8                           aucReserved5[2];

    APP_GUTI_STRU                       stGuti;
    APP_TMGI_MBMS_STRU                  stTmgiMbms;
}APP_UEID_STRU;

/*****************************************************************************
�ṹ����    :APP_LAC_STRU
ʹ��˵��    :APP_LAC_STRU����ز���
*****************************************************************************/

typedef struct
{
    VOS_UINT8                           ucLac;
    VOS_UINT8                           ucLacCnt;
    VOS_UINT8                           aucRsv[2];
} APP_LAC_STRU;

/*****************************************************************************
�ṹ����    :APP_RAC_STRU
ʹ��˵��    :APP_RAC_STRU����ز���
*****************************************************************************/

typedef struct
{
    VOS_UINT8                           ucRac;
    VOS_UINT8                           aucRsv[3];
} APP_RAC_STRU;

/*****************************************************************************
�ṹ����    :APP_TAC_STRU
ʹ��˵��    :APP_TAC_STRU����ز���
*****************************************************************************/

typedef struct
{
    VOS_UINT8                           ucTac;
    VOS_UINT8                           ucTacCnt;
    VOS_UINT8                           aucRsv[2];
} APP_TAC_STRU;

/*****************************************************************************
�ṹ����    :APP_NETWORK_ID_STRU
ʹ��˵��    :APP_NETWORK_ID_STRU����ز���
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpPlmnId   : 1; /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          bitOpLac      : 1; /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          bitOpRac      : 1; /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          bitOpTac      : 1; /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          bitOpCellId   : 1;
    VOS_UINT32                          bitOpRsv      : 27;

    APP_PLMN_ID_STRU                    stPlmnId;
    APP_LAC_STRU                        stLac;
    APP_RAC_STRU                        stRac;
    APP_TAC_STRU                        stTac;
    VOS_UINT32                          ulCellId;                           /* Cell Identity */
} APP_NETWORK_ID_STRU;


/*****************************************************************************
�ṹ����    :APP_MS_CLASSMARK_1_STRU
ʹ��˵��    :24.008 840 10.5.1.5
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucValue;
    VOS_UINT8                           aucRsv[3];

}APP_MS_CLASSMARK_1_STRU;

/*****************************************************************************
�ṹ����    :APP_MS_CLASSMARK_2_STRU
ʹ��˵��    :24.008 840 10.5.1.6
              ���Ǵ�С�˺�BIT�򣬽����޸ģ�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucLenLvLen;
    VOS_UINT8                           aucClassMark[3];
}APP_MS_CLASSMARK_2_STRU;

/*****************************************************************************
�ṹ����    :APP_MS_CLASSMARK_3_STRU
ʹ��˵��    :24.008 840 10.5.1.7
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucLenLvLen;
    VOS_UINT8                           aucValue[35];

}APP_MS_CLASSMARK_3_STRU;

/*****************************************************************************
�ṹ����    :APP_MS_CLASSMARK_STRU
ʹ��˵��    :24.008 840 10.5.1.6
            0   EPS encryption algorithm *** not supported
            1   EPS encryption algorithm *** supported

            #define NAS_MM_ALGORITHM_NOT_SUPPORT    0
            #define NAS_MM_ALGORITHM_SUPPORT        1
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpClassMark1     :1;
    VOS_UINT32                          bitOpClassMark2     :1;
    VOS_UINT32                          bitOpClassMark3     :1;

    VOS_UINT32                          bitOpRsv            :29;

    APP_MS_CLASSMARK_1_STRU             stClassMark1;
    APP_MS_CLASSMARK_2_STRU             stClassMark2;
    APP_MS_CLASSMARK_3_STRU             stClassMark3;

}APP_MS_CLASSMARK_STRU;

/*****************************************************************************
�ṹ����    :APP_UE_NET_CAP_STRU
ʹ��˵��    :23.401-800 9.9.3.34
            0   EPS encryption algorithm *** not supported
            1   EPS encryption algorithm *** supported

            #define NAS_MM_ALGORITHM_NOT_SUPPORT    0
            #define NAS_MM_ALGORITHM_SUPPORT        1
            ���Ǵ�С�˺�BIT�򣬽����޸ģ�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucUeNetCapLen;
    VOS_UINT8                           aucUeNetCap[NAS_MM_MAX_UE_NET_CAP_LEN];
    VOS_UINT8                           aucRsv[2];
}APP_UE_NET_CAP_STRU;

/*****************************************************************************
�ṹ����    :APP_MS_NET_CAP_STRU
ʹ��˵��    :24.008 10.5.5.12

    aucMsNetCap��������Э���������ֽ�/λ�Ĺ�ϵ����:
    --------------------------------------------------------------
    (BIT8)|(BIT7)|(BIT6)|(BIT5)|(BIT4)|(BIT3)|(BIT2)|(BIT1)
    --------------------------------------------------------------
        Length of MS network capability contents, UNIT is byte      octet 0
    --------------------------------------------------------------
        MS network capability value                                 octet 1-8
    --------------------------------------------------------------
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucMsNetCapLen;
    /* ���ڱ���ʱ��ֱ�ӿ��������aucMsNetCap[0]���߼����λ��GEA1 bits����տڴ���һ�� */
    VOS_UINT8                           aucMsNetCap[NAS_MM_MAX_MS_NET_CAP_LEN];
    VOS_UINT8                           aucRsv[3];
}APP_MS_NET_CAP_STRU;

typedef struct
{
    VOS_UINT32                          ulPlmnNum;
    APP_PLMN_ID_STRU                    astPlmnId[APP_MM_MAX_PLMN_NUM];
}APP_MM_PLMN_LIST_STRU;

/*add begin*/
typedef struct
{
    VOS_UINT32                          ulPlmnNum;
    APP_PLMN_ID_STRU                    astPlmnId[APP_MM_MAX_EQU_PLMN_NUM];
} APP_EMM_EPLMN_LIST_STRU;

typedef struct
{
    APP_PLMN_ID_STRU                    stPlmnId;
    APP_TAC_STRU                        stTac;
}APP_TA_STRU;

typedef struct
{
    VOS_UINT32                          ulTaNum;            /* TA�ĸ���    */
    APP_TA_STRU                         astTa[APP_MM_MAX_TA_NUM];
}APP_TA_LIST_STRU;

typedef struct
{
    VOS_UINT32                          ulPlmnNum;
    APP_PLMN_ID_STRU                    astPlmnId[APP_MM_MAX_PLMN_NUM];
}APP_EMM_PLMN_LIST_STRU;

typedef struct
{
    APP_EMM_MAIN_STATE_ENUM_UINT16      ulMainState;        /*MM��״̬*/
    APP_EMM_SUB_STATE_ENUM_UINT16       ulSubState;         /*MM��״̬*/
    APP_EMM_UPDATE_STATE_ENUM_UINT32    ulEmmUpState;       /*EMM update״̬*/
    APP_EMM_REG_STATE_ENUM_UINT32       ulRegState;         /*ע��״̬*/
    APP_EMM_SRV_STATE_ENUM_UINT32       ulMmcSrvStat;       /*EMM����״̬*/
    APP_EMM_SEL_MODE_ENUM_UINT32        ulPlmnSelMode;      /*����ģʽ*/
    APP_EMM_EPLMN_LIST_STRU             stEPlmnList;        /*EPLMN List*/
    APP_PLMN_ID_STRU                    stRplmn;            /*RPlmn*/
    APP_TA_LIST_STRU                    stTaiList;          /*TaiList*/
    APP_TA_STRU                         stLastTa;           /*Last Ta*/
    APP_EMM_PLMN_LIST_STRU              stFplmnList;        /*Forbiden Plmn*/
    APP_TA_LIST_STRU                    stForbTaList;       /*Forbiden Ta*/
    APP_GUTI_STRU                       stGuti;             /*GUTI */
}APP_EMM_INFO_STRU;

typedef struct
{
    APP_MM_TIMEZONE_ENUM_UINT8          enPosNegTimeZone;
    VOS_UINT8                           ucTimeZone;
    VOS_UINT8                           aucRsv[2];
}APP_MM_CN_TIMEZONE_STRU;

typedef struct
{
    APP_MM_CN_TIMEZONE_STRU             stTimeZone;
    VOS_UINT8                           ucYear;
    VOS_UINT8                           ucMonth;
    VOS_UINT8                           ucDay;
    VOS_UINT8                           ucHour;
    VOS_UINT8                           ucMinute;
    VOS_UINT8                           ucSecond;
    VOS_UINT8                           aucRsv[2];
}APP_MM_CN_TIMEZONE_UNITIME_STRU;


typedef struct
{
    VOS_UINT8                           ucMsgLen; /*��ʾ������TextString�ĳ���*/
    VOS_UINT8                           ucCodingScheme;
    VOS_UINT8                           ucAddCI;
    VOS_UINT8                           ucNumOfSpareInLastByte;
    VOS_UINT8                           aucMsg[APP_MM_CN_NAME_MAX_LEN];
    VOS_UINT8                           ucRsv;
}APP_MM_CN_NETWORK_NAME_STRU;

/*add end*/
/*****************************************************************************
�ṹ����    :APP_DRX_STRU
ʹ��˵��    :
    ucSplitPgCode:ȡֵ��Χ [0,98]
    ucPsDrxLen:ֻ��ȡֵ(0,6,7,8,9),����0:��־UE��ָ��DRX Cycle Len
    ucSplitOnCcch:ֻ��ȡֵ0 ���� 1
    ucNonDrxTimer:ȡֵ��Χ[0,7]
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucSplitPgCode;      /* SPLIT PG CYCLE CODE*/
    VOS_UINT8                           ucPsDrxLen;         /* DRX length         */
    VOS_UINT8                           ucSplitOnCcch;      /* SPLIT on CCCH      */
    VOS_UINT8                           ucNonDrxTimer;      /* non-DRX timer      */
}APP_DRX_STRU;

/*****************************************************************************
 �ṹ��    : APP_MM_START_REQ_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
} APP_MM_START_REQ_STRU;

/*****************************************************************************
 �ṹ��    : APP_MM_START_CNF_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    VOS_UINT32                          ulRslt ;
} APP_MM_START_CNF_STRU;

/*****************************************************************************
 �ṹ��    : APP_MM_STOP_REQ_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
} APP_MM_STOP_REQ_STRU;

/*****************************************************************************
 �ṹ��    : APP_MM_STOP_CNF_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    VOS_UINT32                          ulRslt;
} APP_MM_STOP_CNF_STRU;

/*****************************************************************************
 �ṹ��    : APP_MM_ATTACH_REQ_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    APP_MM_ATTACH_TYPE_ENUM_UINT32      enAttachType;        /* �������� */
} APP_MM_ATTACH_REQ_STRU;

/*****************************************************************************
 �ṹ��    : APP_MM_ATTACH_CNF_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER

    VOS_UINT32                          ulOpId;
    VOS_UINT32                          ulRslt;
} APP_MM_ATTACH_CNF_STRU;

/*****************************************************************************
 �ṹ��    : APP_MM_ATTACH_IND_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    VOS_UINT32                          ulRslt;
    APP_MM_ATTACH_TYPE_ENUM_UINT32      enAttachType;       /* ��������       */
} APP_MM_ATTACH_IND_STRU;


/*****************************************************************************
 �ṹ��    : APP_MM_DETACH_REQ_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    APP_MM_DETACH_TYPE_ENUM_UINT32      enDetachType;
} APP_MM_DETACH_REQ_STRU;

/*****************************************************************************
 �ṹ��    : APP_MM_DETACH_CNF_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    VOS_UINT32                          ulRslt;
} APP_MM_DETACH_CNF_STRU;


/*****************************************************************************
 �ṹ��    : APP_MM_DETACH_IND_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    APP_MM_DETACH_ENTITY_ENUM_UINT32    enDetEntityType;
} APP_MM_DETACH_IND_STRU;



/*****************************************************************************
 �ṹ��    : APP_MM_REG_STAT_IND
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                  /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;    /*_H2ASN_Skip*/
    APP_MSG_HEADER

    VOS_UINT32                          ulOpId;
    APP_REG_STAT_ENUM_UINT32            enRegStat;
    APP_MM_SERVICE_DOMAIN_ENUM_UINT32   enSrvDomain;
    APP_PH_RA_MODE_ENUM_UINT32          enAccessMode;  /*����ģʽ*/
    APP_PLMN_ID_STRU                    stPlmnId;      /* PLMN ID  */
    APP_TAC_STRU                        stTac;
    VOS_UINT32                          ulCellId;
}APP_MM_REG_STAT_IND_STRU;



/*========== ���ò�ѯ������  �����ṹ ==========*/

typedef struct
{
    VOS_UINT8                           ucBitOpAttach;
    VOS_UINT8                           aucBitOpRsv[3];

    VOS_UINT8                           ucAttachAtmNum;
    VOS_UINT8                           aucRsv[3];
}APP_MM_OPT_ATTEMP_NUM_STRU;



/*========== ������ͨ������  ��Ϣ�ṹ ========================================*/

typedef struct
{
    VOS_MSG_HEADER                                  /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;    /*_H2ASN_Skip*/

    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    VOS_UINT32                          ulRslt;
}APP_MM_SET_CMD_CNF_STRU;




/*========== ��ѯ��ͨ������     ��Ϣ�ṹ ==========*/

typedef VOS_UINT32 DT_CMD_ENUM_UINT32;

typedef struct
{
    VOS_MSG_HEADER                                  /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;    /*_H2ASN_Skip*/

    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;

    DT_CMD_ENUM_UINT8                   enCmd;
    VOS_UINT8                           ucRsv[3];
    VOS_UINT32                          ulRptPeriod;
}APP_MM_INQ_CMD_REQ_STRU;


typedef APP_MM_INQ_CMD_REQ_STRU           APP_MM_INQ_UE_MODE_REQ_STRU;
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulRslt;           /*0�ɹ���1ʧ��*/
    NAS_LMM_UE_OPERATION_MODE_ENUM_UINT32 enCurrentUeMode;  /*��ǰUEģʽ*/
    VOS_UINT32                            ulSupportModeCnt; /*UE�ܹ�֧�ֵ�ģʽ�ĸ���*/
    NAS_LMM_UE_OPERATION_MODE_ENUM_UINT32 aenSupportModeList[4];	/*UE�ܹ�֧�ֵ�ģʽ*/
} APP_MM_INQ_UE_MODE_CNF_STRU;
typedef APP_MM_INQ_CMD_REQ_STRU           APP_MM_INQ_LTE_CS_REQ_STRU;
typedef struct
{
    VOS_UINT8                             ucSmsOverSGs;
    VOS_UINT8                             ucSmsOverIMS;
    VOS_UINT8                             ucCSFB;
    VOS_UINT8                             ucSrVcc;
    VOS_UINT8                             ucVoLGA;
    VOS_UINT8                          aucRsv[3];
} APP_MM_LTE_CS_INFO_STRU;
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                            ulMsgId;
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulRslt;           /*0�ɹ���1ʧ��*/
    APP_MM_LTE_CS_INFO_STRU               stLtecsInfo;
} APP_MM_INQ_LTE_CS_CNF_STRU;

/*DT begin */
typedef APP_MM_INQ_CMD_REQ_STRU           APP_MM_INQ_LTE_GUTI_REQ_STRU;

/*V7R2-DT ,2014/4/23,CNF ���ϱ���Ϣ�壬��IND�ϱ�, begin*/
typedef struct
{
    VOS_MSG_HEADER                                  /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;  /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulRslt;           /*0�ɹ���1ʧ��*/
} APP_MM_INQ_LTE_GUTI_CNF_STRU;
/*V7R2-DT ,2014/4/23,CNF ���ϱ���Ϣ�壬��IND�ϱ�, end*/

typedef struct
{
    VOS_MSG_HEADER                                  /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;  /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    APP_GUTI_STRU                         stGuti;           /*GUTI��Ϣ */
} APP_MM_INQ_LTE_GUTI_IND_STRU;

typedef APP_MM_INQ_CMD_REQ_STRU           APP_MM_INQ_IMSI_REQ_STRU;

typedef struct
{
    VOS_UINT8               ucImsiLen;                        /*IMSI���� */
    VOS_UINT8               ucImsi[APP_EMM_IMSI_MAX_LEN];     /*IMSI���� */
}NAS_OM_IMSI_INFO_STRU;

/*V7R2-DT ,2014/4/25, begin*/
typedef struct
{
    VOS_MSG_HEADER                                   /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;   /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulRslt;           /*0�ɹ���1ʧ��*/
} APP_MM_INQ_IMSI_CNF_STRU;
/*V7R2-DT ,2014/4/25, end*/

typedef struct
{
    VOS_MSG_HEADER                                 /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;/*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    NAS_OM_IMSI_INFO_STRU                 stImsi;           /*IMSI��Ϣ */
} APP_MM_INQ_IMSI_IND_STRU;

typedef APP_MM_INQ_CMD_REQ_STRU           APP_MM_INQ_EMM_STATE_REQ_STRU;

typedef struct
{
    APP_EMM_MAIN_STATE_ENUM_UINT16       enMainState;        /* EMM��״̬*/
    APP_EMM_SUB_STATE_ENUM_UINT16        enSubState;         /* EMM��״̬ */
    VOS_UINT16                           usStaTId;           /* ��ʱ����Ϣ*/
    VOS_UINT8                            ucRsv[2];
}NAS_OM_EMM_STATE_STRU;


/*V7R2-DT ,2014/4/23,CNF ���ϱ���Ϣ�壬��IND�ϱ�, begin*/
typedef struct
{
    VOS_MSG_HEADER                                /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;/*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulRslt;           /*0�ɹ���1ʧ��*/
} APP_MM_INQ_EMM_STATE_CNF_STRU;
/*V7R2-DT ,2014/4/23, CNF ���ϱ���Ϣ�壬��IND�ϱ�,end*/

typedef struct
{
    VOS_MSG_HEADER                               /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;/*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    NAS_OM_EMM_STATE_STRU                 stEmmState;        /*EMM״̬��Ϣ */
} APP_MM_INQ_EMM_STATE_IND_STRU;

/*DT end */
/* Added for DT report, 2018-11-21, begin */
typedef APP_MM_INQ_CMD_REQ_STRU           APP_MM_INQ_EMM_REG_STATE_REQ_STRU;

typedef struct
{
    VOS_MSG_HEADER                                  /*_H2ASN_Skip*/
    VOS_UINT32                            ulMsgId;  /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                            ulOpId;
    VOS_UINT32                            ulRslt;   /*0�ɹ���1ʧ��*/
} APP_MM_INQ_EMM_REG_STATE_CNF_STRU;
/* Added for DT report, 2018-11-21, end */

typedef struct
{
    APP_MM_MSG_TYPE_ENUM_UINT32         enMsgId;            /*_H2ASN_MsgChoice_Export APP_MM_MSG_TYPE_ENUM_UINT32*/
    VOS_UINT8                           aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          APP_MM_MSG_TYPE_ENUM_UINT32
    ****************************************************************************/
}APP_MM_INTERFACE_MSG_DATA;
/*_H2ASN_Length UINT32*/


typedef struct
{
    VOS_MSG_HEADER
    APP_MM_INTERFACE_MSG_DATA           stMsgData;
} AppMmInterface_MSG;

/* add for ue cap display, 2017-02-03, begin */
/*****************************************************************************
 �ṹ��    : APP_MM_UE_CAP_INFO_REQ_STRU
 �ṹ˵��  : HIDS����LNAS��IMSA���UE��������Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                          ulOpId;
    VOS_UINT8                           aucRsv[32];         /* Ԥ�� */
} APP_MM_UE_CAP_INFO_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LNAS_APP_UE_CAP_INFO_STRU
 �ṹ˵��  : LNAS���UE������Ϣ�Ľṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               aucUeNetCap[NAS_MM_MAX_UE_NET_CAP_LEN];     /* UE NETWORK CAPABILITY */
    VOS_UINT8                               aucRsv[35];                                 /* Ԥ��,����4�ֽڶ���    */
    NAS_EMM_USAGE_SETTING_UINT32            ulUsageSetting;                             /* UE CENTER             */
    NAS_LMM_VOICE_DOMAIN_ENUM_UINT32        ulVoiceDomain;                              /* VOICE DOMAIN          */
    NAS_LMM_CS_SERVICE_ENUM_UINT32          ulCsService;                                /* CS SERVICE            */
    NAS_LMM_UE_OPERATION_MODE_ENUM_UINT32   ulLteUeMode;                                /* CS/PS MODE            */
} LNAS_APP_UE_CAP_INFO_STRU;

/*****************************************************************************
 �ṹ��    : IMSA_APP_UE_CAP_INFO_STRU
 �ṹ˵��  : IMSA���UE�����ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucLteImsSupportFlag;            /**< LTE IMSʹ����,  1 :֧�֣�0 :��֧�� */
    VOS_UINT8                           ucVoiceCallOnImsSupportFlag;    /**< IMS����ʹ����,  1 :֧�֣�0 :��֧�� */
    VOS_UINT8                           ucVideoCallOnImsSupportFlag;    /**< IMS��Ƶʹ����,  1 :֧�֣�0 :��֧�� */
    VOS_UINT8                           ucSmsOnImsSupportFlag;          /**< IMS����ʹ����,  1 :֧�֣�0 :��֧�� */
    VOS_UINT8                           ucSrvccOnImsSupportFlag;        /**< IMS Srvccʹ����,1 :֧�֣�0 :��֧�� */
    VOS_UINT8                           ucAmrWbSupportFlag;             /**< AMR WBʹ����,   1 :֧�֣�0 :��֧�� */
    VOS_UINT8                           ucIr92ComplianceFlag;           /**< IR.92���ӱ�־,  1 :֧�֣�0 :��֧�� */
    VOS_UINT8                           aucRsv[33];                     /**< Ԥ��,����4�ֽڶ���                 */
} IMSA_APP_UE_CAP_INFO_STRU;

/*****************************************************************************
 �ṹ��    : MM_APP_UE_CAP_INFO_CNF_STRU
 �ṹ˵��  : �ظ�HIDS���UE��������Ϣ�ṹ��--����LNAS��IMSA��UE����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                              /*_H2ASN_Skip*/
    VOS_UINT32                              ulMsgId;            /*_H2ASN_Skip*/
    APP_MSG_HEADER
    VOS_UINT32                              ulOpId;
    VOS_UINT32                              bitOpLnasUeCap :1;  /* ָʾLNAS UE�����Ƿ�ɹ���ȡ��, 1:��ȡ�ɹ�; 0:��ȡʧ�� */
    VOS_UINT32                              bitOpImsaUeCap :1;  /* ָʾIMSA UE�����Ƿ�ɹ���ȡ��, 1:��ȡ�ɹ�; 0:��ȡʧ�� */
    VOS_UINT32                              bitOpRsv       :30;
    LNAS_APP_UE_CAP_INFO_STRU               stLnasUeCapInfo;    /* LNAS���UE������Ϣ */
    IMSA_APP_UE_CAP_INFO_STRU               stImsaUeCapInfo;    /* IMSA�ظ�HIDS��ص�UE���� */
}MM_APP_UE_CAP_INFO_CNF_STRU;
/* add for ue cap display, 2017-02-03, end */


/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/

/*****************************************************************************
  9 OTHERS
*****************************************************************************/





#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif



#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of AppMmInterface.h */

