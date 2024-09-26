#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2811.pio.h"

int main(){
	
	// String 1 is connected to GPIO pin 2
	const uint STRING_1_PIN = 2;
	const int STRING_1_LEDS = 50;

	PIO string1_pio = pio0;
	uint sm1 = 0;
	uint offset1 = pio_add_program(string1_pio, &ws2811_program);
	ws2811_program_init(string1_pio, sm1, offset1, STRING_1_PIN, 800000, 0);

	// String 2 is connected to GPIO pin 3
	const uint STRING_2_PIN = 3;
	const int STRING_2_LEDS = 50;

	PIO string2_pio = pio1;
	uint sm2 = 0;
	uint offset2 = pio_add_program(string2_pio, &ws2811_program);
	ws2811_program_init(string2_pio, sm2, offset2, STRING_2_PIN, 800000, 0);

	uint32_t pixel;

	while(true){
		// Lighting string 1
		pixel = 0x0000ff00; //0xRRGGBB--
		for(int i = 0; i < STRING_1_LEDS; i++)
			pio_sm_put_blocking(string1_pio, sm1, pixel);
		// Lighting string 2
		pixel = 0xff000000;
		for(int i = 0; i < STRING_2_LEDS; i++)
			pio_sm_put_blocking(string2_pio, sm2, pixel);
		sleep_ms(1000);
		// Turning off string 1
		pixel = 0x00000000;
		for(int i = 0; i < STRING_1_LEDS; i++)
			pio_sm_put_blocking(string1_pio, sm1, pixel);
		// Turning poff string 2
		for(int i = 0; i < STRING_2_LEDS; i++)
			pio_sm_put_blocking(string2_pio, sm2, pixel);
		sleep_ms(1000);
	}

	return 0;
}
