#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
class lista{
    public:
    lista *sljedeci;
    lista(){
        sljedeci=0;
    }

    int N;

    void dodavanje(int broj){
        lista *novi, *zadnji=this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci=novi;
        novi->sljedeci=0;
        novi->N=broj;
    }

    void deleting(int k){
        lista *prethodni=this;
        lista *tekuci = this->sljedeci;
        while(tekuci){
            if((tekuci->N)%k==0){
                prethodni->sljedeci=tekuci->sljedeci;
                delete tekuci;
                tekuci = prethodni->sljedeci;
                } 
                else {
                prethodni = tekuci;
                tekuci = tekuci->sljedeci;
            }
        }
    }

    void ispis(){
        lista *tekuci=this->sljedeci;
        while(tekuci){
            printf("%d\n", tekuci->N);
            printf("\n");
            tekuci=tekuci->sljedeci;
        }
    }
};

#endif