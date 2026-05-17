#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include "Loc.h"
#include "Bilet.h"
#include "Film.h"
#include "Spectacol.h"
#include "Autentificare.h"

using namespace std;

// Culori ANSI
const string VERDE = "\033[32m";
const string GALBEN = "\033[33m";
const string ALBASTRU = "\033[34m";
const string GRI = "\033[90m";
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string ROSU = "\033[31m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";

void curataEcran() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void afisareSala(const vector<Loc>& sala, int locuriPerRand) {
    const string BULINA = "●"; 
    cout << "\n      " << BOLD << "--- CONFIGURATIE SALA ---" << RESET << "\n\n        ";
    for(int j = 1; j <= locuriPerRand; j++) cout << (j < 10 ? to_string(j) + "  " : to_string(j) + " ");
    cout << "\n";
    int randCurent = 1;
    cout << "R. " << randCurent << " | ";
    for (size_t i = 0; i < sala.size(); i++) {
        if (sala[i].status()) cout << GRI << BULINA << "  " << RESET;
        else cout << VERDE << BULINA << "  " << RESET;
        if ((i + 1) % locuriPerRand == 0 && (i + 1) < sala.size()) {
            randCurent++;
            cout << "\nR. " << randCurent << " | ";
        }
    }
    cout << "\n\n" << GRI << "(Legenda: " << VERDE << "● Liber " << GRI << "● Ocupat)" << RESET << "\n";
}

// BAZA DE DATE EXTINSA: 20 DE FILME (10 ADULTI / 10 COPII)
vector<Film> initializareCinema() {
    vector<Film> filme;

    // ==================== SECTIUNEA ADULTI / ADOLESCENTI ====================
    
    // 1. Avatar
    Film avatar("Avatar: The Way of Water", R"(   ____  _  _  ____
  / ___|| || ||  _ \
  \___ \| || || |_) |
   ___) |__   _|  _ <
  |____/   |_| |_| \_\)");
    avatar.adaugaSpectacol("12:00", true, "Sala 1 (IMAX 3D)");
    avatar.adaugaSpectacol("18:00", true, "Sala 1 (IMAX 3D)");
    avatar.adaugaSpectacol("21:30", false, "Sala 4 (Standard 2D)");
    filme.push_back(avatar);

    // 2. Dune
    Film dune("Dune: Part Two", R"(     /\  _  _  /\
    /  \/ \/ \/  \
   /_____________\)");
    dune.adaugaSpectacol("14:00", false, "Sala 2 (Dolby 2D)");
    dune.adaugaSpectacol("19:30", true, "Sala 3 (Atmos 3D)");
    dune.adaugaSpectacol("22:45", true, "Sala VIP 3D");
    filme.push_back(dune);

    // 3. Deadpool
    Film deadpool("Deadpool & Wolverine", R"(     ( X _ X )
      \|/ \W/ )");
    deadpool.adaugaSpectacol("16:30", false, "Sala 5 (Standard 2D)");
    deadpool.adaugaSpectacol("20:00", true, "Sala 1 (IMAX 3D)");
    deadpool.adaugaSpectacol("23:15", false, "Sala VIP 2D");
    filme.push_back(deadpool);

    // 4. Oppenheimer
    Film oppenheimer("Oppenheimer", R"(       (     )
     (         )
    (___________)
        |||||
        |||||)");
    oppenheimer.adaugaSpectacol("13:00", false, "Sala 4 (Standard 2D)");
    oppenheimer.adaugaSpectacol("17:00", false, "Sala 2 (Dolby 2D)");
    oppenheimer.adaugaSpectacol("21:00", false, "Sala 2 (Dolby 2D)");
    filme.push_back(oppenheimer);

    // 5. Interstellar
    Film interstellar("Interstellar", R"(      ______
   .-'      '-.
  /  _______   \  <- O
  \____________/
   '-.______.-')");
    interstellar.adaugaSpectacol("15:00", false, "Sala 3 (Atmos 2D)");
    interstellar.adaugaSpectacol("21:45", false, "Sala 1 (IMAX 2D)");
    filme.push_back(interstellar);

    // 6. The Dark Knight
    Film batman("The Dark Knight", R"(   /\              /\
  /  \_/\______/\_/  \
  \______      ______/
         \/  \/)");
    batman.adaugaSpectacol("18:30", false, "Sala 5 (Standard 2D)");
    batman.adaugaSpectacol("22:00", false, "Sala 4 (Standard 2D)");
    filme.push_back(batman);

    // 7. Matrix
    Film matrix("The Matrix", R"(  [1][0][1][0][1]
  [0][1][0][1][0]
  [1][0][1][0][1])");
    matrix.adaugaSpectacol("11:00", false, "Sala 6 (Standard 2D)");
    matrix.adaugaSpectacol("23:30", false, "Sala 5 (Standard 2D)");
    filme.push_back(matrix);

    // 8. Inception
    Film inception("Inception", R"(      / \
     /   \
    |  X  |
     \   /
      \_/)");
    inception.adaugaSpectacol("14:15", false, "Sala 6 (Standard 2D)");
    inception.adaugaSpectacol("20:30", false, "Sala 3 (Atmos 2D)");
    filme.push_back(inception);

    // 9. Joker
    Film joker("Joker", R"(   \  :  /
  ( : o o : )
   \  ---  /
    \_____/)");
    joker.adaugaSpectacol("19:00", false, "Sala VIP 2D");
    joker.adaugaSpectacol("22:15", false, "Sala 6 (Standard 2D)");
    filme.push_back(joker);

    // 10. Gladiator II
    Film gladiator("Gladiator II", R"(     ______
    |======|
    | [oo] |  <- [I|I]
    |______/
     /    \)");
    gladiator.adaugaSpectacol("16:00", false, "Sala 2 (Dolby 2D)");
    gladiator.adaugaSpectacol("19:45", true, "Sala 3 (Atmos 3D)");
    filme.push_back(gladiator);


    // ==================== SECTIUNEA COPII / FAMILIE ====================

    // 11. Inside Out 2
    Film insideOut("Inside Out 2", R"(    .-''''-.
   /   _  _ \
  |   (o)(o) |  *Happy*
  |     __   |
   \   \__/ /
    '-....-')");
    insideOut.adaugaSpectacol("10:30", false, "Sala 4 (Standard 2D)");
    insideOut.adaugaSpectacol("13:15", true, "Sala 7 (Kids 3D)");
    insideOut.adaugaSpectacol("16:00", true, "Sala 7 (Kids 3D)");
    filme.push_back(insideOut);

    // 12. Minions
    Film minions("Minions: The Rise of Gru", R"(     .---.
    /     \
    | [o_o]|  <- Banana!
    |  ___ |
    \_____/)");
    minions.adaugaSpectacol("11:15", false, "Sala 7 (Kids 2D)");
    minions.adaugaSpectacol("14:30", false, "Sala 4 (Standard 2D)");
    minions.adaugaSpectacol("17:30", true, "Sala 8 (Kids 3D)");
    filme.push_back(minions);

    // 13. Kung Fu Panda 4
    Film panda("Kung Fu Panda 4", R"(    c(O  O)b
    ,(___).
    /     \
   |   P   |
    \_____/)");
    panda.adaugaSpectacol("12:15", false, "Sala 8 (Kids 2D)");
    panda.adaugaSpectacol("15:15", true, "Sala 7 (Kids 3D)");
    filme.push_back(panda);

    // 14. Frozen II
    Film frozen("Frozen II", R"(     \ | /
    '- * -'
     / | \   *Let it go*)");
    frozen.adaugaSpectacol("10:00", false, "Sala 8 (Kids 2D)");
    frozen.adaugaSpectacol("13:45", true, "Sala 8 (Kids 3D)");
    filme.push_back(frozen);

    // 15. Shrek
    Film shrek("Shrek Forever After", R"(  \/        \/
   \_______/
   / o   o \
  (    _    )
   \_______/)");
    shrek.adaugaSpectacol("15:45", false, "Sala 6 (Standard 2D)");
    shrek.adaugaSpectacol("18:15", false, "Sala 7 (Kids 2D)");
    filme.push_back(shrek);

    // 16. Cars
    Film cars("Cars 3", R"(     ______
   _/__|_\_
  [(o)---(o)] vroom!
   `-()--()` )");
    cars.adaugaSpectacol("11:30", false, "Sala 5 (Standard 2D)");
    cars.adaugaSpectacol("14:00", false, "Sala 8 (Kids 2D)");
    filme.push_back(cars);

    // 17. The Lion King
    Film lionKing("The Lion King", R"(     _  _
    ( `\/' )
   _ \    / _  (CROWN)
   \'-.__.-'/
    `--..--' )");
    lionKing.adaugaSpectacol("12:45", false, "Sala 6 (Standard 2D)");
    lionKing.adaugaSpectacol("17:45", false, "Sala 4 (Standard 2D)");
    filme.push_back(lionKing);

    // 18. Coco
    Film coco("Coco", R"(     _G_
    /   \   [-]
    | O O |  / \
    |  V  |
    \_____/ )");
    coco.adaugaSpectacol("14:45", false, "Sala 7 (Kids 2D)");
    coco.adaugaSpectacol("19:00", false, "Sala 8 (Kids 2D)");
    filme.push_back(coco);

    // 19. Moana
    Film moana("Moana 2", R"(     ~~~~
    ~ (S) ~  <- OOO
     ~~~~)");
    moana.adaugaSpectacol("10:15", false, "Sala 6 (Standard 2D)");
    moana.adaugaSpectacol("16:15", true, "Sala 8 (Kids 3D)");
    filme.push_back(moana);

    // 20. Harry Potter
    Film harryPotter("Harry Potter special", R"(       
     o- -o
    (  .  )  *Magic*)");
    harryPotter.adaugaSpectacol("16:45", false, "Sala 3 (Atmos 2D)");
    harryPotter.adaugaSpectacol("20:15", false, "Sala 5 (Standard 2D)");
    filme.push_back(harryPotter);

    return filme;
}

int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    ManagerAutentificare auth; 
    bool aplicatieInRulare = true;
    bool esteLogat = false;
    string utilizatorCurent = "";

    // --- MENIU AUTENTIFICARE ---
    while (aplicatieInRulare && !esteLogat) {
        curataEcran();
        cout << ALBASTRU << "===============================================" << RESET << endl;
        cout << BOLD << "       🔒 AUTENTIFICARE CINEMA APP 🔒" << RESET << endl;
        cout << ALBASTRU << "===============================================" << RESET << endl;
        cout << VERDE << " 1." << RESET << " Logare cont existent\n";
        cout << VERDE << " 2." << RESET << " Inregistrare cont nou\n";
        cout << ROSU << " 0." << RESET << " Iesire\n";
        cout << "-----------------------------------------------" << endl;
        cout << GALBEN << "➤ " << RESET << "Alege o optiune: ";
        
        int optiuneAuth; cin >> optiuneAuth;

        if (optiuneAuth == 0) {
            aplicatieInRulare = false;
        } 
        else if (optiuneAuth == 1) {
            string u, p;
            cout << " Username: "; cin >> u;
            cout << " Parola: "; cin >> p;
            
            if (auth.logare(u, p)) {
                esteLogat = true;
                utilizatorCurent = u;
                cout << VERDE << "\nAutentificare reusita! Bine ai revenit, " << u << "! Apasa Enter..." << RESET;
                cin.ignore(); cin.get();
            } else {
                cout << ROSU << "\nUsername sau parola incorecta! Apasa Enter..." << RESET;
                cin.ignore(); cin.get();
            }
        } 
        else if (optiuneAuth == 2) {
            string u, p;
            cout << " Alege un Username: "; cin >> u;
            cout << " Alege o Parola: "; cin >> p;
            
            if (auth.inregistrare(u, p)) {
                cout << VERDE << "\nCont creat cu succes! Te rugam sa te loghezi. Apasa Enter..." << RESET;
                cin.ignore(); cin.get();
            } else {
                cout << ROSU << "\nEroare: Username-ul exista deja! Incearca altul. Apasa Enter..." << RESET;
                cin.ignore(); cin.get();
            }
        }
    }

    if (!aplicatieInRulare) {
        curataEcran();
        cout << "\nLa revedere!\n" << endl;
        return 0;
    }

    // --- MENIU PRINCIPAL CINEMA ---
    vector<Film> listaFilme = initializareCinema();

    curataEcran();
    cout << ALBASTRU << "===============================================" << RESET << endl;
    cout << BOLD << "  ✨ Bine ai venit, " << VERDE << utilizatorCurent << RESET << BOLD << "! ✨" << RESET << endl;
    cout << ALBASTRU << "===============================================" << RESET << endl;
    
    cout << "\n" << ALBASTRU << BOLD << "💡 INFO: " << RESET << "In ziua de " << VERDE << "vineri" << RESET << " avem o promotie speciala\n";
    cout << "          pentru orice tip de bilet (doar 15 RON)!" << endl;
    cout << GALBEN << "➤ " << RESET << "In ce zi ne vizitati? ";
    string numeZi; 
    cin >> numeZi;

    while (aplicatieInRulare) {
        curataEcran();
        cout << BOLD << "FILME DISPONIBILE ASTAZI:\n" << RESET;
        cout << "-----------------------------------------------" << endl;
        
        // Afisare catalog impartit vizual
        cout << MAGENTA << "--- PENTRU ADULTI SI ADOLESCENTI ---" << RESET << "\n";
        for (size_t i = 0; i < 10; i++) {
            cout << VERDE << i + 1 << "." << RESET << " " << listaFilme[i].titlu << "\n";
        }
        
        cout << MAGENTA << "\n--- PENTRU COPII SI FAMILIE ---" << RESET << "\n";
        for (size_t i = 10; i < listaFilme.size(); i++) {
            cout << VERDE << i + 1 << "." << RESET << " " << listaFilme[i].titlu << "\n";
        }
        
        cout << "-----------------------------------------------" << endl;
        cout << ROSU << "0. " << RESET << "Deconectare si iesire\n";
        cout << "-----------------------------------------------" << endl;
        
        cout << GALBEN << "➤ " << RESET << "Alege un film (1-20): ";
        int indexFilm; cin >> indexFilm;

        if (indexFilm == 0) break;
        if (indexFilm < 1 || indexFilm > (int)listaFilme.size()) {
            cout << ROSU << "Selectie invalida! Apasa Enter..." << RESET;
            cin.ignore(); cin.get();
            continue;
        }

        int filmSelectat = indexFilm - 1;
        bool inapoiLaFilme = false;

        while (!inapoiLaFilme && aplicatieInRulare) {
            curataEcran();
            cout << CYAN << listaFilme[filmSelectat].asciiArt << RESET << endl;
            cout << BOLD << "\nFilm selectat: " << listaFilme[filmSelectat].titlu << RESET << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "PROGRAMARI SI SALI DISPONIBILE:\n";
            
            for (size_t j = 0; j < listaFilme[filmSelectat].spectacole.size(); j++) {
                Spectacol& spec = listaFilme[filmSelectat].spectacole[j];
                cout << VERDE << j + 1 << ". " << RESET 
                     << BOLD << spec.ora << RESET 
                     << (spec.este3D ? " [3D]" : " [2D]") 
                     << " -> " << GRI << spec.numeSala << RESET << "\n";
            }
            cout << ROSU << "0. " << RESET << "Inapoi la lista de filme\n";
            cout << "-----------------------------------------------" << endl;
            
            cout << GALBEN << "➤ " << RESET << "Alege o ora: ";
            int indexSpec; cin >> indexSpec;

            if (indexSpec == 0) {
                inapoiLaFilme = true;
                continue;
            }
            if (indexSpec < 1 || indexSpec > (int)listaFilme[filmSelectat].spectacole.size()) {
                cout << ROSU << "Selectie invalida! Apasa Enter..." << RESET;
                cin.ignore(); cin.get();
                continue;
            }

            int specSelectat = indexSpec - 1;
            Spectacol& spectacolCurent = listaFilme[filmSelectat].spectacole[specSelectat];
            
            bool inapoiLaOrar = false;
            bool hartaModificata = false;

            while (!inapoiLaOrar && aplicatieInRulare) {
                curataEcran();
                cout << "\n" << BOLD << "-----------------------------------------------" << RESET << endl;
                cout << "Rezervare: " << ALBASTRU << BOLD << listaFilme[filmSelectat].titlu << RESET;
                cout << " | " << BOLD << spectacolCurent.ora << RESET;
                cout << " (" << spectacolCurent.numeSala << ")" << endl;
                cout << "-----------------------------------------------" << endl;
                
                if (hartaModificata) {
                    cout << VERDE << " 1." << RESET << " Vizualizare harta sala (actualizata)" << endl;
                } else {
                    cout << VERDE << " 1." << RESET << " Vizualizare harta sala" << endl;
                }
                
                cout << VERDE << " 2." << RESET << " Rezervare si achizitie bilet" << endl;
                cout << GRI << " 9." << RESET << " Schimbare ora / Inapoi" << endl;
                cout << ROSU << " 0." << RESET << " Iesire din aplicatie" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Alegerea dumneavoastra: ";
                int opt; cin >> opt;

                if (opt == 1) {
                    afisareSala(spectacolCurent.sala, spectacolCurent.nrLocuriPerRand);
                    cout << "Apasati Enter pentru a continua...";
                    cin.ignore(); cin.get();
                } 
                else if (opt == 2) {
                    afisareSala(spectacolCurent.sala, spectacolCurent.nrLocuriPerRand);
                    int r, l;
                    cout << "\nIntroduceti Randul (1-" << spectacolCurent.nrRanduri << "): "; cin >> r;
                    cout << "Introduceti Locul (1-" << spectacolCurent.nrLocuriPerRand << "): "; cin >> l;

                    if (r < 1 || r > spectacolCurent.nrRanduri || l < 1 || l > spectacolCurent.nrLocuriPerRand) {
                        cout << ROSU << "Eroare: Acest loc nu exista in sala." << RESET << endl;
                        cin.ignore(); cin.get();
                    } else {
                        int index = (r - 1) * spectacolCurent.nrLocuriPerRand + (l - 1);
                        if (spectacolCurent.sala[index].status()) {
                            cout << ROSU << "Ne pare rau, locul este deja ocupat!" << RESET << endl;
                            cin.ignore(); cin.get();
                        } else {
                            cout << "Categorie (1.Adult, 2.Elev, 3.Copil, 4.Dizab): ";
                            int tp; cin >> tp;
                            
                            Bilet b(tp, numeZi);
                            spectacolCurent.sala[index].ocupaLoc();
                            
                            hartaModificata = true; 

                            curataEcran();
                            cout << VERDE << "\n==================================================" << RESET << endl;
                            cout << BOLD << "       VĂ MULȚUMIM PENTRU ACHIZIȚIE! 🍿" << RESET << endl;
                            cout << VERDE << "==================================================" << RESET << endl;
                            cout << " 👤 Client:  " << utilizatorCurent << "\n";
                            cout << " 🎬 Film:    " << BOLD << listaFilme[filmSelectat].titlu << RESET << "\n";
                            cout << " 🕒 Ora:     " << BOLD << spectacolCurent.ora << RESET 
                                 << " (" << (spectacolCurent.este3D ? "3D" : "2D") << ")\n";
                            cout << " 🏢 Sala:    " << spectacolCurent.numeSala << "\n";
                            cout << " 🪑 Locatie: Randul " << r << ", Locul " << l << "\n";
                            cout << " 💳 Pret:    " << b.calculeazaPret(spectacolCurent.este3D) << " RON (" << b.getNumeTip() << ")\n";
                            cout << VERDE << "==================================================\n" << RESET;
                            
                            cout << "\nApasati Enter pentru a continua...";
                            cin.ignore(); cin.get();
                        }
                    }
                } 
                else if (opt == 9) {
                    inapoiLaOrar = true; 
                }
                else if (opt == 0) {
                    aplicatieInRulare = false; 
                }
            }
        }
    }

    curataEcran();
    cout << "\n" << ALBASTRU << "Va multumim, " << utilizatorCurent << ", ca ati ales Cinema App. La revedere! 🎬\n" << RESET << endl;
    return 0;
}
