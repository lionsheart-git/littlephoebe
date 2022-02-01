set(ARDUINO_DEFAULT_BOARD arduino) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyS3) # Default Port, when not specified

set(LIBRARIES blink_lib SD_lib SPI_lib HDC100X_lib BMP280_lib Makerblog_TSL45315_lib VEML6070_lib)

generate_arduino_firmware(RocketDataLogger
        SRCS main.cpp
        LIBS ${LIBRARIES}
        BOARD uno)

# target_link_libraries(RocketDataLogger ${LIBRARIES})


# If simple blink is needed to verify connection or cmake
add_subdirectory(blink)

