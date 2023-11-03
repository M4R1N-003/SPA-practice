#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

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

    void brisanje(){
        lista *prethodni=this;
        lista *trenutni = this->sljedeci;
        while(trenutni){
            if(trenutni->brojac==1){
                prethodni->sljedeci=trenutni->sljedeci;
                delete trenutni;
                trenutni=prethodni->sljedeci;
            }
            else{
                prethodni=trenutni;
                trenutni = trenutni->sljedeci;
            }
        }
    }

};
int main(){
    lista *objekt = new lista();
    int n;
    cout << "Unesite broj brojeva: ";
    cin >> n;
    srand(time(0));
    for(int i=0;i<n;i++){
        int s = rand()%20;
        objekt->dodavanje(s);
    }
    objekt->ispis();
    cout << endl;
    objekt->brisanje();
    objekt->ispis();

    return 0;
}