#include <iostream>
#include <vector>
using namespace std;

class vektor{
    public:
    int broj;
    char ime[100];
    vector <vektor> vek;
    void dodavanje(){
        vektor priv;
        cout << "Unesite broj: ";
        cin >> priv.broj;
        cout << "Unesite ime: ";
        cin >> priv.ime;
        vek.push_back(priv);
    }

};

int main(){
    int biranje;
    vektor *objekt = new vektor;
    do{
        cout << endl;
        cout << "1-dodavanje!" << endl;
        cout << "2-ispisivanje!" << endl;
        cout << "3-pretrazivanje!" << endl;
        cout << "4-brisanje elementa" << endl;
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
            case 9:
                cout << "Kraj programa!" << endl;
                break;
            default:
            cout << "Unesite ponovno!" << endl;
                break;
        }
    }while(biranje!=9);
}