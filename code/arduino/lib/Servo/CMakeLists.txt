generate_arduino_library(Servo_lib
	SRCS src/avr/Servo.cpp src/mbed/Servo.cpp src/megaavr/Servo.cpp src/nrf52/Servo.cpp src/sam/Servo.cpp src/samd/Servo.cpp src/stm32f4/Servo.cpp
	HDRS src/Servo.h src/avr/ServoTimers.h src/mbed/ServoTimers.h src/megaavr/ServoTimers.h src/nrf52/ServoTimers.h src/sam/ServoTimers.h src/samd/ServoTimers.h src/stm32f4/ServoTimers.h
)
target_include_directories(Servo_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
