#include <iostream>
#include <cmath>
#include "prosta.hpp"
#include "wektor.hpp"
#include "punkt.hpp"

using namespace std;

prosta::prosta(punkt p1, punkt p2){

    if (p1.x==p2.x && p1.y==p2.y)
        throw invalid_argument("Punkty musza byc rozne!");

    a=p2.y-p1.y;
    b=p1.x-p2.x;
    c=p2.x*p1.y-p1.x*p2.y;

    double u=1/sqrt(a*a+b*b);
    if (c>0)
        u*=-1;
    a*=u;
    b*=u;
    c*=u;
}

prosta::prosta (wektor w){

    a=w.dx;
    b=w.dy;
    c=-w.dx*w.dx - w.dy*w.dy;

    double u=1/sqrt(a*a+b*b);
    if (c>0)
        u*=-1;
    a*=u;
    b*=u;
    c*=u;
}

prosta::prosta (double a1, double a2, double a3){

    if (a1==0 && a2==0)
        throw invalid_argument("A i B nie mogą być rowne 0!");

    a=a1;
    b=a2;
    c=a3;

    double u=1/sqrt(a*a+b*b);
    if (c>0)
        u*=-1;
    a*=u;
    b*=u;
    c*=u;
}

prosta::prosta(prosta *p,wektor w){

    double y1= -1 * p->getC()/p->getB();
    double y2= -1 * p->getC()/p->getB() - p->getA()/p->getB();

    y1+=w.dy;
    y2+=w.dy;

    punkt p1(w.dx, y1);
    punkt p2(w.dx+1, y2);

    prosta nowa(p1,p2);

    a=nowa.getA();
    b=nowa.getB();
    c=nowa.getC();

    double u=1/sqrt(a*a+b*b);
        if (c>0)
            u*=-1;
        a*=u;
        b*=u;
        c*=u;
}

double prosta::getA(){
    return a;}

double prosta::getB(){
    return b;}

double prosta::getC(){
    return c;}

bool prosta::czy_wektor_prostopadly(wektor w){

     prosta prosta1(w);
     prosta prosta2(a,b,c);

     if (czy_rownolegle(&prosta1, &prosta2))
        return true;
    return false;
}

bool prosta::czy_wektor_rownolegly(wektor w){

    prosta prosta1(w);
    prosta prosta2(a,b,c);

    if (czy_prostopadle(&prosta1, &prosta2))
        return true;
    return false;
}

bool prosta::czy_punkt_lezy_na_prostej(punkt p){

    if(a*p.x + b*p.y + c==0)
    return true;

    cout<<(abs(a*p.x+b*p.y+c))/(sqrt(a*a+b*b))<<'\n';
    return false;
}

bool czy_prostopadle(prosta *p1,prosta *p2){
    return p1->getA() * p2->getA() + p1->getB() * p2->getB() ? false : true;
}

bool czy_rownolegle(prosta *p1,prosta *p2){
    return ((p1->getA() * p2->getB()) - (p1->getA() * p1->getB())) ? false : true;
}

void punkt_przeciecia_prostych(prosta *p1,prosta *p2){

    double d=p1->getA() * p2->getB() - p2->getA() * p1->getB();

    if (d)
        cout<<"("<<(p1->getB() * p2->getC() - p2->getB() * p1->getC())/d<<" , " <<(p1->getA() * p2->getB() - p2->getA() * p1->getB())/d<<")\n";
    else
        cout<<"Proste sa rownolegle!\n";
}
