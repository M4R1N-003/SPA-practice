#include <iostream>
using namespace std;

class lista{
    private:
    lista *sljedeci;
    lista *prethodni;
    public:
    lista(){
        sljedeci=NULL;
        prethodni=NULL;
    }
    int broj;
    char ime[100];

    void dodavanje(){
        lista *novi, *zadnji=this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci=novi;
        zadnji=novi->prethodni;
        novi->sljedeci=NULL;
        cout << "Unesite broj elementa: ";
        cin >> novi->broj;
        cout << "Unesite ime elementa: ";
        cin >> novi->ime;
    }

    void ispis(){
        lista  *tekuci = this->sljedeci;
        while(tekuci){
            cout << "Broj elementa je: ";
            cout << tekuci->broj << endl;
            cout << "Ime elementa je: ";
            cout << tekuci->ime << endl;
            tekuci=tekuci->sljedeci;
        }
    }

};
int main(){
    int biranje;
    lista *objekt = new lista;
    do{
        cout << endl;
        cout << "1-dodavanje na kraj!" << endl;
        cout << "2-dodavanje na pocetak!" << endl;
        cout << "3-ispisivanje!" << endl;
        cout << "4-pretrazivanje!" << endl;
        cout << "5-deleting!" << endl;
        cout << endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
                objekt->dodavanje();
                break;
            case 2:
                break;
            case 3:
                objekt->ispis();
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }while(biranje!=9);
    return 0;
}