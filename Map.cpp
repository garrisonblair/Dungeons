//
//  Map.cpp
//  Map
//


#include "Map.hpp"


// CONSTRUCTORS

Map::Map()  // Generates a 10x10 blank map
{
    name = "Default Map";
    description = "10x10";
    width = 10;
    length = 10;
    
    for (unsigned int i = 0; i < width; i++)
    {
        grid[i] = new Cell[width];
    }
} // End of Default Constructor

Map::Map(int w, int l)  // Generates a WxH blank map
{
    name = "Default Map";
    description = to_string(w) + "x" + to_string(l);
    width = w;
    length = l;
    
    for (unsigned int i = 0; i < width; i++)
    {
        grid[i] = new Cell[width];
    }
} // End of Constructor


// ATTRIBUTE ACCESSORS

string Map::getName() const {return name;}
string Map::getDescription() const {return description;}
int Map::getWidth() const {return width;}
int Map::getLength() const {return length;}
int Map::getStart() const {return start;}
int Map::getFinish() const {return finish;}

Cell Map::getCell(int x, int y) {return grid[x][y];}


// ATTRIBUTE EDITORS

void Map::setName(string n) {name = n;}
void Map::setDescription(string d) {description = d;}
void Map::setStart(int x, int y) {startX = x; startY = y;}
void Map::setFinish(int x, int y) {finishX = x; finishY = y;}

void Map::setCell(int x, int y, char c)
{
    this -> getCell(x, y).addInter(c);
}

void Map::clearFlags()
{
    for (unsigned int i = 0; i < width; i++)
    {
        for (unsigned int j = 0; j < length; j++)
        {
            this -> getCell(i, j).unflag();
        }
    }
}


// CHECK MAP FOR VIABLE PATH FROM START TO FINISH

bool Map::checkPath(int x, int y) // Infinite loop case to be resolved
{
    vector<int> north, south, east, west;

    north = {x, (y == length ? y : y + 1)};
    south = {x, (y == 0 ? y : y - 1)};
    east = {(x == width ? x : x + 1), y};
    west = {(x == 0 ? x : x - 1), y};

    vector<vector<int>> borders = {north, east, west, south};

    for (unsigned int i = 0; i < 4; i++)
    {
        this->getCell(x, y).flag();     // flag current cell

        if (x == finishX && y == finishY)       // reach finish cell
        {
            return true;
        }
        else if (this->getCell(borders[i][0], borders[i][1]).isFlagged())   // avoids moving to already visited cell
        {
            continue;       // move on to next option
        }
        else if (!(this->getCell(borders[i][0], borders[i][1])).getInter().block())     // finds open bordering cell
        {
            try
            {
                checkPath(borders[i][0], borders[i][1]);        // recursion on next cell
            } catch (bool dead_end) {
                return dead_end;
            }

        }
        else if (i == 3)
        {
            if (x != startX && y != startY) throw ("Dead End");
        }
    }

    // no path is found
    return false;

} // End of checkPath function


// CHECK MAP FOR VIABLE PATH FROM START TO FINISH

bool Map::checkPath(int x, int y) // Infinite loop case to be resolved
{
    for (unsigned int i = 0; i < length*width ; i++)
    {
        grid[x][y].flag();
        if      ((x == finishX) && (y == finishY)) return true;
        if      ((!grid[x][y+1].isFlagged()) && (y != length) && (!grid[x][y+1].getInter().block()))
            checkPath(x, y + 1);
        else if ((!grid[x+1][y].isFlagged()) && (x != width) && (!grid[x+1][y].getInter().block()))
            checkPath(x + 1, y);
        else if ((!grid[x-1][y].isFlagged()) && (x != 0) && (!grid[x-1][y].getInter().block()))
            checkPath(x - 1, y);
        else if ((!grid[x][y-1].isFlagged()) && (y != 0)&& (!grid[x][y-1].getInter().block()))
            checkPath(x, y - 1);
        else break;
    }
    return false;
} // End of checkPath function

bool Map::checkPath()
{
    this -> clearFlags();
    return this -> checkPath(startX, startY);
}
