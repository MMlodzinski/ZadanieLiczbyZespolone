#include "LZespolona.hh"
#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::cerr;
using std::showpos;
using std::noshowpos;


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1, LZespolona Skl2){
  LZespolona wynik;

  wynik.re=Skl1.re-Skl2.re;
  wynik.im=Skl1.im-Skl2.im;
  return wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona wynik;

  wynik.re=Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  wynik.im=Skl1.re*Skl1.im+Skl1.im*Skl2.re;
  return wynik;
}

/*LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona wynik;

  wynik.re=(Skl1.re*Skl2.re+Skl1.im*Skl2.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im);
  wynik.im=(Skl1.im*Skl2.re-Skl1.re*Skl2.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im);
  return wynik;
}*/

LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona wynik=(Skl1*sprzezenie(Skl2))%(modul(Skl2)*modul(Skl2));
  return wynik;
}

//sprzezenie
LZespolona  sprzezenie (LZespolona  Skl){
  LZespolona wynik;

  wynik.re=Skl.re;
  wynik.im=Skl.im*(-1);
  return wynik;
}

//modul
double modul (LZespolona Skl){
  double wynik;

  wynik=sqrt(Skl.re*Skl.re+Skl.im*Skl.im);
  return wynik;
}

int operator == (LZespolona Skl1, LZespolona Skl2){
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    return 1;
  else
    return 0; 
}

int operator != (LZespolona Skl1, LZespolona Skl2){
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    return 0;
  else
    return 1; 
}

//operator dzielenia liczby zespolonej przez całkowitą
LZespolona operator % (LZespolona Skl, double dziel){
  LZespolona wynik;

  wynik.re=Skl.re/dziel;
  wynik.im=Skl.im/dziel;
  return wynik;
}

LZespolona utworz(double re, double im){
  LZespolona l;
  l.re=re;
  l.im=im;
  return l;
}

void wyswietl(LZespolona l){
  if(l.im!=0)
    cout<<l.re<<showpos<<l.im<<noshowpos<<"i";
  else
    cout<<l.re;
}

void wczytaj(LZespolona *z){
  char lnawias, pnawias, i;
  cin>>lnawias>>z->re>>z->im>>i>>pnawias;
  if(lnawias!='(' || pnawias!=')' || i!='i')
  {
    cerr<<"zle napisana liczba zespolona";
  }
}
