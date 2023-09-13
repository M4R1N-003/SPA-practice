#include <stdio.h>

struct pom{
    int N;
    pom *sljedeci;
};

void dodavanje(pom *glava, int s){
    pom *novi, *zadnji=glava;
    while(zadnji->sljedeci)
        zadnji=zadnji->sljedeci;
    novi = new pom;
    zadnji->sljedeci=novi;
    novi->sljedeci=0;
    novi->N=s;
}

void ispis(pom *glava){
    pom *tekuci=glava->sljedeci;
    while(tekuci){
        printf("%d",tekuci->N);
        printf(" ");
        tekuci=tekuci->sljedeci;
    }
}


