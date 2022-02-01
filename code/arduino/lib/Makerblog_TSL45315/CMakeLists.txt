generate_arduino_library(Makerblog_TSL45315_lib
        HDRS Makerblog_TSL45315.h
        SRCS Makerblog_TSL45315.cpp
        )
target_include_directories(Makerblog_TSL45315_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})