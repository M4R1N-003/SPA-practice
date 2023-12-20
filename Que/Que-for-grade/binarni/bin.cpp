#include<iostream>
#include"queuep.h"
using namespace std;

void generateBinaryStrings(int n) {
    queue<string> q;
    q.Enqueue("1");

    for (int i = 0; i < n; i++) {
        string front = q.Front();
        cout << front << " ";

        q.Enqueue(front + "0");
        q.Enqueue(front + "1");

        q.Dequeue();
    }
}
int main() {
    int n;
    cout << "Unesite broj n: ";
    cin >> n;

    generateBinaryStrings(n);

    return 0;
}