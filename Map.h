//
//  Map.hpp
//  Map
//


#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <vector>
#include "Cell.h"

class Cell;

class Map
{
    string name;
    string description;
    int width, length;
    int startX, startY;
    int finishX, finishY;

    Cell ** grid = new Cell*[length]();
    
public:
    Map();
    Map(int, int);
    
    string getName() const;
    string getDescription() const;
    int getWidth() const;
    int getLength() const;
    int getStart() const;
    int getFinish() const;
    Cell getCell(int, int);

    void setName(string);
    void setDescription(string);
    void setStart(int, int);
    void setFinish(int, int);
    void setCell(int, int, char);
    void clearFlags();
    bool checkPath(int, int);
    bool checkPath();
};

#endif /* Map_hpp */
