#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "ws2811.pio.h"

int main(){

	const uint LED_PIN = 3;
	const int NUM_LEDS = 50;
	const uint BUTTON_PIN = 10;

	PIO pio = pio0;
	uint sm = 0;

	uint offset = pio_add_program(pio, &ws2811_program);
	ws2811_program_init(pio, sm, offset, LED_PIN, 800000, 0);

	uint32_t pixel = 0x00000000;
	bool pressed;
	bool reset;

	gpio_init(BUTTON_PIN);
	gpio_set_dir(BUTTON_PIN, GPIO_IN);

	while(true){
		reset = false;
		pressed = false;

		for(int i = 0; i < NUM_LEDS; i++)
			pio_sm_put_blocking(pio, sm, pixel);
		sleep_ms(500);

		for(int i = NUM_LEDS-1; i >= 0 && pressed == false; i--){
			for(int j = 0; j < NUM_LEDS; j++){
				if(i == j){
					pixel = 0x0000ff00;
				}
				else{
					pixel = 0x00000000;
				}
				pio_sm_put_blocking(pio, sm, pixel);
			}
			sleep_ms(40);
			if (gpio_get(BUTTON_PIN)){
				sleep_ms(1);
				pressed = gpio_get(BUTTON_PIN);
			}
		}

		sleep_ms(40);

		if(!pressed){
			pixel = 0xff000000;
			for(int i = 0; i < NUM_LEDS; i++)
				pio_sm_put_blocking(pio, sm, pixel);
		}

		sleep_ms(5000);

		while(!reset){
			if(gpio_get(BUTTON_PIN)){
				sleep_ms(1);
				reset = gpio_get(BUTTON_PIN);
			}
			sleep_ms(100);
		}
	}

	return 0;
}
