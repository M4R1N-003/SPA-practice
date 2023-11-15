#include <iostream>

using namespace std;

	struct tlista{
		int broj;
		tlista *sljedeci;
	};
	
tlista *lista;
int broj;
void dodaj(tlista *lista){
	tlista *novi, *zadnji;
	zadnji=lista;
	while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
	novi=new tlista;
	zadnji->sljedeci=novi;
	novi->sljedeci=NULL;
	cout<<"Unesite broj: "; cin>>novi->broj;
}

void ispis(tlista *lista){
	tlista *tekuci=lista->sljedeci;
		while(tekuci->sljedeci!=NULL){
			cout<<tekuci->broj<<"  ";
			tekuci=tekuci->sljedeci;
		}
	}

void podijeli(tlista *izvor, tlista **prednja, tlista **straznja);
tlista *SortSpajanje(tlista *a,tlista *b);
	void sortiranje(tlista **ref_glava){
		tlista* glava=*ref_glava;
		tlista* a;
		tlista* b;
		
		if((glava==NULL) || (glava->sljedeci == NULL)){
			return;
		}
		
		podijeli(glava, &a,&b);
		sortiranje(&a);
		sortiranje(&b);
		*ref_glava = SortSpajanje(a,b);
}

tlista *SortSpajanje(tlista *a,tlista *b){
	tlista *rezultat=NULL;
	
	if(a==NULL) return(b);
	else if(b==NULL) return(a);
	
	if(a->broj <= b->broj){
		rezultat=a;
		rezultat->sljedeci=SortSpajanje(a->sljedeci,b);
	}
	else{
		rezultat = b;
		rezultat->sljedeci=SortSpajanje(a,b->sljedeci);
	}
	return(rezultat);
}

void podijeli(tlista *izvor,tlista **prednja,tlista **straznja){
	tlista *brza;
	tlista *sporija;
	if(izvor==NULL || izvor->sljedeci==NULL){
		*prednja=izvor;
		*straznja=NULL;
	}
	else{
		sporija=izvor;
		brza = izvor->sljedeci;

		while(brza != NULL){
			brza = brza->sljedeci;
			if(brza != NULL){
				sporija = sporija->sljedeci;
				brza = brza->sljedeci;
			}
		}		
		*prednja = izvor;	
		*straznja = sporija->sljedeci;
		sporija->sljedeci = NULL;
	}
}

int main(){
	lista=new tlista;
	lista->sljedeci=NULL;
	char dalje;
	do{

		dodaj(lista);	
		cout<<"Jos dodavati? ";
		cin>>dalje;
	}while(dalje=='d');
	sortiranje(&lista);
	ispis(lista);
return 0;
}
