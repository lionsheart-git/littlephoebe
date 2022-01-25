# This configuration file outlines some of the ways Arduino CMake
# can be used. For a detailed explenation of all the options please
# reade README.rst.

set(ARDUINO_DEFAULT_BOARD arduino) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyS3) # Default Port, when not specified

#====================================================================#
# Advanced static library exmaple
#====================================================================#
generate_arduino_library(blink_lib
        SRCS blink_lib.cpp
        HDRS blink_lib.hpp
        BOARD uno)

# Alternative: by variables
#set(blink_lib_SRCS blink_lib.cpp)
#set(blink_lib_HDRS blink_lib.h)
#set(blink_lib_BOARD uno)
#
#generate_arduino_library(blink_lib)




#====================================================================#
# Advanced firwmare example
#====================================================================#
generate_arduino_firmware(blink
        SRCS blink.cpp
        LIBS blink_lib
        BOARD uno)

# Alternative: by variables
#set(blink_SRCS blink.cpp)
#set(blink_LIBS blink_lib)
#set(blink_BOARD uno)
#
#generate_arduino_firmware(blink)

target_include_directories(blink_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})