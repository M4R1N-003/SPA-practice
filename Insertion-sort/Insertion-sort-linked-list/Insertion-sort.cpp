#include <iostream>
using namespace std;
    class lista{
        private:
        lista *sljedeci;

        public:
        lista(){
            sljedeci=NULL;
        }

        int N;

        void dodavanje(int s){
            lista *novi, *zadnji=this;
            while(zadnji->sljedeci)
                zadnji=zadnji->sljedeci;
            novi = new lista;
            zadnji->sljedeci = novi;
            novi->sljedeci = NULL;
            novi->N = s;
        }

        void ispis(){
            lista *tekuci = this->sljedeci;
            while(tekuci){
                cout << tekuci->N << " ";
                tekuci = tekuci->sljedeci;
            }
        }

        void sortiranje(){
            if(!(this->sljedeci)) return;
            
            lista *sortirano = NULL;
            lista *trenutni = this;

            while(trenutni){
                lista *iduci = trenutni->sljedeci;
                if(!sortirano || sortirano->N >= trenutni->N){
                    trenutni->sljedeci = sortirano;
                    sortirano = trenutni;
                }
                else{
                    lista *priv = sortirano;
                    while(priv->sljedeci && priv->sljedeci->N < trenutni->N){
                        priv = priv->sljedeci;
                    }
                    trenutni->sljedeci=priv->sljedeci;
                    priv->sljedeci = trenutni;
                }
                trenutni = iduci;
            }
        }

    };
int main(){
    lista *objekt = new lista;
    int n;
    cout << "Unesi broj brojeva: ";
    cin >> n;
    cin.ignore();
    int s;
    for(int i=0;i<n;i++){
        cin >> s;
        objekt->dodavanje(s);
    }
    objekt->ispis();
    objekt->sortiranje();
    cout << endl;
    objekt->ispis();
    return 0;
}