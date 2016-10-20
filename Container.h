#ifndef Container_hpp
#define Container_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Container
{
    Item * itemList;        // List of items
    int items;              // Size of item list
    
public:
    Container();            // Default Constructor
    ~Container();           // Destructor
    
    void addItem(Item);     // Add item to container
    Item getItem(string);   // Get Item from container based on name
};

#endif /* Container_hpp */
