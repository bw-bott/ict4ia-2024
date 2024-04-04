/**
 * \file IfxQspi_cfg.h
 * \brief QSPI on-chip implementation data
 * \ingroup IfxLld_Qspi
 *
 * \version iLLD_1_0_1_12_0_1
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * \defgroup IfxLld_Qspi QSPI
 * \ingroup IfxLld
 * \defgroup IfxLld_Qspi_Impl Implementation
 * \ingroup IfxLld_Qspi
 * \defgroup IfxLld_Qspi_Std Standard Driver
 * \ingroup IfxLld_Qspi
 * \defgroup IfxLld_Qspi_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Qspi_Impl
 */

#ifndef IFXQSPI_CFG_H
#define IFXQSPI_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxQspi_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXQSPI_HWFIFO_DEPTH (4)

#define IFXQSPI_NUM_MODULES  (5)

#define IFXQSPI_NUM_CHANNELS (16)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available QSPI resources
 */
typedef enum
{
    IfxQspi_Index_none = -1,  /**< \brief Not Selected */
    IfxQspi_Index_0    = 0,   /**< \brief QSPI index 0  */
    IfxQspi_Index_1,          /**< \brief QSPI index 1  */
    IfxQspi_Index_2,          /**< \brief QSPI index 2  */
    IfxQspi_Index_3,          /**< \brief QSPI index 3  */
    IfxQspi_Index_4           /**< \brief QSPI index 4  */
} IfxQspi_Index;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxQspi_cfg_indexMap[IFXQSPI_NUM_MODULES];

#endif /* IFXQSPI_CFG_H */
