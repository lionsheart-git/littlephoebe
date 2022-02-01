generate_arduino_library(Arduino_BuiltIn_lib
	HDRS src/Arduino_BuiltIn.h
		SRCS src/Arduino_Builtin.cpp
)
target_include_directories(Arduino_BuiltIn_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
