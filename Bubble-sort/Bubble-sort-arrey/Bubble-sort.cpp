#include <iostream>
using namespace std;
int main(){
    int N;
    cout << "Unesite broj brojeva: ";
    cin >> N;
    int polje[N];
    for(int i=0;i<N;i++){
        cout << "Unesite " << i+1 << ". broj: ";
        cin >> polje[i];
    }
    return 0;
}