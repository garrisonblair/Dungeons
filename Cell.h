//
//  Cell.hpp
//  Map
//


#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include <iostream>
#include "Interaction.hpp"

using namespace std;
class Interaction;

class Cell
{
    bool empty;
    bool flagged;
    Interaction inter;      // Ally, Opponent, Chest, Wall, Door
    
public:
    Cell();
    Cell(const Cell &);
    Cell(Interaction);
    
    bool isEmpty();
    bool isFlagged();
    Interaction getInter();
    
    void flag();
    void unflag();
    
    void addInter(char);
    void removeInter();
};

#endif /* Cell_hpp */
