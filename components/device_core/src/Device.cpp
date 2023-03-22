#include "Device.h"


void Device::init() {
    hal.init();
    rgb_led_ctrl.set_animation_listener(this);
    rgb_led_ctrl.type = RGBAnimationType::CYCLE;
    rgb_led_ctrl.looping = true;
    rgb_led_ctrl.set_interval(Presets::Animations::RGB_INTERVAL);
    rgb_led_ctrl.start();
}

void Device::on_animation(float progrs_norm, uint8_t r, uint8_t g, uint8_t b) {
    hal.set_rgb_led(r,g,b);
}

void Device::tick(float dt) {
    hal.tick();
    rgb_led_ctrl.tick(dt);
}