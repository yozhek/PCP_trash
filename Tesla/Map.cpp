//
// Created by Leonid on 24.10.2024.
//

#include "Map.h"

Map::Map(int sirka, int delka) {
    m_sirka = sirka;
    m_delka = delka;
}

int Map::getMSirka() const {
    return m_sirka;
}

int Map::getMDelka() const {
    return m_delka;
}
