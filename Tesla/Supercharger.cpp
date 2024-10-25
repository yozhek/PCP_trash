//
// Created by Leonid on 24.10.2024.
//

#include "Supercharger.h"

Supercharger::Supercharger(int x, int y) {
    m_position = new Position(x, y);
}

Position *Supercharger::getMPosition() const {
    return m_position;
}


