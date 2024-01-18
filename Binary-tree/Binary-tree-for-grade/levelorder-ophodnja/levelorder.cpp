#include <iostream>
#include "btreep.h"
#include "queuea.h"
using namespace std;

void unesi(Btree<int> &stablo, int broj){
	Btree<int>::node trenutni, roditelj;
	
	if(stablo.Root() == NULL){
		stablo.CreateRoot(broj);
		return;
	}
	
	trenutni = stablo.Root();
	while(true){
		roditelj = trenutni;
		if (stablo.LeftChild(roditelj) == stablo.lambda){
			stablo.CreateLeftChild(roditelj, broj);
			break;
		}
		else if (stablo.RightChild(roditelj) == stablo.lambda){
			stablo.CreateRightChild(roditelj, broj);
			break;
		}
		else {
			trenutni = stablo.LeftChild(trenutni);
		}
	}
}

int main(){
	Btree<int> stablo;
	Btree<int>::node n;
	queue<Btree<int>::node> red;
	int br, unos;
	
	cout << "N="; cin >> br;
	for(int i=0; i<br; i++){
		cin >> unos;
		unesi(stablo, unos);
	}
	
	
//	//ispunjavanje stabla
//    stablo.CreateRoot(4);
//    n = stablo.Root();
//    stablo.CreateLeftChild(n, 7);
//    stablo.CreateRightChild(n, 6);
//
//    n = stablo.RightChild(n);
//    stablo.CreateLeftChild(n, 5);
//    n = stablo.LeftChild(n);
//    stablo.CreateLeftChild(n, 9);
//    stablo.CreateRightChild(n, 2);
//
//    n = stablo.Root();
//    n = stablo.LeftChild(n);
//    stablo.CreateLeftChild(n, 2);
//    stablo.CreateRightChild(n, 8);
//    n = stablo.LeftChild(n);
//    stablo.CreateRightChild(n, 3);
//    n = stablo.Parent(n);
//    n = stablo.RightChild(n);
//    stablo.CreateLeftChild(n, 1);
    
    //levelorder ophodnja
    n = stablo.Root();
    red.Enqueue(n);
    
    while(!red.IsEmpty()){
    	n = red.Front();
    	red.Dequeue();
    	cout<<stablo.Label(n)<<" ";
    	
    	if(stablo.LeftChild(n) != stablo.lambda)
    		red.Enqueue(stablo.LeftChild(n));
    		
    	if(stablo.RightChild(n) != stablo.lambda)
    		red.Enqueue(stablo.RightChild(n));
	}
}