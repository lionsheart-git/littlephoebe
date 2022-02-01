generate_arduino_library(HID_lib
	SRCS src/HID.cpp
	HDRS src/HID.h
)
target_include_directories(HID_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
