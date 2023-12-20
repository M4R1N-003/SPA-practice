#include "stackp.h"
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char ulaz[100];
	cin.getline(ulaz,100);
	stack <char> K;
	for(int i=0;i<strlen(ulaz);i++){
		if(ulaz[i]=='(' || ulaz[i]=='[' || ulaz[i]=='{'){
			K.Push(ulaz[i]);
		}
		else if(ulaz[i]==')'){
			if(K.Top()=='(') K.Pop();
			else {
				cout<<"false"<<endl;
				return 0;
			}
		}

		else if(ulaz[i]==']'){
			if(K.Top()=='[') K.Pop();
			else{
				cout<<"false"<<endl;
				return 0;
			}
		}
        
		else if(ulaz[i]=='}'){
			if(K.Top()=='{') K.Pop();
			else{
				cout<<"false"<<endl;
				return 0;
			}
		}
	}
	if(!K.IsEmpty()){
		cout<<"false"<<endl;
	}
	else cout<<"true"<<endl;
	return 0;
}