//
//  Container.cpp
//  dungeons1
//


#include "Container.hpp"
#include "Item.hpp"

Container::Container()
{
    itemList = new Item[64];
    items = 0;
}

Container::~Container()
{
    delete [] itemList;
}

void Container::addItem(Item item)
{
    if (items < 64)
    {
        itemList[items] = item;
        items++;
    }
}

Item Container::getItem(string name)
{
    for (unsigned int i = 0; i < items; i++) {
        if (name == itemList[i].getName()) {
            return itemList[i];
        }
    }
    cout << "Item ' " << name << " ' not in container" << endl;
    return *new Item;
    
}
