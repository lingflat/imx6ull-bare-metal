#include "delay.h"

// 现在的delay就是做一些无用功

void delay_short(volatile unsigned int n)
{
	while (n--)
	{
	}
}

void delay(volatile unsigned int n)
{
	while (n--)
	{
		delay_short(0x7ff);
	}
}
