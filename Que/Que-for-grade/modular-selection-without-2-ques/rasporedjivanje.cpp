#include<iostream>
#include<ctime>
#include"queuep.h"

using namespace std;

int main(){
	srand(time(0));

	queue<int> A, B;
	
	int n,k,x;
	int brojac, duljina;
	
	cout<<"Unesi broj n: "; cin>>n;
	cout<<"Unesi broj k: "; cin>>k;

	for(int i=0; i<n; i++){
		x=rand()%100+1;
		A.Enqueue(x);
	}
	
	duljina=n;
	
	for(int i=0; i<k; i++){
		brojac=0;
		for(int j=0; j<duljina; j++){
			if(A.Front()%k==i){
				B.Enqueue(A.Front());
				brojac++;
				A.Dequeue();
			}
			else{
				A.Enqueue(A.Front());
				A.Dequeue();
			}
		}
		duljina-=brojac;
	}
	
    cout << endl;
	for(int i=0; i<n; i++){
		cout << B.Front() << " ";
		B.Dequeue();
	}

	return 0;
}