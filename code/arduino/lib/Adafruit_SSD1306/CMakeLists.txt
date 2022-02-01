generate_arduino_library(Adafruit_SSD1306_lib
	SRCS Adafruit_SSD1306.cpp
	HDRS Adafruit_SSD1306.h
)
target_include_directories(Adafruit_SSD1306_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
