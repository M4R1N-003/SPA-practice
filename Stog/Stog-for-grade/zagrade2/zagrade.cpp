#include "stackp.h"
#include <cstring>

using namespace std;

int main(){
	stack<char> S;
	
	string izraz;
	cout << "Izraz: ";
	cin >> izraz;
	
	int	n = izraz.length();
	
	for(int i=0; i<n; i++){
		S.Push(izraz[i]);
	}
	
	int oble = 0, uglate = 0, viticaste = 0;
	
	bool greska = false;
	
	while(!S.IsEmpty()){
		switch(S.Top()){
			case '(':{
				oble++;
				break;
			}
			case ')':{
				oble--;
				break;
			}
			case '[':{
				uglate++;
				if(oble) greska = true;
				break;
			}
			case ']':{
				uglate--;
				if(oble) greska = true;
				break;
			}
			case '{':{
				viticaste++;
				if(oble || uglate) greska = true;
				break;
			}
			case '}':{
				viticaste--;
				if(oble || uglate) greska = true;
				break;
			}
		}
		S.Pop();
	}
	
	if(!oble && !uglate && !viticaste && !greska){
		cout << "true" << endl;
	}else{
		cout << "false" << endl;
	}
	
	return 0;
}
