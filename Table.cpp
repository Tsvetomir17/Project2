#include "Table.h"

void Table::setCellTypes()
{
    std::string currentString;
    std::size_t cols = this->getTableCols();
    int dots, numbers, otherSymbols, counterForWhitespacesAndNumbers;
    for(std::size_t i = 0; i < this->table.size(); i++)
    {
        std::vector<std::size_t> vec;   
        for(std::size_t j = 0; j < this->table[i].size(); j++)
        {
            currentString = this->table[i][j];
            dots = 0; numbers = 0; otherSymbols = 0; counterForWhitespacesAndNumbers = -1;
            for(std::size_t index = 0; index < currentString.size(); index++)
            {
                if(currentString[index] == '.')
                {
                    dots++;
                }
                else if(currentString[index] >= '0' && currentString[index] <= '9')
                {
                    if(counterForWhitespacesAndNumbers == -1) counterForWhitespacesAndNumbers++;
                    if(counterForWhitespacesAndNumbers == 1) counterForWhitespacesAndNumbers++;
                    numbers++;
                } 
                else if(currentString[index] == ' ')
                {
                    if(counterForWhitespacesAndNumbers == 0) counterForWhitespacesAndNumbers++;
                    
                }
                else
                {
                    otherSymbols++;
                }
            }

            if(otherSymbols > 0 || dots > 1 || currentString.size() == 0 || counterForWhitespacesAndNumbers > 1 || counterForWhitespacesAndNumbers == -1)
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

        for(std::size_t index = vec.size(); index < cols; index++)
        {
            vec.push_back((std::size_t)0);
        }
        this->tableForTypeOfTheCell.push_back(vec);
    }
}

void Table::setOneCellType(const std::size_t row, const std::size_t col)
{
    std::string cell = this->table[row][col];
    int dots = 0, numbers = 0, otherSymbols = 0, counterForWhitespacesAndNumbers=-1;
    for(std::size_t index = 0; index < cell.size(); index++)
    {
        if(cell[index] == '.')
        {
            dots++;
        }
        else if(cell[index] >= '0' && cell[index] <= '9')
        {
            if(counterForWhitespacesAndNumbers == -1) counterForWhitespacesAndNumbers++;
            if(counterForWhitespacesAndNumbers == 1) counterForWhitespacesAndNumbers++;
            numbers++;
        }
        else if(cell[index] == ' ')
        {
            if(counterForWhitespacesAndNumbers == 0) counterForWhitespacesAndNumbers++;

        }
        else
        {
            otherSymbols++;
        }
    }

    if(otherSymbols > 0 || dots > 1 || cell.size() == 0 || counterForWhitespacesAndNumbers > 1 || counterForWhitespacesAndNumbers == -1)
    {
        this->tableForTypeOfTheCell[row][col] = 0;
    }
    else if(dots == 1)
    {
        this->tableForTypeOfTheCell[row][col] = 2;
    }
    else 
    {
        this->tableForTypeOfTheCell[row][col] = 1;
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
    if(com.getIsOpen())
    {
        std::cout << "Opened file, do you want to save it before u proceed" << std::endl;
        std::cout << "Y - yes" << std::endl << "Anything else - no" << std::endl;
        std::string choice;
        std::cin >> choice;
        if(choice.compare("Y") == 0)
        {
            std::cout << "File saved" << std::endl;
            this->save();
        }
        this->close();
    }
    table = com.open(file_path);
    std::size_t cols = this->getTableCols();
    int diff;

    for(std::size_t i = 0; i < table.size(); i++)
    {
        diff = cols - table[i].size();
        for(diff; diff > 0; diff--)
        {
            table[i].push_back(" ");
        }
    }
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

void Table::edit(const std::size_t row, const std::size_t col, const std::string text)
{
    std::size_t r = row;
    std::size_t c = col;
    r--;
    c--;

    if(text[0] != '=')
    {
        this->table[r][c] = text;
        this->setOneCellType(r,c);
    }
    else
    {
        this->table[r][c] = text;
        this->setOneCellType(r,c);
    }
}

void Table::save()
{
    this->com.save(this->getTable());
}

void Table::saveAs(const std::string filePathToSave)
{
    this->com.saveAs(this->getTable(), filePathToSave);
}

void Table::close()
{
    this->com.close();
}

int Table::exit()
{
    return this->com.exit();
}

const void Table::printTable2() const
{
    for(std::size_t i = 0; i < this->tableForTypeOfTheCell.size(); i++)
    {
        for(std::size_t j = 0; j < this->tableForTypeOfTheCell[i].size(); j++)
        {
            std::cout << this->tableForTypeOfTheCell[i][j]<< ' ';
        }
        std::cout <<'\n';
    }
}

void Table::help()
{
    this->com.help();
}