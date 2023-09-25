#include <iostream>
using namespace std;

class lista{
    private:
    lista *sljedeci;
    public:
    int N;
    
    lista(){
        sljedeci=NULL;
    }

    void dodaj(int s){
        lista *novi, *zadnji=this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci = novi;
        novi->sljedeci=NULL;
        novi->N = s;
    }

    void ispisi(){
        lista *tekuci=this->sljedeci;
        while(tekuci){
            cout << tekuci->N << " ";
            tekuci = tekuci->sljedeci;
        }
    }

    void brisanje(int k){
        lista *prethodni = this;
        lista *tekuci = this->sljedeci;
        while(tekuci){
            if(tekuci->N%k==0){
                if(tekuci->sljedeci==NULL){
                    delete tekuci;
                    prethodni->sljedeci=NULL;
                }
                else{
                    prethodni->sljedeci = tekuci->sljedeci;
                    delete tekuci;
                    tekuci=prethodni->sljedeci;
                }
            }
            else{
                prethodni=tekuci;
                tekuci=tekuci->sljedeci;
            }
        }
    }
};
lista *objekt=new lista;
int main(){
    int n;
    cout << "Unesite broj elemenata: ";
    cin >> n;
    int l;
    for(int i=0;i<n;i++){
        cin >> l;
        objekt->dodaj(l);
    }
    int k;
    cout << "Unesite broj ciji ce se visekratnici izbrisati: ";
    cin >> k;
    objekt->brisanje(k);
    objekt->ispisi();
    return 0;
}