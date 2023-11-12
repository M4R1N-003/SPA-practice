#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "listp.h"
using namespace std;
    list<int> L;
int main(){

    list<int>::element el1;
    int n;
    cin >> n;
    srand(time(0));
    el1=L.First();
    for(int i=0;i<n;i++){
        int s;
        s=rand()%20;
        L.Insert(el1, s);
        el1=L.Next(el1);
    }
    int p, k;
    cin >> p;
    cin >> k;

    el1=L.First();
    for(int i=0;i<n;i++){
        int s;
        s=L.Retrieve(el1);
        cout << s << " ";
        el1=L.Next(el1);
    }

    list<int>::element el2, el3, pom;

    el2=L.First();
    for(int i=0;i<p-1;i++){
        L.Delete(el2);
    }
    cout << endl;
    int brojac=0;
    

    list <int>::element el4;
    el4=L.First();
    for(int i=0;i<n-(p-1);i++){
        if(L.Next(el4)==NULL) break;
        cout<<L.Retrieve(el4)<<" ";
        for(int j=0;j<k;j++){
            if(L.Next(el4)==NULL) break;
            L.Delete(el4);
        }
        
    }

    return 0;
}