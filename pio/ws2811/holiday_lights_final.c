// Written by James Palmer
// University of North Alabama
// October 2024

// Program for displaying holiday-themed lights
// Utilizes one button and two strings of LEDS.

// Holidays Included:
// Valentine's Day
// St. Patrick's Day
// Easter
// July 4th
// Halloween
// Thanksgiving
// Christmas

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2811.pio.h"

const uint NUM_HOLIDAYS = 7;

// LED string #1 is connected to GPIO pin 2
const uint STR1_PIN = 2;
const uint STR1_LEDS = 50;

// LED string #2 is connected to GPIO pin 3
const uint STR2_PIN = 3;
const uint STR2_LEDS = 50;

// Button is connected to GPIO pin 10
const uint BUTTON_PIN = 10;

bool buttonPress();
void twoColor(uint32_t color1, uint32_t color2, PIO str1_pio, PIO str2_pio, uint sm1, uint sm2);
void threeColor(uint32_t color1, uint32_t color2, uint32_t color3, PIO str1_pio, PIO str2_pio, uint sm1, uint sm2);

int main(){
	// Enabling I/O state machine for string #1
	PIO str1_pio = pio0;
	uint sm1 = 0;
	uint offset1 = pio_add_program(str1_pio, &ws2811_program);
	ws2811_program_init(str1_pio, sm1, offset1, STR1_PIN, 800000, 0);

	// Enabling I/O state machine for string #2
	PIO str2_pio = pio1;
	uint sm2 = 0;
	uint offset2 = pio_add_program(str2_pio, &ws2811_program);
	ws2811_program_init(str2_pio, sm2, offset2, STR2_PIN, 800000, 0);

	// Setting data direction for button
	gpio_init(BUTTON_PIN);
	gpio_set_dir(BUTTON_PIN, GPIO_IN);

	// 0xRRGGBB--
	uint32_t color1 = 0x00000000;
	uint32_t color2 = 0x00000000;
	uint32_t color3 = 0x00000000;

	// Variable for counting button presses
	int counter = 1;
	while(true){
		// Valentine's Day
		if (counter == 1){
			color1 = 0xff000000; // Red
			color2 = 0xff101b00; // Pink
			twoColor(color1, color2, str1_pio, str2_pio, sm1, sm2);
		}
		// St. Patrick's Day
		else if (counter == 2){
			color1 = 0x00ff1900; // Green
			color2 = 0xffcc1100; // Yellow
			twoColor(color1, color2, str1_pio, str2_pio, sm1, sm2);
		}
		// Easter
		else if (counter == 3){
			color1 = 0x9cd7ff00; // Pastel Blue
			color2 = 0xffacd900; // Pastel Pink
			twoColor(color1, color2, str1_pio, str2_pio, sm1, sm2);
		}
		// July 4th
		else if (counter == 4){
			color1 = 0xff000000; // Red
			color2 = 0xffffff00; // White
			color3 = 0x0000ff00; // Blue
			threeColor(color1, color2, color3, str1_pio, str2_pio, sm1, sm2);
		}
		// Halloween
		else if (counter == 5){
			color1 = 0xff9a0000; // Orange
			color2 = 0xa020f000; // Purple
			twoColor(color1, color2, str1_pio, str2_pio, sm1, sm2);
		}
		// Thanksgiving
		else if (counter == 6){
			color1 = 0x7b481c00; // Tawny Brown
			color2 = 0xdd571c00; // Fire Orange
			twoColor(color1, color2, str1_pio, str2_pio, sm1, sm2);
		}
		// Christmas
		else if (counter == 7){
			color1 = 0xff000000; // Red
			color2 = 0x00ff0000; // Green
			twoColor(color1, color2, str1_pio, str2_pio, sm1, sm2);
		}
		else
			counter = 0;

		counter++;
	}

	return 0;
}

bool buttonPress(){
	bool pressed = false;
	if (gpio_get(BUTTON_PIN)){
		sleep_ms(1);
		pressed = gpio_get(BUTTON_PIN);
	}
	return pressed;
}

void twoColor(uint32_t color1, uint32_t color2, PIO str1_pio, PIO str2_pio, uint sm1, uint sm2){
	bool pressed = false;
	sleep_ms(500);
	while(true){
		// Lighting string 1
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else
				pio_sm_put_blocking(str1_pio, sm1, color2);
		}

		// Lighting string 2
		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		// Searching for button press
		for(int i = 0; i < 40 && !pressed; i++){
			pressed = buttonPress();
			if(pressed)
				return;
			sleep_ms(50);
		}

		// Lighting string 1 w/ alternated colors
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		// Lighting string 2 w/ alternated colors
		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else
				pio_sm_put_blocking(str2_pio, sm2, color2);
		}
		
		// Searching for button press
		for(int i = 0; i < 40 && !pressed; i++){
			pressed = buttonPress();
			if(pressed)
				return;
			sleep_ms(50);
		}
	}
}

void threeColor(uint32_t color1, uint32_t color2, uint32_t color3, PIO str1_pio, PIO str2_pio, uint sm1, uint sm2){
	bool pressed = false;
	sleep_ms(500);
	while(true){
		// Lighting string 1
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%3) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else if((i%3) == 1)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color3);
		}

		// Lighting string 2
		for(int i = 0; i < STR2_LEDS; i++){
			if((i%3) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color3);
			else if((i%3) == 1)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		// Searching for button press
		for(int i = 0; i < 40 && !pressed; i++){
			pressed = buttonPress();
			if(pressed)
				return;
			sleep_ms(50);
		}

		// Lighting string 1 w/ alternate colors
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%3) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color3);
			else if((i%3) == 1)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		// Lighting string 2 w/ alternate colors
		for(int i = 0; i < STR2_LEDS; i++){
			if((i%3) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else if((i%3) == 1)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color3);
		}

		// Searching for button press
		for(int i = 0; i < 40 && !pressed; i++){
			pressed = buttonPress();
			if(pressed)
				return;
			sleep_ms(50);
		}
	}
}
