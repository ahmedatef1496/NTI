/*
 * utils.h
 *
 *  Created on: Nov 1, 2023
 *      Author: atef
 */

#ifndef UTILS_H_
#define UTILS_H_

#define  READ_BIT(reg,bit)       ((reg>>bit)&1)     //(reg &(1<<bit))
#define  SET_BIT(reg,bit)        (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)        (reg=reg&~(1<<bit))
#define  TOGGLE_BIT(reg,bit)     (reg=reg^(1<<bit))
#define  GET_BIT(reg,bit)       ((reg>>bit)&1)

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))

#define _PORT_MODE   1
#define _PIN_MODE    0

/* _4_BIT OR _8_BIT*/

#define  GPIO_MODE   _PINT_MODE

#endif /* UTILS_H_ */
