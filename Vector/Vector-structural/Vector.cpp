#include <iostream>
#include <vector>
using namespace std;

    struct vektor{
        int broj;
        char ime[100];
    };

    vector <vektor> vek;

    void dodavanje(){
        vektor priv;
        cout << "Unesite broj: ";
        cin >> priv.broj;
        cout << "Unesite ime: ";
        cin >> priv.ime;
        vek.push_back(priv);
    }

    void ispis() {
        for (const auto& item : vek) {
            cout << "Broj: " << item.broj << ", Ime: " << item.ime << endl;
        }
    }

    void pretrazivanje(int brojcek){
        for (const auto& item : vek) {
            if(item.broj==brojcek){
                cout << "Broj: " << item.broj << ", Ime: " << item.ime << endl;
            }
        }
    }

    void brisanje(int brojcek) {
        auto it = vek.begin();
        while (it != vek.end()) {
            if (it->broj == brojcek) {
                it = vek.erase(it);
            } else {
                ++it;
            }
        }
    }

int main(){
    int biranje;
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
                dodavanje();
                break;
            case 2:
                ispis();
                break;
            case 3:
                int brojcek;
                cout << "Unesite broj za pretrazivanje: ";
                cin >> brojcek;
                pretrazivanje(brojcek);
                break;
            case 4:
                int brojcek1;
                cout << "Unesite broj za brisanje: ";
                cin >> brojcek1;
                brisanje(brojcek1);
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