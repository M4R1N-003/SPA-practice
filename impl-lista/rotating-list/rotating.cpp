#include <iostream>
#include <ctime>
#include "listp.h"
using namespace std;
int n;

void rotacija(list<int> &L){
    list<int>::element el1;
    el1=L.First();
    for(int i=0;i<n;i++){
        L.Insert(L.First(), L.Retrieve(el1));
        el1=L.Next(el1);
    }
}

int main(){
    list<int>L;
    list<int>::element el;
    srand(time(0));
    cin >> n;
    el=L.First();
    for(int i=0;i<n;i++){
        int s=rand()%20+1;
        L.Insert(el,s);
        el=L.Next(el);
    }

    el=L.First();
    for(int i=0;i<n;i++){
        cout << L.Retrieve(el) << " ";
        el=L.Next(el);
    }
    cout << endl;
    rotacija(L);
    el=L.First();
    for(int i=0;i<n;i++){
        cout << L.Retrieve(el) << " ";
        el=L.Next(el);
    }
}