# DMALightFlow (ARM Cortex M4 Chip and WS2812B LEDs)
This project uses the DMA controller to send the varying duty cycle data from the memory of the STM32 to the Timer peripheral for controlling the WS2812B LED strip.

## BitBanging
In order to experience the issues of using the CPU to control the LEDs, I started out with using the CPU to light the LEDs using the approach called as BitBanging. This process delays a GPIO Pin output by keeping it high for a certain amount of time, then toggles the pin to a low. This essentially simulates the varying PWM type signal required to control the WS2812B strip.


The 'set_ws2812b_color_bitbanging' function in the WS2812B driver source file attempts bitbanging without using any HAL functions to avoid any overhead. This chunk of code has to be run with very few lines of code and functions calls so that there is less latency from the CPU to send the signal. The parameters WS2812B_TH_1 and WS2812B_TH_0 might need to be tuned to control the timing. I am still in the process of being able to make this function to work.

The Timer used for delay is 'Timer 3'
Input Clock Freq for the APB1 Bus: 80 MHz
Prescaler : 1
AutoReload Register/Counter : 65535


## DMA Control
The DMA control will use a timer configured to generate a PWM. WIP to understand what request is required to the DMA to initiate Data Transfer to the Timer peripheral.