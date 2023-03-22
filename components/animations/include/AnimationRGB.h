#pragma once
#include "Animation.h"
#include "AnimationListener.h"

enum class RGBAnimationType:int {
    NONE = -1,
    CYCLE = 0,
};

class AnimationRGBController : public AnimationController {
public:
    inline void set_animation_listener(AnimationRGBListener* listener) {
        this->listener = listener;
    }
RGBAnimationType type{RGBAnimationType::NONE};
void set_brightness(float brightness);
inline float get_brightness() {
    return brightness_norm;
}
protected:
    virtual void on_animation_frame(float progress_norm) override;
private:
    void on_animation_cycle(float progress, uint8_t& r, uint8_t& g, uint8_t& b);
    AnimationRGBListener* listener;
    float brightness_norm{0.1F};
};