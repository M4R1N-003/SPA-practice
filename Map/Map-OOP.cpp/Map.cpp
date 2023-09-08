#include <iostream>
#include <map>
using namespace std;

    class mapa{
        public:
        map <int, string> mojaMapa;

        void dodaj(){
            int N;
            string ime;
                cout << "Unesite broj mape: ";
                cin >> N;
                cout << "Unesite ime mape: ";
                cin >> ime;
                mojaMapa.insert(pair <int, string>(N, ime));
        }
        
    };
int main(){
    int biranje;
    mapa *objekt = new mapa;
    do{
        cout << endl;
        cout << "1-Dodavanje elementa!" << endl;
        cout << "2-Ispis elementa!" << endl;
        cout << "3-Pretrazivanje elementa!" << endl;
        cout << "4-Brisanje elementa!" << endl;
        cout << endl;
        cout << "Unesite odabir: ";
        cin >> biranje;
        switch(biranje){
            case 1:
                objekt->dodaj();
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