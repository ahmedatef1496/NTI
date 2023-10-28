/*
 * app.c
 *
 * Created: 10/20/2023 7:10:26 PM
 *  Author: atef
 */ 
#include "app.h"
/*--------------------------------------------------*/

u8 person[] = {
	0x04,
	0x0A,
	0x04,
	0x1F,
	0x04,
	0x0A,
	0x0A,
	0x11
};

char ball[] = {
	0x00,
	0x0E,
	0x1F,
	0x1F,
	0x1F,
	0x0E,
	0x00,
	0x00
};
u8 location1 =0x01;
u8 location2 =0x02;

	u8 pA_X = 2, pA_Y = 0,pB_X = 2,pB_Y = 19,b_X = 0,b_Y =10;
	u8 input ;
	u8 bflag=0;
void pong_init()
{

	pA_X = 0;
	pA_Y = 0;
	pB_X = 0;
	pB_Y = 19;
	b_X = 0;
	b_Y =10;


	LCD_CustomChar(location1,person);
	LCD4_SetCursor(pA_X,pA_Y);
	LCD_WriteChar(location1);
	LCD_CustomChar(location1,person);
	LCD4_SetCursor(pB_X,pB_Y);
	LCD_WriteChar(location1);
	LCD_CustomChar(location2,ball);
	LCD4_SetCursor(b_X,b_Y);
	LCD_WriteChar(location2);
}

u8 ball_loc=0;    //    0       1
                 //    2       3
u8 pA_loc=0;      //0
//1

u8 pB_loc=1;     //0
//1

u8 playing=0;   //0 at line 1 at digonal
void movef1t2()
{
				for(char i=1;i<18;i++)
				{
					LCD4_SetCursor(0,i);
					LCD_WriteChar(location2);
					_delay_ms(100);
					LCD4_ClearLoc(0,i,1);
					
				}	
				ball_loc=1;
}

void movef2t1()
{
			for(char i=18;i>1;i--)
			{
				LCD4_SetCursor(0,i);
				LCD_WriteChar(location2);
				_delay_ms(100);
				LCD4_ClearLoc(0,i,1);
			} 
			ball_loc=0;
}

void movef1t2d()
{
	for(char i=1;i<18;i++)
	{
		LCD4_SetCursor(3,i);
		LCD_WriteChar(location2);
		_delay_ms(100);
		LCD4_ClearLoc(3,i,1);
		
	}
	ball_loc=3;
}

void movef2t1d()
{
	for(char i=18;i>1;i--)
	{
		LCD4_SetCursor(3,i);
		LCD_WriteChar(location2);
		_delay_ms(100);
		LCD4_ClearLoc(3,i,1);
	}
	ball_loc=2;
}
void movedf1t2()
{
	LCD4_SetCursor(1,6);
	LCD_WriteChar(location2);
	_delay_ms(200);
	LCD4_ClearLoc(1,6,1);
	
	LCD4_SetCursor(2,13);
	LCD_WriteChar(location2);
	_delay_ms(200);
	LCD4_ClearLoc(2,13,1);
	
	
	LCD4_SetCursor(3,18);
	LCD_WriteChar(location2);
	_delay_ms(200);
	LCD4_ClearLoc(3,18,1);
	ball_loc=3;
}
void movedb2t1()
{
	LCD4_SetCursor(3,18);
	LCD_WriteChar(location2);
	_delay_ms(200);
	LCD4_ClearLoc(3,18,1);
	
	LCD4_SetCursor(2,13);
	LCD_WriteChar(location2);
	_delay_ms(200);
	LCD4_ClearLoc(2,13,1);
	
	LCD4_SetCursor(1,6);
	LCD_WriteChar(location2);
	_delay_ms(200);
	LCD4_ClearLoc(1,6,1);
	ball_loc=0;
}
void movedf2t1()
{
LCD4_SetCursor(1,14);
LCD_WriteChar(location2);
_delay_ms(200);
LCD4_ClearLoc(1,14,1);

LCD4_SetCursor(2,7);
LCD_WriteChar(location2);
_delay_ms(200);
LCD4_ClearLoc(2,7,1);


LCD4_SetCursor(3,1);
LCD_WriteChar(location2);
_delay_ms(200);
LCD4_ClearLoc(3,1,1);
ball_loc=2;
}
void movedb1t2()
{
LCD4_SetCursor(3,1);
LCD_WriteChar(location2);
_delay_ms(200);
LCD4_ClearLoc(3,1,1);

LCD4_SetCursor(2,7);
LCD_WriteChar(location2);
_delay_ms(200);
LCD4_ClearLoc(2,7,1);
LCD4_SetCursor(1,14);
LCD_WriteChar(location2);
_delay_ms(200);
LCD4_ClearLoc(1,14,1);

ball_loc=1;
}

void movepA1t4()
{
						LCD4_ClearLoc(0,0,1);
						_delay_ms(1);
						LCD4_SetCursor(3,0);
						LCD_WriteChar(location1);
						pA_loc=2;
	
	
}
void movepA4t1()
{
	LCD4_ClearLoc(3,0,1);
	LCD4_SetCursor(0,0);
	LCD_WriteChar(location1);	
	pA_loc=0;
	
}

void movepB1t4()
{
	LCD4_ClearLoc(0,19,1);
	LCD4_SetCursor(3,19);
	LCD_WriteChar(location1);
	pB_loc=3;
	
}
void movepB4t1()
{
	LCD4_ClearLoc(3,19,1);
	LCD4_SetCursor(0,19);
	LCD_WriteChar(location1);
	pB_loc=1;
	
}
void PongGame()
{   u8 input;

		LCD_CustomChar(location1,&person);
		LCD_CustomChar(location2,&ball);
		LCD4_SetCursor(0,0);
		LCD_WriteChar(location1);
		LCD4_SetCursor(0,19);
		LCD_WriteChar(location1);
		
				 input=KEYPAD_GetKeyNTI();
				 
  
					if (pA_loc==0)
					{
						if (ball_loc==0)
						{


							if (input=='3')
							{
								movedf1t2();
								ball_loc=3;
								pA_loc=0;
								pB_loc=0;
								playing =1;
							}

							else
							{
								movef1t2();
								ball_loc=1;
								pA_loc=0;
								pB_loc=0;
								playing =0;

							}

						}
						else if(ball_loc==1)
						{ 
							
							if (input=='1')
							{
								movedf2t1();
								ball_loc=2;
								pA_loc=0;
								pB_loc=0;
								playing =1;
							}

							else
							{
								movef2t1();
								ball_loc=0;
								pA_loc=0;
								pB_loc=0;
								playing =0;

							}
							
						}

					} 
					
					
					
					                               if (input=='6')
					                             {
						                             if (pA_loc==0)
						                             {
							                             movepA1t4();
						                             }
						                             else
						                             {
							                             movepA4t1();
						                             }
					                             }

}


void PongGame()
{  
	
	 u8 input,ball_mode=0;
      static setup=1,playflag=0;
	 LCD_CustomChar(location1,&person);
	 LCD_CustomChar(location2,&ball);
	 while(setup){
	 LCD4_SetCursor(0,0);
	 LCD_WriteChar(location1);
	 LCD4_SetCursor(0,19);
	 LCD_WriteChar(location1);
	 setup=0;
	 }
	 input=KEYPAD_GetKeyNTI();

	     if (input=='='&&ball_loc==0)
		{
			ball_mode=1;
		}	 
	 	else if (input=='3'&&ball_loc==0)
	 	{
		 	ball_mode=3;
	 	}
	 	else if (input=='3'&&ball_loc==2)
	 	{
		 	ball_mode=4;
	 	}

	 	else if (input=='='&&ball_loc==2)
	 	{
		 	ball_mode=8;
	 	}
	 	else if (input=='1'&&ball_loc==1)
	 	{
		 	ball_mode=5;
	 	}
	 	else if (input=='1'&&ball_loc==3)
	 	{
		 	ball_mode=6;
	 	}
		else if (input=='c'&&ball_loc==1)
		{
			ball_mode=2;
		}
	 	else if (input=='c'&&ball_loc==3)
	 	{
		 	ball_mode=7;
	 	}

	  if (input=='9'&& pA_loc==0)
	  {
		  movepA1t4();
	  }
	  else if (input=='9'&& pA_loc==2)
	  {
		  movepA4t1();
	  }
	   if (input=='7'&&pB_loc==1)
	  {
		  movepB1t4();
	  }
	  else if (input=='7'&&pB_loc==3)
	  {
		  movepB4t1();
	  }
		 while(ball_mode>0)
		 { 
			 
	 input=KEYPAD_GetKeyNTI();
	 
	switch (ball_mode)
	{
		case 1 :
		movef1t2();
		break;
		case 2 :
		movef2t1();
		break;
		case 3 :
		movedf1t2();
		break;
		case 4 :
		movedb1t2();
		break;
		case 5 :
		movedf2t1();
		break;
		case 6 :
		movedb2t1();
		break;
		case 7 :
		movef2t1d();
		break;
		case 8 :
		movef1t2d();
		break;
		default :
		break;
		
	} 
	


	 ball_mode=0;
	 

		 }
	
			
	
}
