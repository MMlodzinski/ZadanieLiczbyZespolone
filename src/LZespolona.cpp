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

/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - odjemna,
 *    Skl2 - odjemnik.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2){
  LZespolona wynik;

  wynik.re=Skl1.re-Skl2.re;
  wynik.im=Skl1.im-Skl2.im;
  return wynik;
}

/*!
 * Realizuje pomnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona wynik;

  wynik.re=Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  wynik.im=Skl1.re*Skl2.im+Skl1.im*Skl2.re;
  return wynik;
}

/*!
 * Realizuje podzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona wynik=(Skl1*sprzezenie(Skl2))%(modul(Skl2)*modul(Skl2));
  return wynik;
}

/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    Skl - liczba sprzezana
 * Zwraca:
 *    Liczbe sprzezona do podanej liczby.
 */
LZespolona  sprzezenie (LZespolona  Skl){
  LZespolona wynik;

  wynik.re=Skl.re;
  wynik.im=Skl.im*(-1);
  return wynik;
}

/*!
 * Oblicza modul liczby zespolonej.
 * Argumenty:
 *    Skl - liczba z ktorej uzyskamy modul.
 * Zwraca:
 *    Modul podanej liczby.
 */
double modul (LZespolona Skl){
  double wynik;

  wynik=sqrt(Skl.re*Skl.re+Skl.im*Skl.im);
  return wynik;
}

/*!
 * Sprawdza czy 2 liczby zespolone sa identyczne.
 * Argumenty:
 *    Skl1 - pierwsza liczba,
 *    Skl2 - druga liczba.
 * Zwraca:
 *    True gdy liczby są takie same i false gdy nie są.
 */
bool operator == (LZespolona Skl1, LZespolona Skl2){
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    return true;
  else
    return false; 
}

/*!
 * Sprawdza czy 2 liczby zespolone nie sa identyczne.
 * Argumenty:
 *    Skl1 - pierwsza liczba,
 *    Skl2 - druga liczba.
 * Zwraca:
 *    False gdy liczby są takie same i true gdy nie są.
 */
bool operator != (LZespolona Skl1, LZespolona Skl2){
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    return false;
  else
    return true; 
}

/*!
 * Realizuje dzielenie liczby zespolonej przez rzeczywista.
 * Argumenty:
 *    Skl - dzielna,
 *    dziel - dzielnik.
 * Zwraca:
 *    Iloraz liczby zespolonej i calkowitej.
 */
LZespolona operator % (LZespolona Skl, double dziel){
  LZespolona wynik;

  wynik.re=Skl.re/dziel;
  wynik.im=Skl.im/dziel;
  return wynik;
}

/*!
 * Tworzy liczbe zespolona.
 * Argumenty:
 *    re - czesc rzeczywista,
 *    im - czesc urojona.
 * Zwraca:
 *    Liczbe zespolona zlozona z podanej czesci rzeczywistej i urojonej.
 */
LZespolona utworz(double re, double im){
  LZespolona l;
  l.re=re;
  l.im=im;
  return l;
}

/*!
 * Wczytuje liczbe zespolona.
 * Argumenty:
 *    &stream - strumien,
 *    &LZ - liczba zespolona.
 * Wczytuje każda liczbe zespolona, wlacznie z takimi zapisanymi notacja skrotowa.
 * Niezbedne jest zapisanie liczby w nawiasach.
 */
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

/*!
 * Wypisuje liczbe zespolona.
 * Argumenty:
 *    &strm - strumien,
 *    &Z1 - liczba zespolona.
 * Wypisuje liczby zespolone w notacji skrotowej.
 */
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
    if(Z1.im!=1 && Z1.im!=-1)
      strm<<showpos<<Z1.im<<noshowpos;
    if(Z1.im==-1)
      strm<<'-';
    strm<<'i';
  }
  
  strm<<')';

  return strm;

}
