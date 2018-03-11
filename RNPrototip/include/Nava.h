#ifndef NAVA_H
#define NAVA_H
#include <iostream>
#include "CampDeLupta.h"

class CampDeLupta;

using namespace std;
/*
    Caracteristicile clasei:
    - forma navei
    - functie de atac
    - functie de regenerare ( oare clasa separata pentru actiune ? )
    - constructor
    - destructor
    - settere si gettere
    - grad de avarie
    - numar rachete
    - combustibil
    - Operatori de atribuire pentru rachete/grad de avarie( pentru rachete -- , pentru avarie + )
*/
/// Pentru a folosi dynamic_cast trebuie sa existe cel putin o functie virtuala pentru ca dynamic_cast executa o verificare
/// la run-time

class Nava
{
    // Echipa private sau protected ?
    protected:
        // Coordonatele "Centrului navei " . Adica de unde se centreaza constructia navei pe harta
        int X,Y;
        // Forma navei -> reprezentata ca o matrice de stelute care retine si numarul de stele ale navei
        // eventual si daca exista sistem de aparare
        //Forma FormaNava;
        int numarRachete;
        int combustibil;
        int gradAvarie;
        char echipa[20];
        int nrPatrate;
        int distrusa;
    public:
        Nava();
        Nava(int x);
        virtual ~Nava();
        int getnumarRachete();
        int setnumarRachete(int);
        int getCombustibil();
        int setCombustibil(int);
        int getGradAvarie();
        int setGradAvarie(int );
        int setX(int );
        int setY(int );
        int getX();
        int getY();
        int setEchipa(char s[20]);
        int setDistrusa(int x);
        int getDistrusa();
        int getnumarPatrate();
        char* getEchipa();
        //virtual int getasd(){};
        friend istream& operator>>(istream& i,Nava& N);
        friend ostream& operator<<(ostream& o,Nava& N);
        virtual int Atac(CampDeLupta harta[30][30]);
        int Nimic(){return 0;}
        virtual int regenerare();

};
#endif // NAVA_H
