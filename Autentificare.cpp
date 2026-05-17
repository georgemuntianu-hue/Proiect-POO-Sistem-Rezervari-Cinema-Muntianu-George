#include "Autentificare.h"
#include <fstream>
#include <iostream>

// Constructorul setează numele fișierului unde salvăm datele
ManagerAutentificare::ManagerAutentificare(std::string fisier) : fisierDate(fisier) {}

// Metodă privată care verifică dacă un username e deja luat
bool ManagerAutentificare::utilizatorExista(const std::string& username) {
    std::ifstream f(fisierDate);
    if (!f.is_open()) return false; // Daca fisierul nu exista inca, e in regula

    std::string u, p;
    // Citim din fisier perechi de username si parola
    while (f >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

// Metoda pentru crearea unui cont
bool ManagerAutentificare::inregistrare(const std::string& username, const std::string& parola) {
    if (utilizatorExista(username)) {
        return false; // Utilizatorul există deja
    }
    
    // Deschidem fisierul in modul "append" (adaugare la final)
    std::ofstream f(fisierDate, std::ios::app);
    f << username << " " << parola << "\n";
    return true;
}

// Metoda pentru logare
bool ManagerAutentificare::logare(const std::string& username, const std::string& parola) {
    std::ifstream f(fisierDate);
    if (!f.is_open()) return false;

    std::string u, p;
    while (f >> u >> p) {
        if (u == username && p == parola) {
            return true; // S-a gasit o potrivire perfecta
        }
    }
    return false;
}