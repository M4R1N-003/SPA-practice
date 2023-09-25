#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    int N;
    cout << "Unesite broj brojeva: ";
    cin >> N;
    int polje[N];
    srand(time(0));
    for(int i=0;i<N;i++){
        polje[i] = rand()%1000;
    }


    for(int i=0;i<N;i++){
        cout << polje[i] << " ";
    }

    for(int i=1;i<N;i++){
        int j=i-1;
        int pom = polje[i];
        while(j>=0 && polje[j]>pom){
            polje[j+1] = polje[j];
            j--;
        }
        polje[j+1] = pom;
    }

    cout << endl;

    for(int i=0;i<N;i++){
        cout << polje[i] << " ";
    }
    return 0;
}