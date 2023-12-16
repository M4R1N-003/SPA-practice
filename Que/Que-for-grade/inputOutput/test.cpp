#include <iostream>
#include "queuep.h"
using namespace std;
int main(){
    queue<int> red;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int s;
        cin >> s;
        red.Enqueue(s);
    }

    for(int i=0;i<n;i++){
        cout << red.Front() << " ";
        red.Dequeue();
    }
    return 0;
}