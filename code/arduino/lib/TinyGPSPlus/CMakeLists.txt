generate_arduino_library(TinyGPSPlus_lib
	SRCS src/TinyGPS++.cpp
	HDRS src/TinyGPS++.h
)
target_include_directories(TinyGPSPlus_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
