#include "Map.h"

Map::Map()
{
    name = "Default Map";
    description = "10x10";
    width = 10;
    length = 10;
    startX = 0;
    startY = 0;
    endX = 10;
    endY = 10;

    grid = new Cell*[length]();
    for (unsigned int i = 0; i < length; i++)
        grid[i] = new Cell[width];
}

Map::Map(int x, int y)
{
    name = "Default Map";
    description = to_string(x) + "x" + to_string(y);
    width = x;
    length = y;

    grid = new Cell*[length]();
    for (unsigned int i = 0; i < length; i++)
        grid[i] = new Cell[width];
}

string Map::getName() const { return name; }
string Map::getDescription() const { return description; }
Cell Map::getCell(int x, int y) { return grid[x][y]; }

void Map::setName(string n)
{
    name = n;
}

void Map::setDescription(string d)
{
    description = d;
}

void Map::setStart(int x, int y)
{
    startX = x;
    startY = y;
}

void Map::setEnd(int x, int y)
{
    endX = x;
    endY = y;
}

void Map::setCell(int x, int y, int c)
{
    grid[x][y].setType(c);
}

void Map::clearFlags()
{
    for (unsigned int i = 0; i < length; i++)
        for (unsigned int j = 0; j < width; j++)
            if (grid[i][j].isFlagged()) grid[i][j].unFlag();
}

bool Map::checkPath(int x, int y)
{
    grid[x][y].flag();
    if ((x == endX) && (y == endY)) return true;
    else {
        if (y + 1 < length)
            if (!(grid[x][y + 1].isFlagged()) && !(grid[x][y + 1].getType().isBlocked()))
                if (checkPath(x, y + 1)) return true;
        if (x + 1 < width)
            if (!(grid[x + 1][y].isFlagged()) && !(grid[x + 1][y].getType().isBlocked()))
                if (checkPath(x + 1, y)) return true;
        if (x - 1 >= 0)
            if (!(grid[x - 1][y].isFlagged()) && !(grid[x - 1][y].getType().isBlocked()))
                if (checkPath(x - 1, y)) return true;
        if (y - 1 >= 0)
            if (!(grid[x][y - 1].isFlagged()) && !(grid[x][y - 1].getType().isBlocked()))
                if (checkPath(x, y - 1)) return true;
    }
    return false;
}


bool Map::test()
{
    clearFlags();
    return checkPath(startX, startY);
}