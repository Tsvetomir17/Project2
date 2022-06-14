#include "Table.h"

void Table::setCellTypes()
{
    std::string currentString;
    int dots, numbers, otherSymbols;
    for(std::size_t i = 0; i < this->table.size(); i++)
    {
        std::vector<std::size_t> vec;   
        for(std::size_t j = 0; j < this->table[i].size(); j++)
        {
            currentString = this->table[i][j];
            dots = 0; numbers = 0; otherSymbols = 0;
            for(std::size_t index = 0; index < currentString.size(); index++)
            {
                if(currentString[index] == '.')
                {
                    dots++;
                }
                else if(currentString[index] >= '0' && currentString[index] <= '9')
                {
                    numbers++;
                } 
                    
                else
                {
                    otherSymbols++;
                }
            }

            if(otherSymbols > 0 || dots > 1 || currentString.size() == 0)
            {
                vec.push_back((std::size_t)0);
            }
            else if(dots == 1)
            {
                vec.push_back((std::size_t)2);
            }
            else 
            {
                vec.push_back((std::size_t)1);
            }
        }
        this->tableForTypeOfTheCell.push_back(vec);
    }

    std::cout << "test" << std::endl;
        for(std::size_t i = 0; i < this->tableForTypeOfTheCell.size(); i++)
    {
        for(std::size_t j = 0; j < this->tableForTypeOfTheCell[i].size(); j++)
        {
            std::cout << this->tableForTypeOfTheCell[i][j] << ' ';
        }
        std::cout<<std::endl;
    }

}

const std::size_t Table::getTableCols() const
{
    std::size_t size = 0;
    for(std::size_t i = 0; i < this->table.size(); i++)
    {
        if(this->table[i].size() > size) size = this->table[i].size();
    }

    return size;
}

const std::vector<std::size_t> Table::getBiggestNumberOnEveryCol() const
{
    std::cout << "test3.1" << std::endl;
    std::vector<std::size_t> result;
    int cols = this->getTableCols();

    std::size_t* arr = new std::size_t[cols];
    for(std::size_t i = 0; i < cols; i++) arr[i] = 0;

    for(std::size_t i = 0; i < this->table.size(); i++)
    {
        for(std::size_t j = 0; j < this->table[i].size(); j++)
        {
            if(this->table[i][j].size() > arr[j])
            {
                arr[j] = this->table[i][j].size();
            }
        }
    }
    for(std::size_t i = 0; i < cols; i++)
    {
        result.push_back(arr[i]);
    }
 
    delete[] arr;
    return result;
}

void Table::setTable(const std::string file_path)
{
    table = com.open(file_path);
    std::cout << "test1" <<std::endl;
    this->setCellTypes();
}

const void Table::print() const
{
    std::size_t cols = this->getTableCols();
    std::vector<std::size_t> maxNumberOnEveryCol = this->getBiggestNumberOnEveryCol();
    std::size_t toTheMaxOnCurrentCell;
    char whitespace = ' ';
    std::string currCell;

    for(std::size_t i = 0; i < this->table.size(); i++)
    {
        std::cout << "|";
        for(std::size_t j = 0; j < cols; j++)
        {
            if(j >= table[i].size()) currCell = ""; 
            else currCell = this->table[i][j];
            std::cout << currCell;
            toTheMaxOnCurrentCell = maxNumberOnEveryCol[j] - currCell.size();
            for(int index = toTheMaxOnCurrentCell; index >= 0; index--)
            {
                std::cout << whitespace;
            }
            std::cout << "|";
        }
        std::cout << std::endl;
    }
}

const std::vector<std::vector<std::string>> Table::getTable() const
{
    return this->table;
}

void Table::save()
{
    this->com.save(this->getTable());
}

void Table::saveAs(const std::string filePathToSave)
{
    this->com.saveAs(this->getTable(), filePathToSave);
}

