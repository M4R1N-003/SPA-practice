#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct lista{
	int a;
	lista *sljedeci;
	lista *sm;
	lista *sv;
};

int broj_elemenata_liste(lista *l){
	lista *el;
	int k=0;
	el=l->sljedeci;
	while(el){
		k++;
		el=el->sljedeci;
	}
	return k;
}

void quick_sort(lista *l){
	int poz=rand()%broj_elemenata_liste(l);
	lista *el=l->sljedeci;
	for(int i=0; i<poz; i++) el=el->sljedeci;
	int pivot=el->a;
	el=l->sljedeci;
	while(el){
		if(el->a<pivot){
			lista *manj, *vec;
			manj=l;
			vec=l->sm;
			while(vec && vec->a<el->a){
				vec=vec->sm;
				manj=manj->sm;
			}
			el->sm=vec;
			manj->sm=el;
		}
		else{
			lista *manj, *vec;
			manj=l;
			vec=l->sv;
			while(vec && vec->a<el->a){
				vec=vec->sv;
				manj=manj->sv;
			}
			el->sv=vec;
			manj->sv=el;
		}
		el=el->sljedeci;
	}
	lista *zadnji_manji;
	zadnji_manji=l->sm;
	while(zadnji_manji->sm) zadnji_manji=zadnji_manji->sm;
	lista *prvi_veci=l->sv;
	while(prvi_veci){
	zadnji_manji->sm=prvi_veci;
	prvi_veci=prvi_veci->sv;
	zadnji_manji=zadnji_manji->sm;
	}
}

void popuni_listu(lista *l, int n){
	lista *novi;
	for(int i=0; i<n; i++){
		novi=new lista;
		cin>>novi->a;
		novi->sljedeci=l->sljedeci;
		l->sljedeci=novi;
		novi->sm=NULL;
		novi->sv=NULL;	
	}
}

void ispisi_listu(lista *l){
	lista *el=l->sm;
	while(el){
		cout<<el->a<<" ";
		el=el->sm;
	}
}

int main(){
	srand(time(NULL));
	lista *L;
	L=new lista;
	L->sljedeci=NULL;
	L->sm=NULL;
	L->sv=NULL;
	int n, k;
	cin>>n;
	popuni_listu(L, n);
	quick_sort(L);
	ispisi_listu(L);
	srand(time(NULL));
		
	return 0;
}
