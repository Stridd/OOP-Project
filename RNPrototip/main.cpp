#include <iostream>
#include <fstream>
#include <cstring>

#include "Nava.h"
#include "Crucisator.h"
#include "Distrugator.h"
#include "Submarin.h"
#include "Salupa.h"
#include "vectorNave.h"
#include "CampDeLupta.h"

using namespace std;

/*
-Dreptunghi N x N
-Navele nu apuca sa isi miste pozitia
-Navele ocupa pozitii disjuncte
-4 tipuri de nave: Salupa,Submarin,Distrugator si Crucisator
-Toate navele au o pozitie si o forma (patrate 1x1)
-Toate navele sunt echipate cu rachete de atac
-Toate navele dispun de combustibil si au grad de avarie(0-100). Pentru combustibil 0 sau avarie 100 nava este scoasa din joc.
-Conflictul se desfasoara pe randuri, iar actiunile au loc la inceputul urmatoarei runde
-La finalul fiecarei runde, nava consuma combustibil (egala cu numarul de patratele)
-Actiunea de regenerare consuma 5 L combustibil si scade gradul de avarie cu 14
-Lansarea unei rachete reduce stocul de rachete cu 1. Se poate lansa maximum o racheta pe rand.
-Salupa ->Forma *
-Submarin -> Forma 2 *
-Distrugator -> Forma 3 *
-Crucisator -> Forma 6* sau 8*
-Resurse pentru toate navele: Combustibil + Rachete de atac
-Grad de avarie(in cazul unui atac cu rachete din partea  pentru : Salupa -> 100
                                                                   Submarin -> 50
                                                                   Distrugator -> 35
                                                                   Crucisator -> 20 (in caz ca nu sunt interceptate)

-Actiuni posibile pentru:  Salupa(atac cu rachete, nimic)
                           Submarin(atac cu rachete, autodistrugere, nimic)
                           Distrugator(atac cu rachete, regenerare, nimic)
                           Crucisator(atac cu rachete, regenerare, nimic + incarcare sistem autoaparare)

-Nivel initial combustibil : Salupa(55), Submarin(225), Distrugator(300), Crucisator(De la tastatura)
-O nava cu grad de avarie >= 70 nu poate lansa atacuri in acel rand
-Crucisatorul poate sa-si activeze sistemul de aparare pentru 2L . Daca rachetele ar lovi acel crucisator, atunci
rahetele au sansa de 75% sa fie distruse,caz in care nu produc avarii.
-Autodistrugerea submarinului -> Distrugerea completa (avarie +100) a tuturor navelor cu care se intersecteaza.
                -Zona tinta difera cu 2 patratele de pozitia submarinului
-Lansarea unei rachete -> Input dat de Utilizator prin X si Y

*/

/// Din pacate nu am reusit sa fac functia de "interceptare si exista cateva buguri

int funct1(Nava& S1,CampDeLupta harta[30][30],vectorNave v[100],int i)
{
        cout << "Alegeti actiune pentru " << v[i].getTipNava() << " " << v[i].getEchipa();
        cout << "( X = " << S1.getX() << " Y = " << S1.getY() << ')' <<'\n';
        cout << "Actiunile disponibile sunt: ";
            cout << " Atac, ";
        if(strcmp(v[i].getTipNava(),"Submarin") == 0)
           cout << " Autodistrugere, ";
        else
            if(strcmp(v[i].getTipNava(),"Distrugator") == 0 || strcmp(v[i].getTipNava(),"Crucisator") == 0)
                cout << " Regenerare, ";
        cout << "Nimic\n";
        char opt[20];
        cin >> opt;
        strlwr(opt);
        if(strcmp(opt,"atac") == 0 && S1.getnumarRachete() != 0 && S1.getGradAvarie() < 70 && S1.getnumarRachete()!= 0)
            {
            S1.Atac(harta);
            S1.setnumarRachete(S1.getnumarRachete()-1);
            }
        else
            if(strcmp(opt,"autodistrugere") == 0)
            {
                if(strcmp(v[i].getTipNava(),"Submarin") == 0)
                   {
                       Submarin S2 = dynamic_cast<Submarin&>(S1);
                       S2.autodistrugere(harta);
                   }
                else
                    cout << "Nava aceasta nu se poate autodistruge\n";
            }
        else
            if(strcmp(opt,"regenerare") == 0)
            {
                if(strcmp(v[i].getTipNava(),"Crucisator") == 0)
                   {

                       Crucisator& S2 = dynamic_cast<Crucisator&>(*(v[i].getNava()));
                       S2.regenerare();
                   }
                else
                    if(strcmp(v[i].getTipNava(),"Distrugator") == 0)
                    {
                        Distrugator& S2 = dynamic_cast<Distrugator&>(*(v[i].getNava()));
                        S2.regenerare();
                    }
                else
                    cout << "Nava aceasta nu se poate regenera\n";
            }
        if(strcmp(v[i].getTipNava(),"Crucisator") == 0)
           {
               Crucisator& S2 = dynamic_cast<Crucisator&>(*(v[i].getNava()));
               if(S2.getSistemAparare() == true)
                {
                    cout << "Doriti sa activati sistemul de aparare al crucisatorului?\n";
                    char opt[20];
                    cin >> opt;
                    strlwr(opt);
                    if(strcmp(opt,"da") == 0)
                    {
                        S2.setActivat();
                        S2.setCombustibil(S2.getCombustibil()-2);
                    }
                }
           }
        S1.setCombustibil(S1.getCombustibil()-S1.getnumarPatrate());

}
int getInput(vectorNave v[100],int i,CampDeLupta harta[30][30])
{

    if(strcmp(v[i].getTipNava(),"Salupa") == 0)
        {
            Salupa& S1 = dynamic_cast<Salupa&>(*(v[i].getNava()));
            funct1(S1,harta,v,i);
        }
    else
        if(strcmp(v[i].getTipNava(),"Submarin") == 0)
            {
                Submarin& S1 = dynamic_cast<Submarin&>(*(v[i].getNava()));
                funct1(S1,harta,v,i);
            }
    else
        if(strcmp(v[i].getTipNava(),"Distrugator") == 0)
            {
                Distrugator& S1 = dynamic_cast<Distrugator&>(*(v[i].getNava()));
                funct1(S1,harta,v,i);
            }
    else
        if(strcmp(v[i].getTipNava(),"Crucisator") == 0)
            {
                Crucisator& S1 = dynamic_cast<Crucisator&>(*(v[i].getNava()));
                funct1(S1,harta,v,i);
            }
    return 0;
}
int main()
{
    CampDeLupta harta[30][30];
    vectorNave v[100];
    ifstream f("input.in");
    char echipaText[20],tipNavaText[10];
    char sistAp[10],additionalText[40],temp[20];
    int Coord1,Coord2,nrLitriNava,numarRachete2;
    char c;
    int k = 0;
    int numarNaveRosii = 0,numarNaveAlb = 0;
    while(1)
    {
        f >> echipaText;
        strcpy(temp,echipaText);
        if(f.eof())
            break;

        f >> tipNavaText;
        f >> c >> Coord1;
        f >> c >> Coord2;
        if(strcmp(temp,"Rosu") == 0)
            numarNaveRosii ++;
        else
            numarNaveAlb ++;
        if(strcmp(tipNavaText,"Crucisator") == 0)
            f >> sistAp;

        if(strcmp(tipNavaText,"Crucisator") == 0)
            f >> nrLitriNava >> additionalText;

        f >> numarRachete2 >> additionalText;

        v[k].setNava(tipNavaText);
        v[k].setTipNava(tipNavaText);
        v[k].setEchipa(temp);

        // Optimizare

        if(strcmp(tipNavaText,"Salupa") == 0)
        {
            Salupa& S1 = dynamic_cast<Salupa&>(*(v[k].getNava()));
            S1.setX(Coord1);
            S1.setY(Coord2);
            S1.setnumarRachete(numarRachete2);
            S1.ConstruiesteForma(harta);
            S1.setEchipa(temp);
        }
        if(strcmp(tipNavaText,"Submarin") == 0)
        {

            Submarin& S1 = dynamic_cast<Submarin&>(*(v[k].getNava()));
            S1.setX(Coord1);
            S1.setY(Coord2);
            S1.setnumarRachete(numarRachete2);
            S1.ConstruiesteForma(harta);
            S1.setEchipa(temp);
        }
        if(strcmp(tipNavaText,"Crucisator") == 0)
        {
            Crucisator& C1 = dynamic_cast<Crucisator&>(*(v[k].getNava()));
            C1.setX(Coord1);
            C1.setY(Coord2);
            C1.setnumarRachete(numarRachete2);
            C1.setCombustibil(nrLitriNava);
            if(strcmp(sistAp,"true") == 0)
            {
                C1.setSistemAparare(true);
            }
            else
                C1.setSistemAparare(false);

            C1.ConstruiesteForma(harta);
            C1.setEchipa(temp);
            // De adaugat sistem de aparare
        }
        if(strcmp(tipNavaText,"Distrugator") == 0)
        {
            Distrugator& D1 = dynamic_cast<Distrugator&>(*(v[k].getNava()));
            D1.setX(Coord1);
            D1.setY(Coord2);
            D1.setnumarRachete(numarRachete2);
            D1.ConstruiesteForma(harta);
            D1.setEchipa(temp);
        }
        k++;
    }
    int runda = 0;
    while(numarNaveAlb >0 && numarNaveRosii>0)
    {
        runda++;
        cout << "Runda: " << runda << '\n';
        cout << "Nave albastre ramase: " << numarNaveAlb << '\n';
        cout << "Nave rosii ramase: " << numarNaveRosii << '\n';
        for(int i = 0 ; i < k; i++)
        {
            if(v[i].getDistrusa() == 0)
                getInput(v,i,harta);
        }
        for(int i = 0 ; i < k; i++)
        {
            if(strcmp(v[i].getTipNava(),"Salupa") == 0)
            {
                Salupa& S1 = dynamic_cast<Salupa&>(*(v[i].getNava()));
                S1.setCombustibil(S1.getCombustibil() - S1.getnumarPatrate());
           // funct1(S1,harta,v,i);
                if(S1.getCombustibil() == 0 || S1.getGradAvarie() >= 100 && v[i].getDistrusa() == 0)
                {
                    v[i].setDistrusa(1);
                    if(strcmp(v[i].getEchipa(),"Rosu") == 0)
                        numarNaveRosii--;
                    else
                        if(strcmp(v[i].getEchipa(),"Albastru") == 0)
                        numarNaveAlb--;
                }
            }
        else
            if(strcmp(v[i].getTipNava(),"Submarin") == 0)
                {
                    Submarin& S1 = dynamic_cast<Submarin&>(*(v[i].getNava()));
                    S1.setCombustibil(S1.getCombustibil() - S1.getnumarPatrate());
                    if(S1.getCombustibil() == 0 || S1.getGradAvarie() >= 100 && v[i].getDistrusa() == 0)
                    {
                        v[i].setDistrusa(1);
                        if(strcmp(v[i].getEchipa(),"Rosu") == 0)
                        numarNaveRosii--;
                        else
                            if(strcmp(v[i].getEchipa(),"Albastru") == 0)
                            numarNaveAlb--;
                    }
                }
        else
            if(strcmp(v[i].getTipNava(),"Distrugator") == 0)
                {
                    Distrugator& S1 = dynamic_cast<Distrugator&>(*(v[i].getNava()));
                    S1.setCombustibil(S1.getCombustibil() - S1.getnumarPatrate());
                    if(S1.getCombustibil() == 0 || S1.getGradAvarie() >= 100 && v[i].getDistrusa() == 0)
                    {
                        v[i].setDistrusa(1);
                         if(strcmp(v[i].getEchipa(),"Rosu") == 0)
                        numarNaveRosii--;
                        else
                            if(strcmp(v[i].getEchipa(),"Albastru") == 0)
                            numarNaveAlb--;
                    }
                }
        else
            if(strcmp(v[i].getTipNava(),"Crucisator") == 0)
                {
                    Crucisator& S1 = dynamic_cast<Crucisator&>(*(v[i].getNava()));
                    S1.setCombustibil(S1.getCombustibil() - S1.getnumarPatrate());
                    if(S1.getCombustibil() == 0 || S1.getGradAvarie() >= 100 && v[i].getDistrusa() == 0)
                    {
                        v[i].setDistrusa(1);
                         if(strcmp(v[i].getEchipa(),"Rosu") == 0)
                        numarNaveRosii--;
                        else
                            if(strcmp(v[i].getEchipa(),"Albastru") == 0)
                            numarNaveAlb--;
                    }
                }
        }

    }
    if(numarNaveAlb == 0 && numarNaveRosii == 0)
        cout << "Remiza\n";
    else
        if(numarNaveAlb == 0)
            cout << "Rosu este invingator\n";
    else
        if(numarNaveRosii == 0)
            cout << "Albastru este invingator\n";
    //for(int i = 0 ; i < k ; i++)
      //  if(v[i].getDistrusa() == 0)
        //    getInput(v,i,harta);

    for(int i = 0 ; i < k; i++)
    {
        if(strcmp(v[i].getTipNava(),"Salupa")==0)
        {
            Salupa& S1=dynamic_cast<Salupa&>(*(v[i].getNava()));
            cout << S1 <<'\n';
        }
        if(strcmp(v[i].getTipNava(),"Submarin")==0)
        {
            Submarin& S1=dynamic_cast<Submarin&>(*(v[i].getNava()));
            cout << S1 <<'\n';
        }
        if(strcmp(v[i].getTipNava(),"Distrugator")==0)
        {
            Distrugator& S1=dynamic_cast<Distrugator&>(*(v[i].getNava()));
            cout << S1 <<'\n';
        }
        if(strcmp(v[i].getTipNava(),"Crucisator") == 0)
        {
            Crucisator& S1=dynamic_cast<Crucisator&>(*(v[i].getNava()));
            cout << S1 <<'\n';
        }
    }

    return 0;
}
