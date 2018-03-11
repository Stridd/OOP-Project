#include <cstring>
#include "Nava.h"
#include "Distrugator.h"
#include "Salupa.h"
#include "Crucisator.h"
#include "Submarin.h"


Nava::Nava()
{
    numarRachete = 0;
    combustibil = 100;
    gradAvarie = 0;
    nrPatrate = 0;
}
Nava::~Nava()
{

}
Nava::Nava(int x)
{
    combustibil = x;
}
int Nava::setDistrusa(int x)
    {
        distrusa = x;
        return 0;
    }
int Nava::getnumarRachete()
{
    return numarRachete;
}

int Nava::getGradAvarie()
{
    return gradAvarie;
}

int Nava::getCombustibil()
{
    return combustibil;
}

int Nava::setCombustibil(int x)
{
    combustibil = x;
    return 0;
}

int Nava::setnumarRachete(int x)
{
    numarRachete = x;
    return 0;
}

int Nava::setGradAvarie(int x)
{
    gradAvarie = x;
    if (gradAvarie < 0)
        gradAvarie -= gradAvarie;
    return 0;
}
int Nava::setX(int x)
{
    X = x;
    return 0;
}
int Nava::getX()
{
    return X;
}
int Nava::setY(int y)
{
    Y = y;
    return 0;
}
int Nava::getY()
{
    return Y;
}
int Nava::setEchipa(char s[20])
{
    strcpy(echipa,s);
    return 0;
}
char* Nava::getEchipa()
{
    return echipa;
}
istream& operator>>(istream& i,Nava& N)
{
            std::cout << "Introduceti echipa din care face parte nava\n";
            i >> N.echipa;
            std::cout << "Introduceti coordonata X a navei\n";
            i >> N.X;
            std::cout << "Introduceti coordonata Y a navei\n";
            i >> N.Y;
            std::cout << "Introduceti numarul de rachete al navei \n";
            i >> N.echipa;
            return i;
}
ostream& operator<<(ostream& o,Nava& N)
{
    std::cout << " X = " << N.getX();
    std::cout << " Y = " << N.getY() << " ";
    std::cout << "Combustibil = " << N.getCombustibil();
    std::cout << " Rachete = " << N.getnumarRachete();
    std::cout << " Echipa = " << N.getEchipa();
    std::cout << " Grad avarie = " << N.getGradAvarie();
    std::cout << '\n';
    return o;
}

int Nava::Atac(CampDeLupta harta[30][30])
{
        cout << "Introduceti coordonatele (X , Y) la care vreti sa lansati o racheta\n";
        int x,y;
        cin >> x >> y;
        if(harta[y][x].getPatrat()!=' ')
        {
            if(strcmp(harta[y][x].getTipNava(),"Salupa") == 0)
            {
                Salupa& S2 = dynamic_cast<Salupa&>(*(harta[y][x].getNavaStationara()));
                S2.setGradAvarie(100);
            }
            if(strcmp(harta[y][x].getTipNava(),"Submarin") == 0)
            {
                Submarin& S2 = dynamic_cast<Submarin&>(*(harta[y][x].getNavaStationara()));
                S2.setGradAvarie(S2.getGradAvarie()+50);
            }
            if(strcmp(harta[y][x].getTipNava(),"Distrugator") == 0)
            {
                Distrugator& S2 = static_cast<Distrugator&>(*(harta[y][x].getNavaStationara()));
                S2.setGradAvarie(S2.getGradAvarie()+35);

            }
            if(strcmp(harta[y][x].getTipNava(),"Crucisator") ==0)
            {
                Crucisator& S2 = static_cast<Crucisator&>(*(harta[y][x].getNavaStationara()));
                S2.setGradAvarie(S2.getGradAvarie()+20);
            }
        }
        return 0;
}
int Nava::regenerare()
{
    return 0;
}
int Nava::getnumarPatrate()
{
    return nrPatrate;
}
int Nava::getDistrusa()
{
    return distrusa;
}
