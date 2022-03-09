#ifndef FLIGHTCOMPUTER_DATALOGGER_HPP
#define FLIGHTCOMPUTER_DATALOGGER_HPP

#include "Logger.hpp"

#ifndef D_LOG_PATH
#define D_LOG_PATH "/datalog.log"
#endif

#ifndef SHORT_D_LOG_FORMAT//(letter, format)
#define SHORT_D_LOG_FORMAT(format) format
#endif

#ifndef SHORT_D_LOGN_FORMAT//(letter, format)
#define SHORT_D_LOGN_FORMAT(format) format "\r\n"
#endif

//@todo Implemented using of rtc time
#ifndef D_LOG_FORMAT//(letter, format)
#define D_LOG_FORMAT(format) "[%ld] " format, millis()
#endif

#ifndef D_LOGN_FORMAT//(letter, format)
#define D_LOGN_FORMAT(format) "[%ld] " #format "\r\n", millis()
#endif

#ifndef dlog
#define dlog(format, ...) Logging::Logger::Log(D_LOG_PATH, D_LOG_FORMAT(format), ##__VA_ARGS__)
#endif

#ifndef dlogn
#define dlogn(format, ...) Logging::Logger::Log(D_LOG_PATH, D_LOGN_FORMAT(format), ##__VA_ARGS__)
#endif

#ifndef dlogs
#define dlogs(format, ...) Logging::Logger::Log(D_LOG_PATH, SHORT_D_LOG_FORMAT(format), ##__VA_ARGS__)
#endif

#ifndef dlogsn
#define dlogsn(format, ...) Logging::Logger::Log(D_LOG_PATH, SHORT_D_LOGN_FORMAT(format), ##__VA_ARGS__)
#endif

#endif //FLIGHTCOMPUTER_DATALOGGER_HPP
