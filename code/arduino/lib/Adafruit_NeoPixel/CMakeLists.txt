generate_arduino_library(Adafruit_NeoPixel_lib
	SRCS Adafruit_NeoPixel.cpp
	HDRS Adafruit_NeoPixel.h
)
target_include_directories(Adafruit_NeoPixel_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
