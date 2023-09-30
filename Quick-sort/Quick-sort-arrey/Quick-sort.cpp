#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Unesite broj brojeva: ";
    cin >> n;
    int polje[n];
    for(int i=0;i<n;i++){
        cout << "Unesite " << i+1 << ". broj: ";
        cin >> polje[i];
    }
    int k;
    cout << "Unesite broj ciji ce se visekratnici izbrisati: ";
    cin >> k;
    for(int i=0;i<n;i++){
        if(polje[i]%k==0){
            polje[i]=-9371635234;
        }
    }
    for(int i=0;i<n;i++){
        if(polje[i]!=-9371635234){
            cout << polje[i] << " ";
        }
    }
    return 0;
}