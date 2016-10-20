#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Item
{
    char type;              // h, a, s, r, c, b, w
    string name;            // Helmet, Armor, Shield, Ring, Belt, Boots, Weapon
    int enchantment;        // Enchantment associated to item
    // Enhancement on characters abilities
    int enhance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};   // [STR, DEX, CON, INT, WIS, CHA, AC, ATK, DMG]
    
public:
    
    Item();                 // Default Constructor
    Item(char, int);        // Constructor with Type and Enchantment
    Item(const Item&);      // Copy Constructor

    // Attribute Accessors
    string getName() const;
    char getType() const;
    int getEnchantment() const;
    const int * getEnhancement() const;

    void setName(string);   // Set specific name to item
};

#endif /* Item_hpp */
