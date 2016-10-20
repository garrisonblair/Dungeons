#include "Container.h"

Container::Container()
{
    itemList = new Item[64];        // Container is list of size 64
    items = 0;                      // Size initiated to 0
}

Container::~Container()
{
    delete [] itemList;             // destruction of itemList
}

void Container::addItem(Item item)
{
    if (items < 64)
    {
        itemList[items] = item;     // Item appended to list if container is not full
        items++;                    // Size of list incremented
    }
    else
        cout << "Container is full, cannot add Item" << endl;
}

Item Container::getItem(string name)
{
    // Searches for name in the list and returns associated item if the name is found
    for (unsigned int i = 0; i < items; i++) {
        if (name == itemList[i].getName()) {
            return itemList[i];
        }
    }
    // Item is not found, empty item is returned
    cout << "Item '" << name << "' not in container" << endl;
    return *new Item;
}
