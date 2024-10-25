#ifndef TRASH_GAME_H
#define TRASH_GAME_H

#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <vector>
#include <random>
#include <ctime>


class Game {
private:
    string m_slovo;
    int m_poc_pokusu;
public:
    Game();
    void zvol_slovo();
    void nakresli_mapu();

};


#endif //TRASH_GAME_H
