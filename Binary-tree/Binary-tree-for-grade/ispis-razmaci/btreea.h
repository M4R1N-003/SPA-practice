#ifndef MAXB
#define MAXB 1000
#endif

#include <iostream>
#include <cstdlib>

template <typename nodetype>
class btree {
private:
struct elem {
       nodetype label;
       bool used;
};

elem B[MAXB+1];

public:
typedef int node;
const node lambda = 0;

btree(nodetype x) {
     B[1].label = x;
     B[1].used = true;
     for (int i = 2; i <= MAXB; i++)
         B[i].used = false;
}

btree() {
     for (int i = 1; i <= MAXB; i++)
         B[i].used = false;
}

bool IsEmpty() {
     return !B[1].used;
}

node Label(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         return B[n].label;
}

node Root() {
     return B[1].used ? 1 : lambda;
}

node Parent(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         return n/2;
}

node LeftChild(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         if (2*n <= MAXB && B[2*n].used)
            return 2*n;
         else
             return lambda;
}

node RightChild(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         if (2*n+1 <= MAXB && B[2*n+1].used)
            return 2*n+1;
         else
             return lambda;
}

void ChangeLabel(node n, nodetype x) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         B[n].label = x; 
}

void CreateRoot(nodetype x) {
     if (B[1].used) {
        std::cout << "Stablo nije prazno"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          B[1].used = true;
          B[1].label = x;
     }
}

void CreateLeftChild(node n, nodetype x) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         if (2*n > MAXB) {
            std::cout << "Cvor je izvan dosega"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else 
             if (B[2*n].used) {
                std::cout << "Cvor vec ima "
                          << "lijevo dijete"
                          << std::endl;
                exit(EXIT_FAILURE);
             }
             else {
                  B[2*n].used = true;
                  B[2*n].label = x;
             } 
}

void CreateRightChild(node n, nodetype x) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor "
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         if (2*n+1 > MAXB) {
            std::cout << "Cvor je izvan dosega"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else 
             if (B[2*n+1].used) {
                std::cout << "Cvor vec ima " 
                          << "desno dijete"
                          << std::endl;
                exit(EXIT_FAILURE);
             }
             else {
                  B[2*n+1].used = true;
                  B[2*n+1].label = x;
             } 
}

private:
void Del(node n) {
     if (2*n <= MAXB && B[2*n].used)
        Del(2*n);
     if (2*n+1 <= MAXB && B[2*n+1].used)
        Del(2*n+1); 
     B[n].used = false;
}

public:
void Delete(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         Del(n);
}
};



