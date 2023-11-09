#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class lista {
private:
    lista* sljedeci;
    lista* prethodni;
public:
    int n;
    int brojac = 0;

    lista() {
        sljedeci = NULL;
        prethodni = NULL;
    }

    void unos(int x) {
        lista* novi, * zadnji = this;
        while (zadnji->sljedeci)
            zadnji = zadnji->sljedeci;
        novi = new lista();
        zadnji->sljedeci = novi;
        novi->n = x;
        novi->sljedeci = NULL;
        novi->prethodni = zadnji;
        
    }

    void ispis() {
        lista* tekuci = this->sljedeci;
        while (tekuci) {
            cout << tekuci->n << " ";
            tekuci = tekuci->sljedeci;
        }
        cout << endl;
    }

    void dvosmjernoMjehurastoSortiranje() {
        lista* pocetak = this->sljedeci;
        lista* kraj = NULL;
        bool zamijenjeno;

        do {
            zamijenjeno = false;
            lista* trenutni = pocetak;

            while (trenutni->sljedeci != kraj) {
                if (trenutni->n > trenutni->sljedeci->n) {
                    int temp = trenutni->n;
                    trenutni->n = trenutni->sljedeci->n;
                    trenutni->sljedeci->n = temp;
                    zamijenjeno = true;
                }
                trenutni = trenutni->sljedeci;
            }

            if (!zamijenjeno) break; // Ako nema zamjena, sortiranje je završeno

            kraj = trenutni;
            trenutni = trenutni->prethodni;

            while (trenutni != pocetak) {
                if (trenutni->n < trenutni->prethodni->n) {
                    int temp = trenutni->n;
                    trenutni->n = trenutni->prethodni->n;
                    trenutni->prethodni->n = temp;
                    zamijenjeno = true;
                }
                trenutni = trenutni->prethodni;
            }

        } while (zamijenjeno);
    }
};

int main() {
    int n;
    lista* objekt = new lista;
    cout << "Unesite broj brojeva: ";
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int s = rand() % 100;
        objekt->unos(s);
    }

    cout << "Nesortirana lista: ";
    objekt->ispis();
    cout << endl;

    objekt->dvosmjernoMjehurastoSortiranje(); // Sortiranje

    cout << "Sortirana lista: ";
    objekt->ispis();

    return 0;
}