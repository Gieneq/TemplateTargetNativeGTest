extern "C" {
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
}

#include "Device.h"

Device device;

extern "C" {
    void app_main() {
        device.init();
        float dt{0};

        auto current_micros = esp_timer_get_time();
        auto last_micros = current_micros - 1;


        while (1) {
            current_micros = esp_timer_get_time();
            dt = static_cast<float>(current_micros - last_micros)/1000.0F;
            last_micros = current_micros;
            device.tick(dt);
            vTaskDelay(1);
        }
    }
}
