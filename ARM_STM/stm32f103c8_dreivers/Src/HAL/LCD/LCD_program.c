#include "../../../Inc/HAL/LCD/LCD_interface.h"
#include "../../../Inc/HAL/LCD/LCD_config.h"
#include "../../../Inc/HAL/LCD/LCD_private.h"



static void _delay_ms(u16 Copy_u16MSec){
    for (int i = 0; i <= Copy_u16MSec; i++)
    {
        for (int j = 0; j <= 600; j++)
        {
            asm("NOP");
        }
    }
}


#if GPIO_MODE == _PORT_MODE
#if LCD_MODE  ==_8_BIT
static void WriteIns(u8 ins)
{

	GPIO_voidSetPinValue(LCD_PORT,RS,LOW);
	GPIO_voidSetPinValue(LCD_PORT,LCD_PORT,ins);
	GPIO_voidSetPinValue(LCD_PORT,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(LCD_PORT,EN,LOW);
	_delay_ms(1);

}

static void WriteData(u8 data)
{
	GPIO_voidSetPinValue(LCD_PORT,RS,HIGH);
	GPIO_voidSetPinValue(LCD_PORT,LCD_PORT,data);
	GPIO_voidSetPinValue(LCD_PORT,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(LCD_PORT,EN,LOW);
	_delay_ms(1);
}



void LCD_Init(void)
{
	_delay_ms(50);

	WriteIns(0x38);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);// increment DDRAM address, no shift
	//CLR_BIT(PORTA,2); //RW

}

#elif LCD_MODE ==_4_BIT
static void WriteIns(u8 ins)
{


	GPIO_voidSetPinValue(LCD_PORT,RS,LOW);
	GPIO_voidSetPinValue(LCD_PORT,D7,READ_BIT(ins,7));
	GPIO_voidSetPinValue(LCD_PORT,D6,READ_BIT(ins,6));
	GPIO_voidSetPinValue(LCD_PORT,D5,READ_BIT(ins,5));
	GPIO_voidSetPinValue(LCD_PORT,D4,READ_BIT(ins,4));

	GPIO_voidSetPinValue(LCD_PORT,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(LCD_PORT,EN,LOW);
	_delay_ms(1);
	GPIO_voidSetPinValue(LCD_PORT,D7,READ_BIT(ins,3));
	GPIO_voidSetPinValue(LCD_PORT,D6,READ_BIT(ins,2));
	GPIO_voidSetPinValue(LCD_PORT,D5,READ_BIT(ins,1));
	GPIO_voidSetPinValue(LCD_PORT,D4,READ_BIT(ins,0));
	GPIO_voidSetPinValue(LCD_PORT,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(LCD_PORT,EN,LOW);
	_delay_ms(1);
}

static void WriteData(u8 data)
{
	GPIO_voidSetPinValue(LCD_PORT,RS,HIGH);
	GPIO_voidSetPinValue(LCD_PORT,D7,READ_BIT(data,7));
	GPIO_voidSetPinValue(LCD_PORT,D6,READ_BIT(data,6));
	GPIO_voidSetPinValue(LCD_PORT,D5,READ_BIT(data,5));
	GPIO_voidSetPinValue(LCD_PORT,D4,READ_BIT(data,4));

	GPIO_voidSetPinValue(LCD_PORT,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(LCD_PORT,EN,LOW);
	_delay_ms(1);
	GPIO_voidSetPinValue(LCD_PORT,D7,READ_BIT(data,3));
	GPIO_voidSetPinValue(LCD_PORT,D6,READ_BIT(data,2));
	GPIO_voidSetPinValue(LCD_PORT,D5,READ_BIT(data,1));
	GPIO_voidSetPinValue(LCD_PORT,D4,READ_BIT(data,0));
	GPIO_voidSetPinValue(LCD_PORT,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(LCD_PORT,EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x02);
	WriteIns(0x28);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);// increment DDRAM address, no shift

}

void LCD_PinsInit ()
{
	   GPIO_voidSetPinDirection(LCD_PORT,D4, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(LCD_PORT,D5, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(LCD_PORT,D6, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(LCD_PORT,D7, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(LCD_PORT,EN, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(LCD_PORT,RS, OUTPUT_SPEED_10MHZ_PP);

}
#endif

#elif GPIO_MODE==_PIN_MODE

#if LCD_MODE==_8_BIT
static void WriteIns(u8 ins)
{

	GPIO_voidSetPinValue(RS,LOW);
	GPIO_voidSetPinValue(LCD_PORT,ins);
	GPIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);

}

static void WriteData(u8 data)
{
	GPIO_voidSetPinValue(RS,HIGH);
	GPIO_voidSetPinValue(LCD_PORT,data);
	GPIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
}



void LCD_Init(void)
{
	_delay_ms(50);

	WriteIns(0x38);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);// increment DDRAM address, no shift
	//CLR_BIT(PORTA,2); //RW

}

#elif LCD_MODE ==_4_BIT
static void WriteIns(u8 ins)
{


	GPIO_voidSetPinValue(RS,LOW);
	GPIO_voidSetPinValue(D7,READ_BIT(ins,7));
	GPIO_voidSetPinValue(D6,READ_BIT(ins,6));
	GPIO_voidSetPinValue(D5,READ_BIT(ins,5));
	GPIO_voidSetPinValue(D4,READ_BIT(ins,4));

	GPIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
	GPIO_voidSetPinValue(D7,READ_BIT(ins,3));
	GPIO_voidSetPinValue(D6,READ_BIT(ins,2));
	GPIO_voidSetPinValue(D5,READ_BIT(ins,1));
	GPIO_voidSetPinValue(D4,READ_BIT(ins,0));
	GPIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
}

static void WriteData(u8 data)
{
	GPIO_voidSetPinValue(RS,HIGH);
	GPIO_voidSetPinValue(D7,READ_BIT(data,7));
	GPIO_voidSetPinValue(D6,READ_BIT(data,6));
	GPIO_voidSetPinValue(D5,READ_BIT(data,5));
	GPIO_voidSetPinValue(D4,READ_BIT(data,4));

	GPIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
	GPIO_voidSetPinValue(D7,READ_BIT(data,3));
	GPIO_voidSetPinValue(D6,READ_BIT(data,2));
	GPIO_voidSetPinValue(D5,READ_BIT(data,1));
	GPIO_voidSetPinValue(D4,READ_BIT(data,0));
	GPIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x02);
	WriteIns(0x28);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);// increment DDRAM address, no shift

}
void LCD_PinsInit ()
{
	   GPIO_voidSetPinDirection(PINB0, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(D5, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(D6, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(D7, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(EN, OUTPUT_SPEED_10MHZ_PP);
	   GPIO_voidSetPinDirection(RS, OUTPUT_SPEED_10MHZ_PP);

}

#endif

#endif
//should be send address in ddram befor this function
void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}
void LCD_WriteString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}

}
void LCD_SetCursor(u8 line,u8 cell)
{
	if (line==0)
	{
		WriteIns(0x80|cell);
	}
	else if (line ==1)
	{
		WriteIns(0x80+0x40+cell);
	}
}
void LCD4_SetCursor(u8 line,u8 cell)
{
	if (line==0)
	{
		WriteIns(0x80+cell);
	}
	else if (line ==1)
	{
		WriteIns(0xc0+cell);
	}
		if (line==2)
	{
		WriteIns(0x94+cell);
	}
	else if (line ==3)
	{
		WriteIns(0xd4+cell);
	}
}
void LCD_Clear(void)
{
	WriteIns(CLR_INS);
	_delay_ms(1);
}


void LCD_WriteNumber(s32 num)
{
	u8 str[10],i=0,j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		num=num*(-1);
		LCD_WriteChar('-');
	}

	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for (j=i;j>0;j--)
	{
		LCD_WriteChar(str[j-1]);
	}

}


void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar(READ_BIT(num,i)+'0');
	}

}


void LCD_ClearLoc(u8 line ,u8 cell,u8 num)
{
	u8 i;
	LCD_SetCursor(line,cell);
	for (i=0;i<num;i++)
	{
		LCD_WriteChar(' ');
	}

}

void LCD4_ClearLoc(u8 line ,u8 cell,u8 num)
{
	u8 i;
	LCD4_SetCursor(line,cell);
	for (i=0;i<num;i++)
	{
		LCD_WriteChar(' ');
	}

}

void LCD_WriteNumber_3D(u16 num)
{
	//LCD_WriteChar(((num%100000)/10000)+'0');
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}


void LCD_CustomChar(u8 loc,u8*pattern)
{
	WriteIns(0x40+loc*8);
	for(u8 i=0;i<8;i++)
	{
		WriteData(pattern[i]);
	}
	WriteIns(0x80);
}



   void LCD_DisplayFloat(f32 f32_a_number)
   {
	   u8 arr_l_NumString[12];
	   u8 u8_l_NumIterator = 3, u8_l_StrLen, u8_l_tempVar, u8_l_decimal;
	   u8 u32_l_integer;

	   /* Get the integer part */
	   u32_l_integer = (u16)f32_a_number;

	   /* Get the first two decimal places */
	   u8_l_decimal = (u16)((f32_a_number - u32_l_integer) * 100);

	   /* Get decimal digits as characters */
	   arr_l_NumString[0] = u8_l_decimal % 10 + '0';
	   arr_l_NumString[1] = u8_l_decimal / 10 + '0';

	   arr_l_NumString[2] = '.';

	   /* Get integer digits as characters */
	   while (u32_l_integer > 0)
	   {
		   arr_l_NumString[u8_l_NumIterator] = (u32_l_integer % 10) + '0';
		   u32_l_integer /= 10;
		   u8_l_NumIterator++;
	   }

	   /* Terminate String */
	   arr_l_NumString[u8_l_NumIterator] = '\0';

	   u8_l_StrLen = u8_l_NumIterator;

	   /* Reverse String */
	   for (u8_l_NumIterator = 0; u8_l_NumIterator< u8_l_StrLen/2; u8_l_NumIterator++)
	   {
		   u8_l_tempVar = arr_l_NumString[u8_l_NumIterator];
		   arr_l_NumString[u8_l_NumIterator] = arr_l_NumString[u8_l_StrLen - u8_l_NumIterator - 1];
		   arr_l_NumString[u8_l_StrLen - u8_l_NumIterator - 1] = u8_l_tempVar;
	   }

	   /* Display Number */
	   LCD_WriteString(arr_l_NumString);
   }


