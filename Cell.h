#ifndef __CELL_HPP
#define __CELL_HPP
#include <iostream>
#include <string>

class Cell
{
private:
    std::string cell;
    int row;
    int col;

public:

    Cell(const std::string text);
    void setRow(const std::string text);

    void setCol(const std::string text);

    const int getRow() const;

    const int getCol() const;
};

#endif