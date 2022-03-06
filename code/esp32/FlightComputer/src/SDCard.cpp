#include "SDCard.hpp"

#include <FS.h>
#include <SD.h>

#include "PinConfiguration.hpp"
#include "Logger.hpp"

bool SDCard::initSuccessful = false;

void SDCard::Begin() {
    SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

    if (!SD.begin(SD_CS))
    {
        fclog_e("Card Mount Failed");
        return;
    }

    uint8_t cardType = SD.cardType();

    if (cardType == CARD_NONE)
    {
        fclog_e("No SD card attached");
        return;
    }

    initSuccessful = true;
}

void SDCard::ListDir(fs::FS &fs, const char *dirname, uint8_t levels)
{
    fclog_d("Listing directory: %s", dirname);

    File root = fs.open(dirname);
    if (!root)
    {
        fclog_e("Failed to open directory %s", dirname);
        return;
    }
    if (!root.isDirectory())
    {
        fclog_e("Not a directory %s", dirname);
        return;
    }

    File file = root.openNextFile();
    while (file)
    {
        if (file.isDirectory())
        {
            fclog_i("  DIR : ");
            fclog_i("%s", file.name());
            if (levels)
            {
                ListDir(fs, file.name(), levels - 1);
            }
        } else
        {
            fclog_i("  FILE: %s   SIZE: %u", file.name(), file.size());
        }
        file = root.openNextFile();
    }
}

void SDCard::CreateDir(fs::FS &fs, const char *path)
{
    fclog_d("Creating Dir: %s", path);
    if (fs.mkdir(path))
    {
        fclog_i("Dir %s created", path);
    } else
    {
        fclog_e("mkdir %s failed", path);
    }
}

void SDCard::RemoveDir(fs::FS &fs, const char *path)
{
    fclog_d("Removing Dir: %s.", path);
    if (fs.rmdir(path))
    {
        fclog_i("Dir %s removed", path);
    } else
    {
        fclog_e("rmdir %s failed", path);
    }
}

void SDCard::ReadFile(fs::FS &fs, const char *path)
{
    fclog_d("Reading file: %s.", path);

    File file = fs.open(path);
    if (!file)
    {
        fclog_e("Failed to open file %s for reading.", path);
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
    fclog_d("Writing file: %s", path);

    File file = fs.open(path, FILE_WRITE);
    if (!file)
    {
        fclog_e("Failed to open file %s message %s for writing.", path, message);
        return;
    }
    if (file.print(message))
    {
        fclog_i("File %s written.", path);
    } else
    {
        fclog_e("Write file %s message %s failed.", path, message);
    }
    file.close();
}

void SDCard::AppendFile(fs::FS &fs, const char *path, const char *message)
{
    fclog_d("Appending to file: %s", path);

    File file = fs.open(path, FILE_APPEND);
    if (!file)
    {
        fclog_e("Failed to open file %s for appending %s.", path, message);
        return;
    }
    if (file.print(message))
    {
        fclog_i("Message %s appended to %s.", path, message);
    } else
    {
        fclog_e("Append %s to %s failed.", message, path);
    }
    file.close();
}

void SDCard::RenameFile(fs::FS &fs, const char *path1, const char *path2)
{
    fclog_d("Renaming file %s to %s.", path1, path2);
    if (fs.rename(path1, path2))
    {
        fclog_i("File %s renamed to %s.", path1, path2);
    } else
    {
        fclog_e("Rename %s to  %s failed.", path1, path2);
    }
}

void SDCard::DeleteFile(fs::FS &fs, const char *path)
{
    fclog_d("Deleting file: %s.", path);
    if (fs.remove(path))
    {
        fclog_i("File %s deleted.", path);
    } else
    {
        fclog_e("Delete %s failed.", path);
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
        fclog_i("%u bytes read for %u ms.", flen, end);
        file.close();
    } else
    {
        fclog_e("Failed to open file %s for reading.", path);
    }


    file = fs.open(path, FILE_WRITE);
    if (!file)
    {
        fclog_e("Failed to open file %s for writing.", path);
        return;
    }

    size_t i;
    start = millis();
    for (i = 0; i < 2048; i++)
    {
        file.write(buf, 512);
    }
    end = millis() - start;
    fclog_i("%u bytes written for %u ms.", 2048 * 512, end);
    file.close();
}

SDCard::~SDCard()
{

}
