#include <iostream>
using namespace std;

unsigned long long binomialCoeff(int n, int k) {
    long long result = 1;

    int smaller = (k < n - k) ? k : n - k;

    for (int i = 0; i < smaller; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

int main() {
    unsigned short n, k;
    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;

    cout << "Vrijednost C(" << n << ", " << k << ") je " << binomialCoeff(n, k) << endl;

    return 0;
}
