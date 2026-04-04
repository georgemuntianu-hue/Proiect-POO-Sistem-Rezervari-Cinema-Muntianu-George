#include "Bilet.h"
#include <algorithm>
#include <cctype>

// Transforma textul in litere mici (ex: "ViNeRi" -> "vineri")
std::string Bilet::toLower(std::string data) {
    std::transform(data.begin(), data.end(), data.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return data;
}

Bilet::Bilet(int tip, std::string zi) : tipPersoana(tip), ziSaptamana(toLower(zi)) {
    pret = calculeazaPret();
}

float Bilet::calculeazaPret() {
    // Verificam daca e vineri (nu conteaza daca a scris Vineri sau vineri)
    if (ziSaptamana == "vineri") {
        return 15.0;
    }

    switch (tipPersoana) {
        case 1: return 30.0; // Adult
        case 2: return 20.0; // Elev
        case 3: return 10.0; // Copil
        case 4: return 0.0;  // Dizabilitati
        default: return 30.0;
    }
}

std::string Bilet::getNumeTip() {
    if (ziSaptamana == "vineri") return "Promotie Vineri";
    switch (tipPersoana) {
        case 1: return "Adult";
        case 2: return "Elev";
        case 3: return "Copil";
        case 4: return "Pers. Dizabilitati";
        default: return "Standard";
    }
}