#include<iostream>
#include"queuep.h"
using namespace std;
int main(){
    queue<int>stog;
    int n, x, pocetak=0, pom=0, zbroj=0, trajanje;

    cin >> n;
    cin >> trajanje;
    for(int i=0;i<n-1;i++){
        cin >> x;
        stog.Enqueue(x);
    }
    cout << "0 0 0" << endl;

    while(!stog.IsEmpty()){
        pocetak+=trajanje;
        cout << pom+stog.Front() << " " << pocetak << " " << pocetak-(pom+stog.Front()) << endl;
        zbroj+=pocetak-(pom+stog.Front());
        pom+=stog.Front();
        stog.Dequeue();
    }

    cout << "Prosjek: " << (double)zbroj/n << endl;
    return 0;
}