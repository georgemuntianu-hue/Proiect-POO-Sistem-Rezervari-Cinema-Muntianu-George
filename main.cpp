#include <iostream>
#include <vector>
#include <string>
#include "Loc.h"
#include "Bilet.h"

using namespace std;

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
    vector<Loc> cinema;
    for (int r = 1; r <= 3; r++) {
        for (int l = 1; l <= 10; l++) {
            cinema.push_back(Loc(r, l, false));
        }
    }

    string numeZi;
    cout << "Introduceti ziua saptamanii (ex: Luni, Vineri, sambata): ";
    cin >> numeZi;

    int optiune;
    do {
        cout << "\n1. Sala | 2. Rezerva | 0. Iesire\nOptiune: ";
        cin >> optiune;

        if (optiune == 2) {
            int rDorit, lDorit;
            cout << "Rand (1-3): "; cin >> rDorit;
            cout << "Loc (1-10): "; cin >> lDorit;

            int index = (rDorit - 1) * 10 + (lDorit - 1);

            if (rDorit < 1 || rDorit > 3 || lDorit < 1 || lDorit > 10) {
                cout << "Loc inexistat!\n";
            } else if (cinema[index].status()) {
                cout << "Locul este deja ocupat!\n";
            } else {
                int tip;
                cout << "Categorie: 1.Adult 2.Elev 3.Copil 4.Dizabilitati: ";
                cin >> tip;

                Bilet b(tip, numeZi);
                cinema[index].ocupaLoc();

                cout << "\n--- BILET GENERAT ---" << endl;
                cout << "Zi: " << numeZi << " | Categorie: " << b.getNumeTip() << endl;
                cout << "Locatie: R" << rDorit << " L" << lDorit << endl;
                cout << "PRET: " << b.calculeazaPret() << " RON" << endl;
            }
        } else if (optiune == 1) {
            afisareSala(cinema);
        }
    } while (optiune != 0);

    return 0;
}