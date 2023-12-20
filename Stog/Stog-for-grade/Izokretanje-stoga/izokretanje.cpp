#include<iostream>
#include"stackp.h"
using namespace std;

void insertAtBottom(stack<double>& S, double item) {
    if (S.IsEmpty()) {
        S.Push(item);
    } else {
        double temp = S.Top();
        S.Pop();
        insertAtBottom(S, item);
        S.Push(temp);
    }
}

void reverseStack(stack<double>& S) {
    if (!S.IsEmpty()) {
        double item = S.Top();
        S.Pop();
        reverseStack(S);
        insertAtBottom(S, item);
    }
}

int main(){
    stack<double> stog;
    int n;
    cout << "Unesite broj brojeva: ";
    cin >> n;
    for(int i=0;i<n;i++){
        double x;
        cin >> x;
        stog.Push(x);
    }

    reverseStack(stog);

    while (!stog.IsEmpty()) {
        cout << stog.Top() << " ";
        stog.Pop();
    }

    return 0;
}