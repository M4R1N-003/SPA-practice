#include <iostream>
using namespace std;

class lista{
    private:
    lista *sljedeci;
    lista *prethodni;
    
    public:
    
    int broj;
    char ime[100];
    lista(){
        sljedeci = NULL;
        prethodni = NULL;
    }
    
    void dodajKraj(){
        lista *novi, *zadnji=this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci=novi;
        novi->sljedeci=NULL;
        novi->prethodni=zadnji;
        cout << "Unesi broj elementa: ";
        cin >> novi->broj;
        cin.ignore();
        cout << "Unesite ime: ";
        cin.getline(novi->ime, 100);
    }
    
    void dodajPocetak(){
        lista *novi, *zadnji=this;
        if(zadnji->sljedeci==NULL){
            novi = new lista;
            zadnji->sljedeci=novi;
            novi->prethodni = zadnji;
            novi->sljedeci=NULL;
            cout << "Unesite broj elementa: ";
            cin >> novi->broj;
            cin.ignore();
            cout << "Unesite ime elementa: ";
            cin.getline(novi->ime, 100);
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
            cin.ignore();
            cout << "Unesite ime elementa: ";
            cin.getline(novi->ime, 100);
        }
    }
    
    void ispis(){
        lista *tekuci=this->sljedeci;
        while(tekuci){
            cout << "Broj je: " << tekuci->broj << endl;
            cout << "Ime je: " << tekuci->ime << endl;
            tekuci=tekuci->sljedeci;
        }
    }
    
    void pretrazivanje(int brojcek){
        lista *tekuci=this->sljedeci;
        while(tekuci){
            if(brojcek==tekuci->broj){
            cout << "Broj je: " << tekuci->broj << endl;
            cout << "Ime je: " << tekuci->ime << endl;
            }
            tekuci=tekuci->sljedeci;
        }
    }
    
    void brisanje(int brojcek){
        lista *tekuci, *prethodni;
        tekuci=this->sljedeci;
        prethodni=this;
        while(tekuci){
            lista *iduci=tekuci->sljedeci;
            if(tekuci->broj==brojcek){
                if(!(tekuci->sljedeci)){
                    prethodni->sljedeci=tekuci->sljedeci;
                    delete tekuci;
                    return;
                }
                prethodni->sljedeci=tekuci->sljedeci;
                iduci->prethodni=tekuci->prethodni;
                delete tekuci;
                return;
            }
            prethodni=tekuci;
            tekuci=tekuci->sljedeci;
        }
    }
};
int main(){
    lista *objekt = new lista;
    int biranje;
    do{
        cout << endl;
        cout << "1-dodavanje na kraj!" << endl;
        cout << "2-dodavanje na pocetak!" << endl;
        cout << "3-ispis vezane liste!" << endl;
        cout << "4-pretrazivanje vezane liste!" << endl;
        cout << "5-brisanje elementa iz vezane liste!" << endl;
        cout <<endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
                objekt->dodajKraj();
                break;
            case 2:
                objekt->dodajPocetak();
                break;
            case 3:
            objekt->ispis();
                break;
            case 4:
                int brojcek;
                cout << "Unesite broj elementa za pretrazivanje: ";
                cin >> brojcek;
                objekt->pretrazivanje(brojcek);
                break;
            case 5:
                int N;
                cout << "Unesite broj elementa za brisanje: ";
                cin >> N;
                objekt->brisanje(N);
                break;
            case 9:
                cout << "Kraj programa" << endl;
                break;
            default:
                cout << "Unesite ponovno!" << endl;
                break;
        }
    }while(biranje!=9);
    
    
    return 0;
    }