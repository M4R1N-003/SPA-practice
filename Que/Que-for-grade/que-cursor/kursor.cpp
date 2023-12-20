#include "red-kursor.h"
using namespace std;
int main(){
	int broj,n;
	cout<<"Broj brojeva: "; cin>>n;
	red_kursori <int> Z;
	for(int i=0;i<n;i++){
		cout<<"Broj: "; cin>>broj;
		Z.Enqueue(broj);
	}
	for(int i=0;i<n;i++){
		if(Z.Front()%2==0){
			Z.Dequeue();
		}
		else{
			Z.Enqueue(Z.Front());
			Z.Dequeue();
		}
	}
	while(!Z.IsEmpty()){
		cout<<Z.Front()<<" ";
		Z.Dequeue();
	}
	return 0;
}
