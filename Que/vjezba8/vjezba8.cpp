#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "queuep.h"
using namespace std;

void sortiranje(queue<int> &red, int n){
	for(int i=0;i<n;i++){
		int pom = red.Front();
		red.Dequeue();
		for(int j=0;j<n-i-1;j++){
			
			if(red.Front()<pom){
				red.Enqueue(pom);
				pom=red.Front();
				red.Dequeue();
			}
			else{
				red.Enqueue(red.Front());
				red.Dequeue();
			}
		}
		
		for(int k=0;k<i;k++){
			red.Enqueue(red.Front());
			red.Dequeue();
		}
		
		red.Enqueue(pom);
	}	
}

int main(){
	srand(time(0));
	queue<int> red;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int s = rand()%100+1;
		red.Enqueue(s);
	}
	
	sortiranje(red, n);
	
	for(int i=0;i<n;i++){
		cout << red.Front() << " ";
		red.Dequeue();
	}
	
	return 0;
}