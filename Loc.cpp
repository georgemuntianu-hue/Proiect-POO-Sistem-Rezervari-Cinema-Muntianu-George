#include "Loc.h"

Loc::Loc(int r, int nr, bool status) : rand(r), numar(nr), ocupat(status) {}

int Loc::getNumar() const { return numar; }
int Loc::getRand() const { return rand; }
bool Loc::status() const { return ocupat; }

void Loc::ocupaLoc() { 
    ocupat = true; 
}