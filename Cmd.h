#ifndef __CMD_H
#define __CMD_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

/// Този клас се изпозлва за командите, относно файловете
///
/// Класът има две променливи, които следят дали в момента има отворен файл
/// и какво е неговото име

class CMD
{
private:

    /// Порменлива от тип 'bool' за да знаем дали в момента има отворен файл
    bool isOpen;

    /// Символен низ, който съдържа името на текущия отворен файл
    std::string filePath;

public:

    /// Конструктор по подразбиране, за да можем да използваме командите в Table.h
    CMD();

    /// Команда, извеждаща съдържанието на всички команди в програмата, включително кратко описание какво правят
    const void help() const;

    /// Команда, отваряща даден файл по зададен път към него
    std::vector<std::vector<std::string>> open(const std::string file_path);

    /// Команда, която затваря отворения файл
    void close();

    /// Команда, която запазва промените на текущия файл в същия файл
    void save(const std::vector<std::vector<std::string>> currTable);

    /// Команда, която запазва промените на текущия файл в друг файл, зададен като параметър
    void saveAs(const std::vector<std::vector<std::string>> currTable, const std::string newPath);
    
    /// Команда, която след като бъде извикана, приключва програмата, ако няма отворени файлове 
    int exit();

    /// Селектор, който дава информация дали в момента има отворен файл
    const bool getIsOpen() const;

    /// Селектор, който дава информация за името на отворения файл
    const std::string getFilePath() const;

    /// Мутатор за това дали в момента има отворен файл
    void setIsOpen(const bool b);

    /// Мутатор за името на отворения файл
    void setFilePath(std::string path);
};

#endif