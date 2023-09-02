#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <string.h>

class lista{
    private:
    lista *sljedeci;
    lista *glSljedeci;

    public:
    int broj;
    char ime[100];
    int godine;

    lista(){
        sljedeci=0;
        glSljedeci=0;
    }

    static int broj2;

    void dodavanjeElementa(int grana, int broj1, char ime1[100], int godine1){
        lista *zadnji1=this;
        for(int i=0;i<grana;i++){
            zadnji1=zadnji1->glSljedeci;
        }
        lista *novi, *zadnji=zadnji1;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci=novi;
        novi->sljedeci=0;
        novi->broj = broj1;
        strcpy(novi->ime, ime1);
        novi->godine=godine1;
    }

    void dodavanjeGlave(){
        lista *novi, *zadnji=this;
        while(zadnji->glSljedeci)
            zadnji=zadnji->glSljedeci;
        novi = new lista;
        zadnji->glSljedeci=novi;
        novi->sljedeci=0;
        novi->glSljedeci=0;
        broj2++;
    }

    void ispis(){
        lista *zadnji=this;
        for(int i=0;i<broj2;i++){
            zadnji=zadnji->glSljedeci;
            lista *prvi=zadnji->sljedeci;
            while(prvi){
                printf("%d\n", prvi->broj);
                printf("%s\n", prvi->ime);
                printf("%d\n", prvi->godine);
                prvi=prvi->sljedeci;
            }
        }
    }
};
#endif