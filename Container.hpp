//
//  Container.hpp
//  dungeons1
//


#ifndef Container_hpp
#define Container_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class Item;
using namespace std;

class Container
{
    Item * itemList;
    int items;
    
public:
    Container();
    ~Container();
    
    void addItem(Item);
    Item getItem(string);
};

#endif /* Container_hpp */
