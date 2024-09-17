#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2811.pio.h"

int main(){
	
	// connecting output to GPIO pin 2
	const uint LED_PIN = 2;

	// number of LEDs to be controlled
	const int NUM_LEDS = 50;

	PIO pio = pio0;
	uint sm = 0;
	uint offset = pio_add_program(pio, &ws2811_program);
	ws2811_program_init(pio, sm, offset, LED_PIN, 800000, 0);

	const uint32_t pixelBlue = 0x0000ff00;	//0xRRGGBB--
	const uint32_t pixelOff = 0x00000000;

	int numLoops = 0;

	// This should light up only one LED at a time, with the lit pixel moving
	// one position down the string and looping back to the front once it reaches the end
	while(true){
		for(int i = 0; i < NUM_LEDS; i++){
			if (i == numLoops)
				pio_sm_put_blocking(pio, sm, pixelBlue);
			else
				pio_sm_put_blocking(pio, sm, pixelOff);
		}
		if (numLoops < NUM_LEDS - 1)
			numLoops++;
		else
			numLoops = 0;
		// This controls the speed at which the lit LED changes
		sleep_ms(100);
	}

	return 0;
}
