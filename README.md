Acesta este un proiect de tip consolă pentru gestionarea rezervărilor într-o sală de cinema. Programul este structurat modular, folosind clase separate pentru locuri și bilete.

Funcționalități
Harta Sălii: Afișare tabelară pe rânduri și locuri (L = Liber, XX = Ocupat).

Categorii Preț: Calcul automat pentru Adult, Elev, Copil și Persoane cu dizabilități.

Reducere Vineri: Preț unic de 15 RON în fiecare vineri, indiferent de categoria aleasă.

Input Case-Insensitive: Ziua săptămânii poate fi scrisă cu litere mari sau mici (ex: Vineri, vineri, VINERI).

Structura Fișierelor
Loc.h / Loc.cpp - Clasa pentru obiectele de tip scaun (stare, rând, număr).

Bilet.h / Bilet.cpp - Clasa pentru logica de calcul a prețului și validarea zilelor.

main.cpp - Interfața cu utilizatorul și controlul fluxului programului.

Compilare și Rulare
Pentru a compila proiectul, rulează următoarea comandă în terminal:

Bash
g++ main.cpp Loc.cpp Bilet.cpp -o cinema
Pentru a rula programul:

Bash
./cinema
Utilizare
La pornire, introduceți ziua săptămânii.

Folosiți meniul interactiv pentru a vedea sala sau pentru a rezerva un loc.

Pentru rezervare, introduceți rândul (1-3) și locul (1-10).

Selectați categoria de bilet pentru a primi prețul final.
