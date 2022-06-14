#include "Engine.h"

std::size_t Engine::counter = 0;

Engine::Engine() {}

Engine& Engine::getInstance()
{
    static Engine obj;
    return obj;
}

void Engine::programStart()
{
    std::string choice;
    int programEnd = 1;
    bool changes = false;

    std::cout << "Hello!" << std::endl;
    std::cout << "Please enter your command! If you do not know what to type, you can use 'help'" << std::endl;
    while(programEnd == 1)
    {
        std::getline(std::cin, choice);
        if(choice.compare("help") == 0)
        {
            this->table.help();
        }
        else if(choice.compare(0,5,"open ") == 0)
        {
            std::string path;
            path.append(&choice[5]);
            this->table.setTable(path);
            changes = false;
        }
        else if(choice.compare("save") == 0)
        {
            this->table.save();
            changes = false;
        }
        else if(choice.compare(0,7,"saveas ") == 0)
        {
            std::string path;
            path.append(&choice[7]);
            this->table.saveAs(path);
            changes = false;
        }
        else if(choice.compare("close") == 0)
        {
            if(changes)
            {
                std::cout << "Your changes will be lost if you do not save them, do you want to continue:" << std::endl;
                std::cout << "Y - yes" << std::endl;
                std::cout << "Anything else - no" << std::endl;
                std::string newchoice;
                std::getline(std::cin, newchoice);
                if(newchoice.compare("Y") == 0)
                {
                    this->table.close();
                }
            }
            else
            {
                this->table.close();
            }
        }
        else if(choice.compare("exit") == 0)
        {
            programEnd = this->table.exit();
        }
        else if(choice.compare(0,5,"edit ") == 0)
        {
            std::string path;
            path.append(&choice[5]);
            changes = true;
            this->table.edit(path);
        }
        else if(choice.compare("print") == 0)
        {
            this->table.print();
        }
        else
        {
            std::cout << "Invalid command! Try again please! If you need help, you can use 'help'!" << std::endl;
        }
    }
}