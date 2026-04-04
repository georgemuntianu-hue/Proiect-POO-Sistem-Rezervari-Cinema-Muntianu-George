#ifndef BILET_H
#define BILET_H

#include <string>

class Bilet {
private:
    int tipPersoana;
    std::string ziSaptamana; // Acum e string ("luni", "vineri", etc.)
    float pret;

public:
    Bilet(int tip, std::string zi);
    float calculeazaPret();
    std::string getNumeTip();
    static std::string toLower(std::string data); // Functie utilitara
};

#endif