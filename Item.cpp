#include "Item.h"

Item::Item() {}

Item::Item(char type, int e)
{
    // Attributes assigned based on type
    // Enchantment applied to stats affected based on type of item
    switch (type) {
        // Helmet
        case 'h':
        {
            name = "Helmet";
            int temp[9] = {0, 0, 0, e, e, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        // Armor
        case 'a':
        {
            name = "Armor";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        // Shield
        case 's':
        {
            name = "Shield";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        // Ring
        case 'r':
        {
            name = "Ring";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        // Belt
        case 'c':
        {
            name = "Belt";
            int temp[9] = {e, 0, e, 0, 0, 0, 0, 0, 0,};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        // Boots
        case 'b':
        {
            name = "Boots";
            int temp[9] = {0, e, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        // Weapon
        case 'w':
        {
            name = "Weapon";
            int temp[9] = {0, 0, 0, 0, 0, 0, 0, e, e};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }

        default:
            break;
    }

    enchantment = e;
}

Item::Item(const Item &item)
{
    name = item.name;
    enchantment = item.enchantment;
    for (unsigned int i = 0; i < 9; i++) {
        enhance[i] = item.enhance[i];
    }
}

string Item::getName() const { return name;}

char Item::getType() const { return type;}

int Item::getEnchantment() const { return enchantment;}

void Item::setName(string n) { name = n;}
