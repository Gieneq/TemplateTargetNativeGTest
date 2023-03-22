#include "gtest/gtest.h"
#include "gmock/gmock.h" 
#include "test_main.h"

#include "AnimationRGB.h"
#include "AnimationListener.h"

using ::testing::AtLeast;
using ::testing::_;

TEST(AnimationTest, ShouldCreateController)
{
    AnimationController ctrl;
    
    // EXPECT_TRUE(ctrl.looping); //hide this junk
    EXPECT_FALSE(ctrl.looping);
    EXPECT_FALSE(ctrl.is_running());
}

class MockAnimationRGBListener : public AnimationRGBListener {
public:
    MOCK_METHOD( void, on_animation, (float progrs_norm, uint8_t r, uint8_t g, uint8_t b), (override) );
};

TEST(RGBAnimationTest, ShouldTickAnimationOnce) {
    AnimationRGBController rgb_ctrl;
    MockAnimationRGBListener device;

    EXPECT_CALL(device, on_animation(_,_,_,_)).Times(AtLeast(1));
    rgb_ctrl.set_animation_listener(&device);

    rgb_ctrl.start();
    rgb_ctrl.tick(10.0F);
}


TEST(RGBAnimationTest, UseDefaultAnimation) {
    constexpr float animation_interval{2000.0F};
    AnimationRGBController rgb_ctrl;
    MockAnimationRGBListener device;

    EXPECT_EQ(rgb_ctrl.type, RGBAnimationType::NONE);

    EXPECT_CALL(device, on_animation(0.5F,0,0,0)).Times(AtLeast(1));

    rgb_ctrl.set_interval(animation_interval);
    rgb_ctrl.set_animation_listener(&device);

    rgb_ctrl.start();
    rgb_ctrl.tick(1000.0F);
}

TEST(RGBAnimationTest, UseCycleAnimation) {
    constexpr float animation_interval{2000.0F};
    AnimationRGBController rgb_ctrl;
    MockAnimationRGBListener device;

    rgb_ctrl.type = RGBAnimationType::CYCLE;
    rgb_ctrl.set_brightness(1.0F);

    EXPECT_CALL(device, on_animation(0.5F,0,255,255)).Times(AtLeast(1));

    rgb_ctrl.set_interval(animation_interval);
    rgb_ctrl.set_animation_listener(&device);

    rgb_ctrl.start();
    rgb_ctrl.tick(1000.0F);
}

int do_animations_tests(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    if (RUN_ALL_TESTS()){}
    return 0;
}