//
// Created by Leonid on 24.10.2024.
//

#ifndef TRASH_SUPERCHARGER_H
#define TRASH_SUPERCHARGER_H

#include "Position.h"
using namespace std;

class Supercharger {
private:
    Position* m_position;
public:
    Supercharger(int x, int y);

    Position *getMPosition() const;
};


#endif //TRASH_SUPERCHARGER_H
