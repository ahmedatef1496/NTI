/*
 * SPI_config.h
 *
 * Created: 10/30/2023 9:49:48 AM
 *  Author: Dell
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*			SPI	MODE			*/
#define		SPI_SLAVE				0	
#define		SPI_MASTER				1

#define		SPI_MODE		SPI_MASTER
/*								*/

/*		SPI Clock Polarity		*/
#define		SPI_CLK_POL_RISING		0
#define		SPI_CLK_POL_FALLING		1

#define		SPI_CLK_POL		SPI_CLK_POL_RISING
/*								*/

/*		 SPI Clock phase		*/
#define		SPI_CLK_PH_SAM_SET		0
#define		SPI_CLK_PH_SET_SAM		1

#define		SPI_CLK_PH		SPI_CLK_PH_SET_SAM
/*								*/

/*		 SPI Data Order		*/
#define		SPI_DATA_MSB			0
#define		SPI_DATA_LSB			1

#define		SPI_DATA_ORDER		SPI_DATA_MSB
/*								*/

/*		 SPI Clock 2X		*/
#define		SPI_2X_DISABLE			0
#define		SPI_2X_ENABLE			1

#define		SPI_DOUBLE_SPEED		SPI_2X_DISABLE
/*								*/

/*			SPI	Prescaler		*/

#if SPI_DOUBLE_SPEED == SPI_2X_DISABLE	// SPI2x Disable Clock.

#define		SPI_FREQ_4				0
#define		SPI_FREQ_16				1
#define		SPI_FREQ_64				2
#define		SPI_FREQ_128			3

#else  // SPI2x Enable Clock.

#define		SPI_FREQ_2				4
#define		SPI_FREQ_8				5
#define		SPI_FREQ_32				6
#define		SPI_FREQ_64				7

#endif

#define		SPI_FREQ		SPI_FREQ_4
/*								*/

#endif /* SPI_CONFIG_H_ */