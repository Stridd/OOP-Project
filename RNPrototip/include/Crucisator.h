#ifndef CRUCISATOR_H
#define CRUCISATOR_H
#include "Nava.h"
#include "Forma.h"
#include "CampDeLupta.h"

class Crucisator: public Nava,protected Forma
{
    public:
        Crucisator();
        ~Crucisator();
        int ConstruiesteForma(CampDeLupta harta[30][30]);
        bool getSistemAparare()
        {
            return sistemAparare;
        }
        int setSistemAparare(bool x);
        friend istream& operator>>(istream& i,Crucisator& C);
        friend ostream& operator<<(ostream& o,Crucisator& C);
        int regenerare();
        int setActivat();
        bool getActivat();
    protected:

    private:
        bool sistemAparare;
        bool sistemActivat;
};

#endif // CRUCISATOR_H
