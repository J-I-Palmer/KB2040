#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2811.pio.h"

int main(){
	
	// Using GPIO pin 3 for LED control
	const uint LED_PIN = 3;
	const int NUM_LEDS = 50;

	PIO pio = pio0;
	uint sm = 0;

	uint offset = pio_add_program(pio, &ws2811_program);
	ws2811_program_init(pio, sm, offset, LED_PIN, 800000, 0);

	uint32_t pixel;
	int button_presses = 0;

	// Using GPIO pin 10 for button input
	const uint BUTTON_PIN = 10;

	gpio_init(BUTTON_PIN);
	gpio_set_dir(BUTTON_PIN, GPIO_IN);

	while(true){
		button_presses = button_presses % 3;
		if (button_presses == 0){
			pixel = 0xff000000; // RRGGBB--
			for (int i = 0; i < NUM_LEDS; i++)
				pio_sm_put_blocking(pio, sm, pixel);
		}

		else if (button_presses == 1){
			pixel = 0x00ff0000;
			for (int i = 0; i < NUM_LEDS; i++)
				pio_sm_put_blocking(pio, sm, pixel);
		}

		else{
			pixel = 0x0000ff00;
			for (int i = 0; i < NUM_LEDS; i++)
				pio_sm_put_blocking(pio, sm, pixel);
		}

		sleep_ms(200);

		if (gpio_get(BUTTON_PIN)){
			sleep_ms(1);
			if (gpio_get(BUTTON_PIN))
				button_presses++;
		}
	}

	return 0;
}
