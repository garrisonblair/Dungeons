//
//  Map.cpp
//  Map
//
//  Created by Garrison Blair on 2016-10-02.
//  Copyright © 2016 Garrison Blair. All rights reserved.
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
    
    //this -> setBorders();
} // End of Default Constructor

Map::Map(int w, int l)  // Generates a WxH blank map
{
    name = "Default Map";
    description = to_string(w) + "x" + to_string(h);
    width = w;
    length = l;
    
    for (unsigned int i = 0; i < width; i++)
    {
        grid[i] = new Cell[width];
    }
    
    this -> setBorders();
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
void Map::setStart(int s) {start = s;}
void Map::setFinish(int f) {finish = f;}

void Map::setCell(int x, int y, char c)
{
    this -> getCell(x, y).addInter(c);
}


// CHECK MAP FOR VIABLE PATH FROM START TO FINISH

bool Map::checkPath(int st) // Infinite loop case to be resolved
{
    int direct[4];  // cell borders for current location
    
    direct[0] = this->getCell(st).getN();
    direct[1] = this->getCell(st).getE();
    direct[2] = this->getCell(st).getW();
    direct[3] = this->getCell(st).getS();
    
    for (unsigned int i = 0; i < 4; i++)
    {
        if (st == finish)                               // reach finish cell
        {
            return true;
        }
        else if (this->getCell(direct[i]).isflagged())  // avoids moving to already visited cell
        {
            this->getCell(st).flag();                   // flag current cell
            continue;                                   // move on to next option
        }
        else if (this->getCell(direct[i]).isOpen())     // finds open bordering cell
        {
            this->getCell(st).flag();                   // flag current cell before moving on
            checkPath(direct[i]);                       // recursion on next cell
        }
    }
    
    // no path is found
    return false;
    
} // End of checkPath function
