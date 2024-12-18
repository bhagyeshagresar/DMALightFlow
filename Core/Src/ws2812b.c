/*
 * ws2812b.c
 *
 *  Created on: Dec 14, 2024
 *      Author: bhagy
 */



#include "ws2812b.h"
#include "stm32f4xx_hal.h"


uint16_t WS2812B_DMA_BUFF[WS2812B_DMA_BUFF_LEN];


//create a buffer to store all delays for each bit
//uint32_t delay_array[2*3*8*len]; //Each pixel is 8bits. Each LED has 3 pixels and we have len number of LEDs.
void set_ws2812b_color_bitbanging(ws2812b* led_array, unsigned int* delay_array){

	//Get the number of leds
	int len = 1;


	//initialize the delay counter to 1
	int dn = 1;
	delay_array[0] = 0;
	//iterate over each LED
	for(int i = 0; i < len; i++){

		//iterate over each pixel. Each pixel is of 8 bits. Fill values MSB first



		//start with green
		for(int j = 7; j >=0 ; j--){

			//check for each bit if it is a high or a low

			if(((led_array[i].g >> j) & 0x01) == 1){

				//set the high duty cycle THI_1
				delay_array[dn] = delay_array[dn-1] + WS2812B_TH_1;
				dn++;
				delay_array[dn] = delay_array[dn-1] + WS2812B_TH_0;
				dn++;


			}

			else{

				//set the low duty cycle THI_0
				delay_array[dn] = delay_array[dn-1] + WS2812B_TH_0;
				dn++;
				delay_array[dn] = delay_array[dn-1] + WS2812B_TH_1;
				dn++;


			}

		}


		//then with red
		for(int j = 7; j >=0 ; j--){

			//check for each bit if it is a high or a low

			if(((led_array[i].r >> j) & 0x01) == 1){

				//set the high duty cycle THI_1
				delay_array[dn] = delay_array[dn-1] + WS2812B_TH_1;
				dn++;
				delay_array[dn] = delay_array[dn-1] + WS2812B_TH_0;
				dn++;

			}

			else{

				//set the low duty cycle THI_0
				delay_array[dn] = delay_array[dn-1] + WS2812B_TH_0;
				dn++;
				delay_array[dn] = delay_array[dn-1] + WS2812B_TH_1;
				dn++;

			}

		}


	//then with blue
	for(int j = 7; j >=0 ; j--){

		//check for each bit if it is a high or a low

		if(((led_array[i].b >> j) & 0x01) == 1){

			//set the high duty cycle THI_1
			delay_array[dn] = delay_array[dn-1] + WS2812B_TH_1;
			dn++;
			delay_array[dn] = delay_array[dn-1] + WS2812B_TH_0;
			dn++;

		}

		else{

			//set the low duty cycle THI_0
			delay_array[dn] = delay_array[dn-1] + WS2812B_TH_0;
			dn++;
			delay_array[dn] = delay_array[dn-1] + WS2812B_TH_1;
			dn++;

		}

	}

	}


	TIM3->CNT = 0;  // set the counter value as 0
	GPIOA->BSRR = (1U << 7); // Set PA7 high
	for(int i = 1; i < WS2812B_NUM_BITS; i++){

		while (TIM3->CNT < delay_array[i]){
			;
		}
		//toggle the pin
		GPIOA->BSRR ^= (1U << 7);

	}

	//Delay for 50us
	GPIOA->BSRR = (1U << (7 + 16));
	TIM3->CNT = 0; // set the counter value a 0
	while (TIM3->CNT < 000){
		;
	}



}




void ws2812b_init(){


	for(int i = 0; i < WS2812B_DMA_BUFF_LEN; i++){

		WS2812B_DMA_BUFF[i] = 0;

	}


}



void ws2812b_update_dma_buff(ws2812b* led_array){


	int dn = 0;

	for(int i = 0; i < WS2812B_LED_COUNT; i++){

		//start with green
		for(int j = 7; j >= 0; j--){

			if(((led_array[i].g >> j) & 0x01) == 1){

				//set the high duty cycle THI_1
				WS2812B_DMA_BUFF[dn] =  WS2812B_TH_1;
				dn++;


			}

			else
			{
				//set the low duty cycle THI_0
				WS2812B_DMA_BUFF[dn] = WS2812B_TH_0;
				dn++;

			}

		}


		//then with red
		for(int j = 7; j >= 0; j--){

			if(((led_array[i].r >> j) & 0x01) == 1){

				//set the high duty cycle THI_1
				WS2812B_DMA_BUFF[dn] =  WS2812B_TH_1;
				dn++;

			}

			else
			{
				//set the low duty cycle THI_0
				WS2812B_DMA_BUFF[dn] = WS2812B_TH_0;
				dn++;

			}


		}


		//then with blue
		for(int j = 7; j >= 0; j--){

			if(((led_array[i].b >> j) & 0x01) == 1){

				//set the high duty cycle THI_1
				WS2812B_DMA_BUFF[dn] = WS2812B_TH_1;
				dn++;
			}

			else
			{
				//set the low duty cycle THI_0
				WS2812B_DMA_BUFF[dn] =  WS2812B_TH_0;
				dn++;

			}


		}


	}


	// The reset pulse is already accounted for since the buffer length includes the reset period



}


















