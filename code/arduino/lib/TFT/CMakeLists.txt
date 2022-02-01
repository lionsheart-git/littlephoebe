generate_arduino_library(TFT_lib
	SRCS src/TFT.cpp src/utility/Adafruit_GFX.cpp src/utility/Adafruit_ST7735.cpp src/utility/glcdfont.c
	HDRS src/TFT.h src/utility/Adafruit_GFX.h src/utility/Adafruit_ST7735.h src/utility/PImage.h
)
target_include_directories(TFT_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
