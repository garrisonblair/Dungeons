#ifndef MAP_CELL_H
#define MAP_CELL_H

#include <iostream>

using namespace std;

class Type
{
    bool blocked;

public:
    Type();
    Type(int);

    bool isBlocked() const;
};

class Cell
{
    bool flagged;
    Type type;

public:
    Cell();
    Cell(Type);

    bool isFlagged() const;

    void flag();
    void unFlag();
    void setType(int);

    Type getType() const;
};

#endif //MAP_CELL_H
