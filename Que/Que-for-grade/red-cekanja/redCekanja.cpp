#include "queuep.h"
using namespace std;
int main(){
	queue <int> Q;
	int trajanje,pocetak=0,pom=0,x,n,zbroj=0;
	float prosjek;
	cout<<"Broj procesa: "; cin>>n;
	cout<<"Trajanje: "; cin>>trajanje;
	for(int i=0;i<n-1;i++){
		cout<<"Proces: "; cin>>x;
		Q.Enqueue(x);
	}
	cout<<"0 0 0 "<<endl;
	while(!Q.IsEmpty()){
		pocetak+=trajanje;
		cout<<Q.Front() + pom << " "<<pocetak<<" "<<pocetak - (Q.Front()+pom)<<endl;
		zbroj+=pocetak -(Q.Front()+pom);
		pom+=Q.Front();
		Q.Dequeue();
	}
	prosjek=(float)zbroj/n;
	cout<<"Prosjek "<<prosjek<<endl;
	return 0;
}