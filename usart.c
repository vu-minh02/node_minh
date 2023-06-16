/*
 * iostream_usart.c
 *
 *  Created on: Jun 8, 2023
 *      Author: assus
 */
#include <stdio.h>
#include<string.h>
#include"sl_iostream.h"
#include"sl_iostream_init_instances.h"
#include"sl_iostream_handles.h"
#include"em_gpio.h"
#include"sl_sleeptimer.h"
#ifndef BUFSIZE
#define BUFSIZE    80
#endif
int result;
//static char buffer[BUFSIZE];
void iostream_usart_init(void){
  //int8_t c = 0;
   uint8_t index = 0;
   char buffer[BUFSIZE];
  const char str1[]="123456789";
  char str[sizeof(str1)];
  strcpy(str, str1);
  sl_sleeptimer_delay_millisecond(2000);
      sl_iostream_write(sl_iostream_vcom_handle,str,strlen(str));

  sl_iostream_set_default(sl_iostream_vcom_handle);
  const char str2[]="this is output on the default strem\r\n";
  sl_iostream_write(SL_IOSTREAM_STDOUT,str2,strlen(str2));
  printf("Printf uses the default stream, as long as iostream_retarget_stdio is included.\r\n");

   printf("> ");
   /* Retrieve characters, print local echo and full line back */
   while (1) {
       char c;
       sl_status_t status = sl_iostream_getchar(sl_iostream_vcom_handle, &c);
       if (status == SL_STATUS_OK) {
         if (c == '\r' || c == '\n'||c=='H') {
           // Ký tự kết thúc dòng được nhận, xử lý dữ liệu đã đọc
           buffer[index] = '\0';
           printf("Received data: %s\n", buffer);
           const char *str = "a";
                               //const char *str2 = "World";

                               result = strcmp(str, buffer);

                               if (result < 0) {
                                   printf("Chuoi str1 nho hon str2\n");
                                   GPIO_PinModeSet (gpioPortA,4,gpioModePushPull,0);
                               } else if (result > 0) {
                                   printf("Chuoi str1 lon hon str2\n");
                                   GPIO_PinModeSet (gpioPortA,4,gpioModePushPull,0);
                               }
                               else {
                                   printf("Hai chuoi bang nhau\n");
                                   GPIO_PinModeSet (gpioPortA,4,gpioModePushPull,1);
                               }
           index = 0;
         } else {
           // Lưu trữ ký tự vào bộ đệm
           if (index < BUFSIZE - 1) {
             buffer[index] = c;
             index++;
           }
         }
       }

   }
   }

void iostream_usart(void){
  const char str1[]="IOstream USART example\r\n\r\n";
      sl_iostream_write(sl_iostream_vcom_handle,str1,strlen(str1));

  sl_iostream_set_default(sl_iostream_vcom_handle);
  const char str2[]="this is output on the default strem\r\n";
  sl_iostream_write(SL_IOSTREAM_STDOUT,str2,strlen(str2));
  printf("Printf uses the default stream, as long as iostream_retarget_stdio is included.\r\n");
}
void gpio_set(void){
  GPIO_PinModeSet (gpioPortA,7,gpioModePushPull,1);
  GPIO_PinModeSet (gpioPortC,1,gpioModePushPull,1);
  GPIO_PinModeSet (gpioPortC,3,gpioModePushPull,0);
}
