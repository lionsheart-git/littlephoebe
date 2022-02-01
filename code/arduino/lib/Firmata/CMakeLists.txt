generate_arduino_library(Firmata_lib
	SRCS Firmata.cpp FirmataMarshaller.cpp FirmataParser.cpp utility/BLEStream.cpp utility/BluefruitLE_SPI_Stream.cpp utility/EthernetClientStream.cpp utility/EthernetServerStream.cpp utility/SerialFirmata.cpp utility/WiFiStream.cpp
	HDRS Boards.h Firmata.h FirmataConstants.h FirmataDefines.h FirmataMarshaller.h FirmataParser.h utility/BLEStream.h utility/BluefruitLE_SPI_Stream.h utility/EthernetClientStream.h utility/EthernetServerStream.h utility/firmataDebug.h utility/FirmataFeature.h utility/SerialFirmata.h utility/WiFiClientStream.h utility/WiFiServerStream.h utility/WiFiStream.h
)
target_include_directories(Firmata_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
