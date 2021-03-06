/********************************************************************
* 文件名  ： 串行12864显示.c
* 描述    :  这个器件是选配器件，价格是50元一片。带字库，可以显示汉字。
			 该程序实现了12864以串行的方式进行通信。
             串行显示比并行显示速度慢。

***********************************************************************/
#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint  unsigned int

sbit CS=P2^5;	    //片选信号
sbit SID=P2^6;		//数据信号
sbit SCLK=P2^7;		//时钟信号 
sbit RST=P2^2;		//复位信号
sbit CH = P2^4;		//并行、串行选择信号

/********************************************************************
* 名称 : delay()
* 功能 : 延时,延时时间为 100us * t。这是通过软件延时，有一定误差。
* 输入 : t
* 输出 : 无
***********************************************************************/
void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0; i<t;  i++)
    for(j=0; j<10; j++);
}

/********************************************************************
* 名称 : sendbyte()
* 功能 : 按照液晶的串口通信协议，发送数据
* 输入 : zdata
* 输出 : 无
***********************************************************************/
void sendbyte(unsigned char zdata)
{
	unsigned int i;
	for(i=0; i<8; i++)
	{
		if((zdata << i) & 0x80)
		{
			SID = 1;
		}
		else 
		{
			SID = 0;
		}
		SCLK = 0;
		SCLK = 1;
	}
}

/********************************************************************
* 名称 : write_com()
* 功能 : 写串口指令
* 输入 : cmdcode
* 输出 : 无
***********************************************************************/
void write_com(unsigned char cmdcode)
{
	CS = 1;
	sendbyte(0xf8);
	sendbyte(cmdcode & 0xf0);
	sendbyte((cmdcode << 4) & 0xf0);
	delay(2);
}

/********************************************************************
* 名称 : write_data()
* 功能 : 写串口指令
* 输入 : cmdcode
* 输出 : 无
***********************************************************************/
void write_data(unsigned char Dispdata)
{
	CS = 1;
	sendbyte(0xfa);
	sendbyte(Dispdata & 0xf0);
	sendbyte((Dispdata << 4) & 0xf0);
	delay(2);
}

/********************************************************************
* 名称 : lcdinit()
* 功能 : 初始化函数
* 输入 : cmdcode
* 输出 : 无
***********************************************************************/
void lcdinit()
{  
	RST = 0;
	delay(100);
	RST = 1;
	delay(20000);
	write_com(0x30);
	delay(50);
	write_com(0x0c);
	delay(50);
}

/********************************************************************
* 名称 : hzkdis()
* 功能 : 显示字符串
* 输入 : *s
* 输出 : 无
***********************************************************************/
void hzkdis(unsigned char code *s)
{  
	while(*s > 0)
    { 
		write_data(*s);
		s++;
		delay(50);
    }
}

/********************************************************************
* 名称 : Test()
* 功能 : 显示子函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Test()
{  
	write_com(0x03);
	delay(50);    
	write_com(0x81);
	hzkdis("   STC-51");
	write_com(0x91);
	hzkdis("电子产品世界");
	write_com(0x89);
	hzkdis("          ");
	write_com(0x98);
	hzkdis("    EEPW");
}


/********************************************************************
* 名称 : Main()
* 功能 : 主函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Main()
{ 
	CH = 0;
	delay(1);
	lcdinit();
	delay(10);
	while(1)
	{
		Test();
		delay(5000);
	}
}
