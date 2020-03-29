#include "Statystyka.hh"
#include <iostream>

/*
*Inicjalizuje strukture ze statystykami zmieniajac wszystkie jej parametry na 0.
*Argumenty:
*  *stats-wskaźnik do struktury przechowujacej ilosc poprawnych odpowiedzi oraz ilosc pytan.
*/
void inicjalizacja(Statystyka *stats){
    stats->odp=0;
    stats->pop=0;
}

/*
* Funkcja oblicza wynik testu
* Argumenty:
*   stats-struktura statystyk
* Zwraca:
*   Wynik testu w procentach.
*/
float procent(Statystyka stats){
    float wynik=(stats.pop*100/stats.odp);
    return wynik;
}

/*
* Funkcja wypisuje wyniki przeprowadzonego testu.
* Argumenty:
*   stats-struktura statystyk
*/
void pokaz(Statystyka stats){
    std::cout<<"Poprawne odpowiedzi: "<<stats.pop<<std::endl<<"Ilość pytań: "<<stats.odp<<std::endl<<"Wynik: "<<procent(stats)<<'%'<<std::endl;
}