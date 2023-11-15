#include <iostream>
#include <ctime>
using namespace std;

class lista{    
    private:
    lista *sljedeci;
    public:
    int N;

    lista(){
        sljedeci=NULL;
    }

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
        lista *tekuci=this->sljedeci;
        while(tekuci){
            cout << tekuci->N << " ";
            tekuci=tekuci->sljedeci;
        }
    }

    void sortiranje(){
        mergeSort(&this->sljedeci);
    }

    void mergeSort(lista **refGlava){
        lista *glava = *refGlava;
        lista *a;
        lista *b;
        
        if(glava==NULL || glava->sljedeci==NULL)
            return;
        
        odvajanje(glava, &a, &b);

        mergeSort(&a);
        mergeSort(&b);

        *refGlava=sortirano(a, b);
    }

    lista *sortirano(lista *a, lista *b){
        lista *rezultat=NULL;
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a->N<=b->N){
            rezultat=a;
            rezultat->sljedeci=sortirano(a->sljedeci, b);
        }
        else{
            rezultat=b;
            rezultat->sljedeci=sortirano(b->sljedeci, a);
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

        *ispred=korijen;
        *iza=spori->sljedeci;
        spori->sljedeci=NULL;
    }

};
int main(){
    lista *objekt=new lista();
    int n;
    cin >> n;
    srand(time(0));
    for(int i=0;i<n;i++){
        int s;
        s=rand()%20+1;
        objekt->unos(s);
    }

    objekt->ispis();
    cout << endl;

    objekt->sortiranje();

    objekt->ispis();
    return 0;
}