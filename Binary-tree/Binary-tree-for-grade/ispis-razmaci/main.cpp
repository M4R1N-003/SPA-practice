#include "Stablo_polje.h"
#include "reda.h"
#include <iostream>
#include <cmath>
using namespace std;
 
Btree<char> T;
int visina;

int height(Btree<char>::node n) {	
	if (n == T.lambda) 
		return 0;
	return max(height(T.LeftChild(n)), height(T.RightChild(n))) + 1;
}

void ispis(Btree<char>::node root) {
    if (root == T.lambda) {
        return;
    }

	Queue<Btree<char>::node> q;
	q.Enqueue(root);
	int velicina=1;
    while (!q.IsEmpty()) {
        int size = velicina;

        for (int i = 0; i < size; i++) {
            Btree<char>::node current = q.Front();
            q.Dequeue();
            velicina--;

            for (int i = 0; i < visina * 2; i++) {
	            cout << " ";
	        }
            cout << T.Label(current);

			
            if (T.LeftChild(current) != T.lambda) {
            	q.Enqueue(T.LeftChild(current));
                velicina++;
			}
            if (T.RightChild(current) != T.lambda) {
                q.Enqueue(T.RightChild(current));
                velicina++;
			}
        }
    	visina --;
        cout << endl;
    }
}

 
int main()
{
	Btree<char>::node n;
	T.CreateRoot('4');
	n = T.Root();
	T.CreateLeftChild(n, '7');
	T.CreateRightChild(n, '6');
	
	n = T.LeftChild(n);
	T.CreateLeftChild(n, '2');
	T.CreateRightChild(n, '8');
	n = T.LeftChild(n);
	T.CreateRightChild(n, '3');
	T.CreateLeftChild(n, '2');
	n = T.Parent(n);
	n = T.RightChild(n);
	T.CreateLeftChild(n,'1');
	
	n = T.Root();
	n = T.RightChild(n);
	T.CreateLeftChild(n, '5');
	n = T.LeftChild(n);
	T.CreateRightChild(n, '2');
	T.CreateLeftChild(n, '9');
	
	visina = height(T.Root());
	ispis(T.Root());

 
    return 0;
}