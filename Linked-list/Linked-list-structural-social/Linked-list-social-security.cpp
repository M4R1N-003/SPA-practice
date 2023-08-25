#include <iostream>
using namespace std;

    struct maticni{
        int mat_br;
        char ime_prez[100];
        int starost;
        char spol[6];
        maticni *sljedeci;
    };

    void dodavanje(maticni *glava){
        maticni *zadnji, *novi;
        zadnji = glava;
        while(zadnji -> sljedeci)
            zadnji = zadnji -> sljedeci;
        novi = new maticni;
        zadnji -> sljedeci = novi;
        novi->sljedeci=NULL;
        cout << "Unesite maticni broj osobe: ";
        cin >> novi->mat_br;
        cin.ignore();
        cout << "Unesite ime i prezime osobe: ";
        cin.getline(novi->ime_prez, 100);
        cout << "Unesite starost osobe: ";
        cin >> novi->starost;
        cout << "Unesite spol osobe: ";
        cin >> novi->spol;
    }

    void ispis(maticni *glava){
        maticni *tekuci = glava->sljedeci;
        while(tekuci){
            cout << "Maticni broj osobe: ";
            cout << tekuci->mat_br << endl;
            cout << "Ime i prezime osobe: ";
            cout << tekuci->ime_prez << endl;
            cout << "Starost osobe: ";
            cout << tekuci->starost << endl;
            cout << "Spol osobe: ";
            cout << tekuci->spol << endl;
            cout << endl;
            tekuci = tekuci->sljedeci;    
        }
    }

int main(){
    int biranje;
    maticni *glava = new maticni;
    glava->sljedeci=NULL;
    do{
        cout << "\n1-Dodavanje novog elementa!" << endl;
        cout << "2-Ispis novog elementa!" << endl;
        cout << "3-Pretrazivanje elemenata!" << endl;
        cout << "4-Azuriranje postojeceg elementa!" << endl;
        cout << "5-Brisanje odredjenog elementa!" << endl;
        cout << "9-Kraj programa!\n" << endl;
        cout<<"Unesite odabir: ";
        cin>>biranje;
        
        switch(biranje){
            case 1:
            dodavanje(glava);
                break;
            case 2:
            ispis(glava);
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
        }
    }while(biranje!=9);

    return 0;
}