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
        novi->sljedeci=NULL;
        novi->N=x;
    }

    void ispis(){
        lista *tekuci=this->sljedeci;
        while(tekuci){
            cout << tekuci->N << " ";
            tekuci=tekuci->sljedeci;
        }
        cout << endl;
    }

    void brisanje(){
        lista *tekuci;
        tekuci =this->sljedeci;
        while(tekuci){
            lista *trenutni=tekuci->sljedeci;
            lista *prethodni = tekuci;
            while(trenutni){
                if(trenutni->N==tekuci->N){
                    prethodni->sljedeci=trenutni->sljedeci;
                    delete trenutni;
                    trenutni=prethodni->sljedeci;
                }
                else{
                    prethodni=trenutni;
                    trenutni=trenutni->sljedeci;
                }
            }
            tekuci=tekuci->sljedeci;
        }
    }
};

int main(){
    lista *objekt = new lista();

    int N;
    cin >> N;

    srand(time(0));
    for(int i=0;i<N;i++){
        int k=rand()%20;
        objekt->unos(k);
    }

    cout << endl;
    objekt->ispis();
    objekt->brisanje();
    cout << endl;
    objekt->ispis();
}