#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "imx6ul.h"

void led_init(void);
void led_switch(int led, int status);

#endif

