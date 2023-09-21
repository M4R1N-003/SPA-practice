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
        novi->prethodni=zadnji;
        novi->sljedeci=NULL;
        cout << "Unesite broj elementa: ";
        cin >> novi->broj;
        cout << "Unesite ime elementa: ";
        cin >> novi->ime;
    }

    void dodavanjePocetak(){
        lista *novi, *zadnji=this;
        if(zadnji->sljedeci==NULL){
            novi = new lista;
            zadnji->sljedeci=novi;
            novi->prethodni = zadnji;
            novi->sljedeci=NULL;
            cout << "Unesite broj elementa: ";
            cin >> novi->broj;
            cout << "Unesite ime elementa: ";
            cin >> novi->ime;
        }
        else{
            lista *iduci=zadnji->sljedeci;
            novi = new lista;
            zadnji->sljedeci = novi;
            iduci->prethodni = novi;
            novi->prethodni = zadnji;
            novi->sljedeci = iduci;
            cout << "Unesite broj elementa: ";
            cin >> novi->broj;
            cout << "Unesite ime elementa: ";
            cin >> novi->ime;
        }
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

    void pretrazivanje(int brojcic){
        lista  *tekuci = this->sljedeci;
        while(tekuci){
            if(tekuci->broj == brojcic){
                cout << "Broj elementa je: ";
                cout << tekuci->broj << endl;
                cout << "Ime elementa je: ";
                cout << tekuci->ime << endl; 
            }
            tekuci=tekuci->sljedeci;
        }
    }

    void brisanje(int brojcic){
        lista *tekuci = this->sljedeci;
        lista *prosli = this;
        while(tekuci){
            if(tekuci->broj == brojcic){
                if(tekuci->sljedeci==NULL){
                    prosli->sljedeci=tekuci->sljedeci;
                    delete tekuci;
                    return;
                }
                else{
                    lista *iduci = tekuci->sljedeci;
                    iduci->prethodni = prosli;
                    prosli->sljedeci=tekuci->sljedeci;
                    delete tekuci;
                    return;
                }
            }
            prosli=tekuci;
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
                objekt->dodavanjePocetak();
                break;
            case 3:
                objekt->ispis();
                break;
            case 4:
                int br;
                cout << "Unesi broj za pretrazivanje: ";
                cin >> br;
                objekt->pretrazivanje(br);
                break;
            case 5:
                int kr;
                cout << "Unesite broj za brisanje: ";
                cin >> kr;
                objekt->brisanje(kr);
                break;
        }
    }while(biranje!=9);
    return 0;
}