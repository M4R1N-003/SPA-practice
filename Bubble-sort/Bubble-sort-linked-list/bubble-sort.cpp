#include <iostream>
using namespace std;

class lista{
    private:
    lista *sljedeci;
    public:
    lista(){
        sljedeci = NULL;
    }
    int N;

    void dodavanje(int s){       
        lista *novi, *zadnji=this;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci=novi;
        novi->sljedeci=NULL;
        novi->N = s;
    }

    void ispis(){
        lista *tekuci = this->sljedeci;
        while(tekuci){
            cout << tekuci->N << " ";
            tekuci=tekuci->sljedeci;
        }
    }

    
};
int main(){
    int biranje;
    lista *objekt = new lista();
    do{
        cout << endl;
        cout << "1-dodavanje" << endl;
        cout << "2-sortiranje" << endl;
        cout << "3-ispisivanje" << endl;
        cout << "9-kraj" << endl;
        cout << endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
                int s;
                char prov;
                do{
                cout << "Unesite broj elementa: ";
                cin >> s;
                objekt->dodavanje(s);
                cout << "Zelite li ponovno(D-da, N-ne): ";
                cin >> prov;
                }while(prov!='N');
                break;
            case 2:
                break;
            case 3:
                objekt->ispis();
                break;
            case 9:
                cout << "Kraj programa!" << endl;
                break;
            default:
            cout << "Unesite ponovno!" << endl;
        }
    }while(biranje!=9);
    return 0;
}