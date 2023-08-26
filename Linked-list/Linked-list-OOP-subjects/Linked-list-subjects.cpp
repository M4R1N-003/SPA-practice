#include <iostream>
using namespace std;
    class kolegij{
        private:
        kolegij *sljedeci;

        public:
        int sif_kolegij;
        char ime_kolegija[100];
        int ECTS;
        char ime_prof[100];

        kolegij(){
            sljedeci = NULL;
        }

        void dodavanje(){
            kolegij *novi;
            kolegij *zadnji = this;
            while(zadnji->sljedeci)
                zadnji = zadnji->sljedeci;
            novi = new kolegij;
            zadnji->sljedeci = novi;
            novi->sljedeci = NULL;
            cout << "Unesite sifru kolegija: ";
            cin >> novi->sif_kolegij;
            cin.ignore();
            cout << "Unesite ime kolegija: ";
            cin.getline(novi->ime_kolegija, 100);
            cout << "Unesite broj ECTS bodova za kolegij: ";
            cin >> novi->ECTS;
            cin.ignore();
            cout << "Unesite ime profesora: ";
            cin.getline(novi->ime_prof, 100);
        }
    };

    kolegij *objekt = new kolegij;
int main(){
    int biranje;
    do{
        cout << endl;
        cout << "1-dodavanje novog elementa!" << endl;
        cout << "2-ispisivanje elemenata!" << endl;
        cout << "3-pretrazivanje elemenata!" << endl;
        cout << "4-azuriranje elemenata!" << endl;
        cout << "5-brisanje elemenata!" << endl;
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
                break;
            case 4:
                break;
            case 5:
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