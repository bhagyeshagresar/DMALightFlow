# DMALightFlow

I am using Timer2 to configure to generate a PWM. The WS2812B leds have a THI and TLO duty cycles and a reset period to latch the outputs.
T0H of 0.35us and T1H of 1.36us.


Ftim = 82 MHz (configured using the clock configuration tool in CubeIDE)

fpwm = Ftim/(arr+1)(psc+1)

Tpwm = 1.22us
ARR = 100
PSC = 1


##DMA stream


