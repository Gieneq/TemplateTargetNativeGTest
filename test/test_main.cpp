#include "gtest/gtest.h"
#include "test_main.h"

TEST(DummyTest, ShouldPass)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    if (RUN_ALL_TESTS())
    ;
    do_animations_tests(argc, argv);

    return 0;
}