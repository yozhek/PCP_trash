//
// Created by Leonid on 24.10.2024.
//

#ifndef TRASH_POSITION_H
#define TRASH_POSITION_H

using namespace std;;


class Position {
private:
    int m_positionX;
    int m_positionY;
public:
    Position(int x, int y);

    int getMPositionX() const;

    int getMPositionY() const;

    void setMPositionX(int mPositionX);

    void setMPositionY(int mPositionY);
};


#endif //TRASH_POSITION_H
