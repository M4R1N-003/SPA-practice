#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "listp.h"
using namespace std;
int main(){

    list<int> L;
    list<int>::element el1, el2, el3, el4;
    srand(time(0));
    int n;
    cin >> n;

    el1=L.First();
    for(int i=0;i<n;i++){
        int s;
        s=rand()%20;
        L.Insert(el1, s);
        el1=L.Next(el1);
    }

    el1=L.First();
    for(int i=0;i<n;i++){
        cout << L.Retrieve(el1) << " ";
        el1=L.Next(el1);
    }
    cout << endl;

    for(el2=L.First();el2!=L.End();el2=L.Next(el2)){
        for(el3=L.First();el3!=L.End();el3=L.Next(el3)){
            if(L.Retrieve(el2)==L.Retrieve(el3) && el3!=el2){
                L.Delete(el3);
            }
            if(el3==L.End()) break;
        }
    }

    for(el4=L.First();el4!=L.End();el4=L.Next(el4)){
        cout << L.Retrieve(el4) << " ";
    }

    return 0;
}