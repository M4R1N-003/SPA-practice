#ifndef MAXS
#define MAXS 1000
#endif

#include <iostream>
#include <cstdlib>

template <typename elementtype>
class stack {
private:
elementtype el[MAXS];
int top;

public:
stack() {
     top = MAXS - 1;
}

bool IsEmpty() {
     return top == MAXS - 1;
}

elementtype Top() {
            if (top == MAXS-1) {
               std::cout << "Stog je prazan"  
                         << std::endl;
               exit(EXIT_FAILURE); 
            }
            else
                 return el[top+1];
}

void Push(elementtype x) {
     if (top == -1) {
        std::cout << "Stog je prepunjen"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
          el[top--] = x;
}

void Pop() {
     if (top == MAXS-1) {
        std::cout << "Stog je prazan" 
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         top++;
}
};

