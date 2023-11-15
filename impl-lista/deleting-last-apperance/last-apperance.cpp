#include <iostream>
#include <cstdlib>
#include <ctime>
#include "listp.h"

using namespace std;

void brisanjeJedinstvene(list<int> &L) {
    list<int>::element el1, el2;
    el1 = L.First();
    while (el1 != L.End()) {
        bool provjera = false;
        el2 = L.Next(el1);
        while (el2 != L.End()) {
            if (L.Retrieve(el1) == L.Retrieve(el2)) {
                provjera = true;
                break;
            }
            el2 = L.Next(el2);
        }
        if (!provjera) {
            L.Delete(el1);
            el1 = L.Next(L.First());
        } else {
            el1 = L.Next(el1);
        }
    }
}

void funkcija(list<int> &L) {
    list<int>::element current = L.First();

    while (current != L.End()) {
        int currentElement = L.Retrieve(current);
        list<int>::element nextElement = L.Next(current);

        // Flag to check if any duplicates are found
        bool foundDuplicate = false;

        // Compare the current element with the elements that come after it
        while (nextElement != L.End()) {
            if (currentElement == L.Retrieve(nextElement)) {
                // Duplicate element found, set the flag and break the inner loop
                foundDuplicate = true;
                break;
            }
            nextElement = L.Next(nextElement);
        }

        // If a duplicate is found, delete the current element
        if (foundDuplicate) {
            list<int>::element toDelete = current;
            current = L.Next(current);  // Move to the next element before deleting
            L.Delete(toDelete);
        } else {
            // Move to the next element
            current = L.Next(current);
        }
    }
}


int main() {
    srand(time(0));
    int n;
    cout << "unesite broj nasumicnih brojeva: ";
    cin >> n;

    list<int> L;
    for (int i = 0; i < n; i++) {
        int a = rand() % 21;
        L.Insert(L.End(), a);
    }

    cout << "Originalni niz: ";
    for (list<int>::element el2 = L.First(); el2 != L.End(); el2 = L.Next(el2)) {
        cout << L.Retrieve(el2) << " ";
    }
    cout << endl;

    brisanjeJedinstvene(L);
    funkcija(L);

    cout << "Niz nakon brisanja jedinstvenih i duplikatnih elemenata: ";
    for (list<int>::element el3 = L.First(); el3 != L.End(); el3 = L.Next(el3)) {
        cout << L.Retrieve(el3) << " ";
    }

    return 0;
}
