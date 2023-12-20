#include <iostream>
#include "stackm.h"
#include <ctime>
using namespace std;
int main(){
    stack<int> stog;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int s=rand()%100;
        stog.Gurni(s);
    }

    for(int i=0;i<n;i++){
        cout << stog.Vrh() << " ";
        stog.Odvuci();
    }

    return 0;
};