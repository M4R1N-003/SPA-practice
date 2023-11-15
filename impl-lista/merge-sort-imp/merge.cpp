#include <iostream>
#include "listp.h"

using namespace std;

// Function to merge two sorted lists
typename list<int>::element merge(list<int>::element left, list<int>::element right) {
    list<int> mergedList;
    list<int>::element mergedIndex = mergedList.First();

    while (left != mergedList.lambda && right != mergedList.lambda) {
        if (mergedList.Retrieve(left) < mergedList.Retrieve(right)) {
            mergedList.Insert(mergedIndex, mergedList.Retrieve(left));
            left = mergedList.Next(left);
        } else {
            mergedList.Insert(mergedIndex, mergedList.Retrieve(right));
            right = mergedList.Next(right);
        }
        mergedIndex = mergedList.Next(mergedIndex);
    }

    // Append the remaining elements from left and right lists
    while (left != mergedList.lambda) {
        mergedList.Insert(mergedIndex, mergedList.Retrieve(left));
        left = mergedList.Next(left);
        mergedIndex = mergedList.Next(mergedIndex);
    }

    while (right != mergedList.lambda) {
        mergedList.Insert(mergedIndex, mergedList.Retrieve(right));
        right = mergedList.Next(right);
        mergedIndex = mergedList.Next(mergedIndex);
    }

    return mergedList.First();
}

// Merge sort function for the linked list
list<int>::element mergeSort(list<int>::element head) {
    if (head == NULL || head == head->next) {
        return head;
    }

    list<int>::element middle = head;
    list<int>::element fast = head->next;

    // Use fast and slow pointers to find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        middle = middle->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    list<int>::element left = head;
    list<int>::element right = middle->next;
    middle->next = NULL;

    // Recursively sort the two halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    return merge(left, right);
}

int main() {
    int n, a;
    list<int> lista;
    list<int>::element index = lista.First();

    cout << "unesi broj: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". broj: ";
        cin >> a;
        lista.Insert(index, a);
        index = lista.Next(index);
    }

    cout << endl;
    list<int>::element index2 = lista.First();
    // Perform merge sort
    index2 = mergeSort(lista.First());

    // Print the sorted lista
    
    for (int i = 0; i < n; i++) {
        cout << lista.Retrieve(index2) << " ";
        index2 = lista.Next(index2);
    }

    return 0;
}
