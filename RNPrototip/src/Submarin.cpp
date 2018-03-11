#include "Submarin.h"
#include <iostream>
#include <cstring>
#include "Salupa.h"
#include "Distrugator.h"
#include "Crucisator.h"

Submarin::Submarin():Nava(225)
{
    //ctor
    combustibil = 225;
}

Submarin::~Submarin()
{
    //dtor
}

int Submarin::ConstruiesteForma(CampDeLupta harta[30][30])
{
    int x = this->getX();
    int y = this->getY();
    if(harta[y][x].getPatrat()!=' ' || harta[y+1][x].getPatrat()!=' ')
        {
            std::cout << "Nu se poate crea un submarin la aceasta locatie \n";
            return -1;
        }
    harta[y][x].setPatrat('*');
    harta[y+1][x].setPatrat('*');
    harta[y][x].setTipNava("Submarin");
    harta[y][x].setNavaStationara(*this);
    harta[y+1][x].setTipNava("Submarin");
    harta[y+1][x].setNavaStationara(*this);
    return 0;
}

istream& operator>>(istream& i,Submarin& S)
{
    std::cin>>static_cast<Nava&>(S);
    return i;
}

ostream& operator<<(ostream& o,Submarin& S)
{
    std::cout<<static_cast<Nava&>(S);
    return o;
}
int Submarin::autodistrugere(CampDeLupta harta[30][30])
{
    int i,j;
    int x = this->getX();
    int y = this->getY();
    for(i = x-1 ; i <= x+1; i++)
        for( j = y-1; j <= y+1; j++)
            if(harta[j][i].getPatrat()!=' ')
                {
                    if(strcmp(harta[j][i].getTipNava(),"Salupa") == 0)
                        {
                            Salupa& S2 = dynamic_cast<Salupa&>(*(harta[j][i].getNavaStationara()));
                           S2.setGradAvarie(100);
                        }
                     if(strcmp(harta[j][i].getTipNava(),"Submarin") == 0)
                        {

                            Submarin& S2 = dynamic_cast<Submarin&>(*(harta[j][i].getNavaStationara()));
                            S2.setGradAvarie(100);
                        }
                     if(strcmp(harta[j][i].getTipNava(),"Distrugator") == 0)
                        {
                            Distrugator& S2 = dynamic_cast<Distrugator&>(*(harta[j][i].getNavaStationara()));
                            S2.setGradAvarie(100);
                        }
                     if(strcmp(harta[j][i].getTipNava(),"Crucisator") == 0)
                        {
                            Crucisator& S2 = dynamic_cast<Crucisator&>(*(harta[j][i].getNavaStationara()));
                            S2.setGradAvarie(100);
                        }
                }
    this->setGradAvarie(100);
    return 0;
}
