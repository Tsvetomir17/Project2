#ifndef __TABLE_H
#define __TABLE_H
#include "Commands.h"

class Table
{
private:
    Commands com;
    std::vector<std::string> table;
    std::vector<std::string> tableOnlyForTypes;
    
public:
    void setTable();
    const std::vector<std::string> getTable() const;
    void save();
    void saveAs(const std::string filePathToSave);

    const void print() const;
    void edit(const short row, const short column, const std::string text);
    
};


#endif