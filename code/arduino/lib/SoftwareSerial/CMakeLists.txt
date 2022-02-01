generate_arduino_library(SoftwareSerial_lib
	SRCS src/SoftwareSerial.cpp
	HDRS src/SoftwareSerial.h
)
target_include_directories(SoftwareSerial_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
