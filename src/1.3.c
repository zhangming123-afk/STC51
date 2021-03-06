/****************************方法二************************************
* 文件名：闪烁灯.c
* 描述  : 点亮P0口的多个LED灯
          该程序是单片机学习中最简单最基础的，
			    通过程序了解如何控制端口的高低电平
			    通过对P1口和P2口的直接赋值，来点亮LED	
			    LED1、LED3、LED5、LED7点亮。
			    LED2、LED4、LED6、LED8不亮。	
			    相比前面一个代码，这个代码显得简洁的多。
			    如果是多为IO进行控制，建议大家直接对P1--P3进行操作。
***********************************************************************/
#include
#define uchar unsigned char   //这里用"uchar"代替"unsigned char"，"uchar"用来定义无符号字符型数。
#define uint  unsigned int	  //"uint"用来定义无符号整型数。									  

/********************************************************************
* 名称 : Main()
* 功能 : 实现灯的闪烁
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Main(void)
{
	P0 = 0xaa;    //相当于二进制   0B 1010 1010
	while(1)
	{
	}
}
