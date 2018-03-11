#ifndef ACTIUNE_H
#define ACTIUNE_H
#include "Nava.h"

class Actiune
{
    public:
        Actiune();
        ~Actiune();
        virtual int Atac(int X,int Y) = 0;
        virtual int Nimic() = 0;
    protected:
        virtual int Regenerare();
    private:
};

#endif // ACTIUNE_H
