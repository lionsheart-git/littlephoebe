generate_arduino_library(HDC100X_lib
        HDRS HDC100X.h
        SRCS HDC100X.cpp
        )
target_include_directories(HDC100X_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
