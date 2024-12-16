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

#define WS2812B_TH_0 32 		// Duty cycle for the LOW mode (0.4us)
#define WS2812B_TH_1 64 		// Duty cycle for the HIGH mode (0.8us)
#define WS2812B_COUNT 1 		// Number of WS2812b LEDs
#define WS2812B_NUM_BITS (3*8*WS2812B_COUNT) // Total number of bits in the LED array
//#define WS2812B_TIMER TIM3
#define WS2812B_TIMER_CHANNEL TIM_CHANNEL_2


//create a struct to represent an LED
//Each LED has 3 pixels i.e. R, G and B. Each Pixel is 8 bits
typedef struct{

	unsigned char r;
	unsigned char g;
	unsigned char b;
}ws2812b;




//This function does bitbanging to toggle LEDs
void set_ws2812b_color_bitbanging(ws2812b* led_array, unsigned int * delay_array);

//void update_ws2812b(unsigned int * delay_array);




#endif /* INC_WS2812B_H_ */
