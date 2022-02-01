generate_arduino_library(Sqlite_Micro_Logger_lib
	SRCS src/ulog_sqlite.c
	HDRS src/ulog_sqlite.h
)
target_include_directories(Sqlite_Micro_Logger_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
