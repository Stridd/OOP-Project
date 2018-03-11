#ifndef DISTRUGATOR_H
#define DISTRUGATOR_H
#include "Nava.h"
#include "Forma.h"
#include "CampDeLupta.h"

class Distrugator:public Nava,protected Forma
{
    public:
        Distrugator();
        ~Distrugator();
        int ConstruiesteForma(CampDeLupta harta[30][30]);
        friend istream& operator>>(istream& i,Distrugator& D);
        friend ostream& operator<<(ostream& o,Distrugator& D);
        int regenerare();
    protected:

    private:
};

#endif // DISTRUGATOR_H
