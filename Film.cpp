#include "Film.h"

Film::Film(std::string t, std::string art) : titlu(t), asciiArt(art) {}

void Film::adaugaSpectacol(std::string ora, bool este3D, std::string sala) {
    spectacole.push_back(Spectacol(ora, este3D, sala));
}