/**
  ******************************************************************************
  * @author  WuShihong
  * @version V1.0
  * @date    2016-03-27
  * @brief   
  ******************************************************************************
  * @attention
  *
  * �ɶ��ڰ��ص��ӿƼ����޹�˾    :http://www.cdebyte.com
  * �ٷ��Ա�ֱӪ :http://yhmcu.taobao.com
  * ����Ͱ�:http://http://shop1399568656388.1688.com
  ******************************************************************************
  */ 
#include <at89x52.h>
#define uchar unsigned char
#define uint unsigned int

sbit K1 = P3^2;//����P3.2��Ϊ�����˿�
sbit LED = P2^7;//����P2.7��Ϊ�����˿�

uchar Error;	  //��֤��־

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
	LED = 1;//Ĭ��Ϩ��
	SM0 = 0;
	SM1 = 1;//������ʽ1
	//SMOD = 0;//�����ʲ��ӱ�(Ĭ��)
	REN = 1;//�������
	TMOD = 0X20;//T1�����ڷ�ʽ2���Զ���װ��ֵ
	TH1 = 0XFD;
	TL1 = 0XFD;	//�˳�ֵ������Ϊ��9600bps
	TR1 = 1;	//��ʱ����������Ϊ�����ʵķ�����
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
		while (TI == 0);//�ȴ����ͽ���
		TI = 0;
		while (RI == 0);//���ͺͽ���ͬ�����У����ͽ����󣬵ȴ����ܽ���
		RI = 0;
		table1[i] = SBUF;//���ܶ�
	}
}

void main ()
{
	uchar i;

	inital ();
	while (1)
	{
		for (i=0;i<6;i++)
			table1[i] = i;//�������
	
		if(K1 == 0)
		{
			delay (10);
			if(K1 == 0)
			{
				Send_and_Sin_Data ();//���Ͳ���������
				Check_Data ();//��֤���ܵ�����
				if (Error == 0)//�жϽ��ܵ���ȷ��
				{
					LED = 0;		//��
					delay (50);
					LED = 1;		//��
				}
			}
		}
	}
}