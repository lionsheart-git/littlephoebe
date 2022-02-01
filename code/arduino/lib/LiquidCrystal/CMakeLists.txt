generate_arduino_library(LiquidCrystal_lib
	SRCS src/LiquidCrystal.cpp
	HDRS src/LiquidCrystal.h
)
target_include_directories(LiquidCrystal_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
