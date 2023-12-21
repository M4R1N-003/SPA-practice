#include<iostream>
#include<ctime>
#include "queuep.h"
using namespace std;
int main(){
    srand(time(0));
    queue<int> red, red2;
    int n, k, x;

    int brojac, duljina;
    cout << "Unesite n: ";
    cin >> n;
    cout << "Unesite k: ";
    cin >> k;

    duljina = n;

    for(int i=0;i<n;i++){
        x=rand()%100;
        red.Enqueue(x);
    }

    for(int i=0;i<k;i++){
        brojac=0;
        for(int j=0;j<duljina;j++){
            if(red.Front()%k==i){
                red2.Enqueue(red.Front());
                red.Dequeue();
                brojac++;
            }
            else{
                red.Enqueue(red.Front());
                red.Dequeue();
            }
        }
        duljina-=brojac;
    }

    for(int i=0;i<n;i++){
        cout << red2.Front() << " ";
        red2.Dequeue();
    }

    return 0;
}