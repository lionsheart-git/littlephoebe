generate_arduino_library(Ethernet2_lib
	SRCS src/Dhcp.cpp src/Dns.cpp src/Ethernet2.cpp src/EthernetClient.cpp src/EthernetServer.cpp src/EthernetUdp2.cpp src/Twitter.cpp src/utility/socket.cpp src/utility/w5500.cpp
	HDRS src/Dhcp.h src/Dns.h src/Ethernet2.h src/EthernetClient.h src/EthernetServer.h src/EthernetUdp2.h src/Twitter.h src/util.h src/utility/socket.h src/utility/util.h src/utility/w5500.h
)
target_include_directories(Ethernet2_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
