#include "SDCard.hpp"

#include <FS.h>
#include <SD.h>

#include "PinConfiguration.hpp"
#include "Logging/SystemLogger.hpp"

bool SDCard::initSuccessful = false;

//@todo Error handling if init not Successful

void SDCard::Begin()
{
    SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

    if (!SD.begin(SD_CS))
    {
        slog_e("Card Mount Failed");
        return;
    }

    uint8_t cardType = SD.cardType();

    if (cardType == CARD_NONE)
    {
        slog_e("No SD card attached");
        return;
    }

    initSuccessful = true;
}

void SDCard::ListDir(fs::FS &fs, const char *dirname, uint8_t levels)
{
    slog_d("Listing directory: %s", dirname);

    File root = fs.open(dirname);
    if (!root)
    {
        slog_e("Failed to open directory %s", dirname);
        return;
    }
    if (!root.isDirectory())
    {
        slog_e("Not a directory %s", dirname);
        return;
    }

    File file = root.openNextFile();
    while (file)
    {
        if (file.isDirectory())
        {
            slog_i("  DIR : ");
            slog_i("%s", file.name());
            if (levels)
            {
                ListDir(fs, file.name(), levels - 1);
            }
        } else
        {
            slog_i("  FILE: %s   SIZE: %u", file.name(), file.size());
        }
        file = root.openNextFile();
    }
}

void SDCard::CreateDir(fs::FS &fs, const char *path)
{
    slog_d("Creating Dir: %s", path);
    if (fs.mkdir(path))
    {
        slog_i("Dir %s created", path);
    } else
    {
        slog_e("mkdir %s failed", path);
    }
}

void SDCard::RemoveDir(fs::FS &fs, const char *path)
{
    slog_d("Removing Dir: %s.", path);
    if (fs.rmdir(path))
    {
        slog_i("Dir %s removed", path);
    } else
    {
        slog_e("rmdir %s failed", path);
    }
}

void SDCard::ReadFile(fs::FS &fs, const char *path)
{
    slog_d("Reading file: %s.", path);

    File file = fs.open(path);
    if (!file)
    {
        slog_e("Failed to open file %s for reading.", path);
        return;
    }

    while (file.available())
    {
        //@todo Why read from file? How to redirect output?
        Serial.write(file.read());
    }
    file.close();
}

void SDCard::WriteFile(fs::FS &fs, const char *path, const char *message)
{
//     slog_d("Writing file: %s", path);

    File file = fs.open(path, FILE_WRITE);
    if (!file)
    {
        slog_e("Failed to open file %s message %s for writing.", path, message);
        return;
    }
    if (file.print(message))
    {
//         slog_i("File %s written.", path);
    } else
    {
        slog_e("Write file %s message %s failed.", path, message);
    }
    file.close();
}

void SDCard::AppendFile(fs::FS &fs, const char *path, const char *message)
{
//    slog_d("Appending to file: %s", path);

    File file = fs.open(path, FILE_APPEND);
    if (!file)
    {
        slog_e("Failed to open file %s for appending %s.", path, message);
        return;
    }
    if (file.print(message))
    {
//        slog_i("Message %s appended to %s.", path, message);
    } else
    {
        slog_e("Append %s to %s failed.", message, path);
    }
    file.close();
}

void SDCard::RenameFile(fs::FS &fs, const char *path1, const char *path2)
{
    slog_d("Renaming file %s to %s.", path1, path2);
    if (fs.rename(path1, path2))
    {
        slog_i("File %s renamed to %s.", path1, path2);
    } else
    {
        slog_e("Rename %s to  %s failed.", path1, path2);
    }
}

void SDCard::DeleteFile(fs::FS &fs, const char *path)
{
    slog_d("Deleting file: %s.", path);
    if (fs.remove(path))
    {
        slog_i("File %s deleted.", path);
    } else
    {
        slog_e("Delete %s failed.", path);
    }
}

void SDCard::TestFileIO(fs::FS &fs, const char *path)
{
    File file = fs.open(path);
    static uint8_t buf[512];
    size_t len = 0;
    uint32_t start = millis();
    uint32_t end = start;
    if (file)
    {
        len = file.size();
        size_t flen = len;
        start = millis();
        while (len)
        {
            size_t toRead = len;
            if (toRead > 512)
            {
                toRead = 512;
            }
            file.read(buf, toRead);
            len -= toRead;
        }
        end = millis() - start;
        slog_i("%u bytes read for %u ms.", flen, end);
        file.close();
    } else
    {
        slog_e("Failed to open file %s for reading.", path);
    }


    file = fs.open(path, FILE_WRITE);
    if (!file)
    {
        slog_e("Failed to open file %s for writing.", path);
        return;
    }

    size_t i;
    start = millis();
    for (i = 0; i < 2048; i++)
    {
        file.write(buf, 512);
    }
    end = millis() - start;
    slog_i("%u bytes written for %u ms.", 2048 * 512, end);
    file.close();
}
