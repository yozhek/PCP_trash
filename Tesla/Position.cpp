//
// Created by Leonid on 24.10.2024.
//

#include "Position.h"

Position::Position(int x, int y) {
    m_positionX = x;
    m_positionY = y;
}

int Position::getMPositionX() const {
    return m_positionX;
}

int Position::getMPositionY() const {
    return m_positionY;
}

void Position::setMPositionX(int mPositionX) {
    m_positionX = mPositionX;
}

void Position::setMPositionY(int mPositionY) {
    m_positionY = mPositionY;
}
