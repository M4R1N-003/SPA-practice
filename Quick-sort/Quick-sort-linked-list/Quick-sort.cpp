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

};
int main(){
    

    return 0;
}