#include<iostream>
#include "stackp.h"
using namespace std;

void ispis(stack<int> &stog){
    if(stog.IsEmpty()){
        return;
    }
    int temp = stog.Top();

    stog.Pop();

    ispis(stog);

    cout << temp << " ";
    stog.Push(temp);
}

int main(){
    stack<int>stog;
    int n;
    cout << "Unesite broj brojeva: ";
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        stog.Push(k);
    }
    
    cout << "Rekurzivno rjesenje ispisa: ";
    ispis(stog);

    cout << endl;
    cout << "Normalan ispis od kraja unosa: ";
    for(int i=0;i<n;i++){
        cout << stog.Top() << " ";
        stog.Pop();
    }



    return 0;
}