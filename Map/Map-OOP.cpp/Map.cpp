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
        
        void ispis(){
            for(map <int, string>::iterator i=mojaMapa.begin(); i!=mojaMapa.end();++i)
                cout << (*i).first << "---" << (*i).second << endl;
        }

        void pretrazivanje(int broj){
            for(map <int, string>::iterator i=mojaMapa.begin(); i!=mojaMapa.end();++i){
                if((*i).first==broj)
                cout << (*i).first << "---" << (*i).second << endl;
            }
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
                objekt->ispis();
                break;
            case 3:
                int brojcek;
                cout << "Unesite broj za pretrazivanje: ";
                cin >> brojcek;
                objekt->pretrazivanje(brojcek);
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