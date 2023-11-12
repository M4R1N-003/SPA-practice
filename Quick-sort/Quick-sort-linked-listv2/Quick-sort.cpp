#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class lista {
public:
    lista* sljedeci;
    int N;

    lista() {
        sljedeci = nullptr;
    }

    void dodaj(int s) {
        lista* novi, * zadnji = this;
        while (zadnji->sljedeci)
            zadnji = zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci = novi;
        novi->sljedeci = nullptr;
        novi->N = s;
    }

    void ispisi() {
        lista* tekuci = this->sljedeci;
        while (tekuci) {
            cout << tekuci->N << " ";
            tekuci = tekuci->sljedeci;
        }
        cout << endl;
    }

    lista* partition(lista* low, lista* high) {
        int pivot = high->N;
        lista* i = low;
        for (lista* j = low; j != high; j = j->sljedeci) {
            if (j->N <= pivot) {
                swap(i->N, j->N);
                i = i->sljedeci;
            }
        }
        swap(i->N, high->N);
        return i;
    }

    lista* getTail(lista* node) {
        while (node != nullptr && node->sljedeci != nullptr) {
            node = node->sljedeci;
        }
        return node;
    }

    lista* partition_r(lista* low, lista* high) {
        srand(time(nullptr));
        int random = rand() % (high->N - low->N + 1);
        lista* pivot = low;
        for (int i = 0; i < random; i++) {
            pivot = pivot->sljedeci;
        }
        swap(pivot->N, high->N);
        return partition(low, high);
    }

    void quicksort(lista* low, lista* high) {
        if (low != nullptr && low != high && low->sljedeci != high) {
            lista* p = partition_r(low, high);
            quicksort(low, p);
            quicksort(p->sljedeci, high);
        }
    }

    void sort() {
        lista* tail = getTail(this);
        quicksort(this->sljedeci, tail);
    }
};

int main() {
    srand(time(nullptr));

    int n;
    cout << "Unesite broj elemenata: ";
    cin >> n;
    int l;
    lista* objekt = new lista(); // Initialize without creating the dummy head node
    for (int i = 0; i < n; i++) {
        cin >> l;
        objekt->dodaj(l);
    }

    cout << "Nesortirana lista: ";
    objekt->ispisi();

    objekt->sort();

    cout << "Sortirana lista: ";
    objekt->ispisi();

    delete objekt;

    return 0;
}
