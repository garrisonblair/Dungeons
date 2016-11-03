#include "Menu.h"

Menu::Menu() {
    game = new Edit();
    gameMode = 0;
}

Menu::~Menu() {};

void Menu::edit() {
    game = new Edit();

    ifstream directory;
    directory.open("Save_Data/Campaigns.txt");
    int index = 1;
    string ls, filename;
    int active;

    while (directory >> ls)
    {
        cout << index << ". " << ls << endl;
        index++;
    }
    cout << index << ". " << "Create new campaign" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Which Campaign would you like to edit? ";
    cin >> active;

    if (active == index)
    {
        cout << "Enter a name for this campaign: ";
        cin >> filename;
        game->load("Save_Data/" + filename);
        game->editCampaign();
    }

}

void Menu::mainMenu() {
    cout << "**** WELCOME TO DUNGEONS & DRAGONS ****" << endl;
    cout << "1. PLAY" << endl;
    cout << "2. EDIT" << endl;
    cout << "What would you like to do? ";
    cin >> gameMode;

    //if (gameMode == 1) play();
    if (gameMode == 2) edit();

}