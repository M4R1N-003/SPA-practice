#include <iostream>
#include <cstring>
using namespace std;

#define prostiBroj 2147483647
#define ASCII 256

int racunanjeHash(int broj, int iterator, string niz){
	broj = 0;
	for (int i = 0; i < iterator; i++) {
		broj = (ASCII * broj + niz[i]) % prostiBroj;
	}
	return broj;
}

bool rabinKarpPretraga(string uzorak, string tekst){
	bool provjera = false;	
	int M = uzorak.length();
	int N = tekst.length();
	int j, faktorPomicanja = 1;

	if(M > N){
		cout << "Uzorak koji zelite pronaci je dulji od niza u kojem ga zelite pronaci!" << endl;
		exit(EXIT_FAILURE);
	}

	int uzorakHash = racunanjeHash(uzorakHash, M, uzorak);
	int tekstHash = racunanjeHash(tekstHash, M, tekst);
	
	for (int i = 0; i < M - 1; i++)
		faktorPomicanja = (faktorPomicanja * ASCII) % prostiBroj;
		
	for (int i = 0; i <= N - M; i++) {
		if (uzorakHash == tekstHash) {
			for (j = 0; j < M; j++) {
				if (tekst[i + j] != uzorak[j])
					break;
			}
			if (j == M){
				cout << "Uzorak je pronadjen na indeksu: " << i << endl;
				provjera = true;
			}
		}
		if (i < N - M) {
			tekstHash = (ASCII * (tekstHash - tekst[i] * faktorPomicanja) + tekst[i + M]) % prostiBroj;
			if (tekstHash < 0)
				tekstHash = (tekstHash + prostiBroj);
		}
	}
	if(!provjera)
		return false;
	return true;
}

int main(){   
    string tekst;
    string uzorak;
    cout << "Unesite tekst: ";
    getline(cin, tekst);
    cout << "Unesite uzorak: ";
    getline(cin, uzorak);

    if(!rabinKarpPretraga(uzorak, tekst)){
		cout << "Uzorak nije pronadjen!" << endl;
	}
    return 0;
}
