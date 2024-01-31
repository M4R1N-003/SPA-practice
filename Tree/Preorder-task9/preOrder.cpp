#include <iostream>
#include "stacka.h"
#include "tree.h"
typedef int node;

using namespace std;

void printNodesWithOneChild(tree<int> T) {
    stack<int> s;
    int root = T.Root();
    s.Push(root);

    while (!s.IsEmpty()) {
        int current = s.Top();
        s.Pop();

        int count = 0;
        int child = T.FirstChild(current);

        for (child; child != T.lambda; child = T.NextSibling(child)) {
            s.Push(child);
            count++;
        }

        if (count == 1) {
            cout << "Node with one child: " << T.Label(current) << endl;
        }
    }
}

int main() {
    tree<int> stablo;
    tree<int>::node tekuci;
    int n, element;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the root: ";
    cin >> element;
    stablo.CreateRoot(element);

    for (int i = 0; i < n - 1; i++) {
        int izbor;
        tekuci = stablo.Root();

        do {
            cout << "Current node: " << stablo.Label(tekuci) << endl;
            cout << "Options: New child(0) \t Child(1) \t Sibling(2) \t Parent(3): ";
            cin >> izbor;

            if (izbor == 0) {
                cout << "Enter the new element: ";
                cin >> element;
                stablo.CreateChild(tekuci, element);
            } else if (izbor == 1) {
                tekuci = stablo.FirstChild(tekuci);
            } else if (izbor == 2) {
                tekuci = stablo.NextSibling(tekuci);
            } else if (izbor == 3) {
                tekuci = stablo.Parent(tekuci);
            }
        } while (izbor != 0);
    }

    cout << "Nodes with one child: ";
    printNodesWithOneChild(stablo);

    return 0;
}
