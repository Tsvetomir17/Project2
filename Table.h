#ifndef __TABLE_H
#define __TABLE_H
#include "Cmd.h"
#include "Calculation.h"
#include "Cell.h"

/// Този клас се отнася за таблицата и промените по нея

class Table
{
private:

    /// Променлива за изпозлването на командите от "Cmd.h"
    CMD com;
    
    /// Текущата таблица
    std::vector<std::vector<std::string>> table;

    /// Таблица, която съдържа видът на дадените клетки в оригиналната таблица
    /// 0 - отговаря на символен низ
    /// 1 - отговаря на цяло число
    /// 2 - отговаря на дробно число 
    std::vector<std::vector<std::size_t>> tableForTypeOfTheCell;

    /// Функция, която при получаване на таблица от даден файл, попълва таблицата с типовете на клетките
    void setCellTypes();

    /// Фунцкия, която при промяна на дадена клетка, променя нейния тип в таблицата с типовете
    void setOneCellType(const std::size_t row, const std::size_t col);

    /// Селектор за броя колони в таблицата
    const std::size_t getTableCols() const;

    /// Селектор, който връща размера (броят символи) на най-голямата клетка във всяка една колона
    const std::vector<std::size_t> getMaxNumberOnEveryCol() const;

    /// Фунцкия, която проверява дали даден символен низ отговаря на изискванията за правилно въведена клетка
    bool isItCell(const std::string cell);

    /// Селектор, който връща стойността на дадена клетка
    const std::string getCellValue(const Cell& cell) const;

    /// Мутатор, който променя стойността на дадена клетка
    void setValue(const int row, const int col, const std::string value);

    /// Селектор за цялата таблица. Използва се при запазване на файл
    const std::vector<std::vector<std::string>> getTable() const;

    /// Функция, която принтира втората таблица с цел улесняване на работата на създателят на програмата
    const void printTable2() const;

public:

    /// Фунцкия, която създава таблиците при отваряне на файл
    void setTable(const std::string file_path);

    /// Функция, която принтира таблицата
    const void print() const;

    /// Функция, която запаметява текущата таблица в същия файл
    void save();

    /// Фунцкия, която запаметява текущата таблица на място, зададено като параметър
    void saveAs(const std::string filePathToSave);

    /// Функция, която затваря текущия файл
    void close();

    /// Функция, която приключва програмата
    int exit();

    /// Фунцкия, която извежда на екрана всички възможни команди за потребителя
    void help();

    /// Функция, която по подадена клетка в правилен формат позволява на потребителя да я промени
    void edit(const std::string cell);

};


#endif