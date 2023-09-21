#include <iostream>
#include <cstring>
using namespace std;

class lista{
    private:
    lista *sljedeci;

    public:
    lista(){
        sljedeci=0;
    }
    int N;
    char ime[100];

    void dodavanje(int k, char im[100]){
        lista *novi, *zadnji=this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci=novi;
        novi->sljedeci=0;
        novi->N=k;
        strcpy(novi->ime, im);
    }

    void ispisivanje(){
        lista *tekuci=this->sljedeci;
        while(tekuci){
            cout << tekuci->N << "---";
            cout << tekuci->ime << endl;
            tekuci=tekuci->sljedeci;
        }
    }

    void sortiranje(){
        lista *prethodni, *tekuci, *iduci;
        int provjera;
        do{
            provjera=0;
            tekuci=this->sljedeci;
            prethodni=this;
            while(tekuci && tekuci->sljedeci){
                iduci=tekuci->sljedeci;
                if(tekuci->N > iduci->N){
                    prethodni->sljedeci=iduci;
                    tekuci->sljedeci=iduci->sljedeci;
                    iduci->sljedeci=tekuci;
                    provjera=1;
                }
                prethodni=tekuci;
                tekuci=tekuci->sljedeci;
            }
        }while(provjera==1);
    }

    lista *trazenjeSredine(lista *pocetak, lista *kraj){
        lista *spori=pocetak;
        lista *brzi=pocetak->sljedeci;

        while(brzi!=kraj){
            brzi=brzi->sljedeci;
            if(brzi!=kraj){
                spori=spori->sljedeci;
                brzi=brzi->sljedeci;
            }
        }
        
        return spori;
    }

    void binarno(int k){
        lista *kraj=0;
        lista *pocetak=this;
        do{
            lista *sredina=trazenjeSredine(pocetak, kraj);

            if(sredina==0)return;

            if(sredina->N==k){
                cout << sredina->N << "---";
                cout << sredina->ime << endl;
                return;  
            }
            
            else if(sredina->N>k){
                pocetak=this;
                kraj=sredina;
            }

            else if(sredina->N<k){
                pocetak=sredina->sljedeci;
            }
        }while(kraj==NULL||kraj!=pocetak);
    }

};

int main(){
    int biranje;
    lista *objekt = new lista;
    do{
        cout << endl;
        cout << "1-Unesite element!" << endl;
        cout << "2-ispisite elemente!" << endl;
        cout << "3-binarno pretrazite elemente!" << endl;
        cout << "4-sortirajte elemente!" << endl;
        cout << endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
                int N;
                char ime[100];
                cout << "Unesite broj elementa: ";
                cin >> N;
                cin.ignore();
                cout << "Unesite ime elementa: ";
                cin.getline(ime, 100);
                objekt->dodavanje(N, ime);
                break;
            case 2:
                objekt->ispisivanje();
                break;
            case 3:
                int s;
                cout << "Unesite broj za pretrazivanje: ";
                cin >> s;
                objekt->binarno(s);
                break;
            case 4:
                objekt->sortiranje();
                break;
            case 9:
                cout << "kraj!" << endl;
                break;
            default:
                cout << "Unesite ponovno!" << endl;
                break;
        }
    }while(biranje!=9);
}