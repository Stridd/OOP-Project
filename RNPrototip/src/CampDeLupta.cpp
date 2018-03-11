#include "CampDeLupta.h"
#include <cstring>

CampDeLupta::CampDeLupta()
{
    //ctor
    Patrat = ' ';
    strcpy(tipNava,"");
    NavaStationara = NULL;
}

CampDeLupta::~CampDeLupta()
{
    //dtor
}
int CampDeLupta::setPatrat(char x)
{
    Patrat = x;
    return 0;
}
char CampDeLupta::getPatrat()
{
    return Patrat;
}
int CampDeLupta::setTipNava(char s[20])
{
    strcpy(tipNava,s);
    return 0;
}
char* CampDeLupta::getTipNava()
{
    return tipNava;
}
 int CampDeLupta::setNavaStationara(Nava& n)
 {
     NavaStationara = &n;
     return 0;
 }
Nava* CampDeLupta::getNavaStationara()
{
    return NavaStationara;
}
