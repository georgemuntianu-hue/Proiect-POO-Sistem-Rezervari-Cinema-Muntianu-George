#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include "Loc.h"
#include "Bilet.h"
#include "Film.h"

using namespace std;

// Culori ANSI
const string VERDE = "\033[32m";
const string GALBEN = "\033[33m";
const string ALBASTRU = "\033[34m";
const string GRI = "\033[90m";
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string ROSU = "\033[31m";

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

int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    bool aplicatieInRulare = true;

    while (aplicatieInRulare) {
        curataEcran();
        cout << ALBASTRU << "===============================================" << RESET << endl;
        cout << BOLD << "       ✨ Bine ati venit! Cu ce va pot ajuta? ✨" << RESET << endl;
        cout << ALBASTRU << "===============================================" << RESET << endl;
        
        cout << "\n" << GALBEN << "➤ " << RESET << "Introduceti numele filmului (sau 'exit' pt inchidere): ";
        string numeFilm;
        getline(cin >> ws, numeFilm); 

        if (numeFilm == "exit" || numeFilm == "0") break;

        cout << GALBEN << "➤ " << RESET << "Selectati formatul (1 pentru 3D Premium, 0 pentru 2D Standard): ";
        int tipFormat; cin >> tipFormat;
        bool este3D = (tipFormat == 1);

        Film filmCurent(numeFilm, este3D);
        int nrRanduri = este3D ? 4 : 6;
        int nrLocuriPerRand = este3D ? 6 : 10;
        
        vector<Loc> cinema;
        for (int r = 1; r <= nrRanduri; r++)
            for (int l = 1; l <= nrLocuriPerRand; l++)
                cinema.push_back(Loc(r, l, false));

        cout << "\n" << ALBASTRU << BOLD << "💡 INFO: " << RESET << "In ziua de " << VERDE << "vineri" << RESET << " avem o promotie speciala\n";
        cout << "          pentru orice tip de bilet (doar 15 RON)!" << endl;
        cout << GALBEN << "➤ " << RESET << "In ce zi doriti vizionarea? ";
        string numeZi; cin >> numeZi;

        bool inapoiLaFilm = false;
        bool hartaModificata = false; // Variabila care tine minte daca s-a cumparat un bilet
        
        // Bucla pentru meniul filmului
        while (!inapoiLaFilm && aplicatieInRulare) {
            cout << "\n" << BOLD << "-----------------------------------------------" << RESET << endl;
            cout << "Film selectat: " << ALBASTRU << BOLD << filmCurent.titlu << RESET;
            cout << (este3D ? " [3D]" : " [2D]") << " | Zi: " << BOLD << numeZi << RESET << endl;
            cout << "Optiunile dumneavoastra sunt:" << endl;
            cout << "-----------------------------------------------" << endl;
            
            // Textul se schimba dinamic daca s-a achizitionat un bilet
            if (hartaModificata) {
                cout << VERDE << " 1." << RESET << " Vizualizare harta sala (actualizata)" << endl;
            } else {
                cout << VERDE << " 1." << RESET << " Vizualizare harta sala" << endl;
            }
            
            cout << VERDE << " 2." << RESET << " Rezervare si achizitie bilet" << endl;
            cout << GRI << " 9." << RESET << " Schimbare film / Inapoi la selectie" << endl;
            cout << ROSU << " 0." << RESET << " Iesire din aplicatie" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Alegerea dumneavoastra: ";
            int opt; cin >> opt;

            if (opt == 1) {
                afisareSala(cinema, nrLocuriPerRand);
            } 
            else if (opt == 2) {
                int r, l;
                cout << "\nIntroduceti Randul (1-" << nrRanduri << "): "; cin >> r;
                cout << "Introduceti Locul (1-" << nrLocuriPerRand << "): "; cin >> l;

                if (r < 1 || r > nrRanduri || l < 1 || l > nrLocuriPerRand) {
                    cout << ROSU << "Eroare: Acest loc nu exista in sala." << RESET << endl;
                } else {
                    int index = (r - 1) * nrLocuriPerRand + (l - 1);
                    if (cinema[index].status()) {
                        cout << ROSU << "Ne pare rau, locul este deja ocupat!" << RESET << endl;
                    } else {
                        cout << "Categorie (1.Adult, 2.Elev, 3.Copil, 4.Dizab): ";
                        int tp; cin >> tp;
                        
                        Bilet b(tp, numeZi);
                        cinema[index].ocupaLoc();
                        
                        hartaModificata = true; // Acum harta s-a modificat!

                        cout << VERDE << "\n===============================================" << RESET << endl;
                        cout << BOLD << "     VĂ MULȚUMIM PENTRU ACHIZIȚIE! 🍿" << RESET << endl;
                        cout << BOLD << "          VIZIONARE PLĂCUTĂ! 🎬" << RESET << endl;
                        cout << VERDE << "===============================================" << RESET << endl;
                        cout << " Detalii bilet: " << b.calculeazaPret(este3D) << " RON\n";
                        cout << " Locatie: Randul " << r << ", Locul " << l << "\n";
                        cout << "===============================================\n";
                    }
                }
            } 
            else if (opt == 9) {
                inapoiLaFilm = true; 
            }
            else if (opt == 0) {
                aplicatieInRulare = false; 
            }
        }
    }

    curataEcran();
    cout << "\n" << ALBASTRU << "Va multumim ca ati ales Cinema App. La revedere! 🎬\n" << RESET << endl;
    
    return 0;
}
