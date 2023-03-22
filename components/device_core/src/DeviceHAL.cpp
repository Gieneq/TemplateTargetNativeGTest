#include "DeviceHAL.h"


void DeviceHAL::init() {
    led_strip_config_t strip_config = {
        .strip_gpio_num = Presets::Pins::LED_RGB,
        .max_leds = 1, // at least one LED on board
    };

    led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000, // 10MHz
    };

    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_rgb));
}

void DeviceHAL::set_rgb_led(uint8_t r, uint8_t g, int8_t b) {
    if(led_rgb) {
        led_strip_set_pixel(led_rgb, 0, r, g, b);
        led_strip_refresh(led_rgb);
    }
}

void DeviceHAL::tick() {
}
