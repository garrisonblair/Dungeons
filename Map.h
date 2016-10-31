#ifndef MAP_MAP_H
#define MAP_MAP_H

#include "Cell.h"

class Map
{
    string name;
    string description;
    int width, length;
    int startX, startY;
    int endX, endY;

    Cell ** grid;

public:
    Map();
    Map(int, int);

    string getName() const;
    string getDescription() const;
    Cell getCell(int, int);

    void setName(string);
    void setDescription(string);
    void setStart(int, int);
    void setEnd(int, int);
    void setCell(int, int, char);
    void clearFlags();

    bool checkPath(int, int);
    bool test();

    void print();
};

#endif //MAP_MAP_H