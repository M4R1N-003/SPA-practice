#include <iostream>
#include "btreep.h"

using namespace std;

int count = 0;

void setNodeChild(Btree<char>& tree, Btree<char>::node node) {
    if (count < 1) return;
    char left_char, right_char;
    cout << "Enter left child of " << tree.Label(node) << " (Y/N): ";
    cin >> left_char;
    cout << "/count/" << count << "\n";
    if ((left_char == 'Y' || left_char == 'y') && count > 0) {
        --count;
        char temp;
        cout << "Enter value for left child: ";
        cin >> temp;
        tree.CreateLeftChild(node, temp);
        setNodeChild(tree, tree.LeftChild(node));
    }
    if (count < 1) return;

    cout << "Enter right child of " << tree.Label(node) << " (Y/N): ";
    cin >> right_char;
    if ((right_char == 'Y' || right_char == 'y') && count > 0) {
        --count;
        char temp;
        cout << "Enter value for right child: ";
        cin >> temp;
        tree.CreateRightChild(node, temp);
        setNodeChild(tree, tree.RightChild(node));
    }
}

int height(Btree<char>& tree, Btree<char>::node node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(tree, tree.LeftChild(node));
        int rheight = height(tree, tree.RightChild(node));

        if (lheight > rheight) {
            return (lheight + 1);
        } else {
            return (rheight + 1);
        }
    }
}

void printCurrentLevel(Btree<char>& tree, Btree<char>::node root, int level, int max) {
    if (root == NULL || level == 0) {
        for (int i = 0; i < max * 3; i++)
            cout << " ";
        return;
    }

    if (level == 1) {
        cout << "   " << tree.Label(root);
        for (int i = 0; i < max * 3; i++)
            cout << " ";
    } else if (level > 1) {
        printCurrentLevel(tree, tree.LeftChild(root), level - 1, max);
        printCurrentLevel(tree, tree.RightChild(root), level - 1, max);

        for (int i = 0; i < max * 3; i++)
            cout << " ";
    }
}

int main() {
    Btree<char> stablo;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    count = n - 1;

    char label;
    cout << "Enter the value for the root: ";
    cin >> label;
    stablo.CreateRoot(label);

    setNodeChild(stablo, stablo.Root());

    int h = height(stablo, stablo.Root());

    for (int i = 0; i < h+1; i++) {
        for (int j = 2*(h - i - 2); j >= 0; j--)
            cout << " ";
        printCurrentLevel(stablo, stablo.Root(), i, h - i);
        cout << "\n";
        for (int j = 2*(h - i - 2); j >= 0; j--)
            cout << " ";
    }

    cout << endl;
    system("pause");
    return 0;
}