/*
 * app.c
 *
 * Created: 10/20/2023 7:10:26 PM
 *  Author: atef
 */ 
#include "app.h"

/*--------------------------------------------------*/
#define CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS		7

#define ASCII_TO_INT(ASCII)	(u32)(ASCII-48)

u32 CALC_OperandsArr[CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS+1] = {0} ;

u8 CALC_ArithOperatorssArr[CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS] = {'+','+','+','+','+','+','+'};

/* Counter to use it in the operands array */
u8 CALC_OperandsCounter = 0 ;

/* Counter to use it in the operators array */
u8 CALC_ArithOpCounter = 0;
/* array to store the results*/
u32 result_storage [2]={0};
u8 results_counter=0;

u8 counter , counter2 ;					/* General purpose Counters */

u8 result_flag = 0 ;
u32 result;

/*--------------------------------------------------*/

void calculator ()
{
	u8 key ;
	key =KEYPAD_GetKeyNTI();

	if (key!='T')
	{

		LCD_WriteChar(key);
		if (result_flag==0)
		{

			switch (key)
			{
				case '+':
				case '-':
				case '*':
				case '/':

				CALC_ArithOperatorssArr[CALC_ArithOpCounter] = key;
				CALC_ArithOpCounter++;
				CALC_OperandsCounter++;
				break;

				case '=':
				result_flag = 1;

				/*Calculating the multiplication and shifting all operands after it to the left */
				for(counter = 0 ; counter < CALC_ArithOpCounter ; counter++)
				{
					if(CALC_ArithOperatorssArr[counter] == '*')
					{

						CALC_OperandsArr[counter] *= CALC_OperandsArr[counter+1];

						for(counter2 = counter ; counter2 < CALC_ArithOpCounter-1 ; counter2++)
						{
							CALC_ArithOperatorssArr[counter2] = CALC_ArithOperatorssArr[counter2 + 1];
							CALC_OperandsArr[counter2 + 1] = CALC_OperandsArr[counter2 + 2];
						}

						CALC_ArithOpCounter--;
						counter--;
					}
					/*Calculating the division and shifting all operands after it to the left */
					else if(CALC_ArithOperatorssArr[counter] == '/')
					{

						CALC_OperandsArr[counter] = CALC_OperandsArr[counter] / CALC_OperandsArr[counter+1];

						for(counter2 = counter ; counter2 < CALC_ArithOpCounter-1 ; counter2++)
						{
							CALC_ArithOperatorssArr[counter2] = CALC_ArithOperatorssArr[counter2 + 1];
							CALC_OperandsArr[counter2 + 1] = CALC_OperandsArr[counter2 + 2];
						}

						CALC_ArithOpCounter--;
						counter--;

					}
				}
				result = CALC_OperandsArr[0];	/* 1st operand is initially the result */

				/* completing the calculations of the result */
				for(counter = 0 ; counter < CALC_ArithOpCounter ; counter++)
				{

					if(CALC_ArithOperatorssArr[counter] == '+')
					CALC_OperandsArr[0] += CALC_OperandsArr[counter+1];

					else
					CALC_OperandsArr[0] -= CALC_OperandsArr[counter+1];
				}

				result = CALC_OperandsArr[0];

				/* Displaying the result */
				//result_storage[results_counter]=result;
				//results_counter++;
				LCD4_SetCursor(3,0);
				LCD_WriteNumber(result);

				break;

				case 'c':

				/* Resting the calculator when the user press ON/C */
				LCD4_SetCursor(0,0);
				LCD_Clear();
				CALC_ArithOpCounter = 0;
				CALC_OperandsCounter = 0;
				result_flag = 0;
				for(counter = 0 ; counter < CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS ; counter++)
				{

					CALC_ArithOperatorssArr[counter] = '+';
				}
				for(counter = 0 ; counter < CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS+1 ; counter++)
				{
					CALC_OperandsArr[counter] = 0;
				}
				break;


				default :

				CALC_OperandsArr[CALC_OperandsCounter] =				\
				CALC_OperandsArr[CALC_OperandsCounter]*10				\
				+ ASCII_TO_INT(key);
				break;



			}
		}
		else                                // (result_flag==1)
		{
			switch(key)
			{

				case '+':
				case '-':
				case '*':
				case '/':

				LCD_Clear();
				LCD4_SetCursor(0,0);
				LCD_WriteNumber(result);
				LCD_WriteChar(key);

				for(counter = 0 ; counter < CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS ; counter++)
				{
					CALC_ArithOperatorssArr[counter] = '+';
				}
				for(counter = 0 ; counter < CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS+1 ; counter++)
				{
					CALC_OperandsArr[counter] = 0;
				}

				CALC_OperandsArr[0] = result;

				CALC_ArithOperatorssArr[0] = key;

				CALC_OperandsCounter = 1;
				CALC_ArithOpCounter = 1;
				results_counter++;
				result_flag = 0;
				break;

				case 'c':

				/* Resting the calculator when the user press ON/C */
				LCD4_SetCursor(0,0);
				LCD_Clear();
				CALC_ArithOpCounter = 0;
				CALC_OperandsCounter = 0;
				result_flag = 0;
				for(counter = 0 ; counter < CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS ; counter++)
				{

					CALC_ArithOperatorssArr[counter] = '+';
				}
				for(counter = 0 ; counter < CALCULATOR_MAX_NO_ARITHMATIC_OPERATORS+1 ; counter++)
				{
					CALC_OperandsArr[counter] = 0;
				}
				break;
			}
		}
	}
}
