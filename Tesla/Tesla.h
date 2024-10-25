//
// Created by Leonid on 24.10.2024.
//

#ifndef TRASH_TESLA_H
#define TRASH_TESLA_H

#include "Position.h"
using namespace std;


class Tesla {
private:
    Position* m_position;
    int m_baterie;
public:
    Tesla(int x, int y);

    Position *getMPosition() const;

    int getMBaterie() const;

    void setMBaterie(int mBaterie);
};


#endif //TRASH_TESLA_H
