//
// Created by Leonid on 24.10.2024.
//

#include "Tesla.h"

Tesla::Tesla(int x, int y) {
    m_position = new Position(x, y);
    m_baterie = 100;
}

Position *Tesla::getMPosition() const {
    return m_position;
}

int Tesla::getMBaterie() const {
    return m_baterie;
}

void Tesla::setMBaterie(int mBaterie) {
    m_baterie = mBaterie;
}


