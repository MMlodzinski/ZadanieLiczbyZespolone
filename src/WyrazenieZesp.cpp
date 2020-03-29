#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

#include <iostream>

using std::cout;
using std::showpos;
using std::noshowpos;


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

/*
void Wyswietl(WyrazenieZesp WyrZ){
  if (WyrZ.Arg1.re==0)
  {
    if (WyrZ.Arg1.im==0)
        cout<<0;
    else
        cout<<"("<<WyrZ.Arg1.im<<"i)";
    
  }
  else
  {
    if (WyrZ.Arg1.im==0)
        cout<<"("<<WyrZ.Arg1.re<<")";
    else
        cout<<"("<<WyrZ.Arg1.re<<showpos<<WyrZ.Arg1.im<<noshowpos<<"i)";
  }

switch (WyrZ.Op)
{
case 0:
    cout<<"+";
    break;
case 1:
    cout<<"-";
    break;
case 2:
    cout<<"*";
    break;
case 3:
    cout<<"/";
    break;
}

  if (WyrZ.Arg2.re==0)
  {
    if (WyrZ.Arg2.im==0)
        cout<<0;
    else
        cout<<"("<<WyrZ.Arg2.im<<"i)";
    
  }
  else
  {
    if (WyrZ.Arg2.im==0)
        cout<<"("<<WyrZ.Arg2.re<<")";
    else
        cout<<"("<<WyrZ.Arg2.re<<showpos<<WyrZ.Arg2.im<<noshowpos<<"i)";
  }
  
}
*/

/*
* Funkcja oblicza wyrażenie zespolone.
* Argumenty:
*   WyrZ-wyrazenie zespolone ktore bedzie obliczane
* Zwraca:
*   Wynik wyrazenia zespolonego
*/
LZespolona Oblicz(WyrazenieZesp  WyrZ){
    LZespolona wynik;
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        wynik=WyrZ.Arg1+WyrZ.Arg2;
        break;
    case Op_Odejmij:
        wynik=WyrZ.Arg1-WyrZ.Arg2;
        break;
    case Op_Mnoz:
        wynik=WyrZ.Arg1*WyrZ.Arg2;
        break;
    case Op_Dziel:
        wynik=WyrZ.Arg1/WyrZ.Arg2;
        break;    
    }
    return wynik;
    
}

/*
std::istream & operator >> (std::istream & strm, WyrazenieZesp & wyraz) {
  strm >> wyraz.Arg1 >> wyraz.Op >> wyraz.Arg2;
  return strm;
}

std::istream & operator >> (std::istream & strm, Operator & op) {
  char znak;
  strm >> znak;
  if(znak!='+' && znak!='-' && znak!='*' && znak!='/')strm.setstate(std::ios::failbit);
  switch (znak) {
  case '+':op = Op_Dodaj;break;
  case '-':op = Op_Odejmij;break;
  case '*':op = Op_Mnoz;break;
  case '/':op = Op_Dziel;break;
  }
  return strm;
}
*/

/*
* Wypisuje wyrazenie zespolone
*/
std::ostream & operator << (std::ostream & strm, WyrazenieZesp & wyraz){
    strm << wyraz.Arg1 << wyraz.Op << wyraz.Arg2;
    return strm;
}

/*
* Wypisuje operator w wyrazeniu zespolonym
*/
std::ostream & operator << (std::ostream & strm, Operator & op){
    switch (op){
    case Op_Dodaj:strm<<'+';break;
    case Op_Odejmij:strm<<'-';break;
    case Op_Mnoz:strm<<'*';break;
    case Op_Dziel:strm<<'/';break;
    }
    return strm;
}

