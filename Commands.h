#ifndef __COMMANDS_H
#define __COMMANDS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Commands
{
private:
    std::string filePath;
    std::string saveAsPath;
    bool isFileOpened = false;

public:
    const void help() const;
    std::vector<std::string> open(const std::string file_path);
    void close();
    void save(const std::vector<std::string> currTable);
    void saveAs(const std::vector<std::string> currTable, std::string str);
    int exit();

    void setFilePath(const std::string other);
    void setIsFileOpened(const bool trueOrFalse);
    const std::string getFilePath() const;
    const bool getIsFileOpened() const;

};
#endif