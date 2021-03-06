/*********************************************************************************************************
**
**                                    中国软件开源组织
**
**                                   嵌入式实时操作系统
**
**                                       SylixOS(TM)
**
**                               Copyright  All Rights Reserved
**
**--------------文件信息--------------------------------------------------------------------------------
**
** 文   件   名: s3c2440a_pm.c
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2014 年 07 月 20 日
**
** 描        述: 电源管理驱动, 目前还不包括 CPU 模式管理 (实验性质)
*********************************************************************************************************/
#define  __SYLIXOS_KERNEL
#include "config.h"                                                     /*  工程配置 & 处理器相关       */
#include "SylixOS.h"
/*********************************************************************************************************
  S3C2440A 电源管理器
*********************************************************************************************************/
typedef struct {
    LW_PMA_FUNCS    pmafuncs;
    PVOID           reserved;
} S3C2440A_PMA;
/*********************************************************************************************************
** Function name:           pmPowerOn
** Descriptions:            指定设备上电
** input parameters:        pmadapter   电源管理适配器
** output parameters:       pmdev       设备
** Returned value:          OK
** Created by:              Hanhui
** Created Date:            2014-07-20
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
static INT  pmPowerOn (PLW_PM_ADAPTER  pmadapter,
                       PLW_PM_DEV      pmdev)
{
    rCLKCON |= (1 << pmdev->PMD_uiChannel);

    return  (ERROR_NONE);
}
/*********************************************************************************************************
** Function name:           pmPowerOff
** Descriptions:            指定设备下电
** input parameters:        pmadapter   电源管理适配器
** output parameters:       pmdev       设备
** Returned value:          OK
** Created by:              Hanhui
** Created Date:            2014-07-20
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
static INT  pmPowerOff (PLW_PM_ADAPTER  pmadapter,
                        PLW_PM_DEV      pmdev)
{
    rCLKCON &= ~(1 << pmdev->PMD_uiChannel);

    return  (ERROR_NONE);
}
/*********************************************************************************************************
** Function name:           pmPowerIsOn
** Descriptions:            指定设备是否已经上电
** input parameters:        pmadapter   电源管理适配器
** output parameters:       pmdev       设备
**                          pbIsOn      是否上电
** Returned value:          OK
** Created by:              Hanhui
** Created Date:            2014-07-20
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
static INT  pmPowerIsOn (PLW_PM_ADAPTER  pmadapter,
                         PLW_PM_DEV      pmdev,
                         BOOL           *pbIsOn)
{
    if (pbIsOn) {
        if (rCLKCON & (1 << pmdev->PMD_uiChannel)) {
            *pbIsOn = LW_TRUE;
        } else {
            *pbIsOn = LW_FALSE;
        }
    }

    return  (ERROR_NONE);
}
/*********************************************************************************************************
** Function name:           pmGetFuncs
** Descriptions:            获取电源管理适配器函数集
** input parameters:        NONE
** output parameters:       NONE
** Returned value:          pfuncs      驱动程序集
** Created by:              Hanhui
** Created Date:            2014-07-20
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
PLW_PMA_FUNCS  pmGetFuncs (VOID)
{
    static S3C2440A_PMA     pma;

    pma.pmafuncs.PMAF_pfuncOn   = pmPowerOn;
    pma.pmafuncs.PMAF_pfuncOff  = pmPowerOff;
    pma.pmafuncs.PMAF_pfuncIsOn = pmPowerIsOn;

    return  (&pma.pmafuncs);
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
