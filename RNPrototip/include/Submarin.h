#ifndef SUBMARIN_H
#define SUBMARIN_H
#include "Nava.h"
#include "Forma.h"
#include "CampDeLupta.h"
#include "Actiune.h"

class Submarin:public Nava,protected Forma
{
    public:
        Submarin();
        ~Submarin();
        int ConstruiesteForma(CampDeLupta harta[30][30]);
        friend istream& operator>>(istream&i,Submarin&S);
        friend ostream& operator<<(ostream&o,Submarin&S);
        int atac(int X,int Y);
        int autodistrugere(CampDeLupta harta[30][30]);
    protected:

    private:
};

#endif // SUBMARIN_H
