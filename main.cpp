#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include "Loc.h"
#include "Bilet.h"
#include "Film.h"
#include "Spectacol.h"

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

// Functie pentru popularea bazei de date a cinematografului
vector<Film> initializareCinema() {
    vector<Film> filme;

    // 1. AVATAR
    Film avatar("Avatar: The Way of Water", R"(
       .
      / \
     /   \   <O>
    /_____\  /|\
      |||    / \
    )");
    avatar.adaugaSpectacol("12:00", true, "Sala 1 (IMAX)");
    avatar.adaugaSpectacol("15:30", false, "Sala 4 (Standard)");
    avatar.adaugaSpectacol("18:00", true, "Sala 1 (IMAX)");
    avatar.adaugaSpectacol("20:45", true, "Sala VIP 3D");
    filme.push_back(avatar);

    // 2. DUNE
    Film dune("Dune: Part Two", R"(
      /\  _  _  /\
     /  \/ \/ \/  \
    /__________\___\
    )");
    dune.adaugaSpectacol("13:00", false, "Sala 2 (Standard)");
    dune.adaugaSpectacol("16:00", false, "Sala 2 (Standard)");
    dune.adaugaSpectacol("19:30", true, "Sala 3 (Atmos 3D)");
    dune.adaugaSpectacol("22:00", true, "Sala 3 (Atmos 3D)");
    filme.push_back(dune);

    // 3. DEADPOOL
    Film deadpool("Deadpool & Wolverine", R"(
      ( X _ X )
       \|/ \W/
    )");
    deadpool.adaugaSpectacol("14:00", false, "Sala 5 (Standard)");
    deadpool.adaugaSpectacol("17:15", false, "Sala 5 (Standard)");
    deadpool.adaugaSpectacol("20:00", true, "Sala 6 (3D)");
    deadpool.adaugaSpectacol("23:15", false, "Sala VIP 2D");
    filme.push_back(deadpool);

    return filme;
}

int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    vector<Film> listaFilme = initializareCinema();
    bool aplicatieInRulare = true;

    curataEcran();
    cout << ALBASTRU << "===============================================" << RESET << endl;
    cout << BOLD << "       ✨ Bine ati venit la Cinema App ✨" << RESET << endl;
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
        
        for (size_t i = 0; i < listaFilme.size(); i++) {
            cout << VERDE << i + 1 << ". " << RESET << BOLD << listaFilme[i].titlu << RESET << "\n";
        }
        cout << ROSU << "0. " << RESET << "Iesire aplicatie\n";
        cout << "-----------------------------------------------" << endl;
        
        cout << GALBEN << "➤ " << RESET << "Alege un film (1-" << listaFilme.size() << "): ";
        int indexFilm; cin >> indexFilm;

        if (indexFilm == 0) break;
        if (indexFilm < 1 || indexFilm > (int)listaFilme.size()) {
            cout << ROSU << "Selectie invalida! Apasa Enter pentru a continua..." << RESET;
            cin.ignore(); cin.get();
            continue;
        }

        int filmSelectat = indexFilm - 1;
        bool inapoiLaFilme = false;

        while (!inapoiLaFilme && aplicatieInRulare) {
            curataEcran();
            cout << CYAN << listaFilme[filmSelectat].asciiArt << RESET << endl;
            cout << BOLD << "Film: " << listaFilme[filmSelectat].titlu << RESET << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "PROGRAMARI DISPONIBILE:\n";
            
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
            // Extragem referinta catre spectacolul ales pentru a salva locurile permanent
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
    cout << "\n" << ALBASTRU << "Va multumim ca ati ales Cinema App. La revedere! 🎬\n" << RESET << endl;
    return 0;
}
