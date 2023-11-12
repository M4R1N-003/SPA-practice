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

    void sortiranje() {
        MergeSort(&this->sljedeci);
    }

    void MergeSort(lista** headRef) {
        lista* head = *headRef;
        lista* a;
        lista* b;

        if ((head == NULL) || (head->sljedeci == NULL))
            return;

        FrontBackSplit(head, &a, &b);

        MergeSort(&a);
        MergeSort(&b);

        *headRef = SortedMerge(a, b);
    }

    lista* SortedMerge(lista* a, lista* b) {
        lista* result = NULL;

        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        if (a->N <= b->N) {
            result = a;
            result->sljedeci = SortedMerge(a->sljedeci, b);
        } else {
            result = b;
            result->sljedeci = SortedMerge(a, b->sljedeci);
        }
        return result;
    }

    void FrontBackSplit(lista* source, lista** frontRef, lista** backRef) {
        lista* fast;
        lista* slow;
        slow = source;
        fast = source->sljedeci;

        while (fast != NULL) {
            fast = fast->sljedeci;
            if (fast != NULL) {
                slow = slow->sljedeci;
                fast = fast->sljedeci;
            }
        }

        *frontRef = source;
        *backRef = slow->sljedeci;
        slow->sljedeci = NULL;
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

    objekt->sortiranje();

    cout << "Sortirana lista: ";
    objekt->ispis();
    cout << endl;

    delete objekt; // Oslobodi alociranu memoriju

    return 0;
}
