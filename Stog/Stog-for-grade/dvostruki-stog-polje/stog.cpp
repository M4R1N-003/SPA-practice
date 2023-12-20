#include "double-stog.h"
using namespace std;
int main(){
	stog_polje<int> A,B;
	int n,broj;
	cout<<"n = :"; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Broj: "; cin>>broj;
		A.Push(0,broj);
	}
	for(int i=0;i<n;i++){
		B.Push(1,A.Top(0));
		A.Pop(0);
	}
	while(!B.IsEmpty(1)){
		cout<<B.Top(1)<<" ";
		B.Pop(1);
	}
	return 0;
}