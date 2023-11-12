#include <iostream>
#include <ctime>
#include <cstdlib>
#include "listp.h"

using namespace std;

list<int> L;

int main() {
    int n;
    cin >> n;
    srand(time(0));

    list<int>::element el1, el2, el3, el4;
    el1 = L.First();
    
    for (int i = 0; i < n; i++) {
        int s;
        s = rand() % 20;
        L.Insert(el1, s);
        el1 = L.Next(el1);
    }

    el2 = L.First();
    for (int i = 0; i < n; i++) {
        cout << L.Retrieve(el2) << " ";
        el2 = L.Next(el2);
    }
    cout << endl;

    for (el3 = L.First(); el3 != L.End(); el3 = L.Next(el3)) {
        int pom = L.Retrieve(el3);
        el4 = el3;
        if (el4 != L.First()) {
            while (el4 != L.First() && L.Retrieve(L.Previous(el4)) > pom) {
                L.ChangeValue(el4, L.Retrieve(L.Previous(el4)));
                el4 = L.Previous(el4);
                if (el4 == L.First()) {
                    break;
                }
            }
        }
        L.ChangeValue(el4, pom);
    }

    el2 = L.First();
    for (int i = 0; i < n; i++) {
        cout << L.Retrieve(el2) << " ";
        el2 = L.Next(el2);
    }

    return 0;
}
