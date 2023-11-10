#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "unesite stupanj polinoma 1: ";
    cin >> n;
    int polje1[1000]={0};
    for(int i=0;i<=n;i++){
        cin >> polje1[i];
    }
    int prvoPolje[n]={0};
    int brojac=0;
    for(int i=n;i>=0;i--){
        prvoPolje[brojac]=polje1[i];
        brojac++;
    }

    int k;
    cout << "unesite stupanj polinoma 2: ";
    cin >> k;
    int polje2[1000]={0};
    for(int i=0;i<=k;i++){
        cin >> polje2[i];
    }

    int drugoPolje[k]={0};
    int brojac1=0;
    for(int i=k;i>=0;i--){
        drugoPolje[brojac1]=polje2[i];
        brojac1++;
    }

    if(n>k){
        int zbroj[n];
        for(int i=0;i<=n;i++){
            zbroj[i]=drugoPolje[i]+prvoPolje[i];
        }
        for(int i=n;i>=0;i--){
            cout << zbroj[i] << " ";
        }
    }
    else{
        int zbroj[k];
        for(int i=0;i<=k;i++){
            zbroj[i]=drugoPolje[i]+prvoPolje[i];
        }
        for(int i=n;i>=0;i--){
            cout << zbroj[i] << " ";
        }
    }

    return 0;
}