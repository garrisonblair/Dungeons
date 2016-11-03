#ifndef GAME_H
#define GAME_H

#include "Campaign.h"
#include "Director.h"

class Game
{
protected:
    Campaign * campaign;

public:
    Game();
    ~Game();

    void save();
    void load(string);
    void loadCampaign(string);
    void newGame();

    Map getMap(int) const;
};

class Edit: public Game
{
public:
    Edit();
    ~Edit();

    void createCampaign();
    void editCampaign();
};

class Play: public Game
{

public:
    Play();
    void play();
};

#endif /* GAME_H */

