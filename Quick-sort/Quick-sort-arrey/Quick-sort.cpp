#include <iostream>
using namespace std;

int RazmjestiElem(int nizElem[], int donja, int gornja);
void Zamijeni(int nizElem[], int i, int j);

void Quicksort(int nizElem[], int donja, int gornja){
    if (gornja <= donja) return;
    int j = RazmjestiElem(nizElem, donja, gornja);
    Quicksort(nizElem, donja, j - 1); 
    Quicksort(nizElem, j + 1, gornja); 
}

int RazmjestiElem(int nizElem[], int donja, int gornja){
    int i = donja, j = gornja + 1;
    int pivot = nizElem[donja];
    while (true)
    {
        while (nizElem[++i] < pivot)
            if (i == gornja) break;
        while (pivot < nizElem[--j])
        { /*if (j == donja) break;*/ }
        if (i >= j) break;
        Zamijeni(nizElem, i, j);
    }
    Zamijeni(nizElem, donja, j);
    return j;
}

void Zamijeni(int nizElem[], int i, int j){
    int prvr = nizElem[i];
    nizElem[i] = nizElem[j]; 
    nizElem[j] = prvr; 
}


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
            polje[i]=-93716352;
        }
    }

    Quicksort(polje, 0, n - 1);

    for(int i=0;i<n;i++){
        if(polje[i]!=-93716352){
            cout << polje[i] << " ";
        }
    }
    return 0;
}