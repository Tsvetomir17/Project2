#ifndef __ENGINE_H
#define __ENGINE_H

#include "Table.h"

class Engine
{
private:
    Table table;

    static std::size_t counter;
    Engine();

public:
    Engine(const Engine& other) = delete;
    Engine& operator = (const Engine& other) = delete;

    static Engine& getInstance();

    void programStart();
};


#endif