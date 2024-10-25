//
// Created by Leonid on 24.10.2024.
//

#ifndef TRASH_MAP_H
#define TRASH_MAP_H

using namespace std;


class Map {
private:
    int m_sirka;
    int m_delka;
public:
    Map(int sirka, int delka);

    int getMSirka() const;

    int getMDelka() const;
};


#endif //TRASH_MAP_H
