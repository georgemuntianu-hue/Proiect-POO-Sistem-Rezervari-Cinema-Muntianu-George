#include <iostream>
#include <vector>
#include <string>
#include "Loc.h"
#include "Bilet.h"
#include "Film.h"

using namespace std;

// Culori ANSI pentru interfata
const string VERDE = "\033[32m";
const string GALBEN = "\033[33m";
const string ALBASTRU = "\033[34m";
const string GRI = "\033[90m";
const string RESET = "\033[0m";
const string BOLD = "\033[1m";

void afisareSala(const vector<Loc>& sala) {
    const string BULINA = "●"; 

    cout << "\n      " << BOLD << "--- ECRAN CINEMA ---" << RESET << "\n\n";
    cout << "        1  2  3  4  5  6  7  8  9  10 (Locuri)\n";
    int randCurent = 1;
    cout << "R. " << randCurent << " | ";
    
    for (size_t i = 0; i < sala.size(); i++) {
        if (sala[i].status()) {
            cout << GRI << BULINA << "  " << RESET;
        } else {
            cout << VERDE << BULINA << "  " << RESET;
        }
        
        if ((i + 1) % 10 == 0 && (i + 1) < sala.size()) {
            randCurent++;
            cout << "\nR. " << randCurent << " | ";
        }
    }
    cout << "\n\n" << GRI << "(Legenda: " << VERDE << "● Liber " << GRI << "● Ocupat)" << RESET << "\n";
}

int main() {
    // Mesaj de bun venit interactiv
    cout << ALBASTRU << "===========================================" << RESET << endl;
    cout << BOLD << "   🍿 BINE ATI VENIT LA CINEMA APP 🍿" << RESET << endl;
    cout << ALBASTRU << "===========================================" << RESET << endl;
    cout << "Cu ce va pot ajuta astazi?" << endl;
    cout << "Va rugam sa introduceti datele filmului pentru a incepe.\n" << endl;

    string numeFilm;
    int tipFormat;
    bool este3D;

    cout << GALBEN << "➤ " << RESET << "Numele filmului: ";
    getline(cin >> ws, numeFilm); 
    cout << GALBEN << "➤ " << RESET << "Format (1 pentru 3D, 0 pentru 2D): ";
    cin >> tipFormat;
    este3D = (tipFormat == 1);

    Film filmCurent(numeFilm, este3D);

    vector<Loc> cinema;
    for (int r = 1; r <= 3; r++) {
        for (int l = 1; l <= 10; l++) {
            cinema.push_back(Loc(r, l, false));
        }
    }

    string numeZi;
    cout << GALBEN << "➤ " << RESET << "Ziua saptamanii: ";
    cin >> numeZi;

    int optiune;
    do {
        cout << "\n" << ALBASTRU << "----------- MENIU PRINCIPAL -----------" << RESET << endl;
        cout << "Va rugam selectati optiunea dorita:" << endl;
        cout << VERDE << " 1. " << RESET << "Vezi harta salii" << endl;
        cout << VERDE << " 2. " << RESET << "Rezerva un loc nou" << endl;
        cout << GRI << " 0. " << RESET << "Iesire din aplicatie" << endl;
        cout << ALBASTRU << "---------------------------------------" << RESET << endl;
        cout << "Optiunea dvs: ";
        cin >> optiune;

        if (optiune == 1) {
            afisareSala(cinema);
        } 
        else if (optiune == 2) {
            int rDorit, lDorit;
            cout << "\n" << BOLD << "Sectiune Rezervare:" << RESET << endl;
            cout << "Introduceti Randul (1-3): "; cin >> rDorit;
            cout << "Introduceti Locul (1-10): "; cin >> lDorit;

            int index = (rDorit - 1) * 10 + (lDorit - 1);

            if (rDorit < 1 || rDorit > 3 || lDorit < 1 || lDorit > 10) {
                cout << "\033[31mEroare: Locul nu exista!\033[0m\n";
            } 
            else if (cinema[index].status()) {
                cout << "\033[31mEroare: Acest loc este deja ocupat!\033[0m\n";
            } 
            else {
                int tipP;
                cout << "Categorie (1.Adult, 2.Elev, 3.Copil, 4.Dizab): ";
                cin >> tipP;

                Bilet b(tipP, numeZi);
                cinema[index].ocupaLoc();

                cout << "\n" << VERDE << "✔ REZERVARE FINALIZATA CU SUCCES!" << RESET << endl;
                cout << "---------------------------------------" << endl;
                cout << "Film: " << BOLD << filmCurent.titlu << RESET << (filmCurent.este3D ? " (3D)" : " (2D)") << endl;
                cout << "Locatie: Randul " << rDorit << ", Locul " << lDorit << endl;
                cout << "Pret total: " << BOLD << b.calculeazaPret(filmCurent.este3D) << " RON" << RESET << endl;
                cout << "---------------------------------------" << endl;
            }
        }
    } while (optiune != 0);

    cout << "\nVa multumim ca ati ales cinema-ul nostru! O zi buna! 🎬\n";

    return 0;
}
