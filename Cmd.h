#ifndef __CMD_H
#define __CMD_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class CMD
{
private:
    bool isOpen;
    std::string filePath;

public:
    CMD();
    const void help() const;
    std::vector<std::vector<std::string>> open(const std::string file_path);
    void close();
    void save(const std::vector<std::vector<std::string>> currTable);
    void saveAs(const std::vector<std::vector<std::string>> currTable, const std::string newPath);
    int exit();



    const bool getIsOpen() const;
    const std::string getFilePath() const;
    void setIsOpen(const bool b);
    void setFilePath(std::string path);
};

#endif