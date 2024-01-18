#include<iostream>
#include<ctime>
#include<stdlib.h>
#define Comp(a,b) (a.vrijednost<b.vrijednost ? -1 : (a.vrijednost==b.vrijednost ? 0 : 1))
#include"heap.h"
using namespace std;

struct clan {
    int vrijednost;
    int iIndeks;
    int jIndeks;
};

int* spajanjePolja(int m, int n, int** polje) {
    heap<clan> hrpa;
    int* polje1 = new int[m * n];
    clan str;
    for (int i = 0; i < m; i++) {
        str.iIndeks = i;
        str.jIndeks = 0;
        str.vrijednost = polje[i][0];
        hrpa.Insert(str);
    }
    int s = 0;
    while (!hrpa.IsEmpty()) {
        clan p = hrpa.RootLabel();
        polje1[s] = p.vrijednost;
        hrpa.DeleteRoot();

        if (p.jIndeks + 1 < n) {
            clan novi;
            novi.iIndeks = p.iIndeks;
            novi.jIndeks = p.jIndeks + 1;
            novi.vrijednost = polje[novi.iIndeks][novi.jIndeks];
            hrpa.Insert(novi);
        }

        s++;
    }

    return polje1;
}

int main() {
    int m, n;
    srand(time(0));
    cout << "Unesite broj polja(m): ";
    cin >> m;
    cout << "Unesite duljinu polja(n): ";
    cin >> n;

    int** polje = new int*[m];

    for (int i = 0; i < m; i++) {
        polje[i] = new int[n];
        for (int j = 0; j < n; j++) {
            polje[i][j] = rand() % 20;
        }
    }

    for (int k = 0; k < m; k++) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (polje[k][j] > polje[k][i]) {
                    int temp = polje[k][j];
                    polje[k][j] = polje[k][i];
                    polje[k][i] = temp;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << "Uneseni brojevi " << i + 1 << ". polja: ";
        for (int j = 0; j < n; j++) {
            cout << polje[i][j] << " ";
        }
        cout << endl;
    }

    int* polje1 = new int[m * n];
    polje1 = spajanjePolja(m, n, polje);

    cout << "Spojeno sortirano polje: ";
    for (int i = 0; i < m * n; i++) {
        cout << polje1[i] << " ";
    }

    return 0;
}
