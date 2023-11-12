#include <iostream>
#include <ctime>
#include <cstdlib>
#include "listp.h"
using namespace std;

list<int> L1, L2;
list<int>::element el1, el2, el3, el4, pom, el5;

int main() {
    int n;
    cin >> n;
    srand(time(0));

    el1 = L1.First();
    for (int i = 0; i < n; i++) {
        int s = rand() % 20;
        L1.Insert(el1, s);
        el1 = L1.Next(el1);
    }

    int maxCount = 0;

    el3 = L1.First();
    for (int i = 0; i < n; i++) {
        int currentNumber = L1.Retrieve(el3);
        int count = 0;

        el4 = L1.First();
        for (int j = 0; j < n; j++) {
            if (L1.Retrieve(el4) == currentNumber) {
                count++;
            }
            el4 = L1.Next(el4);
        }

        if (count > maxCount) {
            maxCount = count;
        }

        el3 = L1.Next(el3);
    }

    el3 = L1.First();
    cout << "Originalna Lista: ";
    for (int i = 0; i < n; i++) {
        cout << L1.Retrieve(el3) << " ";
        el3 = L1.Next(el3);
    }
    if (maxCount > 1) {
        el3 = L1.First();
        for (int i = 0; i < n; i++) {
            int currentNumber = L1.Retrieve(el3);
            int count = 0;

            el4 = L1.First();
            for (int j = 0; j < n; j++) {
                if (L1.Retrieve(el4) == currentNumber) {
                    count++;
                }
                el4 = L1.Next(el4);
            }

            if (count == maxCount) {
                bool pronaci = false;
                for (pom = L2.First(); pom != L2.End(); pom = L2.Next(pom)) {
                    if (currentNumber == L2.Retrieve(pom)) {
                        pronaci = true;
                        break;
                    }
                }
                
                if (!pronaci) {
                    L2.Insert(L2.End(), currentNumber);
                }
            }

            el3 = L1.Next(el3);
        }
    }

    cout << endl;

    cout << "Brojevi sa najvise ponavljanja su:  ";
    for (el5 = L2.First(); el5 != L2.End(); el5 = L2.Next(el5)) {
        cout << L2.Retrieve(el5) << " ";
    }
    cout << endl;
    cout << "Ponovljeni su " << maxCount << " puta!" << endl;;

    return 0;
}
