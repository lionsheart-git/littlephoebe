generate_arduino_library(Stepper_lib
	SRCS src/Stepper.cpp
	HDRS src/Stepper.h
)
target_include_directories(Stepper_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
