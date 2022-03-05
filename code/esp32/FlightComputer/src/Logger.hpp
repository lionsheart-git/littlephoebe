
#ifndef FLIGHTCOMPUTER_LOGGER_HPP
#define FLIGHTCOMPUTER_LOGGER_HPP

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

#ifndef CONFIG_FC_LOG_COLORS
#define CONFIG_FC_LOG_COLORS 0
#endif

#ifndef SHORT_FC_LOG_FORMAT//(letter, format)
#define SHORT_FC_LOG_FORMAT(letter, format)  FC_LOG_COLOR_ ## letter format FC_LOG_RESET_COLOR "\r\n"
#endif

#ifndef FC_LOG_FORMAT//(letter, format)
#define FC_LOG_FORMAT(letter, format)  FC_LOG_COLOR_ ## letter "[" #letter "][%s:%u] %s(): " format FC_LOG_RESET_COLOR "\r\n", Logger::PathToFileName(__FILE__), __LINE__, __FUNCTION__
#endif

#if CONFIG_FC_LOG_COLORS
#define FC_LOG_COLOR_BLACK   "30"
#define FC_LOG_COLOR_RED     "31" //ERROR
#define FC_LOG_COLOR_GREEN   "32" //INFO
#define FC_LOG_COLOR_YELLOW  "33" //WARNING
#define FC_LOG_COLOR_BLUE    "34"
#define FC_LOG_COLOR_MAGENTA "35"
#define FC_LOG_COLOR_CYAN    "36" //DEBUG
#define FC_LOG_COLOR_GRAY    "37" //VERBOSE
#define FC_LOG_COLOR_WHITE   "38"

#define FC_LOG_COLOR(COLOR)  "\033[0;" COLOR "m"
#define FC_LOG_BOLD(COLOR)   "\033[1;" COLOR "m"
#define FC_LOG_RESET_COLOR   "\033[0m"

#define FC_LOG_COLOR_E       FC_LOG_COLOR(FC_LOG_COLOR_RED)
#define FC_LOG_COLOR_W       FC_LOG_COLOR(FC_LOG_COLOR_YELLOW)
#define FC_LOG_COLOR_I       FC_LOG_COLOR(FC_LOG_COLOR_GREEN)
#define FC_LOG_COLOR_D       FC_LOG_COLOR(FC_LOG_COLOR_CYAN)
#define FC_LOG_COLOR_V       FC_LOG_COLOR(FC_LOG_COLOR_GRAY)
#else
#define FC_LOG_COLOR_E
#define FC_LOG_COLOR_W
#define FC_LOG_COLOR_I
#define FC_LOG_COLOR_D
#define FC_LOG_COLOR_V
#define FC_LOG_RESET_COLOR
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_VERBOSE
#define fclog_v(format, ...) Logger::log(FC_LOG_FORMAT(V, format), ##__VA_ARGS__)
#else
#define fclog_v(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_DEBUG
#define fclog_d(format, ...) Logger::log(FC_LOG_FORMAT(D, format), ##__VA_ARGS__)
#else
#define fclog_d(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_INFO
#define fclog_i(format, ...) Logger::log(FC_LOG_FORMAT(I, format), ##__VA_ARGS__)
#else
#define fclog_i(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_WARN
#define fclog_w(format, ...) Logger::log(FC_LOG_FORMAT(W, format), ##__VA_ARGS__)
#else
#define fclog_w(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_ERROR
#define fclog_e(format, ...) Logger::log(FC_LOG_FORMAT(E, format), ##__VA_ARGS__)
#else
#define fclog_e(format, ...)
#endif

#if FC_LOG_LEVEL >= FC_LOG_LEVEL_NONE
#define fclog_n(format, ...) Logger::log(FC_LOG_FORMAT(N, format), ##__VA_ARGS__)
#else
#define fclog_n(format, ...)
#endif

#include <esp32-hal-uart.h>

class Logger
{
public:
    static int log(const char *format, ...);
    static char const * PathToFileName(const char * path);
};


#endif //FLIGHTCOMPUTER_LOGGER_HPP
