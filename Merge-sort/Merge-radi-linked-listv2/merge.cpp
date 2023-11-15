#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

class lista{
    private:
    lista *sljedeci;
    public:
    int N;
    
    lista(){
        sljedeci=NULL;
    }

    void unos(int x){
        lista *novi, *zadnji=this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista();
        zadnji->sljedeci=novi;
        novi->N=x;
        novi->sljedeci=NULL;
    }

    void ispis(){
        lista *tekuci=this->sljedeci;
        while(tekuci){
            cout << tekuci->N << " ";
            tekuci=tekuci->sljedeci;
        }
    }

    void sortiranje(){
        MergeSort(&this->sljedeci);
    }

    void MergeSort(lista **refGlava){
        lista* glava = *refGlava;
        lista *a;
        lista *b;
    	if((glava==NULL)||glava->sljedeci==NULL) 
            return;

        Odvajanje(glava, &a, &b);

        MergeSort(&a);
        MergeSort(&b);

        *refGlava = Sortiran(a, b);
    }

    lista *Sortiran(lista *a, lista *b){
        lista *rezultat = NULL;
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a->N <= b->N){
            rezultat=a;
            rezultat->sljedeci = Sortiran(a->sljedeci, b);
        }
        else{
            rezultat=b;
            rezultat->sljedeci = Sortiran(b->sljedeci, a);
        }
        return rezultat;
    }

    void Odvajanje(lista *korijen, lista **ispred, lista **iza){
        lista *brzi;
        lista *spori;
        spori=korijen;
        brzi=korijen->sljedeci;

        while(brzi!=NULL){
            brzi=brzi->sljedeci;
            if(brzi!=NULL){
                spori=spori->sljedeci;
                brzi=brzi->sljedeci;
            }
        }

        *ispred = korijen;
        *iza = spori->sljedeci;
        spori->sljedeci=NULL;
    }

};

int main(){
    srand(time(0));
    lista *objekt = new lista();

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int s;
        s=rand()%20;
        objekt->unos(s);
    }
    objekt->ispis();

    objekt->sortiranje();

    cout << endl;

    objekt->ispis();

    return 0;
}