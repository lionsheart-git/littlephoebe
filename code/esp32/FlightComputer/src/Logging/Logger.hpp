#ifndef FLIGHTCOMPUTER_LOGGER_HPP
#define FLIGHTCOMPUTER_LOGGER_HPP

namespace Logging
{

    class Logger
    {
    public:
        static int Log(const char *path, const char *format, ...);
        static char const *PathToFileName(const char *path);
    };

}

#endif //FLIGHTCOMPUTER_LOGGER_HPP
