#include <iostream>
#include "btreep.h"
#include "stacka.h"
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
    stack<Btree<int>::node> stog;
    Btree<int>::node n;
    int br, unos;
    
    cout << "N="; cin >> br;
    for(int i=0; i<br; i++){
    	cin >> unos;
    	unesi(stablo, unos);
	}

    //inorder ophodnja
    n = stablo.Root();
	
	do{
		while(n != stablo.lambda){
			stog.Push(n);
			n = stablo.LeftChild(n);
		}
		n = stog.Top();
		cout << stablo.Label(n) << " ";
		stog.Pop();
		n = stablo.RightChild(n);
		
	} while(!stog.IsEmpty() || n != stablo.lambda);    
}