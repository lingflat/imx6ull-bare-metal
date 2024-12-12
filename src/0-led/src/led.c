#include "led.h"

/*
 * 初始化LED对应的GPIO
 */
void led_init(void)
{
	/* 初始化IO复用 */
	IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0); /* 复用为GPIO1_IO03 */

	/* 配置GPIO1_IO03的IO属性
	 *bit 16:0 HYS关闭
	 *bit [15:14]: 00 默认下拉
	 *bit [13]: 0 kepper功能
	 *bit [12]: 1 pull/keeper使能
	 *bit [11]: 0 关闭开路输出
	 *bit [7:6]: 10 速度100Mhz
	 *bit [5:3]: 110 R0/6驱动能力
	 *bit [0]: 0 低转换率
	 */
	IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0X10B0);

	/* 配置GPIO1_IO03为输出, 板子上有4个led，在此只初始化1个*/
	GPIO1->GDIR |= (1 << 3);

	/* 设置GPIO1_IO03输出低电平，打开对应引脚LED*/
	GPIO1->DR &= ~(1 << 3);
}

/*
 * LED控制函数，控制LED打开还是关闭
 * 参数led，暂时无用
 */
void led_switch(int led, int status)
{
	if (status == ON)
		GPIO1->DR &= ~(1 << 3); /* 打开led */
	else if (status == OFF)
		GPIO1->DR |= (1 << 3); /* 关闭led */
}
