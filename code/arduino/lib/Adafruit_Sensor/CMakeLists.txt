generate_arduino_library(Adafruit_Sensor_lib
	HDRS Adafruit_Sensor.h
		SRCS Adafruit_Sensor.cpp
)
target_include_directories(Adafruit_Sensor_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
