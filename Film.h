#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>
#include "Spectacol.h"

class Film {
public:
    std::string titlu;
    std::string asciiArt; // Aici vom stoca desenul reprezentativ
    std::vector<Spectacol> spectacole;

    Film(std::string t, std::string art);
    void adaugaSpectacol(std::string ora, bool este3D, std::string sala);
};

#endif
