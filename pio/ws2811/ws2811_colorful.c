#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2811.pio.h"

int main(){

	// connecting output to GPIO pin 3
	const uint LED_PIN = 3;
	
	// number of LEDs to be controlled
	const int NUM_LEDS = 50;

	PIO pio = pio0;
	uint sm = 0;
	uint offset = pio_add_program(pio, &ws2811_program);
	ws2811_program_init(pio, sm, offset, LED_PIN, 800000, 0);

	const uint32_t pixelRed = 0xff000000;
	const uint32_t pixelGreen = 0x00ff0000;
	const uint32_t pixelBlue = 0x0000ff00;
	const uint32_t pixelOff = 0x00000000;

	while(true){
		for (int i = 0; i < NUM_LEDS; i++){
			if (i%3 == 0)
				pio_sm_put_blocking(pio, sm, pixelRed);
			else if (i%3 == 1)
				pio_sm_put_blocking(pio, sm, pixelGreen);
			else
				pio_sm_put_blocking(pio, sm, pixelBlue);
		}
		sleep_ms(250);
		for (int j = 0; j < NUM_LEDS; j++)
			pio_sm_put_blocking(pio, sm, pixelOff);
		sleep_ms(250);
	}

	return 0;
}
