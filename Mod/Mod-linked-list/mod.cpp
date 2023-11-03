#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int maks=0;

class lista{
    private:
    lista *sljedeci;
    public:
    int N;
    int brojac=0;

    lista(){
        sljedeci=NULL;
    }

    void pretrazivanje(int x) {
        lista* trenutni = this->sljedeci;
        while (trenutni) {
            if (trenutni->N == x) {
                trenutni->brojac++;
                if (trenutni->brojac > maks)
                    maks = trenutni->brojac;
            }

            trenutni = trenutni->sljedeci;
        }
    }


    void dodavanje(int x){
        lista *novi, *zadnji=this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista();
        zadnji->sljedeci=novi;
        novi->N=x;
        novi->sljedeci=NULL;
        pretrazivanje(x); 
    }

    void ispis(){
        lista *tekuci=this->sljedeci;
        while(tekuci){
            cout << tekuci->N << " ";
            tekuci=tekuci->sljedeci;
        }
    }

    void rjesenje(){
        lista *trenutni=this->sljedeci;
        while(trenutni){
            if(trenutni->brojac==maks){
                cout << trenutni->N << " ";
            }
            trenutni=trenutni->sljedeci;
        }
        cout << endl;
    }

};
int main(){
    lista *objekt = new lista();
    int n;
    cout << "Unesite broj brojeva: ";
    cin >> n;
    srand(time(0));
    for(int i=0;i<n;i++){
        int s =  rand()%20;
        objekt->dodavanje(s);
    }
    objekt->ispis();
    cout << endl;
    objekt->rjesenje();
    cout << maks;


    return 0;
}