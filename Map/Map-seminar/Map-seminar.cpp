
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;
	struct Studenti{
		int maticni_broj;
		char prez_ime[50];
		int god_u;
	};
	map<int, Studenti>mapaMarin;
	
	void Ispunjavanje(Studenti *dinpolje, int n){
	srand(time(0));
	char svaSlova[]="abcdefghijklmnoprstquvwxyzABCDEFGHIJKLMNOPRSTQUVWXYZ";
	for(int i=0;i<n;i++){
		dinpolje[i].maticni_broj=rand()%100;
		dinpolje[i].god_u=rand()%100;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<50;j++){
		dinpolje[i].prez_ime[j]=svaSlova[rand()%51];
			}
		}
	}
	
	void Unos(Studenti *dinpolje, int n){
	int brojac=0;
	for(int i=0;i<n;i++){
	cout<<"Unesite maticni broj: ";
	cin>>dinpolje[i].maticni_broj;
	cin.ignore();
	cout<<"Unesite prezime i ime: ";
	cin.getline(dinpolje[i].prez_ime,50);
	cout<<"Unesite godinu upisa: ";
	cin>>dinpolje[i].god_u;
	brojac++;
	}
	if(brojac==n)cout<<"Popunili ste cijelo polje"<<endl;
	}
	
	void kopiranje(Studenti *dinpolje, int n){
	for(int i=0;i<n;i++){
	mapaMarin[i]=dinpolje[i];
	}
	cout<<"Kopirano!"<<endl;
	}
	void ispis(int n){
	for(map<int, Studenti>::iterator i=mapaMarin.begin();i!=mapaMarin.end();++i){
		cout<<"================================"<<endl;
		cout<<"Maticni broj je: "<<i->second.maticni_broj<<endl;
		cout<<"Prezime i ime je: "<<i->second.prez_ime<<endl;
		cout<<"Godina upisa je: "<<i->second.god_u<<endl;
		cout<<"================================"<<endl;
	}
	}
	void Pretrazivanje(int provjera){
	bool test=false;
		for(map<int, Studenti>::iterator i=mapaMarin.begin();i!=mapaMarin.end();++i){
			if(i->second.maticni_broj==provjera){
			test=true;
			cout<<"+++++++++++++++++++++++++++++"<<endl;
			cout<<"Maticni broj je: "<<i->second.maticni_broj<<endl;
			cout<<"Prezime i ime je: "<<i->second.prez_ime<<endl;
			cout<<"Godina upisa je: "<<i->second.god_u<<endl;
			cout<<"+++++++++++++++++++++++++++++"<<endl;
			}
		}
		if(test==false)cout<<"Zapis nije pronadjen"<<endl;
	}
	
int main(){
	int biranje;
	int N;
	cout<<"###########################"<<endl;
	cout<<"Unesite broj elemenata: ";
	cin>>N;
	cout<<"###########################"<<endl;
	cout<<endl;
	Studenti *dinpolje=new Studenti[N];
	do{
	cout<<endl;
	cout<<"1-Ispuniti dinamicko polje slucajnim vrijednostima"<<endl;
	cout<<"2-Rucni unos u dinamicko polje"<<endl;
	cout<<"3-Isprazniti polje, kopirati u mapu"<<endl;
	cout<<"4-Ispis iz asocijativnog polja"<<endl;
	cout<<"5-Pretrazivanje asocijativnog polja"<<endl;
	cout<<endl;
	cout<<"Unesite odabir: ";
	cin>>biranje;
	switch(biranje){
	case 1:
	Ispunjavanje(dinpolje, N);
	break;
	case 2:
	Unos(dinpolje,N);
	break;
	case 3:
	kopiranje(dinpolje, N);
	break;
	case 4:
	ispis(N);
	break;
	case 5:
	int pretrazi;
	cout<<"Unesite broj za pretrazivanje: ";
	cin>>pretrazi;
	Pretrazivanje(pretrazi);
	break;
	case 0:cout<<"Kraj!"<<endl;break;
	default:cout<<"Unesite ponovno!"<<endl;
	}
	}while(biranje!=0);
	system("PAUSE");
}