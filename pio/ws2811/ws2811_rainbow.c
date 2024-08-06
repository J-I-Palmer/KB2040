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

	uint32_t pixel = 0xff000000; // RRGGBB--
	int command_counter = 0;

	// The goal is to have a color gradient that follows the color order of a rainbow.
	while (true){
		// from red to orange to yellow
		while(pixel < 0xffff0000){
			pio_sm_put_blocking(pio, sm, pixel);
			pixel += 0x00010000;
			command_counter++;
			if(command_counter > NUM_LEDS){
				command_counter = 0;
				sleep_ms(0.05);
			}
		}
		// from yellow to green
		while(pixel > 0x00ff0000){
			pio_sm_put_blocking(pio, sm, pixel);
			pixel -= 0x01000000;
			command_counter++;
			if(command_counter > NUM_LEDS){
				command_counter = 0;
				sleep_ms(0.05);
			}
		}
		// from green to blue
		while(pixel > 0x0000ff00){
			pio_sm_put_blocking(pio, sm, pixel);
			pixel -= 0x00010000;
			pixel += 0x00000100;
			command_counter++;
			if(command_counter > NUM_LEDS){
				command_counter = 0;
				sleep_ms(0.05);
			}
		}
		// from blue to indigo to violet
		while(pixel < 0xff00ff00){
			pio_sm_put_blocking(pio, sm, pixel);
			pixel += 0x01000000;
			command_counter++;
			if(command_counter > NUM_LEDS){
				command_counter = 0;
				sleep_ms(0.05);
			}
		}
		// from violet back to red
		while(pixel > 0xff000000){
			pio_sm_put_blocking(pio, sm, pixel);
			pixel -= 0x00000100;
			command_counter++;
			if(command_counter > NUM_LEDS){
				command_counter = 0;
				sleep_ms(0.05);
			}
		}
	}

	return 0;
}
