#ifndef AUTENTIFICARE_H
#define AUTENTIFICARE_H

#include <string>

class ManagerAutentificare {
private:
    std::string fisierDate;
    bool utilizatorExista(const std::string& username);

public:
    ManagerAutentificare(std::string fisier = "utilizatori.txt");
    bool inregistrare(const std::string& username, const std::string& parola);
    bool logare(const std::string& username, const std::string& parola);
};

#endif