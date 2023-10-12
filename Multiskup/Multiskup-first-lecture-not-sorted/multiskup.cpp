#include <iostream>
#include "Bag.h"
using namespace std;

int main(){
    
    int M[] ={1, 3, 3, 1, 2};
    int N[] ={3, 1, 3, 3};

    bag<int> bagInstM;
    bag<int> bagInstN;

    for(int i=0;i<sizeof(M)/sizeof(M[0]);i++){
        bagInstM.Insert(M[i]);
    }
 
    for(int i=0;i<sizeof(N)/sizeof(N[0]);i++){
        bagInstN.Insert(N[i]);
    }
    cout << "Unija je: ";
    bagInstM.Union(bagInstM, bagInstN);
    cout << "Presjek je: ";
    bagInstM.Intersect(bagInstM, bagInstN);

    

    
    return 0;
}