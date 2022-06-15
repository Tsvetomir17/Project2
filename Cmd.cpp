#include "Cmd.h"

CMD::CMD() : isOpen(false), filePath("") {}

const void CMD::help() const
{
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "open <file>       opens <file>" << std::endl;
    std::cout << "close             closes currently opened file" << std::endl;
    std::cout << "save              saves the currently open file" << std::endl;
    std::cout << "saveas            <file> saves the currently open file in <file>" << std::endl;
    std::cout << "help              prints this information" << std::endl;
    std::cout << "exit              exists the program" << std::endl;
}

std::vector<std::vector<std::string>> CMD::open(const std::string file_path)
{
    std::vector<std::vector<std::string>> currVector;
    std::vector<std::vector<std::string>> randomVector;
    std::vector<std::string> randomVec;
    randomVec.push_back(" ,");
    randomVector.push_back(randomVec);

    std::ifstream file(file_path);
    this->setFilePath(file_path);
    this->setIsOpen(true);

    if(!file.is_open())
    {
        file.close();
        std::ofstream file(file_path);
        file.close();
        return randomVector;
    }

    std::string str;
    char symbol = ',';
    std::string cell;
    while(std::getline(file, str))
    {
        std::vector<std::string> vstr;
        for(std::size_t i = 0; i < str.size(); i++)
        {
            if(str[i] == symbol)
            {
                vstr.push_back(cell);
                cell.clear();
            }
            else if(i == str.size() - 1)
            {
                cell.push_back(str[i]);
                vstr.push_back(cell);
                cell.clear();
            }
            else
            {
                cell.push_back(str[i]);
            }
        }
        currVector.push_back(vstr);
    }

    file.close();

    return currVector;
}

void CMD::close()
{
    if(!getIsOpen())
    {
        std::cout << "There is not an opened file!";
        return;
    }

    std::cout << "Successfully closed!" << std::endl;
    this->setIsOpen(false);
    this->setFilePath("");
}

void CMD::save(const std::vector<std::vector<std::string>> currVector)
{
    std::ofstream file(getFilePath(), std::ios::trunc);
    if(!file.is_open())
    {
        std::cout << "ERROR" << std::endl;
        return;
    }

    for(std::size_t i = 0; i < currVector.size(); i++)
    {
        for(std::size_t k = 0; k < currVector[i].size(); k++)
        {
            file << currVector[i][k];
            file << ',';
        }
        file << '\n';
    }

    file.close();
}

void CMD::saveAs(const std::vector<std::vector<std::string>> currVector, const std::string newPath)
{
    std::string tmpPath = this->getFilePath();
    this->setFilePath(newPath);
    this->save(currVector);
    this->setFilePath(tmpPath);
}

int CMD::exit()
{
    if(getIsOpen())
    {
        std::cout << "You have an opened file , please close it first." << std::endl;
        return 1;
    }
    else
    {
        return 0;
    }
}


const bool CMD::getIsOpen() const
{
    return this->isOpen;
}
const std::string CMD::getFilePath() const
{
    return this->filePath;
}

void CMD::setIsOpen(const bool b)
{
    this->isOpen = b;
}
void CMD::setFilePath(const std::string path)
{
    this->filePath = path;
}