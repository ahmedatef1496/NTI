

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define  COLS    4
#define  ROWS    4


#ifdef KEYPAD_C

const   u8 KeysArray[ROWS][COLS]={  {'C','1','4','7'},
							        {'0','2','5','8'},
							        {'=','3','6','9'},
							        {'+','-','*','/'} };
const   u8 KeysArrayNTI[ROWS+1][COLS]=  {{'c','1','4','7'},
							             {'x','x','x','x'},
										 {'0','2','5','8'},
							             {'=','3','6','9'},
							             {'+','-','*','/'} };
#endif									  

#define  NO_KEY   'T'
						
#define  FIRST_OUTPUT  PIND3
#define  FIRST_INPUT   PINC2
						






#endif /* KEYPAD_CFG_H_ */