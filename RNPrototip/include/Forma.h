#ifndef FORMA_H
#define FORMA_H
#include "CampDeLupta.h"

class Forma
{
    public:
        Forma();
        ~Forma();
    protected:
        virtual int ConstruiesteForma(CampDeLupta harta[30][30]) = 0;
    private:
};

#endif // FORMA_H
