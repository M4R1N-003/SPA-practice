#include <iostream>
using namespace std;
int N;

int pretrazivanje(int polje[], int lijevo, int desno, int brojcic){
    while(lijevo<=desno){
        int sredina = lijevo+(desno-lijevo)/2;

        if(brojcic==polje[sredina]){
            return polje[sredina];
        }
        else if(brojcic>polje[sredina]){
            lijevo = sredina + 1;
        }
        else{
            desno = sredina - 1;
        }
    }
    return -1;
}
int main(){
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
    
    int kljuc;
    cout << "Unesite broj za pretrazivanje: ";
    cin >> kljuc;
    int broj = pretrazivanje(polje, 0, N-1, kljuc);
    cout << "Rezultat pretrage je: ";
    cout << broj << endl;

    
    return 0;
}