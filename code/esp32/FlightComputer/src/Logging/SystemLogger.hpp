
#ifndef FLIGHTCOMPUTER_SYSTEMLOGGER_HPP
#define FLIGHTCOMPUTER_SYSTEMLOGGER_HPP

#include "Logger.hpp"

namespace Logging
{

#define FC_LOG_LEVEL_NONE       (0)
#define FC_LOG_LEVEL_ERROR      (1)
#define FC_LOG_LEVEL_WARN       (2)
#define FC_LOG_LEVEL_INFO       (3)
#define FC_LOG_LEVEL_DEBUG      (4)
#define FC_LOG_LEVEL_VERBOSE    (5)

#ifndef CONFIG_FC_LOG_DEFAULT_LEVEL
#define CONFIG_FC_LOG_DEFAULT_LEVEL FC_LOG_LEVEL_VERBOSE
#endif

#ifndef FC_CORE_DEBUG_LEVEL
#define FC_LOG_LEVEL CONFIG_FC_LOG_DEFAULT_LEVEL
#else
#define FC_LOG_LEVEL FC_CORE_DEBUG_LEVEL
#endif

#ifndef FC_LOG_PATH
#define FC_LOG_PATH "/log.log"
#endif

#ifndef SHORT_FC_LOG_FORMAT//(letter, format)
#define SHORT_FC_LOG_FORMAT(letter, format) format "\r\n"
#endif

#ifndef FC_LOG_FORMAT//(letter, format)
#define FC_LOG_FORMAT(letter, format) "[" #letter "][%s:%u] %s(): " format "\r\n", Logging::Logger::PathToFileName(__FILE__), __LINE__, __FUNCTION__
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_VERBOSE
#define fclog_v(format, ...) Logging::Logger::Log(FC_LOG_PATH, FC_LOG_FORMAT(V, format), ##__VA_ARGS__)
#else
#define fclog_v(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_DEBUG
#define fclog_d(format, ...) Logging::Logger::Log(FC_LOG_PATH, FC_LOG_FORMAT(D, format), ##__VA_ARGS__)
#else
#define fclog_d(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_INFO
#define fclog_i(format, ...) Logging::Logger::Log(FC_LOG_PATH, FC_LOG_FORMAT(I, format), ##__VA_ARGS__)
#else
#define fclog_i(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_WARN
#define fclog_w(format, ...) Logging::Logger::Log(FC_LOG_PATH, FC_LOG_FORMAT(W, format), ##__VA_ARGS__)
#else
#define fclog_w(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_ERROR
#define fclog_e(format, ...) Logging::Logger::Log(FC_LOG_PATH, FC_LOG_FORMAT(E, format), ##__VA_ARGS__)
#else
#define fclog_e(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_NONE
#define fclog_n(format, ...) Logging::Logger::Log(FC_LOG_PATH, FC_LOG_FORMAT(N, format), ##__VA_ARGS__)
#else
#define fclog_n(format, ...)
#endif

}


#endif //FLIGHTCOMPUTER_SYSTEMLOGGER_HPP
