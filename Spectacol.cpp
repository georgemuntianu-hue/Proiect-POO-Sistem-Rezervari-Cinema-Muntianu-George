#include "Spectacol.h"

Spectacol::Spectacol(std::string o, bool d3, std::string nSala) 
    : ora(o), este3D(d3), numeSala(nSala) {
    // Sălile 3D pot fi mai mici (Premium), cele 2D mai mari
    nrRanduri = este3D ? 4 : 6;
    nrLocuriPerRand = este3D ? 6 : 10;
    initializareSala();
}

void Spectacol::initializareSala() {
    for (int r = 1; r <= nrRanduri; r++)
        for (int l = 1; l <= nrLocuriPerRand; l++)
            sala.push_back(Loc(r, l, false));
}