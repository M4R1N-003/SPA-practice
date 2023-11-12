#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class lista {
public:
    lista* sljedeci;
    int N;

    lista() {
        sljedeci = NULL;
    }

    void dodavanje(int x) {
        lista* novi, * zadnji = this;
        while (zadnji->sljedeci)
            zadnji = zadnji->sljedeci;
        novi = new lista();
        zadnji->sljedeci = novi;
        novi->sljedeci = NULL;
        novi->N = x;
    }

    void ispis() {
        lista* tekuci = this->sljedeci;
        while (tekuci) {
            cout << tekuci->N << " ";
            tekuci = tekuci->sljedeci;
        }
    }

    void sortiranje(lista** glava) {
        lista* glavurda = *glava;
        lista* a;
        lista* b;

        if ((glavurda == NULL) || (glavurda->sljedeci == NULL)) {
            return;
        }

        odvajanje(glavurda, &a, &b);

        sortiranje(&a);
        sortiranje(&b);

        *glava = sortiranMerge(a, b);
    }

    lista* sortiranMerge(lista* a, lista* b) {
        lista* resultat = NULL;

        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        if (a->N <= b->N) {
            resultat = a;
            resultat->sljedeci = sortiranMerge(a->sljedeci, b);
        }
        else {
            resultat = b;
            resultat->sljedeci = sortiranMerge(a, b->sljedeci);
        }
        return (resultat);
    }

    void odvajanje(lista* korjen, lista** ispred, lista** iza) {
        lista* brzo;
        lista* sporo;
        sporo = korjen;
        brzo = korjen->sljedeci;

        while (brzo != NULL) {
            brzo = brzo->sljedeci;
            if (brzo != NULL) {
                sporo = sporo->sljedeci;
                brzo = brzo->sljedeci;
            }
        }

        *ispred = korjen;
        *iza = sporo->sljedeci;
        sporo->sljedeci = NULL;
    }
};

int main() {
    lista* objekt = new lista();
    int n, s;
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        s = rand() % 100;
        objekt->dodavanje(s);
    }

    cout << "Originalna lista: ";
    objekt->ispis();
    cout << endl;

    objekt->sortiranje(&objekt);

    cout << "Sortirana lista: ";
    objekt->ispis();
    cout << endl;

    delete objekt; // Oslobodi alociranu memoriju

    return 0;
}
