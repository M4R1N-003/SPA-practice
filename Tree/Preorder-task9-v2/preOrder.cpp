#include<iostream>
#include"stacka.h"
#include "tree.h"
typedef int node;

using namespace std;

void printCvora(tree<int> &drvo){
    stack<int> s;
    int korijen = drvo.Root();
    s.Push(korijen);

    while(!s.IsEmpty()){
        int trenutni = s.Top();
        s.Pop();
        int brojac=0;
        int dijete = drvo.FirstChild(trenutni);
        for(dijete;dijete!=drvo.lambda;dijete=drvo.NextSibling(dijete)){
            s.Push(dijete);
            brojac++;
        }
        if(brojac==1){
            cout << "Cvor sa jednim djetetom je: " << drvo.Label(trenutni);
        }

    }
}

int main(){
    tree<int> drvo;
    tree<int>::node tekuci;
    int n, element;

    cout << "Unesite broj elemenata: ";
    cin >> n;
    cout << "Unesite korijen: ";
    cin >> element;
    drvo.CreateRoot(element);

    for(int i=0;i<n-1;i++){
        int biranje;
        tekuci=drvo.Root();

        do{
            cout <<"Trenutni cvor je " << drvo.Label(tekuci) << endl;
            cout << "Option: Novo dijete(0), Dijete(1), Blizanac(2), Otac(3)" << endl;
            cin >> biranje;
            if(biranje==0){
                cout << "Unesite element: ";
                cin >> element;
                drvo.CreateChild(tekuci, element);
            }
            else if(biranje==1){
                tekuci=drvo.FirstChild(tekuci);
            }
            else if(biranje==2){
                tekuci=drvo.NextSibling(tekuci);
            }
            else if(biranje==3){
                tekuci=drvo.Parent(tekuci);
            }
        }while(biranje!=0);
    }

    cout << "Cvorovi sa jednim djetetom: " << endl;
    printCvora(drvo);

    return 0;
}