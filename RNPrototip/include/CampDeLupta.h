#ifndef CAMPDELUPTA_H
#define CAMPDELUPTA_H
#include "Nava.h"
class Nava;

class CampDeLupta
{
    public:
        CampDeLupta();
        ~CampDeLupta();
        int setPatrat(char );
        char getPatrat();
        int setTipNava(char* );
        char* getTipNava();
        int setNavaStationara(Nava& );
        Nava* getNavaStationara();
    private:
        char Patrat;
        char tipNava[20];
        Nava* NavaStationara;
};

#endif // CAMPDELUPTA_H
