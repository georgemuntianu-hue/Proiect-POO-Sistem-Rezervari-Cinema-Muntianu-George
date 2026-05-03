#include "Bilet.h"
#include <algorithm>
#include <cctype>

// Transforma textul in litere mici (ex: "ViNeRi" -> "vineri")
std::string Bilet::toLower(std::string data) {
    std::transform(data.begin(), data.end(), data.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return data;
}

// Constructorul clasei
Bilet::Bilet(int tip, std::string zi) : tipPersoana(tip), ziSaptamana(toLower(zi)) {
}

// Metoda pentru calculul pretului (include suplimentul 3D)
float Bilet::calculeazaPret(bool este3D) {
    float p = 0;
    
    if (ziSaptamana == "vineri") {
        p = 15.0; // Promotia de vineri
    } else {
        switch (tipPersoana) {
            case 1: p = 30.0; break; // Adult
            case 2: p = 20.0; break; // Elev
            case 3: p = 10.0; break; // Copil
            case 4: p = 0.0;  break; // Dizabilitati
            default: p = 30.0;
        }
    }

    if (este3D) {
        p += 5.0; // Suplimentul pentru film 3D
    }
    return p;
}

// Metoda pentru obtinerea numelui tipului de bilet
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
