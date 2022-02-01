generate_arduino_library(SDS011-select-serial_lib
	SRCS SDS011-select-serial.cpp
	HDRS SDS011-select-serial.h
)
target_include_directories(SDS011-select-serial_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
