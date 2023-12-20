#include <iostream>
#include "stackp.h"
using namespace std;

int count = 0;
stack<double> brojStog;
stack<char> operacijaStog;
stack<double> tempBrojStog;
stack<char> tempOperacijaStog;

void razvrstaj(){
    while (!brojStog.IsEmpty()) {
        int x = brojStog.Top();
        brojStog.Pop();
        tempBrojStog.Push(x);
    }
    while (!operacijaStog.IsEmpty()) {
        char x = operacijaStog.Top();
        operacijaStog.Pop();
        tempOperacijaStog.Push(x);
        count++;
    }
}

void unosFunkcija(char unos[]){
	int trenutniBroj = 0;
    bool citanjeBroja = false;
    for (int i = 0; unos[i] != '\0'; i++) {
        if (unos[i] >= '0' && unos[i] <= '9') {
            trenutniBroj = trenutniBroj * 10 + (unos[i] - '0');
            citanjeBroja = true;
        } 
		else {
            if (citanjeBroja) {
                brojStog.Push(trenutniBroj);
                trenutniBroj = 0;
                citanjeBroja = false;
            }

            if (unos[i] == '+' || unos[i] == '-' || unos[i] == '*' || unos[i] == '/') {
                operacijaStog.Push(unos[i]);
            } 
        }
    }
    if (citanjeBroja) {
        brojStog.Push(trenutniBroj);
    }
}

int undo(int n){
	razvrstaj();
	int trenutniBroj = tempBrojStog.Top();
    tempBrojStog.Pop();
    for(int i=0; i<count-n; i++){
    	double broj = tempBrojStog.Top();
    	tempBrojStog.Pop();
    	switch (tempOperacijaStog.Top()) {
        	case '+': trenutniBroj += broj; break;
        	case '-': trenutniBroj -= broj; break;
        	case '*': trenutniBroj *= broj; break;
        	case '/': trenutniBroj /= broj; break;
    	}
    	tempOperacijaStog.Pop();
    }
    return trenutniBroj;
}

int main() {
	cout<<"Unos izraza: ";
    char unos[256];
    cin.getline(unos, 256);
    unosFunkcija(unos);
    
    cout<<"undo: ";
    int n;
    cin>>n;
	cout<<endl<<undo(n);
    return 0;
}