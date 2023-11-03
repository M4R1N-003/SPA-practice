#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

class lista{
    private:
    lista *sljedeci;
    public:
    int N;

    lista(){
        sljedeci=NULL;
    }

    void dodavanje(int x){
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

    void sortiranje() {
        lista *pocetak = this->sljedeci; 
        lista *sortirani = new lista;

        while (pocetak) {
            lista *trenutni = pocetak;
            pocetak = pocetak->sljedeci;

            lista *prev = sortirani;
            lista *t = sortirani->sljedeci;

            while (t && t->N < trenutni->N) {
                prev = t;
                t = t->sljedeci;
            }

            prev->sljedeci = trenutni;
            trenutni->sljedeci = t;
        }

        this->sljedeci = sortirani->sljedeci;

        delete sortirani;
    }


};
int main(){
    int n;
    lista *objekt = new lista();
    srand(time(0));
    cin >> n;
    for(int i=0;i<n;i++){
        int s = rand()%20;
        objekt->dodavanje(s);
    }
    objekt->ispis();
    cout << endl;
    objekt->sortiranje();
    objekt->ispis();


    return 0;
}