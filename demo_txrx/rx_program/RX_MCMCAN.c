/********************************************************************************************************************
 * \file MCMCAN.c
 * \copyright Copyright (C) Infineon Technologies AG 2020
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "RX_MCMCAN.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
McmcanType                  g_mcmcan;                       /* Global MCMCAN configuration and control structure    */
IfxPort_Pin_Config          g_led1;                         /* Global LED1 configuration and control structure      */
IfxPort_Pin_Config          g_led2;                         /* Global LED2 configuration and control structure      */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Macro to define Interrupt Service Routine.
 * This macro:
 * - defines linker section as .intvec_tc<vector number>_<interrupt priority>.
 * - defines compiler specific attribute for the interrupt functions.
 * - defines the Interrupt service routine as ISR function.
 *
 * IFX_INTERRUPT(isr, vectabNum, priority)
 *  - isr: Name of the ISR function.
 *  - vectabNum: Vector table number.
 *  - priority: Interrupt priority. Refer Usage of Interrupt Macro for more details.
 */
IFX_INTERRUPT(canIsrRxHandler, 0, ISR_PRIORITY_CAN_RX);

/* Interrupt Service Routine (ISR) called once the RX interrupt has been generated.
 * Compares the content of the received CAN message with the content of the transmitted CAN message
 * and in case of success, turns on the LED2 to indicate successful CAN message reception.
 */
void canIsrRxHandler(void)
{
    /* Clear the "Message stored to Dedicated RX Buffer" interrupt flag */
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canNode.node, IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);

    /* Read the received CAN message */
    IfxCan_Can_readMessage(&g_mcmcan.canNode, &g_mcmcan.rxMsg, g_mcmcan.rxData);

    /* Turn on the LED2 to indicate correctness of the received message */
    IfxPort_setPinLow(g_led2.port, g_led2.pinIndex);

}

/* Function to initialize MCMCAN module and nodes related for this application use case */
void initMcmcan(void)
{
    IfxCan_Can_Pins canPins;

    /* ==========================================================================================
     * CAN module configuration and initialization:
     * ==========================================================================================
     *  - load default CAN module configuration into configuration structure
     *  - initialize CAN module with the default configuration
     * ==========================================================================================
     */

    /* TC37x provides two CAN module (CAN0/1). We use the CAN0 module. */
    /* Load default cfg into a specific structure. */
    IfxCan_Can_initModuleConfig(&g_mcmcan.canConfig, &MODULE_CAN0);

    /*Initialize the CAN0 module with the default cfg. */
    IfxCan_Can_initModule(&g_mcmcan.canModule, &g_mcmcan.canConfig);

    /* ==========================================================================================
     * Source CAN node configuration and initialization:
     * ==========================================================================================
     *  - load default CAN node configuration into configuration structure
     *  - assign source CAN node to CAN node 0
     *  - set baudrate to 1Mbps
     *  - define the frame type to be the receiving one
     *
     *  - once the message is stored in the dedicated RX buffer, raise the interrupt
     *  - define the receive interrupt priority
     *  - assign the interrupt line 1 to the receive interrupt
     *  - receive interrupt service routine should be serviced by the CPU0
     *
     *  - initialize the source CAN node with the modified configuration
     * ==========================================================================================
     */

    /* load default CAN node configuration into configuration structure */
    IfxCan_Can_initNodeConfig(&g_mcmcan.canNodeConfig, &g_mcmcan.canModule);

    /******************************/
    /* START OF MODIFICATION AREA */
    /******************************/
    /* assign source CAN node to CAN node 0 */
    g_mcmcan.canNodeConfig.nodeId = ;
    /* set baudrate to 1Mbps */
    g_mcmcan.canNodeConfig.baudRate.baudrate = ;
    /* define the frame type to be the receiving one */
    g_mcmcan.canNodeConfig.frame.type = ;

    /* once the message is stored in the dedicated RX buffer, raise the interrupt */
    g_mcmcan.canNodeConfig.interruptConfig.messageStoredToDedicatedRxBufferEnabled = ;
    /* define the receive interrupt priority */
    g_mcmcan.canNodeConfig.interruptConfig.traco.priority = ;
    /* assign the interrupt line 0 to the receive interrupt */
    g_mcmcan.canNodeConfig.interruptConfig.traco.interruptLine = ;
    /* receive interrupt service routine should be serviced by the CPU0 */
    g_mcmcan.canNodeConfig.interruptConfig.traco.typeOfService = ;
    /****************************/
    /* END OF MODIFICATION AREA */
    /****************************/

    /* ------------------------------------------------------------------------------------------
     * Pin configuration
     * ------------------------------------------------------------------------------------------
     * - Define the Rx pin based on connection to CAN PHY (check the Lite-Kit manual or schematic)
     * - Define the Rx pin in input pull-up mode
     * - Define the Tx pin based on connection to CAN PHY (check the Lite-Kit manual or schematic)
     * - Define the Tx pin in output push-pull mode
     * - Define the speed grade of Tx pin
     * ------------------------------------------------------------------------------------------
     */

    /******************************/
    /* START OF MODIFICATION AREA */
    /******************************/
    /* Define the Rx pin based on connection to CAN PHY (check the Lite-Kit manual or schematic) */
    canPins.rxPin = ;
    /* Define the Rx pin in input pull-up mode */
    canPins.rxPinMode = ;
    /* Define the Tx pin based on connection to CAN PHY */
    canPins.txPin = ;
    /* Define the Tx pin in output push-pull mode */
    canPins.txPinMode = ;
    /* Define the speed grade of Tx pin */
    canPins.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed3;
    /****************************/
    /* END OF MODIFICATION AREA */
    /****************************/

    g_mcmcan.canNodeConfig.pins = &canPins;

    /* initialize the source CAN node with the modified configuration */
    IfxCan_Can_initNode(&g_mcmcan.canNode, &g_mcmcan.canNodeConfig);

    /* ==========================================================================================
     * CAN filter configuration and initialization:
     * ==========================================================================================
     *  - filter configuration is stored under the filter element number 0
     *  - store received frame in a dedicated RX Buffer
     *  - define the same message ID as defined for the TX message
     *  - assign the filter to the dedicated RX Buffer (RxBuffer0 in this case)
     *
     *  - initialize the standard filter with the modified configuration
     * ==========================================================================================
     */

    /******************************/
    /* START OF MODIFICATION AREA */
    /******************************/
    /* filter configuration is stored under the filter element number 0 */
    g_mcmcan.canFilter.number = ;
    /* store received frame in a dedicated RX Buffer */
    g_mcmcan.canFilter.elementConfiguration = ;
    /* define the same message ID as defined for the TX message */
    g_mcmcan.canFilter.id1 = ;
    /* assign the filter to the dedicated RX Buffer (RxBuffer0 in this case) */
    g_mcmcan.canFilter.rxBufferOffset = ;
    /****************************/
    /* END OF MODIFICATION AREA */
    /****************************/

    /* initialize the standard filter with the modified configuration */
    IfxCan_Can_setStandardFilter(&g_mcmcan.canNode, &g_mcmcan.canFilter);

}

/* Function to initialize the LEDs */
void initLeds(void)
{
    /* ======================================================================
     * Configuration of the pins connected to the LEDs:
     * ======================================================================
     *  - define the GPIO port
     *  - define the GPIO pin that is connected to the LED
     *  - define the general GPIO pin usage (no alternate function used)
     *  - define the pad driver strength
     * ======================================================================
     */
    g_led1.port      = &MODULE_P00;
    g_led1.pinIndex  = PIN5;
    g_led1.mode      = IfxPort_OutputIdx_general;
    g_led1.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;

    g_led2.port      = &MODULE_P00;
    g_led2.pinIndex  = PIN6;
    g_led2.mode      = IfxPort_OutputIdx_general;
    g_led2.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;

    /* Initialize the pins connected to LEDs to level "HIGH", which keep the LEDs turned off as default state */
    IfxPort_setPinHigh(g_led1.port, g_led1.pinIndex);
    IfxPort_setPinHigh(g_led2.port, g_led2.pinIndex);

    /* Set the pin input/output mode for both pins connected to the LEDs */
    IfxPort_setPinModeOutput(g_led1.port, g_led1.pinIndex, IfxPort_OutputMode_pushPull, g_led1.mode);
    IfxPort_setPinModeOutput(g_led2.port, g_led2.pinIndex, IfxPort_OutputMode_pushPull, g_led2.mode);

    /* Set the pad driver mode for both pins connected to the LEDs */
    IfxPort_setPinPadDriver(g_led1.port, g_led1.pinIndex, g_led1.padDriver);
    IfxPort_setPinPadDriver(g_led2.port, g_led2.pinIndex, g_led2.padDriver);
}

/* Function to initialize the CAN_STB pin */
void initCanStbPin(void)
{
    IfxPort_Pin_Config stbPin;

    /******************************/
    /* START OF MODIFICATION AREA */
    /******************************/
    stbPin.port      = ;
    stbPin.pinIndex  = ;
    stbPin.mode      = ;
    stbPin.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
    /****************************/
    /* END OF MODIFICATION AREA */
    /****************************/

    /* Use the following functions (coming from the Infineon Low Level Drivers). */
    /* Initialize the pin connected to CAN_STB to level "LOW" for Normal-operating mode */
    IfxPort_setPinLow(stbPin.port, stbPin.pinIndex);

    /* Set the pin output mode for pin connected to the CAN_STB */
    IfxPort_setPinModeOutput(stbPin.port, stbPin.pinIndex, IfxPort_OutputMode_pushPull, stbPin.mode);

    /* Set the pad driver mode for pin connected to the CAN_STB */
    IfxPort_setPinPadDriver(stbPin.port, stbPin.pinIndex, stbPin.padDriver);
}