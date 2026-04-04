#ifndef LOC_H
#define LOC_H

class Loc {
private:
    int numar;
    int rand;
    bool ocupat;

public:
    // Constructor care primeste si randul si numarul locului
    Loc(int r = 0, int nr = 0, bool status = false);
    
    int getNumar() const; 
    int getRand() const;
    bool status() const;
    void ocupaLoc();
};

#endif