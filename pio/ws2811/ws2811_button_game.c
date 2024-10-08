#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "ws2811.pio.h"

int main(){
	
	// Setting I/O pins
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

	// Initializing button pin and setting data direction to input
	gpio_init(BUTTON_PIN);
	gpio_set_dir(BUTTON_PIN, GPIO_IN);

	while(true){
		pressed = false;

		// Turns all LEDs off for 0.5 secs
		for(int i = 0; i < NUM_LEDS; i++)
			pio_sm_put_blocking(pio, sm, pixel);
		sleep_ms(500);

		// Continues until the user presses the button or
		// the last LED has been lit
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

		// If the user did not press the button in time,
		// make all LEDs red
		if(!pressed){
			pixel = 0xff000000;
			for(int i = 0; i < NUM_LEDS; i++)
				pio_sm_put_blocking(pio, sm, pixel);
		}

		sleep_ms(5000);

		// User must press the button again to reset the game
		reset = false;
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
