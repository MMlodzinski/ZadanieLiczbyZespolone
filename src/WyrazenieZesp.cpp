#include "WyrazenieZesp.hh"

#include <iostream>

using std::cout;
using std::showpos;
using std::noshowpos;


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

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

LZespolona Oblicz(WyrazenieZesp  WyrZ){
    LZespolona wynik;
    switch (WyrZ.Op)
    {
    case 0:
        wynik=WyrZ.Arg1+WyrZ.Arg2;
        break;
    case 1:
        wynik=WyrZ.Arg1-WyrZ.Arg2;
        break;
    case 2:
        wynik=WyrZ.Arg1*WyrZ.Arg2;
        break;
    case 3:
        wynik=WyrZ.Arg1/WyrZ.Arg2;
        break;    
    }
    return wynik;
}


