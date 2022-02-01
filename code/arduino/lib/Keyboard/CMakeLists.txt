generate_arduino_library(Keyboard_lib
	SRCS src/Keyboard.cpp src/KeyboardLayout_de_DE.cpp src/KeyboardLayout_en_US.cpp src/KeyboardLayout_es_ES.cpp src/KeyboardLayout_fr_FR.cpp src/KeyboardLayout_it_IT.cpp
	HDRS src/Keyboard.h src/KeyboardLayout.h
)
target_include_directories(Keyboard_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
