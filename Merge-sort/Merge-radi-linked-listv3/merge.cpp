#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

    class lista{
        private:
        lista *sljedeci;

        public:
        lista(){
            sljedeci=NULL;
        }
        int N;

        void unos(int x){
            lista *novi, *zadnji=this;
            while(zadnji->sljedeci)
                zadnji=zadnji->sljedeci;
            novi = new lista();
            zadnji->sljedeci=novi;
            novi->N=x;
            novi->sljedeci=NULL;
        }

        void ispis(){
            lista *trenutni=this->sljedeci;
            while(trenutni){
                cout << trenutni->N << " ";
                trenutni=trenutni->sljedeci;
            }
        }

        void sortiranje(){
            MergeSort(&this->sljedeci);
        }

        void MergeSort(lista **refGlava){
            lista *glava= *refGlava;
            lista *a;
            lista *b;
            if((glava==NULL)||(glava->sljedeci==NULL)){
                return;
            }
            odvajanje(glava, &a, &b);

            MergeSort(&a);
            MergeSort(&b);

            *refGlava=sortiran(a, b);
        }

        lista* sortiran(lista *a, lista *b){
            lista *rezultat=NULL;

            if(a==NULL)
                return b;
            if(b==NULL)
                return a;
            if(a->N<=b->N){
                rezultat=a;
                rezultat->sljedeci=sortiran(a->sljedeci, b);
            }
            else{
                rezultat=b;
                rezultat->sljedeci=sortiran(b->sljedeci, a); 
            }

            return rezultat;
        }

        void odvajanje(lista *korijen, lista **ispred, lista **iza){
            lista *spori=korijen;
            lista *brzi=korijen->sljedeci;

            while(brzi!=NULL){
                brzi=brzi->sljedeci;
                if(brzi!=NULL){
                    brzi=brzi->sljedeci;
                    spori=spori->sljedeci;
                }
            }

            *ispred = korijen;
            *iza=spori->sljedeci;
            spori->sljedeci=NULL;
        }
    };
int main(){
    srand(time(0));
    lista *objekt = new lista();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int s;
        s=rand()%100+1;
        objekt->unos(s);
    }
    objekt->ispis();
    cout << endl;
    objekt->sortiranje();
    objekt->ispis();


    return 0;
}