#include <iostream>
using namespace std;
int main(){
    int N;
    cout << "Unesite broj elemenata: ";
    cin >> N;
    int polje[N];
    for(int i=0;i<N;i++){
        cout << "Unesite " << i+1 << ". broj: ";
        cin >> polje[i];
    }

    for(int i=N-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(polje[j]>polje[i]){
                int temp;
                temp = polje[j];
                polje[j] = polje[i];
                polje[i]=temp;
            }
        }
    }
    
    return 0;
}