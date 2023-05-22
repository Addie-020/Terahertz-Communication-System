/**
  ******************************************************************************
  * @author  WuShihong
  * @version V1.0
  * @date    2016-03-27
  * @brief   
  ******************************************************************************
  * @attention
  *
  * 成都亿佰特电子科技有限公司    :http://www.cdebyte.com
  * 官方淘宝直营 :http://yhmcu.taobao.com
  * 阿里巴巴:http://http://shop1399568656388.1688.com
  ******************************************************************************
  */ 
#include <at89x52.h>
#define uchar unsigned char
#define uint unsigned int

sbit K1 = P3^2;//设置P3.2口为按键端口
sbit LED = P2^7;//设置P2.7口为按键端口

uchar Error;	  //验证标志

uchar code table[] = "Ebyte";
uchar table1[] = "01234";


void delay (uint time)
{
	uint i;
	uint j;
	for (i=0; i<time; i++)
		for (j=0; j<110; j++);
}

void inital (void)
{
	LED = 1;//默认熄灭
	SM0 = 0;
	SM1 = 1;//工作方式1
	//SMOD = 0;//波特率不加倍(默认)
	REN = 1;//允许接受
	TMOD = 0X20;//T1工作于方式2：自动重装初值
	TH1 = 0XFD;
	TL1 = 0XFD;	//此初值波特率为：9600bps
	TR1 = 1;	//定时器是用来作为波特率的发生器
//	EA = 1;
//	ES = 1;	
}

void Check_Data (void)
{
	uchar i;
	
	for (i=0;i<6;i++)
	{
		if(table1[i]==table[i])
			Error = 0;
		else
		{
			Error = 1;
			break;	
		}
	}	
}

void Send_and_Sin_Data (void)
{
	uchar i;
	for (i=0;i<6;i++)
	{
		SBUF = table[i];
		while (TI == 0);//等待发送结束
		TI = 0;
		while (RI == 0);//发送和接受同步进行，发送结束后，等待接受结束
		RI = 0;
		table1[i] = SBUF;//接受端
	}
}

void main ()
{
	uchar i;

	inital ();
	while (1)
	{
		for (i=0;i<6;i++)
			table1[i] = i;//数组清空
	
		if(K1 == 0)
		{
			delay (10);
			if(K1 == 0)
			{
				Send_and_Sin_Data ();//发送并接受数据
				Check_Data ();//验证接受的数据
				if (Error == 0)//判断接受的正确性
				{
					LED = 0;		//亮
					delay (50);
					LED = 1;		//灭
				}
			}
		}
	}
}