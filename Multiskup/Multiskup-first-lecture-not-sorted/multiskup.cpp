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
    cout << "Razlika je: ";
    bagInstM.Subtract(bagInstM, bagInstN);

    cout << "Razlika 2 je: ";
    bagInstM.Subtract1(bagInstM, bagInstN);
    
    return 0;
}