#include "Cell.h"

Type::Type()
{
    blocked = false;
}

Type::Type(int in)
{
    if (in == 0) blocked = true;
    else blocked = false;
}

bool Type::isBlocked() const { return blocked; }


Cell::Cell()
{
    flagged = false;
}

Cell::Cell(Type in)
{
    flagged = false;
    type = in;
}

//bool Cell::isEmpty() const { return empty; }
bool Cell::isFlagged() const { return flagged; }

void Cell::flag() { flagged = true; }
void Cell::unFlag() { flagged = false; }

void Cell::setType(int in)
{
    type = Type(in);
}

//void Cell::removeType() { empty = true; }

Type Cell::getType() const { return type; }

