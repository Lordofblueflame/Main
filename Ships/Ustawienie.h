#ifndef Ustawienie_h
#define Ustawienie_h


class mapa
{
    public:
    int length = 11;
    char **Array;
    void createMap();
    void showMap();
};

//ZABAWA Z DZIEDZICZENIEM
//dla latwiejszego zrozumienia kodu w mapie sa kwestie zwiazane z tworzeniem mapy a w setShips jest caly algorytm ustawiajacy statki
//Sa do wyboru dwa rodzaje ustawiania
//1. Reczne
//2. Automatyczne
//Dzialaja na tej samej zasadzie tylko w jednym wybieramy czy chcemy ustawic Poziomo czy Pionowo, oraz wpisujemy wspolrzedne
//A w drugim losowana jest os ustawiania statkow i potem losowane sa wspolrzedne,
//Statki sa ustawiane metoda prob i bledow az sie dobrze ustawia
class setShips : public mapa
{
    public:
   // string userInputString;
    int userInputInt1;
    int userInputInt2;
    int countDoubleShip = 0;
    int numberOfShips = 7;
    /******************************************************
    1 - 4masztowy
    1 - 3masztowy
class setShips : public mapa
{
    2 - 2masztowy
    3 - 1masztowe
    *******************************************************/
    int controlVariable = 4;
    bool loopBreak = false;

    void setShipsManualy();
    void setShipsAutomatically();

};

#endif // Ustawienie_h
