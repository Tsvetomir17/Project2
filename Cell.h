#ifndef __CELL_HPP
#define __CELL_HPP
#include <iostream>
#include <string>

/// Този клас служи за удобство на дадени места, където е нужно клетката да бъде собствена променлива
class Cell
{
private:

    /// Символен низ, отговарящ на дадена клетка в таблицата
    std::string cell;

    /// Номерът на реда на клетката
    int row;

    /// Номерът на колоната на клетката
    int col;

public:

    /// Конструктор, който приема символен низ, отговарящ на клетката
    Cell(const std::string text);

    /// Мутатор за реда на клетката
    void setRow(const std::string text);

    /// Мутатор за колоната на клетката
    void setCol(const std::string text);

    /// Селектор за реда на клетката
    const int getRow() const;

    /// Мутатор за колоната на клетката
    const int getCol() const;
};

#endif