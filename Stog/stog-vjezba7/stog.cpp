#include <iostream>
#include "stackp.h"
#include <cstdlib>
using namespace std;

struct slog {
    int prvi;
    int drugi;
    int sw_case;
};

int potencijaRec(int a, int b){
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else if (b % 2 == 0) {
        int rezultat = potencijaRec(a, b / 2);
        return rezultat * rezultat;
    } else {
        int rezultat = potencijaRec(a, b / 2);
        return rezultat * rezultat * a;
    }
}

int potencijaIter(int a, int b) {
    stack<slog> stog;

    slog rec;
    rec.prvi = a;
    rec.drugi = b;
    rec.sw_case = 0;

    stog.Push(rec);

    do {
        rec = stog.Top();
        stog.Pop();

        switch (rec.sw_case) {
        case 0:
            if (rec.drugi == 0) {
                rec.prvi = 1;
            } else if (rec.drugi == 1) {

            } else if (rec.drugi % 2 == 0) {
                rec.prvi = rec.prvi * rec.prvi;
                rec.drugi = rec.drugi / 2;
                rec.sw_case = 0;
                stog.Push(rec);

                slog novi_rec;
                novi_rec.prvi = rec.prvi; 
                novi_rec.drugi = rec.drugi;
                novi_rec.sw_case = 0;
                stog.Push(novi_rec);
            } else {
                rec.prvi = rec.prvi * rec.prvi;
                rec.drugi = rec.drugi / 2;
                rec.sw_case = 1;
                stog.Push(rec);

                slog novi_rec;
                novi_rec.prvi = rec.prvi;
                novi_rec.drugi = rec.drugi;
                novi_rec.sw_case = 0;
                stog.Push(novi_rec);
            }
            break;

        case 1:
            rec.prvi = rec.prvi * a;
            rec.drugi = rec.drugi / 2;
            rec.sw_case = 0;
            stog.Push(rec);

            slog novi_rec;
            novi_rec.prvi = rec.prvi;
            novi_rec.drugi = rec.drugi;
            novi_rec.sw_case = 0;
            stog.Push(novi_rec);
            break;
        }
    } while (!stog.IsEmpty());

    return rec.prvi;
}

int main() {
    int a, b;
    cout << "Unesite a: ";
    cin >> a;
    cout << "Unesite b: ";
    cin >> b;
    int resultRec = potencijaRec(a, b);

    cout << "Rekurzivno: " << a << "^" << b << " = " << resultRec << endl;

    int resultIter = potencijaIter(a, b);

    cout << "Iterativno: " << a << "^" << b << " = " << resultIter << endl;

    return 0;
}
