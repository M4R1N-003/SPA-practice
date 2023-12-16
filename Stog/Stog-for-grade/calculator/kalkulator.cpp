#include <iostream>
#include <cstring>
#include <cmath>
#include "stackp.h"
using namespace std;
double racunaj(char op, double a, double b){
	switch(op){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '^': return pow(a,b);
	}
}
double eval(char in[],double x){
	stack <double> S;
	int L=strlen(in);
	double a,b;
	for(int i=0;i<L;i++){
		switch(in[i]){
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				b=S.Top();
				S.Pop();
				a=S.Top();
				S.Pop();
				S.Push(racunaj(in[i],a,b));
				break;
			case 'x':
				S.Push(x);
				break;
			default: 
				S.Push(in[i]-48);
		}
	}
	cout<<S.Top()<<endl;
	return S.Top();
}
int main(){
	char in[100];
	cin.getline(in,100);
	double  x;
	cin>>x;
	
	eval(in,x);
	return 0;
}
