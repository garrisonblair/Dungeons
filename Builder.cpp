#include "Builder.h"

// LOAD MAP FROM FILE
void EditBuilder::buildMap(string filename)
{
    ifstream active;
    active.open(filename);

    int x, y;
    int dx, dy;
    int size, e;
    int lvl;
    string in, link, cls, name;
    char t, t2;

    active >> in >> y >> x;
    map = new Map(in, x, y);

    for (unsigned int i = 0; i < y; i++)
    {
        for (unsigned int j = 0; j < x; j++)
        {
            active >> t;
            switch (t) {
                case 'n':
                    map->setCell(j, i, t);
                    break;
                case 'd':
                    active >> link >> dx >> dy;
                    map->setCell(j, i, link, dx, dy);
                    break;
                case 'c':
                    map->setCell(j, i, 'c');
                    active >> size;
                    for (int c = 0; c < size; c++)
                    {
                        active >> t2 >> e;
                        map->getCell(j, i).getContainer()->addItem(t2, e);
                    }
                    break;
                case 'e':
                    active >> lvl >> cls >> name >> size;
                    map->setCell(j, i, lvl, cls, name);
                    for (int e = 0; e < size; e++)
                    {
                        active >> t >> e;
                        map->getCell(j, i).getCharacter()->equip(Item(t, e));
                    }
                    break;
                case 'w':
                    map->setCell(j, i, 'w');
                    break;
                default:
                    break;
            }
        }
    }

    active.close();
}
