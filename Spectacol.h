#ifndef SPECTACOL_H
#define SPECTACOL_H

#include <string>
#include <vector>
#include "Loc.h"

class Spectacol {
public:
    std::string ora;
    bool este3D;
    std::string numeSala;
    int nrRanduri;
    int nrLocuriPerRand;
    std::vector<Loc> sala; // Fiecare spectacol are propria sa sala cu locuri!

    Spectacol(std::string o, bool d3, std::string nSala);
    void initializareSala();
};

#endif