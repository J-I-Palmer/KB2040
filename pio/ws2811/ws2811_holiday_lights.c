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

// String 1 is connected to GPIO pin 2
const uint STR1_PIN = 2;
const int STR1_LEDS = 50;

PIO str1_pio = pio0;
uint sm1 = 0;
uint offset1 = pio_add_program(str1_pio, &ws2811_program);
ws2811_program_init(str1_pio, sm1, offset1, STR1_PIN, 800000, 0);

// String 2 is connected to GPIO pin 3
const uint STR2_PIN = 3;
const int STR2_LEDS = 50;

PIO str2_pio = pio1;
uint sm2 = 0;
uint offset2 = pio_add_program(str2_pio, &ws2811_program);
ws2811_program_init(str2_pio, sm2, offset2, STR2_PIN, 800000, 0);

// Button is connected to GPIO pin 10
const uint BUTTON_PIN = 10;
gpio_init(BUTTON_PIN);
gpio_set_dir(BUTTON_PIN, GPIO_IN);

int valentine(int counter);
int patrick(int counter);
int easter(int counter);
int july4(int counter);
int halloween(int counter);
int thanksgiving(int counter);
int christmas(int counter);
bool button();

int main(){

	// Button press counter
	int counter = 0;

	while(true){
		counter = counter % 7;
		switch(counter){
			case 0:
				counter = valentine(counter);
				break;
			case 1:
				counter = patrick(counter);
				break;
			case 2:
				counter = easter(counter);
				break;
			case 3:
				counter = july4(counter);
				break;
			case 4:
				counter = halloween(counter);
				break;
			case 5:
				counter = thanksgiving(counter);
				break;
			case 6:
				counter = christmas(counter);
				break;
		}
	}

	return 0;
}

bool button(){
	bool pressed = false;
	if (gpio_get(BUTTON_PIN)){
		sleep_ms(1);
		pressed = gpio_get(BUTTON_PIN);
	}
	return pressed;
}

int valentine(int counter){
	bool pressed = false;
	uint32_t color1 = 0xff000000; // Red
	uint32_t color2 = 0xffc0cb00; // Pink
	while(true){
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else
				pio_sm_put_blocking(str1_pio, sm1, color2);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else
				pio_sm_put_blocking(str2_pio, sm2, color2);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

	}

}

int patrick(int counter){
	bool pressed = false;
	uint32_t color1 = 0x009a4900; // Irish Green
	uint32_t color2 = 0xffd70000; // Golden Yellow
	while(true){
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else
				pio_sm_put_blocking(str1_pio, sm1, color2);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else
				pio_sm_put_blocking(str2_pio, sm2, color2);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

	}
}

int easter(int counter){
	bool pressed = false;
	uint32_t color1 = 0xace7ff00; // Pastel Blue
	uint32_t color2 = 0xffccf900; // Pastel Pink
	while(true){
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else
				pio_sm_put_blocking(str1_pio, sm1, color2);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else
				pio_sm_put_blocking(str2_pio, sm2, color2);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

	}
}

int july4(int counter){
	bool pressed = false;
	uint32_t color1 = 0xff000000; // Red
	uint32_t color2 = 0xffffff00; // White
	uint32_t color3 = 0x0000ff00; // Blue
	while(true){
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%3) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else if((i%3) == 1)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color3);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%3) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color3);
			else if((i%3) == 1)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

		for(int i = 0; i < STR1_LEDS; i++){
			if((i%3) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color3);
			else if((i%3) == 1)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%3) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else if((i%3) == 1)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color3);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

	}
}

int halloween(int counter){
	bool pressed = false;
	uint32_t color1 = 0xff9a0000; // Orange
	uint32_t color2 = 0xa020f000; // Purple
	while(true){
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else
				pio_sm_put_blocking(str1_pio, sm1, color2);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else
				pio_sm_put_blocking(str2_pio, sm2, color2);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

	}
}

int thanksgiving(int counter){
	bool pressed = false;
	uint32_t color1 = 0x7b481c00; // Tawny Brown
	uint32_t color2 = 0xdd571c00; // Fire Orange
	while(true){
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else
				pio_sm_put_blocking(str1_pio, sm1, color2);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else
				pio_sm_put_blocking(str2_pio, sm2, color2);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

	}
}

int christmas(int counter){
	bool pressed = false;
	uint32_t color1 = 0xff000000; // Red
	uint32_t color2 = 0x00ff0000; // Green
	while(true){
		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color1);
			else
				pio_sm_put_blocking(str1_pio, sm1, color2);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color2);
			else
				pio_sm_put_blocking(str2_pio, sm2, color1);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

		for(int i = 0; i < STR1_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str1_pio, sm1, color2);
			else
				pio_sm_put_blocking(str1_pio, sm1, color1);
		}

		for(int i = 0; i < STR2_LEDS; i++){
			if((i%2) == 0)
				pio_sm_put_blocking(str2_pio, sm2, color1);
			else
				pio_sm_put_blocking(str2_pio, sm2, color2);
		}

		for(int i = 0; i < 40 && !pressed; i++){
			pressed = button();
			if(pressed)
				return(++counter);
			sleep_ms(50);
		}

	}
}

