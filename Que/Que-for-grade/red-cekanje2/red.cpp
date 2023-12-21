#include<iostream>
#include"queuea.h"
using namespace std;

int main(){
    queue<int>stog;
    int n, pom = 0, trajanje, pocetak =0, zbroj=0, x;

    cout << "Unesite broj procesa: ";
    cin >> n;

    cout << "Unesite trajanje: ";
    cin >> trajanje;

    for(int i=0;i<n-1;i++){
        cin >> x;
        stog.Enqueue(x);
    }

    cout << "0 0 0" << endl;

    while(!stog.IsEmpty()){
        pocetak+=trajanje;
        cout << pom + stog.Front() << " " << pocetak << " " << pocetak - (pom + stog.Front()) << endl;
        zbroj+=pocetak-(pom+stog.Front());
        pom+=stog.Front();
        stog.Dequeue();
    }

    double prosjek = (double)zbroj/n;
    cout << "Prosjek je: " << prosjek << endl;
    return 0;
}