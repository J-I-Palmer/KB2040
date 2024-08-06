#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2811.pio.h"

int main(){
	
	// connecting output to GPIO pin 2
	const uint LED_PIN = 2;
	const int NUM_LEDS = 50;

	PIO pio = pio0;
	uint sm = 0;

	uint offset = pio_add_program(pio, &ws2811_program);

	ws2811_program_init(pio, sm, offset, LED_PIN, 800000, 0);

	uint32_t pixel;

	while(true){
		pixel = 0x0000ff00; //0xRRGGBB--
		for(int i = 0; i < NUM_LEDS; i++)
			pio_sm_put_blocking(pio, sm, pixel);
		sleep_ms(250);
		pixel = 0x00000000;
		for(int i = 0; i < NUM_LEDS; i++)
			pio_sm_put_blocking(pio, sm, pixel);
		sleep_ms(250);
	}
	return 0;
}
