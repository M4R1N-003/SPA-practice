#include <iostream>
#include "merge-arrey.h"
using namespace std;
int main(){
    int N;
    merge *objekt = new merge;
    cout << "Unesite broj brojeva: ";
    cin >> N;
    int polje1[N];
    int polje2[N];
    for(int i = 0;i < N; i++){
        cout << "Unesite " << i+1 << ". broj: ";
        cin >> polje1[i];
    }
    objekt->mergesort(polje1, polje2, 0, N-1);

    for(int i = 0;i < N; i++) cout << polje1[i] << ", ";
    return 0;
}