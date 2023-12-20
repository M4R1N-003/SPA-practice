#include "stackp.h"
#include<iostream>
using namespace std;

void merge(int arr[], int left_start, int mid, int right_end) {
    stack<int> st;
    int left = left_start;
    int right = mid + 1;

    while (left <= mid && right <= right_end) {
        if (arr[left] <= arr[right]) {
            st.Push(arr[left]);
            left++;
        } else {
            st.Push(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        st.Push(arr[left]);
        left++;
    }

    while (right <= right_end) {
        st.Push(arr[right]);
        right++;
    }

    for (int i = right_end; i >= left_start; i--) {
        arr[i] = st.Top();
        st.Pop();
    }
}

void mergeSort(int arr[], int n) {
    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}


int main() {
    int n;
    cout << "Unesite broj elemenata niza: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Unesite elemente niza: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, n);

    cout << "Sortirani niz: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
