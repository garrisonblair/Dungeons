#include "Game.h"

// CONSTRUCTOR
Game::Game() { campaign = new Campaign(); }

// DESTRUCTOR
Game::~Game() { delete campaign; }

// ACCESS MAP
Map Game::getMap(int x) const
{
    return campaign->getMap(x);
}

// SAVE CURRENT CAMPAIGN
void Game::save()
{
    string target;
    target = campaign->getName() + ".txt";

    ofstream campfile;
    campfile.open(target);

    for (unsigned int i = 0; i < campaign->getPos(); i++)
    {
        campfile << campaign->getMap(i).getName() << ".txt" << '\n';
    }
}

// LOAD MAP TO CAMPAIGN
void Game::load()
{
    Director * direct = new Director();
    Builder * build = new EditBuilder();

    string target;
    cout << "Which file would you like to load?" << endl;
    cin >> target;

    ifstream active;
    active.open(target);
    string line;
    while (active >> line)
    {
        cout << target << " " << line << endl;
        if (target == line)
            direct->setBuilder(build);
        direct->constructMap(target);

        campaign->addMap(*direct->getMap());
    }



}

// CREATE NEW CAMPAIGN FILE
void Game::newGame()
{

}

//CONSTRUCTOR / DESTRUCTOR
Edit::Edit():Game() {}
Edit::~Edit() { delete campaign; }

// RESET CAMPAIGN
void Edit::createCampaign()
{
    delete campaign;
    campaign = new Campaign();
}

// EDIT CAMPAIGN
void Edit::editCampaign()
{
    int active;
    char end;
    do
    {
        campaign->print();
        cout << "Which Map would you like to edit? ";
        cin >> active;
        active--;
        if (active == campaign->getPos())
            campaign->createMap();
        else if (active <= campaign->getPos())
        {
            campaign->accessMap(active);
            campaign->editMap();
        }
        else cout << "Please enter a valid number" << endl;

        cout << "Finish editing campaign(y/n): ";
        cin >> end;
        if ((end == 'y') || (end == 'Y')) break;

    } while (1);

    this->save();
}