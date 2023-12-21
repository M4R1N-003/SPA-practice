#include<iostream>
#include<ctime>
#include"queuep.h"
using namespace std;
int main() {
    srand(time(0));
    queue<int>red, red1;

    int n;
    cin >> n;
    int k;
    cin >> k;
    int duljina, brojac;

    for(int i=0;i<n;i++){
        int x = rand()%40;
        red.Enqueue(x);
    }

    duljina=n;
    for(int i=0;i<k;i++){
        brojac=0;
        for(int j=0;j<duljina;j++){
            if(red.Front()%k==i){
                red1.Enqueue(red.Front());
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
        cout << red1.Front() << " ";
        red1.Dequeue();
    }


    return 0;
}