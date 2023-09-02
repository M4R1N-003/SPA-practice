#include <iostream>
#include "lista.h"
using namespace std;


lista* sortiranMerge(lista* a, lista* b);
void odvajanje(lista* korjen, lista** ispred, lista** iza);

void sortiranje(lista** glava)
{
    lista* glavurda = *glava;
    lista* a;
    lista* b;
 
    if ((glavurda == NULL) || (glavurda->sljedeci == NULL)) {
        return;
    }
 
    odvajanje(glavurda, &a, &b);
 
    sortiranje(&a);
    sortiranje(&b);
 
    *glava = sortiranMerge(a, b);
}

lista* sortiranMerge(lista* a, lista* b)
{
    lista* resultat = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (a->N <= b->N) {
        resultat = a;
        resultat->sljedeci = sortiranMerge(a->sljedeci, b);
    }
    else {
        resultat = b;
        resultat->sljedeci = sortiranMerge(a, b->sljedeci);
    }
    return (resultat);
}

void odvajanje(lista* korjen, lista** ispred, lista** iza)
{
    lista* brzo;
    lista* sporo;
    sporo = korjen;
    brzo = korjen->sljedeci;
 
    while (brzo != NULL) {
        brzo = brzo->sljedeci;
        if (brzo != NULL) {
            sporo = sporo->sljedeci;
            brzo = brzo->sljedeci;
        }
    }
 
    *ispred = korjen;
    *iza = sporo->sljedeci;
    sporo->sljedeci = NULL;
}

int main(){
    lista *objekt = new lista;
    int n, brojcek, k;
    cout << "Unesite broj brojeva: ";
    cin >> n;

    for(int i = 0;i < n; i++){
       cout << "Unesite " << i+1 << ". broj: ";
       cin >> brojcek;
       objekt->dodavanje(brojcek); 
    }
    sortiranje(&objekt);

    cout << "Unesi broj ciji ce se visekratnici obrisati: ";
    cin >> k;

    objekt->deleting(k);

    objekt->ispis();

    return 0;
}