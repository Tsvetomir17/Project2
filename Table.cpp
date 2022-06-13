#include "Table.h"

void Table::setTable()
{
    this->table = com.open("file.txt");   
}

const void Table::print() const
{
    int maxPossibleCols = 0;
    int cellsOnRow = 0, currCellsOnRow;
    for(std::size_t i = 0; i < table.size(); i++)
    {
        if(table[i].size() > maxPossibleCols) maxPossibleCols = table[i].size();
    }

    int* maxSizeForCol = new int[maxPossibleCols];
    for(int i = 0; i < maxPossibleCols; i++)
    {
        maxSizeForCol[i] = 0;
    }

    int index = 0;
    int currentCol = 0;
    for(std::size_t i = 0; i < table.size(); i++)
    {
        currentCol = 0;
        index = 0;
        currCellsOnRow = 0;

        for(std::size_t k = 0; k < table[i].size(); k++)
        {
            if(table[i][k] == ',' || k == table[i].size() - 1)
            {
                currCellsOnRow++;
                if(currentCol > maxSizeForCol[index]) maxSizeForCol[index] = currentCol;
                index++;
                currentCol = -1;
            }
            currentCol++;
        }
        if(currCellsOnRow > cellsOnRow) cellsOnRow = currCellsOnRow;
    }

    int wordCount = 0;
    int size = 0;
    for(std::size_t i = 0; i < table.size(); i++)
    {
        wordCount = 0;
        size = maxSizeForCol[wordCount];
        for(std::size_t j = 0; j < table[i].size(); j++)
        {
            if(table[i][j] == ',')
            {
                for(size; size >= 0; size--)
                {
                    std::cout << ' ';
                }

                std::cout << "|";
                size = maxSizeForCol[++wordCount];
            }
            else
            {
                size--;
                std::cout << table[i][j];
            }
        }

        for(wordCount; wordCount < cellsOnRow;)
        {
            for(size; size >= 0; size--)
            {
                std::cout << ' ';
            }
            std::cout << "|";
            size = maxSizeForCol[++wordCount];
        }
        std::cout << std::endl;
    }

    delete[] maxSizeForCol;
}

const std::vector<std::string> Table::getTable() const
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