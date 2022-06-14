#ifndef __TABLE_H
#define __TABLE_H
#include "Cmd.h"

class Table
{
private:
    CMD com;
    std::vector<std::vector<std::string>> table;
    std::vector<std::vector<std::size_t>> tableForTypeOfTheCell; // 0 - string; 1 - int; 2 - double;
    void setCellTypes();
    const std::size_t getTableCols() const;
    const std::vector<std::size_t> getBiggestNumberOnEveryCol() const;

public:
    void setTable(const std::string file_path);
    const std::vector<std::vector<std::string>> getTable() const;

    void save();
    void saveAs(const std::string filePathToSave);

    const void print() const;
    void edit(const short row, const short column, const std::string text);
    
};


#endif