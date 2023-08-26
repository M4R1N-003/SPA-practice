#include <iostream>
#include <cstring>
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

    void pretrazivanje(maticni *glava, int broj){
        maticni *tekuci = glava->sljedeci;
        while(tekuci){
            if(tekuci->mat_br == broj){
                cout << "Maticni broj osobe: ";
                cout << tekuci->mat_br << endl;
                cout << "Ime i prezime osobe: ";
                cout << tekuci->ime_prez << endl;
                cout << "Starost osobe: ";
                cout << tekuci->starost << endl;
                cout << "Spol osobe: ";
                cout << tekuci->spol << endl;
                cout << endl;
            }
            tekuci = tekuci->sljedeci; 
        }
    }

    void azuriranje(maticni *glava, char element[30], int broj){
        maticni *tekuci = glava->sljedeci;
        while(tekuci){
            if(tekuci->mat_br == broj){
                if(strcmp(element, "Maticni_broj")==0){
                    int num;
                    cout << "Unesite novi maticni broj: ";
                    cin >>num;
                    tekuci->mat_br = num;
                }
                if(strcmp(element, "Ime_prezime")==0){
                    char ime[100];
                    cin.ignore();
                    cout << "Unesite novo ime: ";
                    cin.getline(ime, 100);
                    strcpy(tekuci->ime_prez, ime);
                }
                if(strcmp(element,"Starost")==0){
                    int number;
                    cout << "Unesite novu starost: ";
                    cin >>number;
                    tekuci->starost = number;
                }
                if(strcmp(element, "Spol")==0){
                    char spol[6];
                    cin.ignore();
                    cout << "Unesite novi spol: ";
                    cin.getline(spol, 6);
                    strcpy(tekuci->spol, spol);
                }
            }
            tekuci = tekuci->sljedeci; 
        }
    }

    void brisanje(maticni *glava, int broj){
        maticni *prethodni = glava;
        maticni *tekuci = glava->sljedeci;
        while(tekuci){
            if(tekuci->mat_br == broj){
                prethodni->sljedeci=tekuci->sljedeci;
                delete tekuci;
            }
            prethodni=tekuci;
            tekuci=tekuci->sljedeci;
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
            int mat;
            cout << "Unesite maticni broj za pretrazivanje osobe: ";
            cin >> mat;
            pretrazivanje(glava, mat);
                break;
            case 4:
            char element[30];
            int broj;
            cout << "Za azuriranje morate ukucati element koji zelite promjeniti!" << endl;
            cout << "Moguce promjene su: Maticni_broj, Ime_prezime, Starost, Spol!" << endl;
            cout << "Unesite maticni broj osobe kojoj zelite promjeniti element: ";
            cin >> broj;
            cout << "Unesite element koji zelite azurirati: ";
            cin >> element;
            azuriranje(glava, element, broj);
                break;
            case 5:
            int brojcek;
            cout << "Unesite maticni broj osobe za brisanje: ";
            cin >> brojcek;
            brisanje(glava, brojcek);
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