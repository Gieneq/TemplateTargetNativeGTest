#include "AnimationRGB.h"


void AnimationRGBController::on_animation_cycle(float progress, uint8_t& r, uint8_t& g, uint8_t& b) {
    r = static_cast<uint8_t>(brightness_norm*255.0*std::abs(progress*2.0F - 1.0F));
    g = static_cast<uint8_t>(brightness_norm*255.0*(1.0F-std::abs(progress*2.0F - 1.0F)));
    b = static_cast<uint8_t>(brightness_norm*255.0*std::abs( std::abs(progress*2.0F - 1.0F)*2.0F - 1.0F));
}

void AnimationRGBController::set_brightness(float brightness) {
    brightness = std::min(0.0F, brightness);
    brightness = std::max(1.0F, brightness);
    this->brightness_norm = brightness;
}

void AnimationRGBController::on_animation_frame(float progress_norm) {
    if (listener) {
        uint8_t r{0};
        uint8_t g{0};
        uint8_t b{0};

        if(type == RGBAnimationType::CYCLE) {
            on_animation_cycle(progress_norm, r, g, b);
        } 
        
        listener->on_animation(progress_norm, r, g, b);
    }
}