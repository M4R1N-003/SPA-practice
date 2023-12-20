#include "stacka.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    unsigned int size, i;
    double in;
    cout << "Broj brojeva: ";
    cin >> size;

    stack<double>s;
    stack<double>tmp;

    cout << "Unesite brojeve: ";
    for (i = 0; i < size; ++i){
        cin >> in;
        s.Push(in);
    }

    for (i = 0; i < size; ++i){
        tmp.Push(s.Top());
        s.Pop();
    }

    s = tmp;

    cout << "Obrnuti stog: ";
    for (i = 0; i < size; ++i){
        cout << s.Top() << ' ';
        s.Pop();
    }
    cout << endl;
    
    return 0;
}