#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "listp.h"
using namespace std;
	int n;

	void doubleBubbleSort(list<int> &L){
		list<int>::element e;

		for(int i=0;i<n;i++){
			if(i%2==0){
				e=L.Previous(L.End());
				for(int j=n-i;j>1;j--){
					if(L.Retrieve(e)<L.Retrieve(L.Previous(e))){
						int pom=L.Retrieve(e);
						L.ChangeValue(e,L.Retrieve(L.Previous(e)));
						L.ChangeValue(L.Previous(e),pom);
					}
					e=L.Previous(e);
				}
			}
			else{
				e=L.First();
				for(int j=0;j<n-1;j++){
					if(L.Retrieve(e)>L.Retrieve(L.Next(e))){
						int pom1=L.Retrieve(e);
						L.ChangeValue(e,L.Retrieve(L.Next(e)));
						L.ChangeValue(L.Next(e),pom1);
					}
					e=L.Next(e);
				}
			}
		}

	}

int main(){
	list<int> L;
	list<int>::element e1, pom, pom1; 
	srand(time(0));
	int broj;

	cout<<"N = "; 
	
	cin>>n;
	e1=L.First();
	for(int i=0;i<n;i++){
		broj=rand()%20+1;
		L.Insert(e1,broj);
		e1=L.Next(e1);
	}

	e1 = L.First();
	for(int i=0;i<n;i++){
		cout << L.Retrieve(e1) << " ";
		e1=L.Next(e1);
	}

	doubleBubbleSort(L);

	cout << endl;

	e1 = L.First();
	for(int i=0;i<n;i++){
		cout << L.Retrieve(e1) << " ";
		e1=L.Next(e1);
	}
	
	return 0;
}
