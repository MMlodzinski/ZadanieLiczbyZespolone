#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;


int main(int argc, char **argv)
{
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona LZ;
  Statystyka stats;
  inicjalizacja(&stats);
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Podaj wynik operacji: ";
    cout << WyrZ_PytanieTestowe << endl;

    do
    {
      cin.clear();
      cin>>LZ;
    }while (!cin.good());

    if(LZ==Oblicz(WyrZ_PytanieTestowe)){
      stats.pop++;
      cout<<"Poprawna odpowiedź"<<endl;
    }else{
      LZ=Oblicz(WyrZ_PytanieTestowe);
      cout<<"Zła odpowiedź \n Prawidłowa odpowiedź to "<<LZ;
    }
    stats.odp++;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  pokaz(stats);
  }
