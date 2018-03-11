#include "Distrugator.h"
#include <iostream>
Distrugator::Distrugator():Nava(300)
{
    //ctor
    nrPatrate = 3;
}

Distrugator::~Distrugator()
{
    //dtor

}
int Distrugator::ConstruiesteForma(CampDeLupta harta[30][30])
{
    int x = this->getX();
    int y = this->getY();
    if(harta[y][x].getPatrat() !=' ' || harta[y+1][x].getPatrat()!=' ' || harta[y+2][x].getPatrat()!=' ')
    {
        std::cout << "Nu se poate crea un distrugator la aceasta locatie\n";
        return -1;
    }
    harta[y][x].setPatrat('*');
    harta[y+1][x].setPatrat('*');
    harta[y+2][x].setPatrat('*');
    harta[y][x].setNavaStationara(*this);
    harta[y+1][x].setNavaStationara(*this);
    harta[y+2][x].setNavaStationara(*this);
    harta[y][x].setTipNava("Distrugator");
    harta[y+1][x].setTipNava("Distrugator");
    harta[y+2][x].setTipNava("Distrugator");
    return 0;
}

istream& operator>>(istream& i,Distrugator& D)
{
    std::cin>>static_cast<Nava&>(D);
    return i;
}

ostream& operator<<(ostream& o,Distrugator& D)
{
    std::cout<<static_cast<Nava&>(D);
    return o;
}
int Distrugator::regenerare()
{
    this->setCombustibil(this->getCombustibil()-5);
    this->setGradAvarie(this->getGradAvarie()-14);
    return 0;
}
