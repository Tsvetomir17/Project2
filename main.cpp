#include "Cmd.h"
#include "Table.h"

int main()
{
    Table table;
    table.setTable("file.txt");
    table.print();
    //table.save();
}