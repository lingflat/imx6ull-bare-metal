
.global _start  				/* 全局标号 */

/*
 * 描述：	_start函数，首先是中断向量表的创建
 * 参考文档:ARM Cortex-A(armV7)编程手册V4.0.pdf P42，3 ARM Processor Modes and Registers（ARM处理器模型和寄存器）
 * 		 	ARM Cortex-A(armV7)编程手册V4.0.pdf P165 11.1.1 Exception priorities(异常)
 */
_start:
	ldr pc, =Reset_Handler		/* 复位中断 					*/	
	ldr pc, = .
	ldr pc, = .
	ldr pc, = .
	ldr pc, = .
	ldr	pc, = .
	ldr pc, = .		
	ldr pc, = .

/* 复位中断 */	
Reset_Handler:

	cpsid i	 	/* 关闭全局中断 */

	/* 设置栈指针，
	 * 注意：IMX6UL的堆栈是向下增长的！
	 * 堆栈指针地址一定要是4字节地址对齐的！！！
	 * DDR范围:0X80000000~0X9FFFFFFF
	 */
	
	ldr sp, =0X80200000	/* 设置栈首地址为0X80200000,大小为2MB */


	b main				/* 跳转到main函数 			 	*/


