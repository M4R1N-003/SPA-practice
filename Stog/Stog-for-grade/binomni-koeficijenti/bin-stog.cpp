#include <iostream>
#include "stackp.h"
using namespace std;

int binomialCoeff(const int &n, const int &k, stack<int> &stk)
{
    int C[k + 1]{};
    C[0] = 1;
    stk.Push(C[0]);
    
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] = C[j] + C[j - 1];
        }
        stk.Push(C[min(i, k)]);
    }

    return C[k];
}

int main(int argc, char *argv[])
{
    stack<int> stk;

    unsigned short n, k;
    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;

    cout << "Value of C(" << n << ", " << k << ") is "
              << binomialCoeff(n, k, stk) << endl;

    return 0;
}