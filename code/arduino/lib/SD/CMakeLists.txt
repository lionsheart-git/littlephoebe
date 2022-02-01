generate_arduino_library(SD_lib
		SRCS src/File.cpp src/SD.cpp src/utility/Sd2Card.cpp src/utility/SdFile.cpp src/utility/SdVolume.cpp
		HDRS src/SD.h src/utility/FatStructs.h src/utility/Sd2Card.h src/utility/Sd2PinMap.h src/utility/SdFat.h src/utility/SdFatmainpage.h src/utility/SdFatUtil.h src/utility/SdInfo.h
		LIBS SPI_lib
		)
target_include_directories(SD_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
