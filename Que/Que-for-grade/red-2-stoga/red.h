#ifndef MAXS
#define MAXS 1000
#endif

#include <iostream>
#include <cstdlib>
#include "stacka.h"

template <typename elementtype>
class ATPQueue {
private:
    stack<elementtype> mainStack;
    stack<elementtype> auxiliaryStack;

public:
    ATPQueue() {}

    bool IsEmpty() {
        return mainStack.IsEmpty() && auxiliaryStack.IsEmpty();
    }

    void Enqueue(elementtype x) {
        mainStack.Push(x);
    }

    void Dequeue() {
        if (IsEmpty()) {
            std::cout << "Red je prazan" << std::endl;
            exit(EXIT_FAILURE);
        }

        if (auxiliaryStack.IsEmpty()) {
            while (!mainStack.IsEmpty()) {
                auxiliaryStack.Push(mainStack.Top());
                mainStack.Pop();
            }
        }

        auxiliaryStack.Pop();
    }

    elementtype Front() {
        if (IsEmpty()) {
            std::cout << "Red je prazan" << std::endl;
            exit(EXIT_FAILURE);
        }

        if (auxiliaryStack.IsEmpty()) {
            while (!mainStack.IsEmpty()) {
                auxiliaryStack.Push(mainStack.Top());
                mainStack.Pop();
            }
        }

        return auxiliaryStack.Top();
    }
};