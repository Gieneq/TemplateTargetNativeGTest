#pragma once
#include "algorithm"

class AnimationController {
public:
    virtual ~AnimationController() = default;
    void start();
    void stop();
    void tick(float dt);
    bool looping{false};
    void set_interval(float interval);
    bool is_running();

protected:
    virtual void on_animation_frame(float progress_norm);
    bool running{false};
private:
    float interval{1000};
    float accumulator{0};
};