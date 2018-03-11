#include "Salupa.h"
#include <iostream>
#include "Nava.h"

Salupa::Salupa():Nava(55)
{
    //ctor
    std::cout << "Am creat o salupa\n";
    nrPatrate = 1;
}

Salupa::~Salupa()
{
    //dtor
    std::cout << "Am distrus o salupa\n";
}
int Salupa::ConstruiesteForma(CampDeLupta harta[30][30])
{
    int x = this->getX();
    int y = this->getY();
    if(harta[y][x].getPatrat() !=' ')
    {
        std::cout << "Nu se poate crea o salupa la aceasta locatie\n";
        return -1;
    }
    harta[y][x].setPatrat('*');
    harta[y][x].setTipNava("Salupa");
    harta[y][x].setNavaStationara(*this);
    return 0;
}
istream& operator>>(istream&i,Salupa&S)
{
    Nava& n = S;
    i >> S;
    //Nava:operator<<(i,S);
    return i;
}
ostream& operator<<(ostream&o,Salupa& S)
{
    std::cout << "Salupa\n";
    o << S;
    //Nava:operator<<(o,S);
    return o;
}
