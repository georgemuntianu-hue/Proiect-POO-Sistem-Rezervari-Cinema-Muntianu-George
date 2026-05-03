#ifndef BILET_H
#define BILET_H

#include <string>

class Bilet {
private:
    int tipPersoana;
    std::string ziSaptamana;
    float pret;

public:
    Bilet(int tip, std::string zi);
    float calculeazaPret(bool este3D); // Modificat aici
    std::string getNumeTip();
    static std::string toLower(std::string data);
};

#endif
