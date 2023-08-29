#include <iostream>
#include <cstring>
using namespace std;

class binarno{
    private:
    binarno *lijevi;
    binarno *desni;

    public:
    int broj;
    char predmet[100];

    binarno(){
        lijevi=NULL;
        desni=NULL;
        broj = 0;
    }

    void dodavanje(int brojic, char polje[100]){
        binarno *novi, *zadnji=this;
        int dalje=1;
        if(broj==0){
            broj=brojic;
            strcpy(predmet, polje);
            return;
        }
        do{
            if(zadnji->broj<brojic){
                if(zadnji->desni!=NULL){
                    zadnji=zadnji->desni;
                }
                else{
                    novi = new binarno;
                    zadnji->desni=novi;
                    novi->broj=brojic;
                    strcpy(novi->predmet, polje);
                    novi->desni=NULL;
                    novi->lijevi=NULL;
                    dalje=0;
                }
            }
            else{
                if(zadnji->lijevi!=NULL){
                    zadnji=zadnji->lijevi;
                }
                else{
                    novi = new binarno;
                    zadnji->lijevi=novi;
                    novi->broj=brojic;
                    strcpy(novi->predmet, polje);
                    novi->lijevi=NULL;
                    novi->desni=NULL;
                    dalje=0;                   
                }
            }
        }while(dalje==1);
    }

    void ispis(binarno *cvor){
        if(cvor!=NULL){
            ispis(cvor->lijevi);
            cout << cvor->broj << " ---> " << cvor->predmet << endl;
            ispis(cvor->desni);
        }
    }

    void pretrazivanje(binarno *cvor, int brojic){
        if(cvor==NULL){
            cout << "Binarno stablo ne postoji!" << endl;
            return;
        }
        else if(cvor->broj==brojic){
            cout << "Broj je: " << cvor->broj << endl;
            cout << "Predmet je: " << cvor->predmet << endl;
            return;
        }
        else if(cvor->broj<brojic){
            pretrazivanje(cvor->desni, brojic);
        }
        else{
            pretrazivanje(cvor->lijevi, brojic);
        }
    }

};

binarno *objekt = new binarno;

int main(){
    int biranje;
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
            int broj1;
            char predmet[100];
            cout << "Unesite broj elementa: ";
            cin >> broj1;
            cin.ignore();
            cout << "Unesite ime predmeta: ";
            cin.getline(predmet, 100);
            //for(int i=-100;i<100;i++){
            //    broj1=i;
            //    strcpy(predmet, "Marin");
            objekt->dodavanje(broj1, predmet);
            //}
                break;
            case 2:
            objekt->ispis(objekt);
                break;
            case 3:
            int broj2;
            cout << "Unesite broj za pretrazivanje stabla: ";
            cin >> broj2;
            objekt->pretrazivanje(objekt, broj2);
                break;
            case 4:
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
    return 0;
}