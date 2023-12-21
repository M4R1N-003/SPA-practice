#include <iostream>
#include "stackp.h"
using namespace std;

stack<double> s1;

long long sastog(int n, int k){
	long double rezz=1;	

	for(int i=0;i<k;i++){
		s1.Push(n-i);

		long double brojnik = s1.Top();
		s1.Push(i+1);
        long double nazivnik = s1.Top();
        
        if (k > n - k) {
            k = n - k;
        }

        rezz *= (brojnik / nazivnik);
        s1.Pop();
	}
    
	return rezz;
}

long long binomniKoeficijentBezStog(int n, int k) {
    if (k > n - k) {
        k = n - k;
    }
    long long rezultat = 1;
    for (int i = 0; i < k; i++) {
        rezultat *= (n - i);
        rezultat /= (i + 1);
    }
    return rezultat;
}

int main(){
	int n, k;
	char p;
    cout << "Unesite n i k: ";
    cin >> n >> k;

    	cout << sastog(n, k) << endl;
    	cout << binomniKoeficijentBezStog(n, k) << endl;
    
	return 0;
}