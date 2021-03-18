/*********************************************************************************************************
**
**                                    中国软件开源组织
**
**                                   嵌入式实时操作系统
**
**                                SylixOS(TM)  LW : long wing
**
**                               Copyright All Rights Reserved
**
**--------------文件信息--------------------------------------------------------------------------------
**
** 文   件   名: config.h
**
** 创   建   人: RealEvo-IDE
**
** 文件创建日期: 2021 年 02 月 25 日
**
** 描        述: 本文件由 RealEvo-IDE 生成，用于配置 BSP 相关地址信息
*********************************************************************************************************/

#ifndef __BSP_CONFIG_H
#define __BSP_CONFIG_H

/*********************************************************************************************************
  ROM RAM 相关配置
*********************************************************************************************************/

#define BSP_CFG_ROM_BASE (0x00000000)
#define BSP_CFG_ROM_SIZE (4 * 1024 * 1024)

#define BSP_CFG_RAM_BASE (0x30000000)
#define BSP_CFG_RAM_SIZE (64 * 1024 * 1024)

#define BSP_CFG_TEXT_SIZE (6 * 1024 * 1024)
#define BSP_CFG_DATA_SIZE (18 * 1024 * 1024)
#define BSP_CFG_DMA_SIZE (6 * 1024 * 1024)
#define BSP_CFG_APP_SIZE (34 * 1024 * 1024)

#define BSP_CFG_BOOT_STACK_SIZE (128 * 1024)

#endif                                                                  /*  __BSP_CONFIG_H              */
/*********************************************************************************************************
  END
*********************************************************************************************************/
