#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class lista {
private:
    lista* sljedeci;

public:
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
    }

    lista* getTail(lista* current) {
        while (current != nullptr && current->sljedeci != nullptr) {
            current = current->sljedeci;
        }
        return current;
    }

    lista* partition(lista* head, lista* end, lista** newHead, lista** newEnd) {
        lista* pivot = end;
        lista* prev = nullptr, * cur = head, * tail = pivot;

        while (cur != pivot) {
            if (cur->N < pivot->N) {
                if ((*newHead) == nullptr) {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->sljedeci;
            } else {
                if (prev) {
                    prev->sljedeci = cur->sljedeci;
                }
                lista* tmp = cur->sljedeci;
                cur->sljedeci = nullptr;
                tail->sljedeci = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if ((*newHead) == nullptr) {
            (*newHead) = pivot;
        }

        (*newEnd) = tail;

        return pivot;
    }

    lista* quickSortRec(lista* head, lista* end) {
        if (!head || head == end) {
            return head;
        }

        lista* newHead = nullptr, * newEnd = nullptr;

        lista* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            lista* tmp = newHead;
            while (tmp->sljedeci != pivot) {
                tmp = tmp->sljedeci;
            }
            tmp->sljedeci = nullptr;

            newHead = quickSortRec(newHead, tmp);

            tmp = getTail(newHead);
            tmp->sljedeci = pivot;
        }

        pivot->sljedeci = quickSortRec(pivot->sljedeci, newEnd);

        return newHead;
    }

    void quickSort() {
        lista* newHead = nullptr;
        lista* newEnd = nullptr;

        this->sljedeci = quickSortRec(this->sljedeci, getTail(this->sljedeci));
    }
};

lista* objekt = new lista();
int main() {
    int n;
    cout << "Unesite broj elemenata: ";
    cin >> n;
    int l;
    for (int i = 0; i < n; i++) {
        cin >> l;
        objekt->dodaj(l);
    }
    objekt->quickSort();
    objekt->ispisi();
    return 0;
}
