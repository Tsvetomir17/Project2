#ifndef __CELL_HPP
#define __CELL_HPP
#include <iostream>
#include <cstring>

class Cell
{
private:
    std::string cell;
public:
    Cell() : cell("0") {} 

    std::string makeCell(const std::string text)
    {
        if(text[0] != '=')
        {
            return text;
        }

        for(std::size_t i = 1; i < text.size(); i++)
        {
            if(text[i] != ' ' || (text[i] < '0' && text[i] > '9') || text[i] != 'R' || text[i] != 'C'
                || text[i] != '*' || text[i] != '-' || text[i] != '+' || text[i] != '/')
            {
                    std::cout << "Invalid arguments" << std::endl;
                    return "ERROR";
            }

            if(text[i] == 'R')
            {
                std::string row;
                std::string col;
                for(i+1; text[i] != 'C'; i++)
                {
                    row.push_back(text[i]);
                }
                for(i+1; text[i] != ' '; i++)
                {
                    col.push_back(text[i]);
                }
                
                int result = checkCellType(row, col);
            }
        }
    }

    int checkCellType(const std::string row, const std::string col)
    {

    }

};

#endif