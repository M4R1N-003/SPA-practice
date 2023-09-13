#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Unesite broj brojeva: ";
    cin >> n;
    int polje[n];
    for(int i=0;i<n;i++){
        cin >> polje[i];
    }
    int p, k;
    cin >> p;
    cin >> k;
    for(int i=0;i<p-1;i++){
        polje[i]=0;
    }
    for(int i=p;i<n;i++){
        if(i%k!=0){
            polje[i]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(polje[i]!=0){
            cout << polje[i] << " ";
        }
    }
}