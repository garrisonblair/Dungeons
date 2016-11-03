#ifndef MENU_H
#define MENU_H

#include "Game.h"

class Menu
{
    Game * game;
    int gameMode;

public:
    Menu();
    ~Menu();

    void mainMenu();
    void edit();
    void play();
};


#endif /* MENU_H */

