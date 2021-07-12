#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/ana/ti/bios_6_76_03_01/packages;/home/ana/ti/uia_2_30_01_02/packages;/home/ana/ti/pdk_omapl138_1_0_11/packages;/home/ana/workspace/tirtos-workspace/tirtosCfg_common_TMDSLCDK6748_starter/.config
override XDCROOT = /home/ana/ti/xdctools_3_55_02_22_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/ana/ti/bios_6_76_03_01/packages;/home/ana/ti/uia_2_30_01_02/packages;/home/ana/ti/pdk_omapl138_1_0_11/packages;/home/ana/workspace/tirtos-workspace/tirtosCfg_common_TMDSLCDK6748_starter/.config;/home/ana/ti/xdctools_3_55_02_22_core/packages;..
HOSTOS = Linux
endif
