#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

class lista{
    private:
    lista *sljedeci;
    public:
    int N;

    void dodavanje(int x){
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
    }

    void sortiranje(){

    }
};
int main(){
    lista *objekt = new lista();
    int n;
    cin >> n;
    srand(time(0));
    for(int i=0;i<n;i++){
        int s=rand()%20;
        objekt->dodavanje(s);
    }
    objekt->ispis();

    return 0;
}