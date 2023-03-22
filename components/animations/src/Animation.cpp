#include "Animation.h"

void AnimationController::start() {
    running = true;
    accumulator = 0;
}

void AnimationController::stop() {
    running = false;
}

void AnimationController::tick(float dt) {
    if(running) {
        accumulator += dt;
        if(accumulator > interval) {
            accumulator -= interval;
            if(!looping){
                accumulator = 0;
                stop();
            }
        }

        float progress_norm = accumulator / interval;
        progress_norm = std::max(0.0F, progress_norm);
        progress_norm = std::min(1.0F, progress_norm);
        on_animation_frame(progress_norm);
    }
}

bool AnimationController::is_running() {
    return running;
}

void AnimationController::set_interval(float interval) {
    this->interval = interval;
    accumulator = std::min(accumulator, interval);
}

void AnimationController::on_animation_frame(float progress_norm) {
    // override
}