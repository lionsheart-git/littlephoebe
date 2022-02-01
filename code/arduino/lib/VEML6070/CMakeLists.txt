generate_arduino_library(VEML6070_lib
	SRCS VEML6070.cpp
	HDRS VEML6070.h
)
target_include_directories(VEML6070_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
