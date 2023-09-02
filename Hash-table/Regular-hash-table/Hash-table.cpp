#include <iostream>
#include "table.h"
using namespace std;
int lista::broj2;

int main(){
    lista *objekt= new lista;
    int biranje;
    do{
        cout << "1-unos liste!" << endl;
        cout << "2-unos elementa!" << endl;
        cout << "3-ispis" << endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
                objekt->dodavanjeGlave();
                cout << "Dodana " << objekt->broj2 << ". lista!" << endl;
                break;
            case 2:
                int unesi;
                cout << "Unesite u koju zelite listu unijeti: ";
                cin >> unesi;
                int broj;
                cout << "Unesite broj: ";
                cin >> broj;
                char ime[100];
                cin.ignore();
                cout << "Unesite ime: ";
                cin.getline(ime, 100);
                int god;
                cout << "Unesite godine: ";
                cin >> god;
                objekt->dodavanjeElementa(unesi, broj, ime, god);
                break;
            case 3:
            objekt->ispis();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 9:
                cout << "Kraj programa!" << endl;
                break;
            default:
            cout << "Unesite ponovno!"  << endl;
                break;
        }
    }while(biranje!=9);

    return 0;
}