#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>


#include "Ustawienie.h"
#include "Ustawienie.cpp"
#include "Gra.h"
#include "Gra.cpp"


using namespace std;

bool Exit = true;

void menu()
{
    int userInputInt1, userInputInt2;
    cout<<"witaj w grze pod nazwa 'statki'"<<endl;
    cout<<"1: Start"<<endl;
    cout<<"Exit: Wyjscie"<<endl<<endl;
    cin>>userInputInt1;
    switch(userInputInt1)
    {
    case 1:
        {
        cout<<"a wiec zagrajmy :3 "<<endl;
        sleep(2);
        system("cls");
        sleep(1);
        while(Exit)
        {
            cout<<"Jaki poziom trudnosci wybierasz?"<<endl;;
            cout<<"1: Latwy"<<endl;
            cout<<"2: Normalny"<<endl;
            cout<<"3: Trudny"<<endl;
            cout<<"4: Opis poziomow"<<endl;
            cout<<"Exit: Wyjscie"<<endl;// wybor poziomu trudnosci

            cin>>userInputInt1;
            switch(userInputInt1)
            {
                case 1:
                {
                    system("cls");
                    cout<<"Poziom Latwy"<<endl;
                    sleep(2);
                    Game_Easy();
                    Exit = false;
                    break;
                }
                case 2:
                {
                    system("cls");
                    cout<<"Poziom Normalny"<<endl;
                    sleep(2);
                    Game_Normal();
                    Exit = false;
                    break;
                }
                case 3:
                {   system("cls");
                    cout<<"Poziom Trudny"<<endl;
                    sleep(2);
                    Game_Hard();
                    Exit = false;
                    break;
                }
                case 4:
                {
                    system("cls");
                    cout<<"Poziom Latwy - widzisz mape bota i swoja, bot strzela losow, praktycznie nie da sie tego przegrac"<<endl;
                    sleep(5);
                    cout<<"Poziom Normalny - Widzisz tylko swoja mape, mapa bota jest niewidoczna, bot dalej strzela na slepo"<<endl;
                    sleep(5);
                    cout<<"Poziom Trudny - Widzisz tylko swoja mape, bot mysli gdzie strzela i kazdy trafiony strzal zapamietuje i nastepnym razem celuje w lepsze miejsce"<<endl;
                    sleep(1);
                    cout<<"Wiec..."<<endl;
                    sleep(1);
                    break;
                }
                default:
                {
                    cout<<"Dzieki za gre ;) Mam nadzieje ze ci sie podobalo"<<endl;
                    Exit = false;
                    break;
                }
            }
        }
        break;
        }
        default:
        {
            cout<<endl;
            cout<<"chyba cos zle wpisales sprobuj jeszcze raz wpisz liczbe 1 lub 2"<<endl<<endl;
            menu();
            break;
        }
    }
}
int main()
{
    menu();
   // menu();

	return 0;
}
