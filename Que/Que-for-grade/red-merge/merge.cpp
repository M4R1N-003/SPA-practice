#include <iostream>
#include "queuep.h"
using namespace std;

void naturalMergeSort(int *arr, int n) {
    queue<int> q1, q2;

    for (int i = 0; i < n; i++) {
        if (!q1.IsEmpty() && arr[i] < q1.Front()) {
            while (!q1.IsEmpty() && arr[i] < q1.Front()) {
                q2.Enqueue(q1.Front());
                q1.Dequeue();
            }
        }
        q1.Enqueue(arr[i]);
    }

    while (!q1.IsEmpty()) {
        q2.Enqueue(q1.Front());
        q1.Dequeue();
    }

    int i = 0;
    while (!q2.IsEmpty()) {
        arr[i++] = q2.Front();
        q2.Dequeue();
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Nesortirano polje: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    naturalMergeSort(arr, n);

    cout << "Sortirano polje: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
