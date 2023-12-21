#include<iostream>
#include"queuep.h"  // Assuming you have a header file for the queue implementation
using namespace std;

queue<int> myQueue, reversedQueue;

int n;

void reverseQueue() {
    // Move elements from myQueue to reversedQueue
    for (int i = 0; i < n; i++) {
        reversedQueue.Enqueue(myQueue.Front());
        myQueue.Dequeue();
    }

    // Reverse the order of elements in reversedQueue
    for (int i = 0; i < n; i++) {
        myQueue.Enqueue(reversedQueue.Front());
        reversedQueue.Dequeue();
    }
}

int main() {
    cout << "Unesi broj brojeva: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        myQueue.Enqueue(s);
    }

    reverseQueue();

    cout << "Originalni red: ";
    while (!myQueue.IsEmpty()) {
        cout << myQueue.Front() << " ";
        myQueue.Dequeue();
    }
    cout << endl;

    cout << "Obrnuti red: ";
    while (!reversedQueue.IsEmpty()) {
        cout << reversedQueue.Front() << " ";
        reversedQueue.Dequeue();
    }
    cout << endl;

    return 0;
}
