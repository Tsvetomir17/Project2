#ifndef __TABLE_H
#define __TABLE_H
#include "Cmd.h"
#include "Calculation.h"
#include "Cell.h"

class Table
{
private:
    CMD com;
    std::vector<std::vector<std::string>> table;
    std::vector<std::vector<std::size_t>> tableForTypeOfTheCell; // 0 - string; 1 - int; 2 - double;
    void setCellTypes();
    void setOneCellType(const std::size_t row, const std::size_t col);
    const std::size_t getTableCols() const;
    const std::vector<std::size_t> getBiggestNumberOnEveryCol() const;
    bool isItCell(const std::string cell);
    const std::string getCellValue(const Cell& cell) const;
    void setValue(const int row, const int col, const std::string value);
    const std::vector<std::vector<std::string>> getTable() const;

public:
    void setTable(const std::string file_path);
    const void print() const;
    void save();
    void saveAs(const std::string filePathToSave);
    void close();
    int exit();
    void help();

    void edit(const std::string cell);

    const void printTable2() const;

    
};


#endif