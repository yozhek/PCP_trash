//
// Created by Leonid on 24.10.2024.
//

#ifndef TRASH_GAME_H
#define TRASH_GAME_H

#include "Map.h"
#include "Tesla.h"
#include "Supercharger.h"
#include "Position.h"
#include <vector>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Game {
private:
    bool m_bezi;
    Tesla* m_tesla;
    Map* m_map;
    vector<Supercharger*> m_superchargers;
    vector<vector<char>> m_celaMapa;
public:
    Game();

    void pridejSymbol();
    void nakresliMapu();
    void Control(char button);
    void startGame();
    void Info();
    void checkCharge();
    bool checkDischarge();
    void InfoLose();
};


#endif //TRASH_GAME_H
