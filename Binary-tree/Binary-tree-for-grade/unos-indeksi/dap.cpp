#include <iostream>
#include "btreep.h"
using namespace std;

void unosUBinarnoStablo(int m, int** polje, Btree<int>& btree) {
    for (int i = 0; i < m; i++) {
        int vi = polje[i][0];
        int li = polje[i][1];
        int ri = polje[i][2];

        Btree<int>::node current;
        if (btree.IsEmpty()) {
            btree.CreateRoot(vi);
            current = btree.Root();
        } else {
            current = btree.Root();
            while (true) {
                if (li != -1 && li == btree.Label(current)) {
                    break;
                } else if (ri != -1 && ri == btree.Label(current)) {
                    break;
                } else if (li == -1 && btree.LeftChild(current) == btree.lambda) {
                    break;
                } else if (ri == -1 && btree.RightChild(current) == btree.lambda) {
                    break;
                } else if (li != -1 && li < btree.Label(current)) {
                    if (btree.LeftChild(current) == btree.lambda) {
                        break;
                    }
                    current = btree.LeftChild(current);
                } else if (ri != -1 && ri > btree.Label(current)) {
                    if (btree.RightChild(current) == btree.lambda) {
                        break;
                    }
                    current = btree.RightChild(current);
                } else {
                    cout << "Duplikat cvora ili greska u unosu. Ponovite unos." << endl;
                    return;
                }
            }
        }

        if (li != -1) {
            btree.CreateLeftChild(current, li);
        }

        if (ri != -1) {
            btree.CreateRightChild(current, ri);
        }
    }
}

void prikaziBinarnoStablo(Btree<int>& btree, Btree<int>::node current, int razmak = 0) {
    if (current == btree.lambda) {
        return;
    }

    razmak += 10;

    prikaziBinarnoStablo(btree, btree.RightChild(current), razmak);

    for (int i = 10; i < razmak; i++)
        cout << " ";
    cout << btree.Label(current) << "\n";

    prikaziBinarnoStablo(btree, btree.LeftChild(current), razmak);
}

int main() {
    int m;
    cout << "Unesite broj cvorova: ";
    cin >> m;

    int** polje = new int*[m];

    for (int i = 0; i < m; i++) {
        cout << "Unesite " << i + 1 << ". cvor: ";
        polje[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            cin >> polje[i][j];
        }
    }

    Btree<int> btree;
    unosUBinarnoStablo(m, polje, btree);

    cout << "Ispis binarnog stabla:" << endl;
    prikaziBinarnoStablo(btree, btree.Root());

    return 0;
}
