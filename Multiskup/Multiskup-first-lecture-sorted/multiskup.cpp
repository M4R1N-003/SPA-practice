#include <iostream>
#include "Bag1.h"
using namespace std;

int main(){
    
    int M[] ={1, 3, 3, 1, 2};
    int N[] ={3, 1, 3, 3};

    for(int i=(sizeof(M)/sizeof(M[0]))-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(M[j]>M[i]){
                int temp = M[j];
                M[j]=M[i];
                M[i]=temp;
            }
        }
    }

    for(int i=(sizeof(N)/sizeof(N[0]))-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(N[j]>N[i]){
                int temp = N[j];
                N[j]=N[i];
                N[i]=temp;
            }
        }
    }

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

    

    
    return 0;
}