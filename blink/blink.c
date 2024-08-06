// Modified by James Palmer
// October 2023

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"

int main() {
    // NeoPixel LED is connected to GPIO17
    const uint LED_PIN = 17;
    
    // Initialize PIO instance
    PIO pio = pio0;
    uint sm = 0;

    // Load WS2812 PIO
    uint offset = pio_add_program(pio, &ws2812_program);

    // Initialize PIO state machine
    ws2812_program_init(pio, sm, offset, LED_PIN, 800000, 1);

    // Pixel data (set to red)
    uint32_t pixel;

    while (true) {
	pixel = 0x00000010;
        pio_sm_put_blocking(pio, sm, pixel << 8u);
        sleep_ms(250);
        pixel = 0x00000000;
	pio_sm_put_blocking(pio, sm, pixel << 8u);
        sleep_ms(250);
    }
    return 0;
}
