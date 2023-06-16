/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include"app_log.h"
#include "sl_simple_button_instances.h"
#include"usart.h"
#include"em_gpio.h"
/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  //GPIO_PinModeSet (gpioPortA,7,gpioModePushPull,1);
  //app_log("Hello world\n");
  iostream_usart_init();
//gpio_set();

     // GPIO_PinModeSet (gpioPortC,3,gpioModePushPull,0);
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{

}
