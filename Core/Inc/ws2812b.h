/*
 * ws2812b.h
 *
 *  Created on: Dec 13, 2024
 *      Author: bhagy
 */

#ifndef INC_WS2812B_H_
#define INC_WS2812B_H_



//The Timer2 is configured at 80MHZ


#define WS2812B_TH_0 32 		// Duty cycle for the LOW mode (0.4us)
#define WS2812B_TH_1 64 		// Duty cycle for the HIGH mode (0.8us)
#define WS2812B_COUNT 2 // Number of WS2812b LEDs




//create a struct to represent an LED
//Each LED has 3 pixels i.e. R, G and B. Each Pixel is 8 bits
typedef struct{

	uint8_t r;
	uint8_t g;
	uint8_t b;
}ws2812b;





void set_color(ws2812b* led_array);




#endif /* INC_WS2812B_H_ */
