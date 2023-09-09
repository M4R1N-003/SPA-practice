#include <iostream>
#include <cstring>
using namespace std;

    struct lista{
        int broj;
        char ime[100];
        int godine;
        lista *sljedeci;
        lista *glSljedeci;
    };
    int broj2;

    void dodavanjeGlave(lista *glava){
        lista *novi, *zadnji=glava;
        while(zadnji->glSljedeci)
            zadnji=zadnji->glSljedeci;
        novi = new lista;
        zadnji->glSljedeci=novi;
        novi->sljedeci=0;
        novi->glSljedeci=0;
        broj2++;
    }

    void dodavanjeElementa(int grana, int broj1, char ime1[100], int godine1, lista *glava){
        lista *zadnji1=glava;
        for(int i=0;i<grana;i++){
            zadnji1=zadnji1->glSljedeci;
        }
        lista *novi, *zadnji=zadnji1;
        while(zadnji->sljedeci)
            zadnji=zadnji->sljedeci;
        novi = new lista;
        zadnji->sljedeci=novi;
        novi->sljedeci=0;
        novi->broj = broj1;
        strcpy(novi->ime, ime1);
        novi->godine=godine1;
    }

    void ispis(lista *glava){
        lista *zadnji=glava;
        for(int i=0;i<broj2;i++){
            zadnji=zadnji->glSljedeci;
            lista *prvi=zadnji->sljedeci;
            while(prvi){
                cout << prvi->broj << endl;
                cout << prvi->ime << endl;
                cout << prvi->godine << endl;
                prvi=prvi->sljedeci;
            }
        }
    }

    void ispisListe(int broj3, lista *glava){
        lista *zadnji=glava;
        for(int i=0;i<broj3;i++){
            zadnji=zadnji->glSljedeci;
            if(i==broj3-1){
                lista *prvi=zadnji->sljedeci;
                while(prvi){
                    cout << prvi->broj << endl;
                    cout << prvi->ime << endl;
                    cout << prvi->godine << endl;
                    prvi=prvi->sljedeci; 
                }   
            }
        }
    }

    void pretrazivanje(int broj4, lista *glava){
        lista *zadnji=glava;
        for(int i=0;i<broj2;i++){
            zadnji=zadnji->glSljedeci;
            lista *prvi=zadnji->sljedeci;
            while(prvi){
                if(prvi->broj==broj4){
                    cout << prvi->broj << endl;
                    cout << prvi->ime << endl;
                    cout << prvi->godine << endl;
                }
                prvi=prvi->sljedeci;
            }
        }
    }

    void brisanje(int broj4, lista *glava){
        lista *zadnji=glava;
        for(int i=0;i<broj2;i++){
            zadnji=zadnji->glSljedeci;
            lista *prvi=zadnji->sljedeci;
            lista *predzadnji=zadnji;
            while(prvi){
                if(prvi->broj==broj4){
                    predzadnji->sljedeci=prvi->sljedeci;  
                }
                predzadnji=prvi;
                prvi=prvi->sljedeci;
            }
        }
    }

    
int main(){
    int biranje;
    lista *glava = new lista;
    glava->glSljedeci=NULL;
    glava->sljedeci=NULL;
    do{
        cout << endl;
        cout << "1-Dodavanje glave!" << endl;
        cout << "2-Dodavanje elementa!" << endl;
        cout << "3-Ispis svih elemenata!" << endl;
        cout << "4-Ispis specificne liste" << endl;
        cout << "5-Pretrazivanje elementa!" << endl;
        cout << "6-Brisanje elementa!" << endl;
        cout << endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
                dodavanjeGlave(glava);
                cout << "Dodana " << broj2 << ". lista!" << endl;
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
                dodavanjeElementa(unesi, broj, ime, god, glava);
                break;
            case 3:
                ispis(glava);
                break;
            case 4:
                int broj5;
                cout << "Unesite broj liste za ispis: ";
                cin >> broj5;
                ispisListe(broj5, glava);
                break;
            case 5:
                int broj6;
                cout << "Unesite broj elementa za pretrazivanje: ";
                cin >> broj6;
                pretrazivanje(broj6, glava);
                break;
            case 6:
                int broj7;
                cout << "Unesite broj elementa za brisanje: ";
                cin >> broj7;
                brisanje(broj7, glava);
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