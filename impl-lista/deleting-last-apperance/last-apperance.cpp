#include <iostream>
#include <cstdlib>
#include "listp.h"
#include <time.h>
using namespace std;

void brisanje(list<int>& br) {
    list<int>::element e;

    for (e = br.Previous(br.End()); e != br.lambda; e = br.Previous(e)) {
        int b = br.Retrieve(e) - 1;
        list<int>::element iter = br.First();

        // Provjeri pojavljivanje u ostatku liste
        while (iter != e) {
            if (br.Retrieve(iter) == br.Retrieve(e)) {
                break;  // Ako se element ponovno pojavljuje, prekini petlju
            }
            iter = br.Next(iter);
        }

        if (iter == e) {
            // Element se ne pojavljuje ponovno
            br.Delete(e);
        }
    }
}

int main() {
    srand(time(NULL));
    list<int> br;
    list<int>::element e;

    int n;
    cout << "Unesite n brojeva: ";
    cin >> n;

    e = br.First();
    for (int i = 0; i < n; i++) {
        int b = 1 + rand() % 20;
        br.Insert(e, b);
        cout << b << " ";
    }
    cout << endl;

    brisanje(br);

    for (e = br.First(); e != br.End(); e = br.Next(e)) {
        cout << br.Retrieve(e) << " ";
    }

    cout << endl;

    return 0;
}