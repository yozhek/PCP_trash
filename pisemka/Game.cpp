#include "Game.h"

Game::Game() {
    m_slovo = "";
    m_poc_pokusu = 7;
}

void Game::zvol_slovo() {
    ifstream file("Words.txt");

    if(!file.is_open()){
        cerr<<"Nepodarilo se otevrit soubor!"<<endl;
        exit(1);
    }
    else {
        vector < string > words;
        string word;

        while (file >> word) {
            words.push_back(word);
        }

        file.close();

        if (words.empty()) {
            cerr << "Soubor je prazdny!" << endl;
            exit(1);
        }
        else{
            srand(time(nullptr));
            int random_index = rand() % words.size();
            m_slovo = words[random_index];
        }
    }
}

void Game::nakresli_mapu() {
    zvol_slovo();
    vector<string>odahadana_pismena(m_slovo.size(), "_");
    int poc_uhodutych = 0;
    while (m_poc_pokusu != 0){
        string pismeno;
        cout<<"Vitejte ve hre Obesenec!"<<endl<<endl;
        for(int i = 0; i < m_slovo.size(); i++){
            cout<<odahadana_pismena[i]<<" ";
        }
        cout<<endl<<endl;
        cout<<"Zkuzte uhodnout pismeno nebo cele slovo:"<<endl;
        cin>>pismeno;
        if(pismeno.empty()){
            cout<<"Nic jste nenapsali, zkuzte jeste jednou!";
            cout<<endl;
            cout<<"Stisknete Enter pro pokracovani...";
            cin.ignore();
            cin.get();
        }
        else if(pismeno.size() > 1 and pismeno.size() != m_slovo.size()){
            cout<<"Musite napsat nebo 1 pismeno nebo cele slovo! Zkuste jeste jednou!"<<endl;
            cout<<endl;
            cout<<"Stisknete Enter pro pokracovani...";
            cin.ignore();
            cin.get();
        }
        else if(pismeno.size() == 1){
            bool uz_bylo = false;
            for(int i = 0; i < odahadana_pismena.size(); i++){
                if(pismeno == odahadana_pismena[i]){
                    uz_bylo = true;
                }
            }
            if(!uz_bylo) {
                char letter = pismeno[0];
                bool odhodnoul = false;
                for (int i = 0; i < m_slovo.size(); i++) {
                    if (letter == m_slovo[i]) {
                        odahadana_pismena[i] = m_slovo[i];
                        odhodnoul = true;
                        poc_uhodutych++;
                    }
                }
                if (odhodnoul) {
                    if (poc_uhodutych != m_slovo.size()) {
                        cout << "Gratuluji! Odhodnoul jste pismenko! Zkus odhadnout dalsi pismeno." << endl;
                        cout << endl;
                        cout << "Stisknete Enter pro pokracovani...";
                        cin.ignore();
                        cin.get();
                    } else {
                        cout << "Gratuluji! Uhodl jste cele slovo a vyhral hru!" << endl;
                        cout << endl;
                        cout << "Stisknete Enter pro podtvrzeni...";
                        cin.ignore();
                        cin.get();
                        m_poc_pokusu = 0;
                    }
                } else {
                    m_poc_pokusu--;
                    cout << "Bohuzel nepodarilo se ti odhadnout pismenko. Zkus jeste jednou!" << endl;
                    cout << "Pocet zbyvajicich pokusu: " << m_poc_pokusu << endl;
                    cout << endl;
                    cout << "Stisknete Enter pro pokracovani...";
                    cin.ignore();
                    cin.get();
                }
            }else{
                cout<<"Uz jste uhodl toto pismenko, zkus jine!"<<endl;
                cout << endl;
                cout << "Stisknete Enter pro pokracovani...";
                cin.ignore();
                cin.get();
            }
        }
        else if(pismeno.size() == m_slovo.size()){
            if(pismeno == m_slovo){
                cout<<"Gratuluji! Uhodl jste cele slovo a vyhral hru!"<<endl;
                cout<<endl;
                cout<<"Stisknete Enter pro podtvrzeni...";
                cin.ignore();
                cin.get();
                m_poc_pokusu = 0;
            }else{
                cout<<"Bohuzel nepodarilo se ti odhodnout cele slovo. Zkus jeste jednou!"<<endl;
                cout<<endl;
                cout<<"Stisknete Enter pro podtvrzeni...";
                cin.ignore();
                cin.get();
                m_poc_pokusu--;
            }
        }
        system("cls");
    }
}