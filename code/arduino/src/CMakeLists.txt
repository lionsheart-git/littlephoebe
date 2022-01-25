set(ARDUINO_DEFAULT_BOARD arduino) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyS3) # Default Port, when not specified

generate_arduino_firmware(RocketDataLogger
        SRCS main.cpp
        LIBS blink_lib
        BOARD uno)

target_link_libraries(RocketDataLogger blink_lib)


# If simple blink is needed to verify connection or cmake
add_subdirectory(blink)

