#include <iostream>
using namespace std;
class hash1{
    private:
    hash1 *sljedeci;
    hash1 *prethodni;
    hash1 *sljedecig;
    hash1 *prethodnig;

    public:
    int sifra;
    char ime[100];
    static int brojac;

    hash1(){
        sljedeci = NULL;
        prethodni = NULL;
        sljedecig = NULL;
        prethodnig = NULL;
    }

    void dodajListuNaKraj(){
        hash1 *novi, *zadnji=this;
        while(zadnji->sljedecig)
            zadnji=zadnji->sljedecig;
        novi = new hash1();
        zadnji->sljedecig=novi;
        novi->prethodnig=zadnji;
        novi->sljedecig=NULL;
        novi->sljedeci=NULL;
        brojac++;
    }

    void dodajListuNaPocetak(){
        hash1 *novi, *iduci;
        if(brojac==0){
            novi=new hash1();
            this->sljedecig=novi;
            novi->prethodnig=this;
            novi->sljedecig=NULL;
            novi->sljedeci=NULL;
            brojac++;
            return;
        }
        iduci = this->sljedecig;
        novi = new hash1();
        this->sljedecig=novi;
        novi->prethodnig=this;
        novi->sljedecig=iduci;
        iduci->prethodnig=novi;
        novi->sljedeci=NULL;
        brojac++;
    }

    void dodajElementNaPocetak(int broj){
        hash1 *novi, *zadnji=this;
        for(int i=1;i<=brojac;i++){
            zadnji=zadnji->sljedecig;
            if(i==broj){
                hash1 *iduci, *glava;
                glava=zadnji;
                if(glava->sljedeci==NULL){
                    novi=new hash1();
                    glava->sljedeci=novi;
                    novi->prethodni=glava;
                    novi->sljedeci=NULL;
                    cout << "Unesite sifru: ";
                    cin >> novi->sifra;
                    cin.ignore();
                    cout << "Unesite ime: ";
                    cin.getline(novi->ime, 100);
                    return;
                }
                iduci = glava->sljedeci;
                novi = new hash1();
                glava->sljedeci=novi;
                novi->prethodni=glava;
                novi->sljedeci=iduci;
                iduci->prethodni= novi;
                cout << "Unesite sifru: ";
                cin >> novi->sifra;
                cin.ignore();
                cout << "Unesite ime: ";
                cin.getline(novi->ime, 100);
                return;
            }
        }
    }

    void dodajElementNaKraj(int broj){
        hash1 *novi, *zadnji = this;
        for(int i = 1; i <= brojac;i++){
            zadnji=zadnji->sljedecig;
            if(i==broj){
                hash1 *glava;
                glava = zadnji;
                while(glava->sljedeci)
                    glava=glava->sljedeci;
                novi = new hash1();
                glava->sljedeci=novi;
                novi->prethodni=glava;
                novi->sljedeci=NULL;
                cout << "Unesite sifru: ";
                cin >> novi->sifra;
                cin.ignore();
                cout << "Unesite ime: ";
                cin.getline(novi->ime, 100);
                return;
            }
        }
    }

    void ispisivanjeSvega(){
        hash1 *zadnji=this;
        for(int i=0;i<brojac;i++){
            zadnji=zadnji->sljedecig;
            hash1 *tekuci=zadnji->sljedeci;
            cout << "----------------------------" << endl;
            while(tekuci){
                cout << "Sifra je: " << tekuci->sifra << endl;
                cout << "Ime je: " << tekuci->ime << endl;
                
                tekuci=tekuci->sljedeci;
            }
        }
    }

    void ispisivanjeListe(int broj){
        hash1 *zadnji=this;
        for(int i=1;i<=brojac;i++){
            zadnji=zadnji->sljedecig;
            if(i==broj){
                hash1 *tekuci = zadnji->sljedeci;
                while(tekuci){
                    cout << "Sifra je: " << tekuci->sifra << endl;
                    cout << "Ime je: " << tekuci->ime << endl;
                    tekuci=tekuci->sljedeci;
                }
            }
        }
    }

    void pretrazivanje(int broj){
        hash1 *zadnji=this;
        for(int i=0;i<brojac;i++){
            zadnji=zadnji->sljedecig;
            hash1 *tekuci=zadnji->sljedeci;
            while(tekuci){
                if(tekuci->sifra==broj){
                    cout << "Sifra je: " << tekuci->sifra << endl;
                    cout << "Ime je: " << tekuci->ime << endl;
                }
                tekuci=tekuci->sljedeci;
            }
        }
    }

    void brisanje(int broj){
        hash1 *zadnji=this;
        for(int i=0;i<brojac;i++){
            zadnji=zadnji->sljedecig;
            hash1 *tekuci=zadnji->sljedeci;
            while(tekuci){
                hash1 *prosli;
                if(tekuci->sifra==broj){
                    prosli=tekuci->prethodni;
                    if(tekuci->sljedeci==NULL){
                         prosli->sljedeci=NULL;
                         delete tekuci;
                         return;
                    }
                    hash1 *iduci;
                    iduci=tekuci->sljedeci;
                    prosli->sljedeci=tekuci->sljedeci;
                    iduci->prethodni=tekuci->prethodni;
                    delete tekuci;
                    return;
                }
                tekuci=tekuci->sljedeci;
            }
        }
    }
};
int hash1::brojac=0;

int main(){
    hash1 *objekt = new hash1();
    int biranje;
    do{
        cout << endl;
        cout << "1-dodaj vezanu listu na kraj!" << endl;
        cout << "2-dodaj vezanu listu na pocetak!" << endl;
        cout << "3-dodaj element na pocetak vezane liste!" << endl;
        cout << "4-dodaj element na kraj vezane liste!" << endl;
        cout << "5-ispisi sve!" << endl;
        cout << "6-ispisi specificnu vezanu listu!" << endl;
        cout << "7-pretrazi element!" << endl;
        cout << "8-izbrisi element!" << endl;
        cout << endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
                objekt->dodajListuNaKraj();
                cout << "Dodana " << hash1::brojac << ". vezana lista!" << endl;
                break;
            case 2:
                objekt->dodajListuNaPocetak();
                cout << "Dodana 1. vezana lista!" << endl;
                break;
            case 3:
                int broj;
                cout << "Unesite u koju vezanu listu hocete unijeti: ";
                cin >> broj;
                objekt->dodajElementNaPocetak(broj);
                break;
            case 4:
                int broj1;
                cout << "Unesite u koju vezanu listu hocete unijeti: ";
                cin >> broj1;
                objekt->dodajElementNaKraj(broj1);
                break;
            case 5:
                objekt->ispisivanjeSvega();
                break;
            case 6:
                int broj2;
                cout << "Unesite koju listu zelite ispisati: ";
                cin >> broj2;
                objekt->ispisivanjeListe(broj2);
                break;
            case 7:
                int broj3;
                cout << "Unesite koju listu zelite pretraziti: ";
                cin >> broj3;
                objekt->pretrazivanje(broj3);
                break;
            case 8:
                int broj4;
                cout << "Unesite sifru elementa koji zelite izbrisati: ";
                cin >> broj4;
                objekt->brisanje(broj4);
                break;
            case 9:
            cout << "Kraj programa!" << endl;
                break;
            default:
            cout << "Unesite ponovno!" << endl;
            break;
        }
    }while(biranje!=9);
    return 0;
}