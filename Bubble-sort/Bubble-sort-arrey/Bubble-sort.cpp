#include <iostream>
using namespace std;

void sortiranje(int polje[], int N){
    while(true){
        bool zamjena = false;
        for(int i=0;i<N-1;i++){
            if(polje[i]>polje[i+1]){
                zamjena = true;
                int pom=polje[i];
                polje[i]=polje[i+1];
                polje[i+1]=pom;
            }
        }
        if(!zamjena) break;
    }
}
int main(){
    int N;
    cout << "Unesite broj brojeva: ";
    cin >> N;
    int polje[N];
    for(int i=0;i<N;i++){
        cout << "Unesite " << i+1 << ". broj: ";
        cin >> polje[i];
    }

    sortiranje(polje, N);
    for(int i=0;i<N;i++){
        cout << polje[i] << " ";
    }
    return 0;
}