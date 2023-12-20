#include <iostream>
#include "red.h"

int main() {
    int n;
    std::cout << "Unesite prirodni broj n: ";
    std::cin >> n;

    ATPQueue<int> myQueue;
    int broj;
    std::cout << "Unesite " << n << " cijelih brojeva u red:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> broj;
        myQueue.Enqueue(broj);
    }

    ATPQueue<int> filteredQueue;
    while (!myQueue.IsEmpty()) {
        int element = myQueue.Front();
        myQueue.Dequeue();

        if (element % 2 != 0) {
            filteredQueue.Enqueue(element);
        }
    }

    std::cout << "Neparni brojevi u filtriranom redu su:" << std::endl;
    while (!filteredQueue.IsEmpty()) {
        std::cout << filteredQueue.Front() << " ";
        filteredQueue.Dequeue();
    }

    return 0;
}