#include<iostream>
#include"stackp.h"
using namespace std;
int main(){
    int n;
    stack<int>stog, s;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        stog.Push(x);
    }

    for(int i=0;i<n;i++){
        s.Push(stog.Top());
        stog.Pop();
    }

    stog = s;

    for(int i=0;i<n;i++){
        cout << stog.Top() << " ";
        stog.Pop();
    }

    return 0;
}