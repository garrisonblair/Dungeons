#ifndef MENU_H
#define MENU_H

#include "Game.h"

class Menu
{
    Edit * game;
    int gameMode;

public:
    Menu();
    ~Menu();

    void edit();
    void play();
    void mainMenu();
};


#endif /* MENU_H */

