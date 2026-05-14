# Documentație Tehnică: Sistem Informatic pentru Gestiunea și Rezervarea Resurselor (Cinema)

## 1. Introducere și Obiectivele Proiectului
Prezentul proiect reprezintă o aplicație software dezvoltată în limbajul **C++**, având ca scop simularea unui sistem complex de gestiune a resurselor și de procesare a tranzacțiilor (rezervări de bilete) în cadrul unui cinematograf. 

Obiectivul principal din punct de vedere educațional este implementarea riguroasă a paradigmei **Programării Orientate pe Obiecte (POO)**, punând accent pe concepte precum modularitatea, încapsularea datelor, decuplarea logicii de business de interfața cu utilizatorul (UI) și utilizarea eficientă a containerelor din *Standard Template Library* (STL).

## 2. Arhitectura Sistemului și Paradigma Orientată pe Obiecte
Aplicația este structurată pe o arhitectură ierarhică, divizată în module (clase) independente, fiecare având responsabilități clar definite, respectând principiul *Single Responsibility*:

* **Clasa `Loc` (Entitatea de bază):**
    * Reprezintă resursa atomică alocabilă.
    * Încapsulează starea (ocupat/liber) și atributele spațiale (rând, număr).
    * Oferă metode de acces (getters) sigure și o metodă de mutație (`ocupaLoc()`) pentru a modifica starea resursei.

* **Clasa `Bilet` (Logica de Business):**
    * Gestionează politicile de tarifare în mod dinamic, luând în calcul categorii multiple de utilizatori (Adult, Elev, Copil, Dizabilități) și suplimente tehnice (formatul 3D).
    * Implementează algoritmi de analiză a condițiilor speciale (ex: politica "Flat Rate" pentru zilele de vineri).
    * Utilizează metode statice și funcții lambda (`std::transform`) pentru validarea robustă a datelor de intrare (*case-insensitivity*).

* **Clasa `Spectacol` (Gestionarea Colecțiilor și Agregare):**
    * Implementează o structură bidimensională (mapată pe un `std::vector` liniar) pentru reprezentarea matriceală a sălii de cinema.
    * Demonstrează polimorfism contextual prin alocarea dinamică a capacității sălii în funcție de formatul proiecției (ex: sălile 3D necesită configurații spațiale restrânse de 4x6, comparativ cu cele standard de 6x10).

* **Clasa `Film` (Compoziție):**
    * Ațasează metadate (titlu, elemente vizuale) și agreghează un vector de instanțe de tip `Spectacol`, creând o ierarhie logică tip *Unu-la-Mai-Mulți*.

## 3. Concepte Tehnice și Algoritmice Evidențiate
* **Utilizarea STL:** Folosirea intensivă a containerului `std::vector` pentru gestionarea dinamică a memoriei, evitând limitările și riscurile array-urilor statice specifice limbajului C.
* **Manipularea Șirurilor de Caractere:** Transformarea șirurilor de intrare prin `std::tolower` pentru a asigura o procesare uniformă a comenzilor introduse de utilizator.
* **Interfața CLI (Command Line Interface) Avansată:** Utilizarea codurilor de evadare ANSI (ANSI escape codes) pentru a genera o hartă cromatică a resurselor disponibile (verde = liber, gri = ocupat), îmbunătățind considerabil experiența utilizatorului (UX) în mediul terminal.
* **Gestionarea Stărilor (State Machine):** Fluxul programului (în `main.cpp`) este controlat printr-o serie de bucle și flag-uri booleene (`aplicatieInRulare`, `inapoiLaOrar`), mimând o mașină de stări finită care permite navigarea bidirecțională prin meniuri.

## 4. Instrucțiuni de Compilare și Rulare
Proiectul necesită un compilator standard de C++ (minim C++11 recomandat, datorită utilizării funcțiilor lambda și a conversiilor de tip `std::to_string`).

**Sintaxa pentru compilare (GCC / G++):**
```bash
g++ main.cpp Loc.cpp Bilet.cpp Film.cpp Spectacol.cpp -o cinema
