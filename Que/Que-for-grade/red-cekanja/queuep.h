#include <iostream>
#include <cstdlib>

template <typename elementtype>
class queue {
private:
struct que {
       elementtype val;
       que *next;
};

que *front, *rear; 

public:
queue() {
     que *p = new que;
     (*p).next = NULL;
     front = rear = p;
}


bool IsEmpty() {
     return front == rear;
}

elementtype Front() {
            if (front == rear) {
               std::cout << "Red je prazan"
                         << std::endl;
               exit(EXIT_FAILURE);
            }
            else
                return (*(*front).next).val;
}

void Enqueue(elementtype x) {
     que *p = new que;
     (*p).val = x;
     (*p).next = NULL;
     (*rear).next = p;
     rear = p;
}

void Dequeue() {
     if (rear == front) {
        std::cout << "Red je prazan"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          que *p = front;
          front = (*front).next;
          delete p;
     }
}

~queue() {
      while (front != NULL) {
            que *p = front;
            front = (*front).next;
            delete p;
      }
}
};

