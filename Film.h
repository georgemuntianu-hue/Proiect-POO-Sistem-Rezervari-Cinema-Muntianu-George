#ifndef FILM_H
#define FILM_H
#include <string>
class Film {
public:
std::string titlu;
bool este3D;
Film(std::string t = "Nespecificat", bool d3 = false)
: titlu(t), este3D(d3) {}
};
#endif