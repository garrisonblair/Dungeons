//
//  Cell.cpp
//  Map
//


#include "Cell.h"


// CONSTRUCTORS

Cell::Cell()
{
    empty = true;
    flagged = false;
} // End of Default Constructor

Cell::Cell(const Cell &c)
{
    empty = c.empty;
    flagged = c.flagged;
    if (c.empty == false) inter = c.inter;
} // End of Copy Constructor

Cell::Cell(Interaction in)
{
    inter = in;
    empty = true;
    flagged = false;
} // End of Constructor


// BOOLEAN STATE CHECKS

bool Cell::isEmpty()    // Cell is empty
{
    return empty;
} // End of isEmpty function

bool Cell::isFlagged()  // Cell has been visited
{
    return flagged;
} // End of isFlagged function


// ATTRIBUTE ACCESSORS

Interaction Cell::getInter() {return inter;}


// ATTRIBUTE EDITORS

void Cell::flag() {flagged = true;}
void Cell::unflag() {flagged = false;}

void Cell::addInter(char in)
{
    inter = Interaction(in);
    if (empty) {
        empty = false;
    }
} // End of addInter function

void Cell::removeInter()
{
    empty = true;
} // End of removeInter function
