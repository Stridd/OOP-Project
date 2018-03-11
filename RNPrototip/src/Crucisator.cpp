#include "Crucisator.h"
#include <iostream>

Crucisator::Crucisator()
{
    //ctor
    sistemAparare = false;
    sistemActivat = false;
    nrPatrate = 6;
}

Crucisator::~Crucisator()
{
    //dtor
}
int Crucisator::setSistemAparare(bool x)
{
    sistemAparare = x;
    return 0;
}
int Crucisator::ConstruiesteForma(CampDeLupta harta[30][30])
{
    int x = this->getX();
    int y = this->getY();
    if(harta[y][x].getPatrat()!=' ' || harta[y+1][x].getPatrat()!=' ' || harta[y][x+1].getPatrat()!=' ' || harta[y+1][x+1].getPatrat()!=' '
       || harta[y-1][x].getPatrat() != ' ' || harta[y-1][x+1].getPatrat() != ' ')
        {
            std::cout << "Nu se poate construi un crucisator la aceste coordonate1\n";
            return -1;

        }
    else
        if(getSistemAparare() == true)
        {
            if(harta[y][x-1].getPatrat()!=' ' || harta[y][x+2].getPatrat()!=' ')
            {
                std::cout << "Nu se poate construi un crucisator la aceste coordonate2\n";
                return -1;
            }
            else
            {
                harta[y][x-1].setPatrat('*');
                harta[y][x+2].setPatrat('*');
                harta[y][x-1].setNavaStationara(*this);
                harta[y][x+2].setNavaStationara(*this);
                harta[y][x-1].setTipNava("Crucisator");
                harta[y][x+2].setTipNava("Crucisator");
            }
        }
    harta[y][x].setPatrat('*');
    harta[y+1][x].setPatrat('*');
    harta[y][x+1].setPatrat('*');
    harta[y+1][x+1].setPatrat('*');
    harta[y-1][x].setPatrat('*');
    harta[y-1][x+1].setPatrat('*');
    harta[y][x].setNavaStationara(*this);
    harta[y+1][x].setNavaStationara(*this);
    harta[y][x+1].setNavaStationara(*this);
    harta[y+1][x+1].setNavaStationara(*this);
    harta[y-1][x].setNavaStationara(*this);
    harta[y-1][x+1].setNavaStationara(*this);
    harta[y][x].setTipNava("Crucisator");
    harta[y+1][x].setTipNava("Crucisator");
    harta[y][x+1].setTipNava("Crucisator");
    harta[y+1][x+1].setTipNava("Crucisator");
    harta[y-1][x].setTipNava("Crucisator");
    harta[y-1][x+1].setTipNava("Crucisator");
    return 0;
}
istream& operator>>(istream& i,Crucisator& C)
{
    std::cin>>static_cast<Nava&>(C);
    return i;
}

ostream& operator<<(ostream& o,Crucisator& C)
{
    std::cout<<static_cast<Nava&>(C);
    return o;
}

int Crucisator::regenerare()
{
    this->setCombustibil(this->getCombustibil()-5);
    this->setGradAvarie(this->getGradAvarie()-14);
    return 0;
}
int Crucisator::setActivat()
{
    if(sistemAparare == true)
        sistemActivat = true;
    return 0;
}
bool Crucisator::getActivat()
{
    return sistemActivat;
}
