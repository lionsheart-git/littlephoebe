#include "Logger.hpp"

#include <cstdarg>
#include <cstring>
#include <cstdio>

#include <esp_attr.h>
#include <malloc.h>
#include <SD.h>

#include "SDCard.hpp"

namespace Logging
{

    uart_t *uart0_ = uartBegin(0, 115200, SERIAL_8N1, 3, 1, 0, false);

    /**
     * Extracts only file from path given by __FILE__.
     *
     * @param path Path of the file.
     * @return The file name.
     */
    const char *IRAM_ATTR Logger::PathToFileName(const char *path)
    {
        size_t i = 0;
        size_t pos = 0;
        char *p = (char *) path;
        while (*p)
        {
            i++;
            if (*p == '/' || *p == '\\')
            {
                pos = i;
            }
            p++;
        }
        return path + pos;
    }

    /**
     * @brief Adaptation of log_printf from esp32-hal-log.h.
     *
     * @param format
     * @param ...
     * @return
     */
    int Logger::log(const char *path, const char *format, ...)
    {

        static char loc_buf[64];
        char *temp = loc_buf;
        int len;
        va_list arg;
        va_list copy;
        va_start(arg, format);
        va_copy(copy, arg);
        len = vsnprintf(NULL, 0, format, arg);
        va_end(copy);
        if (len >= sizeof(loc_buf))
        {
            temp = (char *) malloc(len + 1);
            if (temp == NULL)
            {
                return 0;
            }
        }
        vsnprintf(temp, len + 1, format, arg);

        // Write to Serial (UART)
        uartWriteBuf(uart0_, (uint8_t const *) temp, len);

        // Write to SD Card
        if (SDCard::initSuccessful)
        {
            SDCard::AppendFile(SD, path, temp);
        }

        va_end(arg);
        if (len >= sizeof(loc_buf))
        {
            free(temp);
        }
        return len;
    }

}
