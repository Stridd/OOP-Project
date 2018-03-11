#ifndef SALUPA_H
#define SALUPA_H
#include "Nava.h"
#include "Forma.h"

class Salupa:public Nava,protected Forma
{
    public:
        Salupa();
        ~Salupa();
        int ConstruiesteForma(CampDeLupta harta[30][30]);
        friend ostream& operator<<(ostream&o,Salupa&S);
        friend istream& operator>>(istream&i,Salupa&S);
    protected:
    private:
};

#endif // SALUPA_H
