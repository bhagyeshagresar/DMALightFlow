/*
 * ws2812b.h
 *
 *  Created on: Dec 13, 2024
 *      Author: bhagy
 */

#ifndef INC_WS2812B_H_
#define INC_WS2812B_H_

#include "stm32f4xx_hal.h"

//The Timer2 is configured at 80MHZ
//extern TIM_HandleTypeDef htim3;

#define WS2812B_TH_0 32 													// Duty cycle for the LOW mode (0.4us)
#define WS2812B_TH_1 64 													// Duty cycle for the HIGH mode (0.8us)
#define WS2812B_LED_COUNT 5 												// Number of WS2812b LEDs
#define WS2812B_NUM_BITS (3*8*WS2812B_LED_COUNT) 							// Total number of bits in the LED array
#define WS2812B_TIMER_CHANNEL TIM_CHANNEL_2									// Define the Timer Channel
#define WS2812B_RESET_TIME 80   											// Reset for 50us
#define WS2812B_DMA_BUFF_LEN (WS2812B_NUM_BITS + WS2812B_RESET_TIME) 		// Define the Buffer Length of the DMA array. It needs to include the reset time

//create a struct to represent an LED
//Each LED has 3 pixels i.e. R, G and B. Each Pixel is 8 bits
typedef struct{

	unsigned char r;
	unsigned char g;
	unsigned char b;
}ws2812b;


//Define the variables
extern uint16_t WS2812B_DMA_BUFF[WS2812B_DMA_BUFF_LEN];





//This function does bitbanging to toggle LEDs
void set_ws2812b_color_bitbanging(ws2812b* led_array, unsigned int * delay_array);




//Function to initialize the WS2812B buffer
void ws2812b_init();


//Function to fill the dma buffer with duty cycle values
void ws2812b_update_dma_buff(ws2812b* led_array);






#endif /* INC_WS2812B_H_ */
