
#include "delay.h"
#include "led.h"

int main(void)
{
	static unsigned char state = 0;
	
	led_init();					/* 初始化led 			*/

	while(1)			
	{	
		delay(500);
		led_switch(LED0, state); 	/* 定时器周期到，反转LED */
		state = !state;
	}

	return 0;
}
