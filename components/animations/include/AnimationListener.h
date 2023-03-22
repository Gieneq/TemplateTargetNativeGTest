#pragma once
#include "stdint.h"

class AnimationRGBListener {
public:
    virtual ~AnimationRGBListener() = default;
    virtual void on_animation(float progrs_norm, uint8_t r, uint8_t g, uint8_t b) = 0;
};