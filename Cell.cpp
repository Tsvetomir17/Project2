#include "Cell.h"

Cell::Cell(const std::string text)
{
    this->setRow(text);
    this->setCol(text);
}

void Cell::setRow(const std::string text)
{
    int row = 0;
    int i = 1;
    while(text[i] != 'C')
    {
        row *= 10;
        row += text[i++] - '0';
    }

    this->row = row;
}

void Cell::setCol(const std::string text)
{
    int i = 2;
    while(text[i] != 'C')
    {
        i++;
    }
    i++;
    int col = 0;
    while(i < text.size())
    {
        col *= 10;
        col += text[i++] - '0';
    }

    this->col = col;
}

const int Cell::getRow() const
{
    return this->row;
}

const int Cell::getCol() const
{
    return this->col;
}