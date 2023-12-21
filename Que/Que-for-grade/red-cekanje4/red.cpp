#include<iostream>
#include"queuep.h"
using namespace std;
int main(){
    int n, trajanje, x, zbroj=0, pom=0, pocetak=0;
    queue<int>red;
    cout << "Unesite broj procesa: ";
    cin >> n;
    cout << "Unesite trajanje: ";
    cin >> trajanje;

    for(int i=0;i<n-1;i++){
        cin >> x;
        red.Enqueue(x);
    }

    cout << "0 0 0" << endl;
    while(!red.IsEmpty()){
        pocetak+=trajanje;
        cout << pom+red.Front() << " " << pocetak << " " << pocetak-(red.Front()+pom) << endl;
        zbroj+= pocetak-(red.Front()+pom);
        pom+=red.Front();
        red.Dequeue();
    }

    cout << "Prosjek je: " << (double)zbroj/n << endl;

    return 0;
}