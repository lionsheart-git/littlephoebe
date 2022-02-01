generate_arduino_library(SenseBox-MCU_lib
	SRCS SenseBoxMCU.cpp
	HDRS SenseBoxMCU.h
)
target_include_directories(SenseBox-MCU_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
