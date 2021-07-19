#include <iostream>
using namespace std;

int main() {

    int *wskaznik;
    int tablica[3] = {2, 4, 5};

    wskaznik = &tablica[0]; // wskaz na adres pierwszego elementu tablicy
    wskaznik++; //dodaj 1 do adresu pierwszego elementu tablicy przez co wskazujesz na drugi element
    cout << *wskaznik << endl; // wyswietl drugi element tablicy
    cout << "Adresy elementow tablicy\n";

    int length = sizeof(tablica) / sizeof(int); // wielkosc tablicy
    wskaznik = &tablica[0]; // wskazanie pierwszego elementu

    for (int i = 0; i < length; i++)
    {
    cout << wskaznik <<" wartosc danej komorki: "<<*wskaznik<< endl;
    wskaznik++;
    } cout<<endl;

    wskaznik = &tablica[0]; // wskaznik teraz wskazuje na adres 1 elementu tablicy
    *wskaznik = 15; // wskaznik zmienia wartosc(aktualnie jest na 1 elemencie tablicy wiec ten tez sie zmienia)
    wskaznik = &tablica[1]; // wskaznik teraz wskazuje na adres 2 elementu tablicy
    *wskaznik = 25; // wskaznik zmienia wartosc(aktualnie jest na 2 elemencie tablicy wiec ten tez sie zmienia)

    wskaznik = &tablica[0]; // wskazanie pierwszego elementu

    for (wskaznik; wskaznik < &tablica[3]; wskaznik++) // petla napedzana wskaznikiem, latwa do popsucia, wystarczy zla wartosc i moga wyjsc dziwne rzeczy
    {
    cout << wskaznik << " wartosc danej komorki: " << *wskaznik << endl;
    }

 return 0;
}
