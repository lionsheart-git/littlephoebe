generate_arduino_library(Mouse_lib
	SRCS src/Mouse.cpp
	HDRS src/Mouse.h
)
target_include_directories(Mouse_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
