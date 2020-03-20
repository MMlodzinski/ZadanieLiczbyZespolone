#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona utworz(double re, double im);
void wyswietl(LZespolona);
LZespolona wczytaj();


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  sprzezenie (LZespolona  Skl);
double modul (LZespolona Skl);
int operator == (LZespolona Skl1, LZespolona Skl2);
int operator != (LZespolona Skl1, LZespolona Skl2);
LZespolona operator % (LZespolona Skl, double dziel);
std::istream & operator >> (std::istream & strm, LZespolona &Z1);
std::ostream & operator << (std::ostream & strm, LZespolona &Z1);




#endif
