#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "listp.h"
using namespace std;

list<int> L1;

void bidirectionalBubbleSort(list<int>& L, int n) {
    bool swapped;

    do {
        swapped = false;

        list<int>::element current = L.First();
        list<int>::element next = L.Next(current);

        for (int i = 0; i < n - 1; ++i) {
            if (L.Retrieve(current) > L.Retrieve(next)) {
                int temp = L.Retrieve(current);
                L.ChangeValue(current, L.Retrieve(next));
                L.ChangeValue(next, temp);

                swapped = true;
            }

            current = L.Next(current);
            next = L.Next(next);
        }

        current = L.Previous(L.End());
        list<int>::element prev = L.Previous(current);

        for (int i = 0; i < n - 1; ++i) {
            if (L.Retrieve(prev) > L.Retrieve(current)) {
                int temp = L.Retrieve(prev);
                L.ChangeValue(prev, L.Retrieve(current));
                L.ChangeValue(current, temp);

                swapped = true;
            }

            current = L.Previous(current);
            prev = L.Previous(prev);
        }

        n -= 2;
    } while (swapped);
}


int main() {
    list<int>::element brojac1, brojac2, brojac3;

    int n;
    cin >> n;
    srand(time(0));

    int s, k;
    brojac1 = L1.First();
    for (int i = 0; i < n; i++) {
        s = rand() % 20;
        L1.Insert(brojac1, s);
        brojac1 = L1.Next(brojac1);
    }

    brojac2 = L1.First();
    for (int i = 0; i < n; i++) {
        k = L1.Retrieve(brojac2);
        cout << k << " ";
        brojac2 = L1.Next(brojac2);
    }
    cout << endl;
    bidirectionalBubbleSort(L1, n);

    brojac3 = L1.First();
    for (int i = 0; i < n; i++) {
        k = L1.Retrieve(brojac3);
        cout << k << " ";
        brojac3 = L1.Next(brojac3);
    }

    return 0;
}
