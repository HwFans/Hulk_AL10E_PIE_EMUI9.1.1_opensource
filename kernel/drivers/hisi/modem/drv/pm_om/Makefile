#gcov
ifeq ($(strip $(llt_gcov)),y)
GCOV_PROFILE := y
GCOV_PROFILE_pm_om_debug.o := n
endif

obj-$(CONFIG_PM_OM_BALONG) +=  pm_om.o pm_om_platform.o pm_om_debug.o  pm_om_pressure.o bsp_ring_buffer.o modem_log_linux.o pm_om_nrccpu.o
obj-$(CONFIG_PM_OM_BALONG_TEST) +=  pm_om_test.o 

subdir-ccflags-y := -Werror
