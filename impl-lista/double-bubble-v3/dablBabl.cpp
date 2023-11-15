#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "listp.h"
using namespace std;
    int n;

    void bablSort(list<int> &L){
        list<int>::element e;

        for(int i=0;i<n;i++){
            if(i%2==0){
                e=L.Previous(L.End());
                for(int j=n-i;j>1;j--){
                    if(L.Retrieve(e)<L.Retrieve(L.Previous(e))){
                        int pom=L.Retrieve(e);
                        L.ChangeValue(e, L.Retrieve(L.Previous(e)));
                        L.ChangeValue(L.Previous(e), pom);
                    }
                    e=L.Previous(e);
                }
            }
            else{
                e=L.First();
                for(int j=0;j<n-1;j++){
                    if(L.Retrieve(L.Next(e))<L.Retrieve(e)){
                        int pom = L.Retrieve(e);
                        L.ChangeValue(e, L.Retrieve(L.Next(e)));
                        L.ChangeValue(L.Next(e), pom);
                    }
                    e=L.Next(e);
                }
            }
        }
    }

int main(){
    srand(time(0));
    list<int> L;
    list<int>::element el1;
    cin >> n;
    
    el1=L.First();
    for(int i=0;i<n;i++){
        int s;
        s=rand()%20+1;
        L.Insert(el1, s);
        el1=L.Next(el1);
    }

    for(el1=L.First();el1!=L.End();el1=L.Next(el1)){
        cout << L.Retrieve(el1) << " ";
    }
    cout << endl;
    bablSort(L);
    for(el1=L.First();el1!=L.End();el1=L.Next(el1)){
        cout << L.Retrieve(el1) << " ";
    }
    

    return 0;
}