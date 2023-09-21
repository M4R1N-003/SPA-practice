#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
class lista{
    private:
    lista *sljedeci;
    public:

    lista(){
        sljedeci=NULL;
    }
    int k;

    void dodavanje(int s){
        lista *novi, *zadnji = this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci=novi;
        novi->sljedeci=NULL;
        novi->k = s;
    }

    void ispisivanje(){
        lista *tekuci = this->sljedeci;
        while(tekuci){
            cout << tekuci->k << " ";
            tekuci = tekuci->sljedeci;
        }
    }

    void brisanje(){
        lista *tekuci = this->sljedeci;
        int l;
        while(tekuci){
            l = tekuci->k;
            lista *temp=tekuci->sljedeci;
                lista *prethodni = tekuci;

            while(temp){  
                if(temp->k == l){
                    prethodni->sljedeci = temp->sljedeci;
                    delete temp;
                    temp = prethodni->sljedeci;
                }
                else{
                prethodni=temp;
                temp=temp->sljedeci;
                }
            }
            tekuci = tekuci->sljedeci;
        }
    }
};
lista *objekt = new lista;
int main(){
    srand(time(0));
    int n;
    cin >> n;
    int s;
    for(int i=0;i<n;i++){
        s = rand()%21;
        objekt->dodavanje(s);
    }
    cout << endl;
    objekt->ispisivanje();
    objekt->brisanje();
    cout << endl;
    objekt->ispisivanje();
    return 0;
}