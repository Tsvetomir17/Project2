#include "Commands.h"


const void Commands::help() const
{
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "open <file>       opens <file>" << std::endl;
    std::cout << "close             closes currently opened file" << std::endl;
    std::cout << "save              saves the currently open file" << std::endl;
    std::cout << "saveas            <file> saves the currently open file in <file>" << std::endl;
    std::cout << "help              prints this information" << std::endl;
    std::cout << "exit              exists the program" << std::endl;
}

std::vector<std::string> Commands::open(const std::string file_path)
{
    std::vector<std::string> tempV;
    this->setFilePath(file_path);
    this->setIsFileOpened(true);

    std::ifstream file(file_path);
    if(!file.is_open())
    {
        file.close();
        std::ofstream file(file_path);
        return tempV;
    }
    
    std::string str;
    while(std::getline(file,str))
    {
        tempV.push_back(str);
    }

    file.close();
    return tempV; 
}

void Commands::close()
{
    if(!getIsFileOpened())
    {
        std::cout << "There is not an opened file!";
        return;
    }
    else
    {
        std::cout << "Successfully closed //" << std::endl;
        this->setIsFileOpened(false);
    }
}

void Commands::save(const std::vector<std::string> currVector)
{
    std::ofstream file(getFilePath(), std::ios::trunc);
    if(!file.is_open())
    {
        std::cout << "ERROR" << std::endl;
        return;
    }

    std::string str;
    for(std::size_t i = 0; i < currVector.size(); i++)
    {
        file << currVector[i];
        file << '\n';
    }

    file.close();
}

void Commands::saveAs(const std::vector<std::string> currVector, const std::string str)
{
    std::string tmp = this->getFilePath();
    this->setFilePath(str);
    this->save(currVector);
    this->setFilePath(tmp);
}

int Commands::exit()
{
    if(getIsFileOpened())
    {
        std::cout << "You have an open file with unsaved changes, please select close or save first." << std::endl;
    }
    else
    {
        return 0;
    }
}

void Commands::setFilePath(const std::string other)
{
    this->filePath = other;
}

void Commands::setIsFileOpened(const bool trueOrFalse)
{
    this->isFileOpened = trueOrFalse;
}

const std::string Commands::getFilePath() const
{
    return this->filePath;
}

const bool Commands::getIsFileOpened() const
{
    return this->isFileOpened;
}