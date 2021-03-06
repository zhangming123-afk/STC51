/***********************************方法一**************************
* 描述: 本实验，让8个LED不停显示依照规律轮流显示。
			  首先，8个LED分别两次间隔显示。然后高4位显示和低4位显示。
			  最后间隔全亮、全灭两次。
***********************************************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned int
/********************************************************************
* 名称 : Delay()
* 功能 : 延时,延时时间为 10ms * del
* 输入 : del
* 输出 : 无
***********************************************************************/
void Delay(uint del)
{
	uint i,j;
	for(i=0; i<del; i++)
	for(j=0; j<1827; j++)    
	;
}
/********************************************************************
* 名称 : Main()
* 功能 : 实现灯的闪烁
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Main(void)
{
	while(1)
	{
		/*下面四行用于控制LED每隔一个亮*/
		P0 = 0xaa;   
		Delay(50);
		P0 = 0x55;  
		Delay(50);

		/*下面四行用于控制LED每隔一个亮*/
		P0 = 0xcc;
		Delay(50);
		P0 = 0x33;
		Delay(50);

		/*下面四行用于控制LED 高四位 或者 低四位亮*/
		P0 = 0x0f;
		Delay(50);
		P0 = 0xf0;
		Delay(50);

		/*下面八行用于控制LED的两次全亮 全灭*/
		P0 = 0x00;
		Delay(25);
		P0 = 0xff;
		Delay(25);
		P0 = 0x00;
		Delay(25);
		P0 = 0xff;
		Delay(25);

		Delay(200);  //延时两秒
	}
}
