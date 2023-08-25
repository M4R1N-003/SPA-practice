#include <iostream>
using namespace std;
int main(){
    int biranje;
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
                break;
            case 2:
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