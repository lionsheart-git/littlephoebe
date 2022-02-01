generate_arduino_library(Adafruit_BMP280_Library_lib
	SRCS Adafruit_BMP280.cpp
	HDRS Adafruit_BMP280.h
)
target_include_directories(Adafruit_BMP280_Library_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
