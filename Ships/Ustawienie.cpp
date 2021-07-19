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
using namespace std;

void mapa::createMap()
{
    mapa::Array = new char *[mapa::length];
        for(int i = 0 ; i < mapa::length; i ++)
        {
             mapa::Array[i] = new char [mapa::length];
        }

        for(int i = 1 ; i < mapa::length-1; i ++)
        {
            for(int j = 1 ; j < mapa::length-1; j++)
                mapa::Array[i][j] = '.';
        }
}

void mapa::showMap()
{
    for(int i = 0; i < mapa::length-1;i++)
		{
			for(int j = 0; j < mapa::length-1;j++)
			{
			if(j == 0 && i == 0)
				{
					cout<<i;
				}
				else if( i == 0 )
				{
					cout<<j;
				}
				else if( j == 0 )
				{
					cout<<i;
				}
				else
				{
				  cout<<mapa::Array[i][j];
				}
			   cout<<" ";
			}
			cout<<endl;
		}
}

void setShips::setShipsManualy()
    {
        string userInputString;
        for(int _ = 0; _ < setShips::numberOfShips; _++)
            {
		    setShips::loopBreak = false;
			cout<<endl<<"Wybierz miejsce "<<setShips::controlVariable<<" masztowca"<<endl<<endl;
			cout<<"Poziom czy pion?"<<endl;
			cin>>userInputString;
				if(userInputString == "Poziom" || userInputString == "poziom" ||userInputString ==  "POZIOM")
				{
				    /********************
				    Wprowadzanie wartosci
				    ********************/
					cout<<"podaj gdzie chcesz ustawic statek"<<endl<<endl;
					cout<<"wybierz wspolrzedna w pionie od 1 do 9"<<endl;
					cin>>setShips::userInputInt1;
                    cout<<"wybierz wspolrzedna w poziomie od 1 do 9"<<endl;
                    cin>>setShips::userInputInt2;
                    /***************************
                    Algorytm wstawiajacy znaczki
                    ***************************/
						if(setShips::userInputInt2+1 > setShips::length - setShips::controlVariable) // jesli to co wpisal uztykownik miesci sie w ramach mapy
						{
						    cout<<"odbite"<<endl;
                            for(int i = setShips::userInputInt2; i > setShips::userInputInt2-controlVariable; i--) // kontrola czy mozna wypisac dane koordynatny na mapke
							{
							    if(setShips::Array[setShips::userInputInt1][i] == '8' || setShips::Array[setShips::userInputInt1][i] == '*')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
                                if(setShips::Array[setShips::userInputInt1][i-1] == '8' || setShips::Array[setShips::userInputInt1][i+1] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
                                if(setShips::Array[setShips::userInputInt1+1][i] == '8' || setShips::Array[setShips::userInputInt1-1][i] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
							}
                            for(int i = setShips::userInputInt2; i > setShips::userInputInt2-controlVariable; i--) // minus bo wypisuje w druga strone
							{
                                if(setShips::loopBreak == true) break;

                                if(i == setShips::userInputInt2) setShips::Array[setShips::userInputInt1][i+1] = '*';

                                setShips::Array[setShips::userInputInt1][setShips::userInputInt2-setShips::controlVariable] = '*';
                                setShips::Array[setShips::userInputInt1+1][i] = '*';
                                setShips::Array[setShips::userInputInt1][i] = '8';
                                setShips::Array[setShips::userInputInt1-1][i] = '*';
							}
							if(setShips::loopBreak == false)
                                if(setShips::controlVariable == 2) setShips::countDoubleShip++;

							if(setShips::loopBreak == true)
                            {
                                cout<<"Ustawiasz statek na statku, zmien wspolrzedne inaczej blad sie powtorzy"<<endl;
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                            }
						}
						else if(setShips::userInputInt2 < setShips::length - setShips::controlVariable) // jesli to co wpisal uztykownik nie miesci sie w ramach mapy
						{
						    for(int i = setShips::userInputInt2; i < setShips::userInputInt2+controlVariable; i++) // kontrola czy mozna wypisac dane koordynatny na mapke
							{
							    if(setShips::Array[setShips::userInputInt1][i] == '8' || setShips::Array[setShips::userInputInt1][i] == '*')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[setShips::userInputInt1][i-1] == '8' || setShips::Array[setShips::userInputInt1][i+1] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[setShips::userInputInt1+1][i] == '8' || setShips::Array[setShips::userInputInt1-1][i] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
							}

							for(int i = setShips::userInputInt2; i < setShips::userInputInt2+controlVariable; i++)
							{

                                if(setShips::loopBreak == true) break;

                                if(i == setShips::userInputInt2) setShips::Array[setShips::userInputInt1][i-1] = '*';

                                setShips::Array[setShips::userInputInt1][setShips::userInputInt2+setShips::controlVariable] = '*';
                                setShips::Array[setShips::userInputInt1+1][i] = '*';
                                setShips::Array[setShips::userInputInt1][i] = '8';
                                setShips::Array[setShips::userInputInt1-1][i] = '*';
							}
							if(setShips::loopBreak == false)
                                if(setShips::controlVariable == 2) setShips::countDoubleShip++;

							if(setShips::loopBreak == true)
                            {
                                cout<<"Ustawiasz statek na statku, zmien wspolrzedne inaczej blad sie powtorzy"<<endl;
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                            }
						}
						else
                        {
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                        }
				}
				else if(userInputString == "Pion" ||userInputString ==  "pion" ||userInputString ==  "PION")
				{
					cout<<"podaj gdzie chcesz ustawic statek"<<endl<<endl;

					cout<<"wybierz wspolrzedna w pionie od 1 do 9"<<endl;

					cin>>setShips::userInputInt1; // wpisuje 1-9

					cout<<"wybierz wspolrzedna w poziomie od 1 do 9"<<endl;

					cin>>setShips::userInputInt2; // wpisuje 1-9


						if(setShips::userInputInt1+setShips::controlVariable <=10)
						{
						     for(int i = setShips::userInputInt1; i < setShips::userInputInt1+controlVariable; i++)
							{

                                if(setShips::Array[i][setShips::userInputInt2] == '8' || setShips::Array[i][setShips::userInputInt2] == '*')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[i-1][setShips::userInputInt2] == '8' || setShips::Array[i+1][setShips::userInputInt2] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[i][setShips::userInputInt2+1] == '8' || setShips::Array[i][setShips::userInputInt2-1] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
							}

                            for(int i = setShips::userInputInt1; i < setShips::userInputInt1+setShips::controlVariable; i++)
							{
							    if(setShips::loopBreak == true) break;

                                if( i == setShips::userInputInt1)
                                {
                                   setShips::Array[i-1][setShips::userInputInt2] = '*';
                                }
                                if( i == setShips::userInputInt1+setShips::controlVariable-1)
                                {
                                    setShips::Array[i+1][setShips::userInputInt2] = '*';
                                }

                               setShips::Array[i][setShips::userInputInt2-1] = '*';
							   setShips::Array[i][setShips::userInputInt2] = '8';
							   setShips::Array[i][setShips::userInputInt2+1] = '*';
							}
							if(setShips::loopBreak == false)
                                if(setShips::controlVariable == 2) setShips::countDoubleShip++;

							if(setShips::loopBreak == true)
                            {
                                cout<<"Ustawiasz statek na statku, zmien wspolrzedne inaczej blad sie powtorzy"<<endl;
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                            }
						}
						else if(setShips::userInputInt1+setShips::controlVariable >10)
						{
                            for(int i = setShips::userInputInt1; i > setShips::userInputInt1-setShips::controlVariable; i--)
							{
                                if(setShips::Array[i][setShips::userInputInt2] == '8' || setShips::Array[i][setShips::userInputInt2] == '*')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[i-1][setShips::userInputInt2] == '8' || setShips::Array[i+1][setShips::userInputInt2] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[i][setShips::userInputInt2+1] == '8' || setShips::Array[i][setShips::userInputInt2-1] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
							}

							for(int i = setShips::userInputInt1; i > setShips::userInputInt1-setShips::controlVariable; i--)
							{
							    if(setShips::loopBreak == true) break;

                                if( i == setShips::userInputInt1)
                                {
                                    setShips::Array[i-1][setShips::userInputInt2] = '*';
                                }
                                if( i == setShips::userInputInt1+setShips::controlVariable-1)
                                {
                                    setShips::Array[i+1][setShips::userInputInt2] = '*';
                                }

                               setShips::Array[i][setShips::userInputInt2-1] = '*';
							   setShips::Array[i][setShips::userInputInt2] = '8';
							   setShips::Array[i][setShips::userInputInt2+1] = '*';
							}
							if(setShips::loopBreak == false)
                                if(setShips::controlVariable == 2) setShips::countDoubleShip++;

							if(setShips::loopBreak == true)
                            {
                                cout<<"Ustawiasz statek na statku, zmien wspolrzedne inaczej blad sie powtorzy"<<endl;
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                            }
						}

				}
				else
                {
                    if(setShips::controlVariable == 4)
                    {
                        setShips::controlVariable++;
                    }
                    cout<<"zle wpisana os wspolrzednych poprawny format to Pozioma,pozioma,POZIOMA lub Pion,pion,PION"<<endl;
                    if(setShips::numberOfShips != 7)
                    {
                    setShips::controlVariable +=1;
                    setShips::numberOfShips+=1;
                    }

                }
            showMap();

            if(setShips::controlVariable == 4)
                setShips::controlVariable--;
            else if(setShips::controlVariable == 3)
                setShips::controlVariable--;
            else if(setShips::controlVariable == 2)
               {
                if(setShips::countDoubleShip == 2)
                    {
                        setShips::controlVariable--;
                    }
               }
            else if(setShips::controlVariable == 1)
            {

            }
            else if(setShips::controlVariable > 4)
            {
                setShips::controlVariable--;
            }


            }
        }

void setShips::setShipsAutomatically()
    {
        srand (time(NULL));
        int verticalHorizontal ;
        for(int _ = 0; _ < setShips::numberOfShips; _++)
		{
            setShips::loopBreak = false;
		   setShips::userInputInt1 = (rand()%(setShips::length-2))+1;   // losowe liczby by miescily sie w zakresie
		   setShips::userInputInt2 = (rand()%(setShips::length-2))+1;    // losowe liczby by miescily sie w zakresie
		    //losowanie czy jest poziomo czy pionowo 0 poziomo 1 pionowo;
		    verticalHorizontal  = rand()%2;
		   if(verticalHorizontal  == 0)
		   {
               // cout<<"poziomo "<<setShips::userInputInt1<<" "<<setShips::userInputInt2<<" || "<<setShips::controlVariable<<" masztowy"<<endl<<endl;
                if(setShips::userInputInt2+1 > setShips::length - setShips::controlVariable) // jesli to co wpisal uztykownik miesci sie w ramach mapy
						{

                            for(int i = setShips::userInputInt2; i > setShips::userInputInt2-setShips::controlVariable; i--) // kontrola czy mozna wypisac dane koordynatny na mapke
							{
							    if(setShips::Array[setShips::userInputInt1][i] == '8' || setShips::Array[setShips::userInputInt1][i] == '*')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[setShips::userInputInt1][i-1] == '8' || setShips::Array[setShips::userInputInt1][i+1] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[setShips::userInputInt1+1][i] == '8' || setShips::Array[setShips::userInputInt1-1][i] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
							}

                            for(int i = setShips::userInputInt2; i > setShips::userInputInt2-setShips::controlVariable; i--) // minus bo wypisuje w druga strone
							{
                                if(setShips::loopBreak == true) break;

                                if(i == setShips::userInputInt2) setShips::Array[setShips::userInputInt1][i+1] = '*';

                                setShips::Array[setShips::userInputInt1][setShips::userInputInt2-setShips::controlVariable] = '*';
                                setShips::Array[setShips::userInputInt1+1][i] = '*';
                                setShips::Array[setShips::userInputInt1][i] = '8';
                                setShips::Array[setShips::userInputInt1-1][i] = '*';
							}
							if(setShips::loopBreak == false)
                                if(setShips::controlVariable == 2) setShips::countDoubleShip++;

							if(setShips::loopBreak == true)
                            {
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                            }
						}
						else if(setShips::userInputInt2 < length - setShips::controlVariable) // jesli to co wpisal uztykownik nie miesci sie w ramach mapy
						{
						    for(int i = setShips::userInputInt2; i < setShips::userInputInt2+setShips::controlVariable; i++) // kontrola czy mozna wypisac dane koordynatny na mapke
							{
							    if(setShips::Array[setShips::userInputInt1][i] == '8' || setShips::Array[setShips::userInputInt1][i] == '*')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[setShips::userInputInt1][i-1] == '8' || setShips::Array[setShips::userInputInt1][i+1] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[setShips::userInputInt1+1][i] == '8' || setShips::Array[setShips::userInputInt1-1][i] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
							}

							for(int i = setShips::userInputInt2; i < setShips::userInputInt2+setShips::controlVariable; i++)
							{

                                if(setShips::loopBreak == true) break;

                                if(i == setShips::userInputInt2) setShips::Array[setShips::userInputInt1][i-1] = '*';

                                setShips::Array[setShips::userInputInt1][setShips::userInputInt2+setShips::controlVariable] = '*';
                                setShips::Array[setShips::userInputInt1+1][i] = '*';
                                setShips::Array[setShips::userInputInt1][i] = '8';
                                setShips::Array[setShips::userInputInt1-1][i] = '*';
							}
							if(setShips::loopBreak == false)
                                if(setShips::controlVariable == 2) setShips::countDoubleShip++;

							if(setShips::loopBreak == true)
                            {
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                            }
						}
						else
                        {
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                        }
				}
		   else if(verticalHorizontal  == 1)
		   {
               // cout<<"pionowo "<<setShips::userInputInt1<<" "<<setShips::userInputInt2<<" || "<<setShips::controlVariable<<" masztowy"<<endl<<endl;
                if(setShips::userInputInt1+setShips::controlVariable <=10)
                        {
						     for(int i = setShips::userInputInt1; i < setShips::userInputInt1+setShips::controlVariable; i++)
							{

                                if(setShips::Array[i][setShips::userInputInt2] == '8' || setShips::Array[i][setShips::userInputInt2] == '*')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[i-1][setShips::userInputInt2] == '8' || setShips::Array[i+1][setShips::userInputInt2] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[i][setShips::userInputInt2+1] == '8' || setShips::Array[i][setShips::userInputInt2-1] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
							}

                            for(int i = setShips::userInputInt1; i < setShips::userInputInt1+setShips::controlVariable; i++)
							{
							    if(setShips::loopBreak == true) break;

                                if( i == setShips::userInputInt1)
                                {
                                    setShips::Array[i-1][setShips::userInputInt2] = '*';
                                }
                                if( i == setShips::userInputInt1+setShips::controlVariable-1)
                                {
                                    setShips::Array[i+1][setShips::userInputInt2] = '*';
                                }

                               setShips::Array[i][setShips::userInputInt2-1] = '*';
							   setShips::Array[i][setShips::userInputInt2] = '8';
							   setShips::Array[i][setShips::userInputInt2+1] = '*';
							}
							if(setShips::loopBreak == false)
                                if(setShips::controlVariable == 2) setShips::countDoubleShip++;

							if(setShips::loopBreak == true)
                            {

                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                            }
						}
						else if(setShips::userInputInt1+setShips::controlVariable >10)
						{
                            for(int i = setShips::userInputInt1; i > setShips::userInputInt1-setShips::controlVariable; i--)
							{
                                if(setShips::Array[i][setShips::userInputInt2] == '8' || setShips::Array[i][setShips::userInputInt2] == '*')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[i-1][setShips::userInputInt2] == '8' || setShips::Array[i+1][setShips::userInputInt2] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }

                                if(setShips::Array[i][setShips::userInputInt2+1] == '8' || setShips::Array[i][setShips::userInputInt2-1] == '8')
                                    {
                                        setShips::loopBreak = true;
                                        break;
                                    }
							}

							for(int i = setShips::userInputInt1; i > setShips::userInputInt1-setShips::controlVariable; i--)
							{
							    if(setShips::loopBreak == true) break;

                                if( i == setShips::userInputInt1)
                                {
                                    setShips::Array[i-1][setShips::userInputInt2] = '*';
                                }
                                if( i == setShips::userInputInt1+setShips::controlVariable-1)
                                {
                                    setShips::Array[i+1][setShips::userInputInt2] = '*';
                                }

                               setShips::Array[i][setShips::userInputInt2-1] = '*';
							   setShips::Array[i][setShips::userInputInt2] = '8';
							   setShips::Array[i][setShips::userInputInt2+1] = '*';
							}
							if(setShips::loopBreak == false)
                                if(setShips::controlVariable == 2) setShips::countDoubleShip++;

							if(setShips::loopBreak == true)
                            {
                                setShips::controlVariable +=1;
                                setShips::numberOfShips+=1;
                            }
						}

		   }
		   else
                {
                    if(setShips::controlVariable == 4)
                    {
                        setShips::controlVariable++;
                    }
                    if(setShips::numberOfShips != 7)
                    {
                    setShips::controlVariable +=1;
                    setShips::numberOfShips+=1;
                    }

                }
		    //showMap();

            if(setShips::controlVariable == 4)
                setShips::controlVariable--;
            else if(setShips::controlVariable == 3)
                setShips::controlVariable--;
            else if(setShips::controlVariable == 2)
               {
                if(setShips::countDoubleShip == 2)
                    {
                        setShips::controlVariable--;
                    }
               }
            else if(setShips::controlVariable == 1)
            {

            }
            else if(setShips::controlVariable > 4)
            {
                setShips::controlVariable--;
            }

		}
    }

