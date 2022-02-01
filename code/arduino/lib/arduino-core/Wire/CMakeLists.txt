generate_arduino_library(Wire_lib
	SRCS src/Wire.cpp src/utility/twi.c
	HDRS src/Wire.h src/utility/twi.h
)
target_include_directories(Wire_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
