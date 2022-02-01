generate_arduino_library(BMP280_lib
        HDRS BMP280.h
        SRCS BMP280.cpp
        )
target_include_directories(BMP280_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})