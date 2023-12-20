#include "queuea.h"
#include <ctime>
#include <iostream>
using namespace std;

void println(queue<int> &q, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << q.Front() << ' ';
        q.Enqueue(q.Front());
        q.Dequeue();
    }
    cout << endl;
}

void order(queue<int> &red, int n, int K)
{
    unsigned short i, j, del;
    queue<int> que;
    for (i = 0; i < K; i++)
    {
        del = 0;
        for (j = 0; j < n; j++)
        {
            if (red.Front() % K == i)
            {
                que.Enqueue(red.Front());
                del++;
            }
            else
                red.Enqueue(red.Front());
            red.Dequeue();
        }
        n = n - del;
    }

    while (not que.IsEmpty())
    {
        red.Enqueue(que.Front());
        que.Dequeue();
    }
}

int main()
{
    queue<int> red;
    int K, n, i;

    cout << "Velicina: ";
    cin >> n;

    cout << "K: ";
    cin >> K;

    srand(time(0));
    for (i = 0; i < n; i++){
        red.Enqueue(rand() % 100 + 1);
    }

    cout << "Prvotni red: ";
    println(red, n);

    order(red, n, K);

    cout << "Ispremjestani red: ";
    println(red, n);

    return 0;
}