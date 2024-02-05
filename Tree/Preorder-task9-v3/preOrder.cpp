#include<iostream>
#include"stacka.h"
#include"tree.h"
typedef int node;
using namespace std;

void ispis(tree<int> &drvo){
    stack<int> s;
    int korijen=drvo.Root();
    s.Push(korijen);

    while(!s.IsEmpty()){
        int trenutni = s.Top();
        s.Pop();
        int brojac=0;
        int dijete=drvo.FirstChild(trenutni);
        for(dijete;dijete!=drvo.lambda;dijete=drvo.NextSibling(dijete)){
            s.Push(dijete);
            brojac++;
        }

        if(brojac==1) cout << drvo.Label(trenutni) << " ";
    }
}

int main(){
    tree<int> drvo;
    tree<int>::node trenutni;
    int element, n;

    cout << "Unesite broj elemenata: ",
    cin >> n;
    cout << "Unesite korijen: ";
    cin >> element;
    drvo.CreateRoot(element);

    for(int i=0;i<n-1;i++){
        int biranje;
        trenutni=drvo.Root();
        do{
            cout << "trenutni cvor je: " << drvo.Label(trenutni) << endl;
            cout << "odaberite: novo dijete(0), dijete(1), blizanac(2), roditelj(3)" << endl;
            cout << "odabir je: ";
            cin >> biranje;
            if(biranje==0){
                cout<< "Unesite oznaku cvora: ";
                cin >> element;
                drvo.CreateChild(trenutni, element);
            }
            else if(biranje==1){
                trenutni=drvo.FirstChild(trenutni);
            }
            else if(biranje==2){
                trenutni=drvo.NextSibling(trenutni);
            }
            else if(biranje==3){
                trenutni=drvo.Parent(trenutni);
            }
        }while(biranje!=0);
    }

    cout << "Cvorovi sa jednim djetetom su: ";
    ispis(drvo);
    return 0;
}