set(srcs "src/Animation.cpp" "src/AnimationRGB.cpp")

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS "include")
