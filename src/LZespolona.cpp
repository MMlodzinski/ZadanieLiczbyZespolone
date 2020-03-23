#include "LZespolona.hh"
#include <math.h>

using std::cout;
using std::cin;
using std::cerr;
using std::showpos;
using std::noshowpos;
using std::istream;
using std::ios;
using std::ostream;


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
  wynik.im=Skl1.re*Skl2.im+Skl1.im*Skl2.re;
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

bool operator == (LZespolona Skl1, LZespolona Skl2){
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    return true;
  else
    return false; 
}

bool operator != (LZespolona Skl1, LZespolona Skl2){
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    return false;
  else
    return true; 
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

/*void wczytaj(LZespolona *z){
  char lnawias, pnawias, i;
  cin>>lnawias>>z->re>>z->im>>i>>pnawias;
  if(lnawias!='(' || pnawias!=')' || i!='i')
  {
    cerr<<"zle napisana liczba zespolona";
  }
}*/

std::istream & operator >> (std::istream &stream, LZespolona &LZ){
  char znak;
  stream.clear();
  stream>>znak;
  if(znak!='('){
    stream.setstate(ios::failbit); 
  }
  else{

  stream.get(znak);
  if(znak=='i') 
  {
    LZ.re=0;
    LZ.im=1;
    stream.get(znak);
    if(znak!=')') 
      stream.setstate(ios::failbit);
  }
  else if(znak=='-'){
    stream.get(znak);
    if(znak=='i'){
      LZ.re=0;
      LZ.im=-1;
      stream.get(znak);
      if(znak!=')') 
        stream.setstate(ios::failbit);
    }
    else{
      stream.unget();
      if(stream>>LZ.re){
        LZ.re=-LZ.re;
        stream.get(znak);
        if(znak!='+' && znak!='-' && znak!=')' && znak!='i'){
          stream.setstate(ios::failbit);
        }

        if(znak==')'){
          LZ.im=0;
        } 

        if(znak=='i'){
          LZ.im=LZ.re;
          LZ.re=0;
          stream.get(znak);
          if(znak!=')') stream.setstate(ios::failbit);
        }

        if(znak=='-'){
          stream.get(znak);
          if(znak=='i'){
            LZ.im=-1;
            stream.get(znak);
            if(znak!=')') stream.setstate(ios::failbit);

          }
          else {
            stream.unget();
            if(stream>>LZ.im){
              LZ.im=-LZ.im;
              stream.get(znak);
              if(znak=='i'){
                stream.get(znak);
                if(znak!=')') stream.setstate(ios::failbit);
              }
              else stream.setstate(ios::failbit);
            }
            else stream.setstate(ios::failbit);
          }
        }

        if(znak=='+'){
          stream.get(znak);
          if(znak=='i'){
            LZ.im=1;
            stream.get(znak);
            if(znak!=')') stream.setstate(ios::failbit);

          }
          else {
            stream.unget();
            if(stream>>LZ.im){
              stream.get(znak);
              if(znak=='i'){
                stream.get(znak);
                if(znak!=')') stream.setstate(ios::failbit);
              }
              else stream.setstate(ios::failbit);
            }
            else stream.setstate(ios::failbit);
          }

        }
      }
      else stream.setstate(ios::failbit);
    }
  }
  
  else{ 
    stream.unget();
    if(stream>>LZ.re){
      
        stream.get(znak);
        if(znak!='+' && znak!='-' && znak!=')' && znak!='i'){
          stream.setstate(ios::failbit);
        }

        if(znak==')'){
          LZ.im=0;
        } 

        if(znak=='i'){
          LZ.im=LZ.re;
          LZ.re=0;
          stream.get(znak);
          if(znak!=')') stream.setstate(ios::failbit);
        }

        if(znak=='-'){
          stream.get(znak);
          if(znak=='i'){
            LZ.im=-1;
            stream.get(znak);
            if(znak!=')') stream.setstate(ios::failbit);

          }
          else{
            stream.unget();
            if(stream>>LZ.im){
              LZ.im=-LZ.im;
              stream.get(znak);
              if(znak=='i'){
                stream.get(znak);
                if(znak!=')') stream.setstate(ios::failbit);
              }
              else stream.setstate(ios::failbit);
            }
            else stream.setstate(ios::failbit);
          }
        }

        if(znak=='+'){
          stream.get(znak);
          if(znak=='i'){
            LZ.im=1;
            stream.get(znak);
            if(znak!=')') stream.setstate(ios::failbit);

          }
          else {
            stream.unget();
            if(stream>>LZ.im){
              stream.get(znak);
              if(znak=='i'){
                stream.get(znak);
                if(znak!=')') stream.setstate(ios::failbit);
              }
              else stream.setstate(ios::failbit);
            }
            else stream.setstate(ios::failbit);
          }

        }
      }
      else stream.setstate(ios::failbit);
  }
}
return stream;

}

ostream & operator << (ostream & strm, LZespolona &Z1){
  strm<<'(';
  if(Z1.re==0 && Z1.im==0)
    strm<<'0';
  else if(Z1.re==0){
    if(Z1.im!=1 && Z1.im!=-1)
      strm<<Z1.im;
    if(Z1.im==-1)
      strm<<'-';
    strm<<'i';
  }
  else if(Z1.im==0)
    strm<<Z1.re;
  else{
    strm<<Z1.re;
    if(Z1.im!=1 || Z1.im!=-1)
      strm<<showpos<<Z1.im<<noshowpos;
    if(Z1.im==-1)
      strm<<'-';
    strm<<'i';
  }
  
  strm<<')';

  return strm;

}
