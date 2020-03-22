#include "Statystyka.hh"
#include <iostream>

void inicjalizacja(Statystyka *stats){
    stats->odp=0;
    stats->pop=0;
}

float procent(Statystyka stats){
    float wynik=(stats.pop/stats.odp)*100;
    return wynik;
}

void pokaz(Statystyka stats){
    std::cout<<"Poprawne odpowiedzi: "<<stats.pop<<std::endl<<"Ilość pytań: "<<stats.odp<<std::endl<<"Wynik: "<<procent(stats)<<'%'<<std::endl;
}