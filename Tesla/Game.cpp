//
// Created by Leonid on 24.10.2024.
//

#include "Game.h"

Game::Game() {
    m_bezi = true;
    m_tesla = new Tesla(9, 4);
    m_map = new Map(20,10);
    m_superchargers.push_back(new Supercharger(1,3));
    m_superchargers.push_back(new Supercharger(5,8));
    m_superchargers.push_back(new Supercharger(3,5));
    m_superchargers.push_back(new Supercharger(18,2));
    m_superchargers.push_back(new Supercharger(16,6));
}

void Game::pridejSymbol() {
    m_celaMapa = vector<vector<char>>(m_map->getMDelka(), vector<char>(m_map->getMSirka(),' '));
    for(int c = 0; c < m_celaMapa.size(); c++){
        m_celaMapa[c][0] = '|';
        m_celaMapa[c][m_celaMapa[0].size() - 1] = '|';
    }
    for(int r = 0; r < m_celaMapa[0].size(); r++){
        m_celaMapa[0][r] = '-';
        m_celaMapa[m_celaMapa.size() - 1][r] = '-';
    }
    for(auto charge: m_superchargers){
        m_celaMapa[charge->getMPosition()->getMPositionY()][charge->getMPosition()->getMPositionX()] = '+'; //Supercharger
    }
    m_celaMapa[m_tesla->getMPosition()->getMPositionY()][m_tesla->getMPosition()->getMPositionX()] = 'T'; //Tesla
}

void Game::nakresliMapu() {
    pridejSymbol();
    for(const auto& raw : m_celaMapa){
        for(const auto& col: raw){
            cout<<col;
        }
        cout<<endl;
    }
}

void Game::Control(char button) {
    if(tolower(button) == 'w' and m_tesla->getMPosition()->getMPositionY()>1){
        m_tesla->getMPosition()->setMPositionY(m_tesla->getMPosition()->getMPositionY() - 1);
        m_tesla->setMBaterie(m_tesla->getMBaterie()-1);
    }
    else if(tolower(button) == 's' and m_tesla->getMPosition()->getMPositionY()<m_map->getMDelka()-2){
        m_tesla->getMPosition()->setMPositionY(m_tesla->getMPosition()->getMPositionY() + 1);
        m_tesla->setMBaterie(m_tesla->getMBaterie()-1);
    }
    else if(tolower(button) == 'a' and m_tesla->getMPosition()->getMPositionX()>1){
        m_tesla->getMPosition()->setMPositionX(m_tesla->getMPosition()->getMPositionX() - 1);
        m_tesla->setMBaterie(m_tesla->getMBaterie()-1);
    }
    else if(tolower(button) == 'd' and m_tesla->getMPosition()->getMPositionX()<m_map->getMSirka()-2){
        m_tesla->getMPosition()->setMPositionX(m_tesla->getMPosition()->getMPositionX() + 1);
        m_tesla->setMBaterie(m_tesla->getMBaterie()-1);
    }
    checkCharge();
}

void Game::startGame() {
    while (m_bezi) {
        nakresliMapu();
        Info();
        char input;
        if(!checkDischarge()) {
            input = _getch();
            Control(input);
        }
        else{
            InfoLose();
            input = _getch();
            m_bezi = false;
        }
        system("cls");
    }
}

void Game::Info() {
    cout << "\x1b[" << 1 << ";" << 25 << "H";
    cout << "Welcome to the Tesla game!";
    cout << "\x1b[" << 3 << ";" << 25 << "H";
    cout << "Your battery charge: "<<m_tesla->getMBaterie()<<"%";
}

void Game::InfoLose() {
    cout << "\x1b[" << 5 << ";" << 25 << "H";
    cout << "The battery is dead! You've lost!";
    cout << "\x1b[" << 7 << ";" << 25 << "H";
    cout << "Press any key to exit the game!";
}

void Game::checkCharge() {
    for(int i = 0; i < m_superchargers.size(); i++){
        if(m_tesla->getMPosition()->getMPositionX() == m_superchargers[i]->getMPosition()->getMPositionX()
            and m_tesla->getMPosition()->getMPositionY() == m_superchargers[i]->getMPosition()->getMPositionY()){
            if(m_tesla->getMBaterie()>=90){
                m_tesla->setMBaterie(100);
            }
            else{
                m_tesla->setMBaterie(m_tesla->getMBaterie()+10);
            }
        }
    }
}

bool Game::checkDischarge() {
    if(m_tesla->getMBaterie()==0){
        return true;
    }
    else{
        return false;
    }
}

