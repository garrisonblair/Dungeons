#include "Menu.h"

Menu::Menu()
{
    game = new Game();
    gameMode = 0;
}

Menu::~Menu()
{
    delete game;
}
void Menu::edit()
{

}

void Menu::mainMenu()
{
    cout << "**** WELCOME TO DUNGEONS & DRAGONS ****" << endl;
    cout << "1. PLAY" << endl;
    cout << "2. EDIT" << endl;
    cout << "What would you like to do? ";
    cin >> gameMode;

    if (gameMode == 1) play();
    else if (gameMode == 2) edit();

}