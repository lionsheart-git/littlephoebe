cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME RocketDataLogger)

set(${PROJECT_NAME}_BOARD uno)
# set(ARDUINO_CPU)

project(${PROJECT_NAME})
#        LANGUAGES C CXX
#        VERSION "0.1"
#        DESCRIPTION "Program for logging sensor data to sd card.")

### Main sketch file
# set(${PROJECT_NAME}_SKETCH src/arduino_sketch.ino)

### Add project directories into the build
add_subdirectory(src)

#### Additional settings for programmer. From programmers.txt
set(${PROJECT_NAME}_PROGRAMMER avrisp)
set(${PROJECT_NAME}_PORT /dev/ttyS3)
set(uno.upload.speed 9600)

### Additional settings to add non-standard or your own Arduino libraries.
# For this example (libs will contain additional arduino libraries)
# An Arduino library my_lib will contain files in libs/my_lib/: my_lib.h, my_lib.cpp + any other cpp files
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

# For nested library sources replace ${LIB_NAME} with library name for each library
# set(_RECURSE true)

## Verbose build process
# set(${PROJECT_NAME}_AFLAGS -v)

# Print available arduino boards
# print_board_list()

# Print available programmers
# print_programmer_list()
