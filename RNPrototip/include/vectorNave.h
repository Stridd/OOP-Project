#ifndef VECTORNAVE_H
#define VECTORNAVE_H
#include "Nava.h"

class vectorNave: public Nava
{
    public:
        vectorNave();
        ~vectorNave();
        int setNava(char s[20]);
        int setEchipa(char s[20]);
        int setTipNava(char s[20]);
        Nava* getNava();
        char* getEchipa();
        char* getTipNava();
        int setActiuneTura(int x)
        {
            int actiuneTura = x;
            return 0;
        }
        int getActiuneTura()
        {
            return actiuneTura;
        }
    protected:

    private:
        Nava* nava1;
        char echipa[20];
        char tipNava[20];
        int actiuneTura;
};

#endif // VECTORNAVE_H
