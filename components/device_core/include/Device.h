#pragma once
#include "AnimationRGB.h"
#include "AnimationListener.h"
#include "DeviceHAL.h"

class Device : public AnimationRGBListener {
public:
    void init();
    void tick(float dt);
    virtual void on_animation(float progrs_norm, uint8_t r, uint8_t g, uint8_t b) override;
protected:
    DeviceHAL hal;
// static const char *TAG{"example"};
private:
    AnimationRGBController rgb_led_ctrl;
};



