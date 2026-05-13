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
const string ROSU = "\033[31m";

// Functie actualizata pentru afisarea hartii salii in functie de dimensiuni
void afisareSala(const vector<Loc>& sala, int locuriPerRand) {
    const string BULINA = "●"; 

    cout << "\n      " << BOLD << "--- ECRAN CINEMA ---" << RESET << "\n\n";
    cout << "        ";
    for(int j = 1; j <= locuriPerRand; j++) cout << (j < 10 ? to_string(j) + "  " : to_string(j) + " ");
    cout << "(Locuri)\n";

    int randCurent = 1;
    cout << "R. " << randCurent << " | ";
    
    for (size_t i = 0; i < sala.size(); i++) {
        if (sala[i].status()) {
            cout << GRI << BULINA << "  " << RESET;
        } else {
            cout << VERDE << BULINA << "  " << RESET;
        }
        
        // Trecerea la urmatorul rand folosind variabila locuriPerRand
        if ((i + 1) % locuriPerRand == 0 && (i + 1) < sala.size()) {
            randCurent++;
            cout << "\nR. " << randCurent << " | ";
        }
    }
    cout << "\n\n" << GRI << "(Legenda: " << VERDE << "● Liber " << GRI << "● Ocupat)" << RESET << "\n";
}

int main() {
    // Configurare terminal pentru caractere speciale (util pentru Windows)
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    cout << ALBASTRU << "===========================================" << RESET << endl;
    cout << BOLD << "   🍿 BINE ATI VENIT LA CINEMA APP 🍿" << RESET << endl;
    cout << ALBASTRU << "===========================================" << RESET << endl;

    string numeFilm;
    int tipFormat;
    bool este3D;

    cout << GALBEN << "➤ " << RESET << "Numele filmului: ";
    getline(cin >> ws, numeFilm); 
    cout << GALBEN << "➤ " << RESET << "Format (1 pentru 3D Premium, 0 pentru 2D Standard): ";
    cin >> tipFormat;
    este3D = (tipFormat == 1);

    Film filmCurent(numeFilm, este3D);

    // Definirea dimensiunilor in functie de tipul salii
    int nrRanduri, nrLocuriPerRand;
    string tipSala;

    if (este3D) {
        // Sala 3D: Mai mica, tip VIP/Premium
        nrRanduri = 4;
        nrLocuriPerRand = 6;
        tipSala = "PREMIUM 3D (Configuratie 4x6)";
    } else {
        // Sala 2D: Standard, mai mare
        nrRanduri = 6;
        nrLocuriPerRand = 10;
        tipSala = "STANDARD 2D (Configuratie 6x10)";
    }

    cout << "\nAti ales sala: " << BOLD << tipSala << RESET << "\n";

    // Initializarea salii cu dimensiunile specifice
    vector<Loc> cinema;
    for (int r = 1; r <= nrRanduri; r++) {
        for (int l = 1; l <= nrLocuriPerRand; l++) {
            cinema.push_back(Loc(r, l, false));
        }
    }

    string numeZi;
    cout << GALBEN << "➤ " << RESET << "Ziua saptamanii: ";
    cin >> numeZi;

    int optiune;
    do {
        cout << "\n" << ALBASTRU << "----------- MENIU PRINCIPAL -----------" << RESET << endl;
        cout << "Film: " << BOLD << filmCurent.titlu << RESET << (este3D ? " (3D)" : " (2D)") << endl;
        cout << "1. Vezi harta salii" << endl;
        cout << "2. Rezerva un loc" << endl;
        cout << "0. Iesire" << endl;
        cout << ALBASTRU << "---------------------------------------" << RESET << endl;
        cout << "Optiunea dvs: ";
        cin >> optiune;

        if (optiune == 1) {
            afisareSala(cinema, nrLocuriPerRand);
        } 
        else if (optiune == 2) {
            int rDorit, lDorit;
            cout << "\n" << BOLD << "Sectiune Rezervare (" << tipSala << "):" << RESET << endl;
            cout << "Rand (1-" << nrRanduri << "): "; cin >> rDorit;
            cout << "Loc (1-" << nrLocuriPerRand << "): "; cin >> lDorit;

            // Validare si calcul index folosind dimensiunile salii alese
            if (rDorit < 1 || rDorit > nrRanduri || lDorit < 1 || lDorit > nrLocuriPerRand) {
                cout << ROSU << "Eroare: Locul nu exista in aceasta sala!" << RESET << "\n";
            } 
            else {
                int index = (rDorit - 1) * nrLocuriPerRand + (lDorit - 1);

                if (cinema[index].status()) {
                    cout << ROSU << "Eroare: Acest loc este deja ocupat!" << RESET << "\n";
                } 
                else {
                    int tipP;
                    cout << "Categorie (1.Adult, 2.Elev, 3.Copil, 4.Dizab): ";
                    cin >> tipP;

                    Bilet b(tipP, numeZi);
                    cinema[index].ocupaLoc();

                    cout << "\n" << VERDE << "✔ REZERVARE FINALIZATA!" << RESET << endl;
                    cout << "Pret: " << BOLD << b.calculeazaPret(filmCurent.este3D) << " RON" << RESET << endl;
                }
            }
        }
    } while (optiune != 0);

    return 0;
}
