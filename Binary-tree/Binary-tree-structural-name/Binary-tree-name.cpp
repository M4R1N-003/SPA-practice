#include <iostream>
#include <cstring>
using namespace std;

struct binarno{
    int broj;
    char ime[100];
    binarno *lijevi;
    binarno *desni;
};

void dodavanje(binarno *korijen, int brojcek, char name[100]){

    if(korijen->broj == 0){
        korijen->broj = brojcek;
        strcpy(korijen->ime, name);
        return;
    }

    binarno *novi, *zadnji = korijen;
    int dalje = 1;
    do{
        if(brojcek > zadnji->broj){
            if(zadnji->desni != NULL){
                zadnji = zadnji->desni;
            }
            else{
                novi = new binarno;
                zadnji->desni = novi;
                novi->broj = brojcek;
                strcpy(novi->ime, name);
                novi->desni = NULL;
                novi->lijevi = NULL;
                dalje = 0;
            }
        }
        else{
            if(zadnji->lijevi != NULL){
                zadnji = zadnji->lijevi;
            }
            else{
                novi = new binarno;
                zadnji->lijevi = novi;
                novi->broj = brojcek;
                strcpy(novi->ime, name);
                novi->desni = NULL;
                novi->lijevi = NULL;
                dalje = 0;
            }
        }
    }while(dalje==1);
}

void ispis(binarno *korijen){
    if(korijen!=NULL){
        ispis(korijen->lijevi);
        cout << korijen->broj << " --> ";
        cout << korijen->ime;
        cout << " ,  ";
        ispis(korijen->desni);
    }
}

void pretrazivanje(binarno *korijen, int broj1){
    if(korijen == NULL){
        return;
    }
    if(korijen->broj == broj1){
        cout << korijen->broj << " ---> " << korijen->ime << endl;
        return;
    }
    if(korijen->broj < broj1){
        pretrazivanje(korijen->desni, broj1);
    }
    else{
        pretrazivanje(korijen->lijevi, broj1);
    }
}

void brisanje1(binarno *cvor, binarno *roditelj, bool lijevi){
    if(cvor==NULL) return;
    if(lijevi){
        roditelj->lijevi=NULL;
    }
    else {roditelj->desni=NULL;}
    
    brisanje1(cvor->desni, cvor, false);
    brisanje1(cvor->lijevi, cvor, true);

    cout << "Brisem cvor: " << cvor->broj << " ---> " << cvor->ime << endl;
    delete cvor;
}

void brisanje2(binarno *korijen, int broj2){
    if(korijen==NULL) return;
    else if(korijen->desni->broj==broj2){
        brisanje1(korijen->desni, korijen, false);
        return;
    }
    else if(korijen->lijevi->broj==broj2){
        brisanje1(korijen->lijevi, korijen, true);
        return;
    }
    else if(korijen->broj<broj2) {
        brisanje2(korijen->desni, broj2);
    }
    else if(korijen->broj>broj2){
        brisanje2(korijen->lijevi, broj2);
    }
}

int main(){
    int biranje;
    binarno *korijen = new binarno;
    korijen->lijevi = NULL;
    korijen->desni = NULL;
    korijen->broj = 0;
    do{
        cout << endl;
        cout << "1-dodavanje novo elementa u binarno stablo!" << endl;
        cout << "2-ispisivanje elemenata iz binarnog stabla!" << endl;
        cout << "3-pretrazivanje elemenata binarnog stabla!" << endl;
        cout << "4-brisanje elementa iz binarnog stabla!" << endl;
        cout << endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
            int brojic1;
            char name[100];
            cout << "Unesite broj: ";
            cin >> brojic1;
            cin.ignore();
            cout << "Unesite ime: ";
            cin.getline(name, 100);
            dodavanje(korijen, brojic1, name);
                break;
            case 2:
            ispis(korijen);
                break;
            case 3:
            int brojic2;
            cout << "Unesite broj za pretrazivanje binarnog stabla: ";
            cin >> brojic2;
            pretrazivanje(korijen, brojic2);
                break;
            case 4:
            int brojic3;
            cout << "Unesite broj za brisanje cvora: ";
            cin >> brojic3;
            brisanje2(korijen, brojic3);
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