#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Pentru system("clear")
#include "Loc.h"
#include "Bilet.h"
#include "Film.h"

using namespace std;

// Culori ANSI pentru un aspect ingrijit
const string VERDE = "\033[32m";
const string GALBEN = "\033[33m";
const string ALBASTRU = "\033[34m";
const string GRI = "\033[90m";
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string ROSU = "\033[31m";

// Functie pentru curatarea ecranului (Linux/Windows)
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

    while (true) {
        curataEcran();
        // Mesaj de bun venit elegant
        cout << ALBASTRU << "===============================================" << RESET << endl;
        cout << BOLD << "       ✨ Bine ati venit! Cu ce va pot ajuta? ✨" << RESET << endl;
        cout << ALBASTRU << "===============================================" << RESET << endl;
        
        cout << "\n" << GALBEN << "➤ " << RESET << "Pentru inceput, va rugam sa introduceti numele filmului: ";
        string numeFilm;
        getline(cin >> ws, numeFilm); 

        // O modalitate discreta de iesire, fara a fi pusa in fata utilizatorului
        if (numeFilm == "admin_exit") break;

        cout << GALBEN << "➤ " << RESET << "Selectati formatul dorit (1 pentru 3D Premium, 0 pentru 2D Standard): ";
        int tipFormat; cin >> tipFormat;
        bool este3D = (tipFormat == 1);

        Film filmCurent(numeFilm, este3D);
        int nrRanduri = este3D ? 4 : 6;
        int nrLocuriPerRand = este3D ? 6 : 10;
        
        vector<Loc> cinema;
        for (int r = 1; r <= nrRanduri; r++)
            for (int l = 1; l <= nrLocuriPerRand; l++)
                cinema.push_back(Loc(r, l, false));

        cout << GALBEN << "➤ " << RESET << "In ce zi doriti sa vizionati filmul? ";
        string numeZi; cin >> numeZi;

        bool biletCumparat = false;
        while (!biletCumparat) {
            cout << "\n" << BOLD << "-----------------------------------------------" << RESET << endl;
            cout << "Sunteti la filmul: " << ALBASTRU << BOLD << filmCurent.titlu << RESET;
            cout << (este3D ? " [Format 3D]" : " [Format 2D]") << endl;
            cout << "Optiunile dumneavoastra sunt:" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << VERDE << " 1." << RESET << " Vizualizare locuri disponibile" << endl;
            cout << VERDE << " 2." << RESET << " Rezervare si achizitie bilet" << endl;
            cout << GRI << " 0." << RESET << " Schimbare film / Inapoi" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Alegerea dumneavoastra: ";
            int opt; cin >> opt;

            if (opt == 1) {
                afisareSala(cinema, nrLocuriPerRand);
            } 
            else if (opt == 2) {
                int r, l;
                cout << "\nIntroduceti Randul: "; cin >> r;
                cout << "Introduceti Locul: "; cin >> l;

                if (r < 1 || r > nrRanduri || l < 1 || l > nrLocuriPerRand) {
                    cout << ROSU << "Ne pare rau, acest loc nu exista in sala noastra." << RESET << endl;
                } else {
                    int index = (r - 1) * nrLocuriPerRand + (l - 1);
                    if (cinema[index].status()) {
                        cout << ROSU << "Acest loc este deja rezervat. Va rugam sa alegeti altul." << RESET << endl;
                    } else {
                        cout << "Categorie (1.Adult, 2.Elev, 3.Copil, 4.Pers. cu dizabilitati): ";
                        int tp; cin >> tp;
                        
                        Bilet b(tp, numeZi);
                        cinema[index].ocupaLoc();

                        // Mesaj final elegant
                        curataEcran();
                        cout << VERDE << "\n===============================================" << RESET << endl;
                        cout << BOLD << "     VĂ MULȚUMIM PENTRU ACHIZIȚIE! 🍿" << RESET << endl;
                        cout << BOLD << "          VIZIONARE PLĂCUTĂ! 🎬" << RESET << endl;
                        cout << VERDE << "===============================================" << RESET << endl;
                        cout << " Detalii: " << BOLD << filmCurent.titlu << RESET << " | " << b.calculeazaPret(este3D) << " RON\n";
                        cout << " Locatie: Randul " << r << ", Locul " << l << "\n";
                        cout << "===============================================\n" << endl;
                        
                        cout << "Apasati orice tasta pentru a reveni la meniul principal...";
                        string pauza; cin >> pauza;
                        biletCumparat = true; 
                    }
                }
            } 
            else if (opt == 0) {
                break; 
            }
        }
    }

    return 0;
}
