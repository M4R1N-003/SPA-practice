#include <iostream>
#include "lista.h"
using namespace std;


    void Slice(pom *L, int p, int k){
        int brojac1=0;
        pom *prethodni1= L;
        pom *tekuci1=L->sljedeci;
        bool ret=false;
        while(tekuci1 && ret == false){
            brojac1++;
            prethodni1->sljedeci=tekuci1->sljedeci;
            delete tekuci1;
            tekuci1=prethodni1->sljedeci;
            if(brojac1==p-1){
                L->sljedeci=tekuci1;
                ret = true;
            }
        }

        pom *prethodni=L->sljedeci;
        pom *tekuci=L->sljedeci->sljedeci;
        int brojac=0;
        while(tekuci){
            brojac++;
            if(brojac%k!=0){
                prethodni->sljedeci=tekuci->sljedeci;
                delete tekuci;
                tekuci=prethodni->sljedeci;
            }
            else{
                prethodni=tekuci;
                tekuci=tekuci->sljedeci;
            }            
        }
    }

int main(){
    pom *l= new pom;
    l->sljedeci=NULL;
    int n;
    int p;
    int k;
    int s;
    cout << "Unesite broj brojeva: ";
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> s;
        dodavanje(l, s);
    }
    cin >> p;
    cin >> k;

    Slice(l, p, k);

    ispis(l);
    return 0;
}