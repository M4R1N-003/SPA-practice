#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "listp.h"
using namespace std;
    int n;
    int k;
    void najveci_iterator(list<int> &L){
        list<int>::element el1, el2, el3;
        int s=0;
        int brojac=0;
        el1=L.First();
        for(int i=1;i<=n;i++){
            if(i%k==0){
                if(s<=L.Retrieve(el1)){
                    s=L.Retrieve(el1);
                    el2=el1;
                }
            }
            el1=L.Next(el1);
        }

        el3=L.First();
        
        for(int i=0;i<n;i++){
            if(el3==el2){
                cout << i;
            }
            el3=L.Next(el3);
        }
        
    }

int main(){
    srand(time(0));
    list <int> L;
    list<int>::element el1;
    cin >> n;
    cin >> k;
    el1=L.First();
    for(int i=0;i<n;i++){
        int s;
        s=rand()%100+1;
        L.Insert(el1, s);
        el1=L.Next(el1);
    }

    cout << endl;

    el1=L.First();
    for(int i=0;i<n;i++){
        cout << L.Retrieve(el1) << " ";
        el1=L.Next(el1);
    }
    cout << endl;

    najveci_iterator(L);


}