#include <iostream>
#include <vector>

// Vaša implementacija općenitog stabla
#include "vasa_implementacija_stabla.h"

template <typename nodetype>
bool hasNodeWithValue(tree<nodetype>& T, nodetype x) {
    typename tree<nodetype>::node n = T.Root();

    if (T.IsEmpty()) {
        return false;
    }

    // Prolazi kroz sve čvorove stabla koristeći DFS
    while (n != T.lambda) {
        if (T.Label(n) == x) {
            return true;
        }

        // Idi na prvo dijete čvora
        typename tree<nodetype>::node child = T.FirstChild(n);
        while (child != T.lambda) {
            if (hasNodeWithValue(T, child, x)) {
                return true;
            }
            // Idi na sljedeće dijete
            child = T.NextSibling(child);
        }

        // Idi na sljedeći čvor na istoj razini
        n = T.NextSibling(n);
    }

    return false;
}

template <typename nodetype>
bool hasNodeWithValue(tree<nodetype>& T, typename tree<nodetype>::node n, nodetype x) {
    if (n == T.lambda) {
        return false;
    }

    // Prolazi kroz sve čvorove podstablo koristeći DFS
    if (T.Label(n) == x) {
        return true;
    }

    // Idi na prvo dijete čvora
    typename tree<nodetype>::node child = T.FirstChild(n);
    while (child != T.lambda) {
        if (hasNodeWithValue(T, child, x)) {
            return true;
        }
        // Idi na sljedeće dijete
        child = T.NextSibling(child);
    }

    return false;
}

int main() {
    // Kreiranje općenitog stabla
    tree<int> T(1);
    T.CreateChild(0, 2);
    T.CreateChild(0, 3);s
    T.CreateChild(1, 4);
    T.CreateChild(1, 5);
    T.CreateChild(2, 6);

    // Testiranje funkcije
    int valueToFind = 4;
    if (hasNodeWithValue(T, valueToFind)) {
        std::cout << "Stablo sadrži čvor s vrijednošću " << valueToFind << std::endl;
    } else {
        std::cout << "Stablo ne sadrži čvor s vrijednošću " << valueToFind << std::endl;
    }

    return 0;
}
