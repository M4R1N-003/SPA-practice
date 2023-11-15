#include <iostream>
#include <cstring>
#include "listpp.h"

using namespace std;

template <typename elementtype>
int pretraziListu(list<elementtype> &mojaLista, std::string trazeniString) {
    typename list<elementtype>::element trenutniElement = mojaLista.First();
    int pozicija = 0;  // Start position from 0

    while (trenutniElement != mojaLista.lambda && mojaLista.Next(trenutniElement) != mojaLista.lambda) {
        if (mojaLista.Retrieve(trenutniElement) == trazeniString[0]) {
            typename list<elementtype>::element pokazivacNaTrazeni = mojaLista.Next(trenutniElement);
            size_t indeks = 1;

            while (pokazivacNaTrazeni != mojaLista.lambda && indeks < trazeniString.size()) {
                if (mojaLista.Retrieve(pokazivacNaTrazeni) == trazeniString[indeks]) {
                    pokazivacNaTrazeni = mojaLista.Next(pokazivacNaTrazeni);
                    indeks++;
                } else {
                    break;
                }
            }

            if (indeks == trazeniString.size()) {
                return pozicija;
            }
        }
        trenutniElement = mojaLista.Next(trenutniElement);
        pozicija++;
    }

    return -1;
}

int main() {
    list<char> L;
    string recenica;
    cout << "Unesite string: ";
    cin >> recenica;
    char polje[100] = {0};
    strcpy(polje, recenica.c_str());

    for (int i = 0; i < 100; i++) {
        if (polje[i] != 0) {
            L.Insert(L.End(), polje[i]);
            cout << polje[i];
        }
    }

    cout << "\nUnesite drugi string za pretragu: ";
    string drugiString;
    cin >> drugiString;

    int rezultat = pretraziListu(L, drugiString);

    if (rezultat != -1) {
        cout << "\nString se nalazi na poziciji: " << rezultat << endl;
    } else {
        cout << "\nString se ne nalazi u listi." << endl;
    }

    return 0;
}
