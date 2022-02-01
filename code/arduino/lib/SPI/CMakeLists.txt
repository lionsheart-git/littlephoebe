generate_arduino_library(SPI_lib
	SRCS src/SPI.cpp
	HDRS src/SPI.h
)
target_include_directories(SPI_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
