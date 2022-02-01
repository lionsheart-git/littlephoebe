generate_arduino_library(RV8523_lib
	SRCS RV8523.cpp
	HDRS RV8523.h
)
target_include_directories(RV8523_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
