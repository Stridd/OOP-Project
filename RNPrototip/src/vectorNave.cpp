#include "vectorNave.h"
#include "Salupa.h"
#include "Submarin.h"
#include "Distrugator.h"
#include "Crucisator.h"
#include <cstring>

vectorNave::vectorNave()
{
    //ctor
}

vectorNave::~vectorNave()
{
    //dtor
}
int vectorNave::setNava(char s[20])
{
    if(strcmp(s,"Salupa") == 0)
        nava1 = new Salupa;
    if(strcmp(s,"Submarin") == 0)
        nava1 = new Submarin;
    if(strcmp(s,"Distrugator") == 0)
        nava1 = new Distrugator;
    if(strcmp(s,"Crucisator") == 0)
        nava1 = new Crucisator;
    return 0;
}
int vectorNave::setEchipa(char s[20])
{
    strcpy(echipa,s);
    return 0;
}
int vectorNave::setTipNava(char s[20])
{
    strcpy(tipNava,s);
    return 0;
}
Nava* vectorNave::getNava()
{
    return nava1;
}
char* vectorNave::getEchipa()
{
    return echipa;
}
char* vectorNave::getTipNava()
{
    return tipNava;
}
