#include <iostream>
#include "listp.h"
using namespace std;
int main(){
    list <int> L;
    list<int>::element el1;
    int n;

    cin >> n;

    el1=L.First();
    for(int i=0;i<n+1;i++){
        int a;
        cin >> a;
        L.Insert(el1, a);
        el1=L.Next(el1);
    }

    int x;
    cin >> x;
    int zbroj=L.Retrieve(L.First());
    int brojac=0;

    for(el1=L.Next(L.First());el1!=L.End();el1=L.Next(el1)){
        zbroj = zbroj * x + L.Retrieve(el1);
        brojac++;
    }

    cout << "Rjesenje je: " << zbroj << endl;
    cout << "Broj mnozenja je: " << brojac << endl;

    return 0;
}