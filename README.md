Sistem de Gestiune și Rezervare Cinema (Arhitectură Modulară C++)
Prezentul proiect constituie o aplicație de tip consolă destinată automatizării procesului de rezervare a locurilor într-o sală de cinema. Soluția este dezvoltată utilizând paradigma programării orientate pe obiecte (POO), asigurând o separare clară a responsabilităților prin module dedicate.

Funcționalități Principale
Gestiunea Dinamică a Locurilor: Reprezentarea grafică a sălii sub formă matricială, permițând identificarea rapidă a disponibilității: L pentru loc disponibil și XX pentru loc rezervat.

Sistem de Tarifare Diferențiat: Implementarea unei logici de calcul automat al prețului în funcție de profilul utilizatorului, acoperind categoriile: Adult, Elev, Copil și Persoane cu dizabilități.

Politici Comerciale Speciale: Integrarea unui algoritm de tip Flat Rate pentru zilele de vineri, aplicând un tarif promoțional unic de 15 RON pentru toți utilizatorii.

Procesarea Flexibilă a Datelor (Case-Insensitivity): Modulul de validare a datelor de intrare permite procesarea corectă a zilelor săptămânii, indiferent de utilizarea majusculelor sau minusculelor în textul introdus.

Arhitectura Sistemului
Aplicația este structurată pe trei paliere fundamentale pentru a asigura mentenanța și scalabilitatea codului:

Modulul Loc (Loc.h / Loc.cpp): Definește entitatea scaun, gestionând coordonatele specifice (rând, număr) și starea de ocupare a acestuia.

Modulul Bilet (Bilet.h / Bilet.cpp): Încapsulează întreaga logică de business referitoare la tarife, categorii de vârstă și excepții calendaristice.

Nucleul aplicației (main.cpp): Orchestrează interacțiunea cu utilizatorul și fluxul logic al operațiunilor de rezervare.

Procedura de Compilare și Execuție
Pentru asamblarea modulelor într-un fișier binar executabil, utilizați compilatorul g++ cu următoarea sintaxă în terminal:

g++ main.cpp Loc.cpp Bilet.cpp -o cinema_complet

Lansarea aplicației se realizează prin comanda:

./cinema_complet

Ghid de Utilizare
Configurare Context: La inițializarea programului, specificați ziua curentă a săptămânii prin introducerea numelui acesteia.

Navigare Meniu: Utilizați interfața numerică pentru a consulta starea actuală a sălii sau pentru a iniția o nouă rezervare.

Selecție Coordonate: Rezervarea necesită introducerea succesivă a rândului (intervalul 1-3) și a locului specific (intervalul 1-10).

Finalizare Tranzacție: Selectați categoria corespunzătoare pentru emiterea biletului și afișarea valorii fiscale finale.
