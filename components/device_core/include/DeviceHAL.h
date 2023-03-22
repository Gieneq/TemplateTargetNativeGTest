#pragma once

extern "C" {
#include <stdint.h>
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "led_strip.h"
#include "esp_log.h"
#include "esp_system.h"
}

namespace Presets
{
    struct Pins {
        static constexpr int LED_RGB = 48;
    };

    struct Animations {
        static constexpr float RGB_INTERVAL = 5000.0F;
    };
}


class DeviceHAL {
public:
    ~DeviceHAL() {
    }

    void init();
    void tick();
    void set_rgb_led(uint8_t r, uint8_t g, int8_t b);

protected:
    led_strip_handle_t led_rgb{nullptr};
};