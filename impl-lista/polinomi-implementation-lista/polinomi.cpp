#include <iostream>
#include "lista.h"
using namespace std;

    int veci;
    list<int> L1;
    list<int> L2;

    list<int>::element el1;
    list<int>::element el2;

    list<int>::element indeks;
    list<int>::element indeks2;
    list<int>::element indeks3;
    list<int>::element indeks4;

    void racunanje(list<int> L1, list<int> L2){
        indeks=L1.First();
        indeks2=L2.First();
        list<int> L3;
        int zbroj[veci]={0};
        for(int i=0;i<veci;i++){
            zbroj[i]=L1.Retrieve(indeks)+L2.Retrieve(indeks2);
            indeks=L1.Next(indeks);
            indeks2=L2.Next(indeks2);
        }
        
        indeks3=L3.First();
        for(int i=veci-1;i>=0;i--){
            L3.Insert(indeks3, zbroj[i]);
            indeks3=L3.Next(indeks3);
        }
        indeks4=L3.First();
        for(int i=0;i<veci;i++){
            int s=L3.Retrieve(indeks4);
            cout << s << " ";
            indeks4=L3.Next(indeks4);
        }
    }
int main(){

    int n1, n;
    cin >> n1;
    n=n1+1;
    int pomPolje1[n];
    for(int i=0;i<n;i++){
        cin >> pomPolje1[i];
    }
    int k1, k;
    cin >> k1;
    k=k1+1;
    int pomPolje2[k];
    for(int i=0;i<k;i++){
        cin >> pomPolje2[i];
    }

    if(n>k)
        veci=n;
    else
        veci=k;

    int polje1[veci]={0};
    int polje2[veci]={0};
    int brojac1=0;
    int brojac2=0;
    for(int i=n-1;i>=0;i--){
        polje1[brojac1]=pomPolje1[i];
        brojac1++;
    }

    for(int i=k-1;i>=0;i--){
        polje2[brojac2]=pomPolje2[i];
        brojac2++;
    }

    el1=L1.First();
    for(int i=0;i<veci;i++){
        L1.Insert(el1, polje1[i]);
        el1=L1.Next(el1);
    }

    el2=L2.First();
    for(int i=0;i<veci;i++){
        L2.Insert(el2, polje2[i]);
        el2=L2.Next(el2);
    }
    racunanje(L1, L2);

}