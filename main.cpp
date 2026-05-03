#include <iostream>
#include <vector>
#include <string>
#include "Loc.h"
#include "Bilet.h"
#include "Film.h"

using namespace std;

// Functie pentru afisarea hartii salii
void afisareSala(const vector<Loc>& sala) {
    cout << "\n      --- ECRAN CINEMA ---\n\n";
    cout << "        1  2  3  4  5  6  7  8  9  10 (Locuri)\n";
    int randCurent = 1;
    cout << "R. " << randCurent << " | ";
    for (size_t i = 0; i < sala.size(); i++) {
        if (sala[i].status()) cout << "XX ";
        else cout << "L  ";
        
        if ((i + 1) % 10 == 0 && (i + 1) < sala.size()) {
            randCurent++;
            cout << "\nR. " << randCurent << " | ";
        }
    }
    cout << "\n";
}

int main() {
    string numeFilm;
    int tipFormat;
    bool este3D;

    // Pasul 1: Configurarea filmului
    cout << "Introduceti numele filmului: ";
    getline(cin >> ws, numeFilm); 
    cout << "Alegeti formatul (1 pentru 3D, 0 pentru 2D): ";
    cin >> tipFormat;
    este3D = (tipFormat == 1);

    Film filmCurent(numeFilm, este3D);

    // Pasul 2: Initializarea salii (3 randuri x 10 locuri)
    vector<Loc> cinema;
    for (int r = 1; r <= 3; r++) {
        for (int l = 1; l <= 10; l++) {
            cinema.push_back(Loc(r, l, false));
        }
    }

    string numeZi;
    cout << "Introduceti ziua saptamanii (ex: luni, vineri): ";
    cin >> numeZi;

    int optiune;
    do {
        cout << "\n1. Sala | 2. Rezerva | 0. Iesire\nOptiune: ";
        cin >> optiune;

        if (optiune == 1) {
            afisareSala(cinema);
        } 
        else if (optiune == 2) {
            int rDorit, lDorit;
            cout << "Rand (1-3): "; cin >> rDorit;
            cout << "Loc (1-10): "; cin >> lDorit;

            // Calcul index pentru vectorul de tip Loc
            int index = (rDorit - 1) * 10 + (lDorit - 1);

            if (rDorit < 1 || rDorit > 3 || lDorit < 1 || lDorit > 10) {
                cout << "Loc inexistent!\n";
            } 
            else if (cinema[index].status()) {
                cout << "Locul este deja ocupat!\n";
            } 
            else {
                int tipP;
                cout << "Categorie (1.Adult 2.Elev 3.Copil 4.Dizab): ";
                cin >> tipP;

                // Creare obiect bilet si marcare loc ca ocupat
                Bilet b(tipP, numeZi);
                cinema[index].ocupaLoc();

                cout << "\n--- BILET REZERVAT ---\n";
                cout << "Film: " << filmCurent.titlu << (filmCurent.este3D ? " (3D)" : " (2D)") << endl;
                cout << "Locatie: Rand " << rDorit << ", Loc " << lDorit << endl;
                cout << "Pret: " << b.calculeazaPret(filmCurent.este3D) << " RON" << endl;
            }
        }
    } while (optiune != 0);

    return 0;
}
