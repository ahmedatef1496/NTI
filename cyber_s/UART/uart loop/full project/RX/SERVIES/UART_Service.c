/*
 * UART_Service.c
 *
 * Created: 6/9/2023 9:53:07 AM
 *  Author: atef
 */ 
#include "UART_Service.h"

void UART_SendString(u8*pu8str)
{
	u8 i;
	for (i=0;pu8str[i];i++)
	{
		UART_SendByte(pu8str[i]);
	}
	
}
void UART_SendNumber(u32 u32num)
 {
// 	UART_SendByte((u8)u32num);
// 	UART_SendByte((u8)(u32num>>8));
// 	UART_SendByte((u8)(u32num>>16));
// 	UART_SendByte((u8)(u32num>>24));
	
	u8*p=&u32num;
	UART_SendByte(p[0]);
	UART_SendByte(p[1]);
	UART_SendByte(p[2]);
	UART_SendByte(p[3]);
	
}
void UART_ReceiveString(u8*pu8str)
{
	u8 i=0;
	
	UART_RecieveByte(&pu8str[i]);
	for(;pu8str[i]!=13;)
	{
		i++;
		UART_RecieveByte(&pu8str[i]);
	}
	pu8str[i]=0;
	
}
void UART_RecieveNumber(u32 *pu32num)
{
	
	u8 b0,b1,b2,b3;
	UART_RecieveByte(&b0);
	UART_RecieveByte(&b1);
	UART_RecieveByte(&b2);
	UART_RecieveByte(&b3);
	
	*pu32num=(u32)b0|((u32)b1<<8)|((u32)b2<<16)|((u32)b3<<24);
	
	
	
	
	UART_RecieveByte(pu32num[0]);
	UART_RecieveByte(pu32num[1]);
	UART_RecieveByte(pu32num[2]);
	UART_RecieveByte(pu32num[3]);
	

	
}




















u8 endian_check(void)
{
	u32 num=1;
	u8*p=&num;
	if(*p==1)
	{
		return 1; //l
	}
	else
	{
		return 0; //b
	}
}

u32 endian_convert(u32 num)
{
	u8*p=&num;
	u8 temp;
	temp=p[0];
	p[0]=p[3];
	p[3]=temp;
	temp=p[1];
	p[1]=p[2];
	p[2]=temp;
	
	num=(num>>24)|(num<<24)|((num>>8)&0x0000ff00)|((num<<8)&0x00ff0000);
	return num;
	
}

u16 endian_convert16(u16 num)
{
	num=num>>8|num<<8;
	return num;
	
}


void UART_SendStringCheckSum(u8*str)
{
	u8 i;
	u16 sum=0;
	u8 len;
	for (i=0;str[i];i++)
	{
		sum=sum+str[i];
	}
	len=i;
	UART_SendByte(len);
	for (i=0;str[i];i++)
	{
		UART_SendByte(str[i]);
	}
	UART_SendByte((u8)sum);
	UART_SendByte((u8)(sum>>8));
}


u8 UART_ReceiveStringCheckSum(u8*str)
{
	u8 len,i,b1,b0;
	u16 sumCalc=0,sumRec;
	UART_RecieveByte(&len);
	for (i=0;i<len;i++)
	{
		UART_RecieveByte(&str[i]);
		sumCalc+=str[i];
	}
	UART_RecieveByte(&b0);
	UART_RecieveByte(&b1);
	/**************************/
	sumRec=(u16)b0|((u16)b1<<8);
	LCD_SetCursor(0,3);
	LCD_WriteNumber(len);
	LCD_WriteChar('-');
	LCD_WriteNumber(sumRec);
	LCD_WriteChar('-');
	LCD_WriteNumber(sumCalc);
	sumCalc++;
	/*********************************/
	if (sumRec==sumCalc)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	
}