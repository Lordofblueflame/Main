#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>


#include "Gra.h"
#include "Ustawienie.h"
using namespace std;

bool checkIfWin(setShips board)
{
    int buffor = 0;
    for(int i = 1 ; i < board.length-1; i ++)
        {
            for(int j = 1 ; j < board.length-1; j++)
                if(board.Array[i][j] == '8')
                    return false;
                else
                    buffor++;
        }
        if(buffor > 0)
        {
            return true;
        }
}

void Game_Easy(setShips player, setShips bot)
{
    int userInputInt1, userInputInt2;
    int countRounds = 0;
    int roundControl = rand()%2;
    while(true)
    {
        if(roundControl == 0){
            countRounds++;
            cout<<endl<<"TURA "<<countRounds<<endl;
            cout<<"TURA GRACZA"<<endl;
            sleep(1);
            cout<<endl;
            cout<<"Mapa bota"<<endl;
            bot.showMap();
            sleep(1);
            cout<<endl;
            cout<<"Mapa playera"<<endl;
            player.showMap();
            sleep(1);
            cout<<"Wprowadz wspolrzedne w jakie chcesz strzelic"<<endl;
            cin>>userInputInt1>>userInputInt2;
            sleep(1);
            if(bot.Array[userInputInt1][userInputInt2] == '*')
            {
                cout<<"jestes chyba blisko"<<endl;
            }
            else if(bot.Array[userInputInt1][userInputInt2] == '8')
            {
                cout<<"brawo trafiles!"<<endl;
                bot.Array[userInputInt1][userInputInt2] = '*';
            }
            else if(bot.Array[userInputInt1][userInputInt2] == '.')
            {
                cout<<"Niestety, pudlo :("<<endl;
                bot.Array[userInputInt1][userInputInt2] = '*';
            }
            sleep(1);
            if(checkIfWin(bot) == true)
            {
                cout<<"Brawo gratulujemy wygranej"<<endl;
                break;
            }


        roundControl++;
        }
        else if(roundControl == 1)
        {
         countRounds++;
            cout<<endl<<"TURA "<<countRounds<<endl;
            cout<<"TURA BOTA"<<endl;
            sleep(1);
            cout<<"Bot strzela w miejsce: ";
            userInputInt1 = (rand()%(bot.length-2))+1;
            userInputInt2 = (rand()%(bot.length-2))+1;
            cout<< userInputInt1<< " || "<< userInputInt2<<endl<<endl;
            sleep(1);
            if(player.Array[userInputInt1][userInputInt2] == '*')
            {
                cout<<"Bot jest trafia blisko twojego statku!"<<endl;
            }
            else if(player.Array[userInputInt1][userInputInt2] == '8')
            {
                cout<<"Bot trafia w twoj statek!!!"<<endl;
                player.Array[userInputInt1][userInputInt2] = '*';
            }
            else if(bot.Array[userInputInt1][userInputInt2] == '.')
            {
                cout<<"Bot pudluje!"<<endl;
                player.Array[userInputInt1][userInputInt2] = '*';
            }
            sleep(1);
        if(checkIfWin(player) == true)
            {
                cout<<"Brawo gratulujemy wygranej"<<endl;
                break;
            }
        roundControl = 0;
        }

    }
}

void Game_Normal(setShips player, setShips bot)
{
    int userInputInt1, userInputInt2;
    int countRounds = 0;
    int roundControl = rand()%2;
    while(true)
    {
        if(roundControl == 0){
            countRounds++;
            cout<<endl<<"TURA "<<countRounds<<endl;
            cout<<"TURA GRACZA"<<endl;
            sleep(1);
            cout<<endl;
            cout<<"Twoja Mapa"<<endl;
            player.showMap();
            cout<<endl;
            cout<<"Wprowadz wspolrzedne w jakie chcesz strzelic"<<endl;
            cin>>userInputInt1>>userInputInt2;
            sleep(1);
            if(bot.Array[userInputInt1][userInputInt2] == '*')
            {
                cout<<"jestes chyba blisko"<<endl;
            }
            else if(bot.Array[userInputInt1][userInputInt2] == '8')
            {
                cout<<"brawo trafiles!"<<endl;
                bot.Array[userInputInt1][userInputInt2] = '*';
            }
            else if(bot.Array[userInputInt1][userInputInt2] == '.')
            {
                cout<<"Niestety, pudlo :("<<endl;
                bot.Array[userInputInt1][userInputInt2] = '*';
            }
            sleep(1);
            if(checkIfWin(bot) == true)
            {
                cout<<"Brawo gratulujemy wygranej"<<endl;
                break;
            }
        roundControl++;
        }
        else if(roundControl == 1)
        {
         countRounds++;
            cout<<endl<<"TURA "<<countRounds<<endl;
            cout<<"TURA BOTA"<<endl;
            sleep(1);
            cout<<"Bot strzela w miejsce: ";
            userInputInt1 = (rand()%(bot.length-2))+1;
            userInputInt2 = (rand()%(bot.length-2))+1;
            sleep(1);
            cout<< userInputInt1<< " || "<< userInputInt2<<endl<<endl;
            sleep(1);
            if(player.Array[userInputInt1][userInputInt2] == '*')
            {
                cout<<"Bot jest trafia blisko twojego statku!"<<endl;
            }
            else if(player.Array[userInputInt1][userInputInt2] == '8')
            {
                cout<<"Bot trafia w twoj statek!!!"<<endl;
                player.Array[userInputInt1][userInputInt2] = '*';
            }
            else if(bot.Array[userInputInt1][userInputInt2] == '.')
            {
                cout<<"Bot pudluje!"<<endl;
                player.Array[userInputInt1][userInputInt2] = '*';
            }

        if(checkIfWin(player) == true)
            {
                cout<<"Brawo gratulujemy wygranej"<<endl;
                break;
            }

        roundControl = 0;
        }

    }
}

void Game_Hard(setShips player, setShips bot)
{
    int userInputInt1, userInputInt2;
    int countRounds = 0;
    int roundControl = rand()%2;
    int rememberX; // zapamietaj x
    int rememberY; // zapamietaj y
    mapa a;
    a.createMap();
    while(true)
    {
        if(roundControl == 0){
            countRounds++;
            cout<<endl<<"TURA "<<countRounds<<endl;
            cout<<"TURA GRACZA"<<endl;
            sleep(1);
            cout<<endl;
            cout<<"Twoja Mapa"<<endl;
            player.showMap();
            cout<<endl;
            cout<<"Plansza twoich strzalow"<<endl;
            a.showMap();
            cout<<endl;
            cout<<"Wprowadz wspolrzedne w jakie chcesz strzelic"<<endl;
            cin>>userInputInt1>>userInputInt2;
            sleep(1);
            if(bot.Array[userInputInt1][userInputInt2] == '*')
            {
                a.Array[userInputInt1][userInputInt2] = '*';
                cout<<"jestes chyba blisko"<<endl;
            }
            else if(bot.Array[userInputInt1][userInputInt2] == '8')
            {
                cout<<"brawo trafiles!"<<endl;
                a.Array[userInputInt1][userInputInt2] = 'o';
                bot.Array[userInputInt1][userInputInt2] = '*';
            }
            else if(bot.Array[userInputInt1][userInputInt2] == '.')
            {
                cout<<"Niestety, pudlo :("<<endl;
                a.Array[userInputInt1][userInputInt2] = '*';
                bot.Array[userInputInt1][userInputInt2] = '*';
            }
            sleep(1);
            if(checkIfWin(bot) == true)
            {
                cout<<"Brawo gratulujemy wygranej"<<endl;
                break;
            }
        roundControl++;
        }
        else if(roundControl == 1)
        {
         countRounds++;
            cout<<endl<<"TURA "<<countRounds<<endl;
            cout<<"TURA BOTA"<<endl;
            sleep(1);
            if(countRounds == 1 || countRounds == 2) // pierwszy strzal zawsze randomowy
            {
            cout<<"Bot strzela w miejsce: ";
            userInputInt1 = (rand()%(bot.length-2))+1;
            userInputInt2 = (rand()%(bot.length-2))+1;
            sleep(1);
            }
            else
            {
                if(player.Array[rememberY][rememberX+1] == '8')
                {
                    userInputInt1 = rememberY;
                    userInputInt2 = rememberX+1;
                }
                else if(player.Array[rememberY][rememberX-1] == '8')
                {
                    userInputInt1 = rememberY;
                    userInputInt2 = rememberX-1;
                }
                else if(player.Array[rememberY+1][rememberX] == '8')
                {
                    userInputInt1 = rememberY+1;
                    userInputInt2 = rememberX;
                }
                else if(player.Array[rememberY-1][rememberX] == '8')
                {
                    userInputInt1 = rememberY-1;
                    userInputInt2 = rememberX;
                }
                else
                {
                    userInputInt1 = (rand()%(bot.length-2))+1;
                    userInputInt2 = (rand()%(bot.length-2))+1;
                }

            }
            cout<< userInputInt1<< " || "<< userInputInt2<<endl<<endl;
            sleep(1);
            if(player.Array[userInputInt1][userInputInt2] == '*')
            {
                cout<<"Bot jest trafia blisko twojego statku!"<<endl;
                rememberY = userInputInt1;
                rememberX = userInputInt2;
            }
            else if(player.Array[userInputInt1][userInputInt2] == '8')
            {
                cout<<"Bot trafia w twoj statek!!!"<<endl;
                rememberX = userInputInt1;
                rememberY = userInputInt2;
                player.Array[userInputInt1][userInputInt2] = '*';
            }
            else if(player.Array[userInputInt1][userInputInt2] == '.')
            {
                cout<<"Bot pudluje!"<<endl;
                player.Array[userInputInt1][userInputInt2] = '*';
            }

            if(checkIfWin(player) == true)
            {
            player.showMap();
            cout<<"Niestety przegrales"<<endl;
                break;
            }
        roundControl--;
        }
    }
}

void Game_Easy()
{
    setShips player;
    setShips bot;
    bot.createMap();
    bot.setShipsAutomatically();
    player.createMap();
    cout<<"To twoja Mapa, rozmiesc na niej statki"<<endl;
    player.showMap();
    player.setShipsManualy();
    sleep(4);
    system("cls");
    Game_Easy(player,bot);
}

void Game_Normal()
{
    setShips player;
    setShips bot;
    bot.createMap();
    bot.setShipsAutomatically();
    player.createMap();
    cout<<"To twoja Mapa, rozmiesc na niej statki"<<endl;
    player.showMap();
    player.setShipsManualy();
    sleep(4);
    system("cls");
    Game_Normal(player,bot);
}

void Game_Hard()
{
    setShips player;
    setShips bot;
    bot.createMap();
    bot.setShipsAutomatically();
    player.createMap();
    cout<<"To twoja Mapa, rozmiesc na niej statki"<<endl;
    player.showMap();
    player.setShipsManualy();
    sleep(4);
    system("cls");
    Game_Hard(player,bot);
}

