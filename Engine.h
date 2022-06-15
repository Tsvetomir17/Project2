#ifndef __ENGINE_H
#define __ENGINE_H

#include "Table.h"

/// Този клас се използва за работата на цялата програма

class Engine
{
private:

    /// Таблицата, която е отворена в паметта
    Table table;

    /// Променлива за синглетон
    static std::size_t counter;

    /// Конструктор по подразбиране
    Engine();

public:

    /// Нямаме конструктор за копиране
    Engine(const Engine& other) = delete;

    /// Нямаме оператор '='
    Engine& operator = (const Engine& other) = delete;

    /// Селектор за инстанцията
    static Engine& getInstance();

    /// Функция за стартиране на програмата
    void programStart();
};


#endif