#ifndef FLIGHTCOMPUTER_SDCARD_HPP
#define FLIGHTCOMPUTER_SDCARD_HPP

#include <FS.h>

class SDCard
{
public:
    SDCard() = delete;

    static void ListDir(fs::FS &fs, const char *dirname, unsigned char levels);
    static void CreateDir(FS &fs, const char *path);
    static void RemoveDir(FS &fs, const char *path);
    static void ReadFile(FS &fs, const char *path);
    static void WriteFile(FS &fs, const char *path, const char *message);
    static void AppendFile(FS &fs, const char *path, const char *message);
    static void RenameFile(FS &fs, const char *path1, const char *path2);
    static void DeleteFile(FS &fs, const char *path);
    static void TestFileIO(FS &fs, const char *path);
    static void Begin();

    static bool initSuccessful;
};


#endif //FLIGHTCOMPUTER_SDCARD_HPP
