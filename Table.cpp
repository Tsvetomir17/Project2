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

void Table::edit(const std::string cell)
{
    if(!isItCell(cell))
    {
        std::cout << "Bad input" << std::endl;
        return;
    }
    
    Cell c(cell);

    std::string toDo;
    std::cout << "You have chosen to change cell R" << c.getRow() << "C" << c.getCol() << std::endl;
    std::cout << "R" << c.getRow() << "C" << c.getCol() << ": "<< std::endl;

    int row = c.getRow() - 1;
    int col = c.getCol() - 1;

    std::getline(std::cin, toDo);
    std::string toCalculate;
    std::string toCheck;
    int index = 0;
    if(toDo[index] == '=')
    {
        index++;
        char whitespace = ' ';
        for(index; index < toDo.size(); index++)
        {
            if((toDo[index] == whitespace ) || (toDo[index] >= '0' && toDo[index] <= '9') ||
                toDo[index] == '+' || toDo[index] == '-' || toDo[index] == '*' || toDo[index] == '/' || 
                toDo[index] == '^')
            {
                toCalculate.push_back(toDo[index]);
                continue;
            }

            else if(toDo[index] == 'R')
            {
                toCheck.clear();
                while(toDo[index] != whitespace && toDo[index] != '+' && toDo[index] != '-' && toDo[index] != '*' &&
                     toDo[index] != '/' && toDo[index] != '^' && index < toDo.size())
                {
                    toCheck.push_back(toDo[index]);
                    index++;
                }
                index--;
                if(isItCell(toCheck))
                {
                    Cell temp(toCheck);
                    std::string value = getCellValue(temp);
                    toCalculate.append(value);
                }
            }
            else
            {
                std::cout << "bad input" << std::endl;
                return;
            }
        }
    }
    else
    {
        if(isItCell(toDo))
        {
            Cell c(toDo);
            std::cout << c.getCol() << c.getRow() << std::endl;
            toCalculate.append(getCellValue(c));
        }
        else
        {
            this->setValue(row, col, toDo);
            return;
        }
    }

    this->setValue(row, col, calculation(toCalculate));
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

bool Table::isItCell(const std::string cell)
{
    if(cell[0] != 'R')
    {
        return false;
    } 

    bool numberBetweenRandC = false, numberAferC = false;
    int row = 0, col = 0;
    std::size_t i = 1;
    while(cell[i] != 'C' && i < cell.size())
    {
        if(cell[i] < '0' || cell[i] > '9')
        {
            return false;
        }

        numberBetweenRandC = true;
        row *= 10;
        row += cell[i++] - '0';
    }

    i++;
    if(!numberBetweenRandC)
    {
        return false;
    }

    while(i < cell.size())
    {
        if(cell[i] < '0' || cell[i] > '9')
        {
            return false;
        }
        numberAferC = true;
        col *= 10;
        col += cell[i++] - '0';
    }

    if(!numberAferC)
    {
        return false;
    }

    return true;
}

const std::string Table::getCellValue(const Cell& cell) const
{
    if(this->tableForTypeOfTheCell[cell.getRow() - 1][cell.getCol() - 1] > 0)
    {
        return this->table[cell.getRow() - 1][cell.getCol() - 1];
    }

    return "0";
}

void Table::setValue(const int row, const int col, const std::string value)
{
    int tableCols = this->getTableCols();
    int tableRows = this->table.size();

    if(row >= tableRows && col < tableCols)
    {
        int diff = (row+1) - tableRows;
        std::vector<std::string> vec;
        std::vector<std::size_t> vec2;

        for(int i = 0; i < diff; i++)
        {
            vec.clear();
            vec2.clear();
            for(int j = 0; j < tableCols; j++)
            {
                vec.push_back("");
                vec2.push_back(0);
            }
            this->table.push_back(vec);
            this->tableForTypeOfTheCell.push_back(vec2);
        }
    }
    else if(row < tableRows && col >= tableCols)
    {
        int diff = (col+1) - tableCols;
        for(int i = 0; i < table.size(); i++)
        {
            for(int j = 0; j < diff; j++)
            {
                table[i].push_back("");
                tableForTypeOfTheCell[i].push_back(0);
            }
        }
    }
    else if(row >= tableRows && col >= tableCols)
    {
        int diffR = (row+1) - tableRows;
        int diffC = (col+1) - tableCols;

        for(int i = 0; i < table.size(); i++)
        {
            for(int j = 0; j < diffC; j++)
            {
                table[i].push_back("");
                tableForTypeOfTheCell[i].push_back(0);
            }
        }   

        std::vector<std::string> vec;
        std::vector<std::size_t> vec2;
        for(int i = 0; i < diffR; i++)
        {
            vec.clear();
            vec2.clear();
            for(int j = 0; j < col+1; j++)
            {
                vec.push_back("");
                vec2.push_back(0);
            }
            this->table.push_back(vec);
            this->tableForTypeOfTheCell.push_back(vec2);
        }
    }

    this->table[row][col] = value;
    setOneCellType(row,col);
}

