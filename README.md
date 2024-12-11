# DMALightFlow

Let's start with controlling the on-board LED using the DMA. The LD2 led on the STM32 Nucleo board is a user-programmable LED which is connected to GPIO Port A Pin 5 of the STM32.

## Configuring the Timer
Timer 2 running at 1 MHz. Timer 2 is configured to use a Prescaler of 80. The ARR register is configured to rollover at 65535. This means the timer will count an event upto 65.5 ms.

## Output Compare Mode
As per the reference manual of STM32F401Re, when the counter (TIM2_CNT) reaches the value set in the Capture/Compare Register (TIM2_CCR1) , assign the output pin to a programmable value defined in the OC2M bits in the TIM2_CCMR2 register. The output pin can keep its level (OCXM=000), be set active (OCxM=001), be set inactive (OCxM=010) or can toggle (OCxM=011) on match.

##DMA stream


