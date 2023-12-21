#include<iostream>
#include"queuep.h"
using namespace std;
int main(){
    srand(time(0));
    queue<int> stog, stog1;
    int brojac, duljina;
    int x, k, n;

    cout << "Unesite n: ";
    cin >> n;
    cout << "Unesite k: ";
    cin >> k;

    for(int i=0;i<n;i++){
        x=rand()%20;
        stog.Enqueue(x);
    }
    duljina=n;
    for(int i=0;i<k;i++){
        brojac=0;
        for(int j=0;j<duljina;j++){
            if(stog.Front()%k==i){
                stog1.Enqueue(stog.Front());
                stog.Dequeue();
                brojac++;
            }
            else{
                stog.Enqueue(stog.Front());
                stog.Dequeue();
            }
        }
        duljina-=brojac;
    }

    for(int i=0;i<n;i++){
        cout << stog1.Front() << " ";
        stog1.Dequeue();
    }

    return 0;
}