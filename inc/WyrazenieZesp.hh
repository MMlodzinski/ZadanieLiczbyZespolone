#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"



/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */


/*void Wyswietl(WyrazenieZesp  WyrZ);*/
LZespolona Oblicz(WyrazenieZesp  WyrZ);
/*std::istream & operator >> (std::istream & strm, WyrazenieZesp & wyraz);
std::istream & operator >> (std::istream & strm, Operator & op);*/
std::ostream & operator << (std::ostream & strm, WyrazenieZesp & wyraz);
std::ostream & operator << (std::ostream & strm, Operator & op);


#endif
