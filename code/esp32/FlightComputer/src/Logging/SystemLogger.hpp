
#ifndef FLIGHTCOMPUTER_SYSTEMLOGGER_HPP
#define FLIGHTCOMPUTER_SYSTEMLOGGER_HPP

#include "Logger.hpp"

namespace Logging
{

#define S_LOG_LEVEL_NONE       (0)
#define S_LOG_LEVEL_ERROR      (1)
#define S_LOG_LEVEL_WARN       (2)
#define S_LOG_LEVEL_INFO       (3)
#define S_LOG_LEVEL_DEBUG      (4)
#define S_LOG_LEVEL_VERBOSE    (5)

#ifndef CONFIG_S_LOG_DEFAULT_LEVEL
#define CONFIG_S_LOG_DEFAULT_LEVEL S_LOG_LEVEL_VERBOSE
#endif

#ifndef S_CORE_DEBUG_LEVEL
#define S_LOG_LEVEL CONFIG_S_LOG_DEFAULT_LEVEL
#else
#define S_LOG_LEVEL S_CORE_DEBUG_LEVEL
#endif

#ifndef S_LOG_PATH
#define S_LOG_PATH "/systemlog.log"
#endif

#ifndef SHORT_S_LOG_FORMAT//(letter, format)
#define SHORT_S_LOG_FORMAT(letter, format) format "\r\n"
#endif

#ifndef S_LOG_FORMAT//(letter, format)
#define S_LOG_FORMAT(letter, format) "[" #letter "][%s:%u] %s(): " format "\r\n", Logging::Logger::PathToFileName(__FILE__), __LINE__, __FUNCTION__
#endif

#if S_LOG_LEVEL >= S_LOG_LEVEL_VERBOSE
#define slog_v(format, ...) Logging::Logger::Log(S_LOG_PATH, S_LOG_FORMAT(V, format), ##__VA_ARGS__)
#else
#define slog_v(format, ...)
#endif

#if S_LOG_LEVEL >= S_LOG_LEVEL_DEBUG
#define slog_d(format, ...) Logging::Logger::Log(S_LOG_PATH, S_LOG_FORMAT(D, format), ##__VA_ARGS__)
#else
#define slog_d(format, ...)
#endif

#if S_LOG_LEVEL >= S_LOG_LEVEL_INFO
#define slog_i(format, ...) Logging::Logger::Log(S_LOG_PATH, S_LOG_FORMAT(I, format), ##__VA_ARGS__)
#else
#define slog_i(format, ...)
#endif

#if S_LOG_LEVEL >= S_LOG_LEVEL_WARN
#define slog_w(format, ...) Logging::Logger::Log(S_LOG_PATH, S_LOG_FORMAT(W, format), ##__VA_ARGS__)
#else
#define slog_w(format, ...)
#endif

#if S_LOG_LEVEL >= S_LOG_LEVEL_ERROR
#define slog_e(format, ...) Logging::Logger::Log(S_LOG_PATH, S_LOG_FORMAT(E, format), ##__VA_ARGS__)
#else
#define slog_e(format, ...)
#endif

#if S_LOG_LEVEL >= S_LOG_LEVEL_NONE
#define slog_n(format, ...) Logging::Logger::Log(S_LOG_PATH, S_LOG_FORMAT(N, format), ##__VA_ARGS__)
#else
#define slog_n(format, ...)
#endif

}


#endif //FLIGHTCOMPUTER_SYSTEMLOGGER_HPP
