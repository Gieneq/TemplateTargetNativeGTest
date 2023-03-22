set(srcs 
"src/Device.cpp"
"src/DeviceHAL.cpp")


idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS "include"
                       REQUIRES driver animations)
