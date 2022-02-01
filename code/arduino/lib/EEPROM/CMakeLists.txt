generate_arduino_library(EEPROM_lib
	HDRS src/EEPROM.h
		SRCS src/EEPROM.cpp
)
target_include_directories(EEPROM_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
