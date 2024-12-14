/*
 * ws2812b.c
 *
 *  Created on: Dec 14, 2024
 *      Author: bhagy
 */



#include "ws2812b.h"




//create a buffer to store all delays for each bit
//uint32_t delay_array[3*8*len]; //Each pixel is 8bits. Each LED has 3 pixels and we have len number of LEDs
void set_ws2812b_color(ws2812b* led_array, uint32_t* delay_array){


	//Get the number of leds
	uint8_t len = sizeof(led_array)/sizeof(led_array[0]);




	//initialize the delay counter to 0
	int dn = 0;

	//iterate over each LED
	for(int i = 0; i < len; i++){

		//iterate over each pixel. Each pixel is of 8 bits. Fill values MSB first

		//start with red
		for(int j = 7; j >=0 ; j--){

			//check for each bit if it is a high or a low

			if((led_array[i]->r[j] >> j) && 0x01 == 1){

				//set the high duty cycle THI_1
				delay_array[dn] = WS2812B_TH_1;
				dn++;

			}

			else{

				//set the low duty cycle THI_0
				delay_array[dn] = WS2812B_TH_0;
				dn++;

			}

		}


		//then with green
		for(int j = 7; j >=0 ; j--){

			//check for each bit if it is a high or a low

			if((led_array[i]->g[j] >> j) && 0x01 == 1){

				//set the high duty cycle THI_1
				delay_array[dn] = WS2812B_TH_1;
				dn++;

			}

			else{

				//set the low duty cycle THI_0
				delay_array[dn] = WS2812B_TH_0;
				dn++;

			}

		}

		//then with blue
		for(int j = 7; j >=0 ; j--){

			//check for each bit if it is a high or a low

			if((led_array[i]->b[j] >> j) && 0x01 == 1){

				//set the high duty cycle THI_1
				delay_array[dn] = WS2812B_TH_1;
				dn++;

			}

			else{

				//set the low duty cycle THI_0
				delay_array[dn] = WS2812B_TH_0;
				dn++;

			}

		}

	}

}




//TODO: start the timer
//TODO: wait for the timer counter to reach the delay[i]
void update_ws2812b(uint32_t* delay_array){



	//method1 : update the ccr register
	//start the counter

	//for each bit:
		//TIM->CCR = delay_array[i] //duty cycle

	//method2: increment the cnt until delay and then toggle the GPIO pin


}



