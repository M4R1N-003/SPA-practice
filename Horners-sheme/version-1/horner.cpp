#include <iostream>
using namespace std;

class lista {
public:
    lista* sljedeci;

public:
    double koeficijent;

    lista() {
        sljedeci = NULL;
    }

    void dodavanje(double koef) {
        lista* novi, * zadnji = this;
        while (zadnji->sljedeci)
            zadnji = zadnji->sljedeci;
        novi = new lista();
        zadnji->sljedeci = novi;
        novi->sljedeci = NULL;
        novi->koeficijent = koef;
    }

    void racunaj(int x  ){
        double result = 0;
        lista* current = this;
        while (current) {
            result = result * x + current->koeficijent;
            current = current->sljedeci;
        }

        cout << result;
    }
};

int main() {
    int n;
    double x;

    lista* objekt = new lista();

    cin >> n;

    for (int i = 0; i <= n; i++) {
        double a;
        cin >> a;
        objekt->dodavanje(a);
    }
    cin >> x;

    objekt->racunaj(x);


    return 0;
}