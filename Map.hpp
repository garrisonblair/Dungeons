//
//  Map.hpp
//  Map
//


#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Cell.hpp"

class Cell;

class Map
{
    string name;
    string description;
    int width, length;
    int start, finish;

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
    void setStart(int);
    void setFinish(int);
    void setCell(int, int, char);
    bool checkPath(int);
};

#endif /* Map_hpp */
