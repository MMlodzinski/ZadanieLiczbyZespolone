#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

struct  Statystyka {
  int odp;
  int pop;
};

void inicjalizacja(Statystyka *stats);
float procent(Statystyka stats);
void pokaz(Statystyka stats);

#endif