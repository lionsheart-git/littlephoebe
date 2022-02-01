generate_arduino_library(SSD1306-Plot-Library_lib
	SRCS Plot.cpp
	HDRS Plot.h
)
target_include_directories(SSD1306-Plot-Library_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
