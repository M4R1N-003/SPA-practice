#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "set.h"
using namespace std;
int main(){
    srand(time(0));
    int n1, n2;
    cout << "Unesite broj elemenata 1. polja: ";
    cin >> n1;
    cout << "Unesite broj elemenata 2. polja: ";
    cin >> n2;
    int polje1[n1];
    int polje2[n2];

    for(int i=0;i<n1;i++){
        polje1[i]=rand()%100;
    }

    for(int i=0;i<n2;i++){
        polje2[i]=rand()%100;
    }

    for(int i=n1-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(polje1[j]>polje1[i]){
                int temp = polje1[j];
                polje1[j]=polje1[i];
                polje1[i]=temp;
            }
        }
    }

    for(int i=n2-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(polje2[j]>polje2[i]){
                int temp = polje2[j];
                polje2[j]=polje2[i];
                polje2[i]=temp;
            }
        }
    }

    set <int> objektU;
    set <int> polje1U;
    set <int> polje2U;
    int el[max];

    for(int i=0;i<n1;i++){
        polje1U.Insert(polje1[i]);
    }

    for(int i=0;i<n2;i++){
        polje2U.Insert(polje2[i]);
    }

    if (polje1U.BrEl + polje2U.BrEl > max) {
        cout << " skupovi su preveliki " << endl;
        exit( EXIT_FAILURE );
    }
    else {
        int i,j;
        for (i = 0; i<polje1U.BrEl; i++)
            el[i] = polje1U.el[i];
        for (j = 0; j < polje2U.BrEl; j++)
            el[i+j] = polje2U.el[j];
        objektU.BrEl = i+j;
    }

    for(int i=objektU.BrEl-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(el[j]>el[i]){
                int temp = el[j];
                el[j]=el[i];
                el[i]=temp;
            }
        }
    }

    cout << "Unija je: ";
    cout << "(";
    for(int i=0;i<objektU.BrEl;i++){
        cout << el[i] << ", ";
    }
    cout << ")";
    cout << endl;

    set <int> objektI;
    int el1[max];

    bool *bv = new bool [polje2U.BrEl] {false};
    int c, k=0;
    for (int i = 0; i<polje1U.BrEl; i++) {
        for (c=0; c<polje2U.BrEl && (!Equal(polje2U.el[c],polje1U.el[i]) || bv[c]); c++); 
        if (c<polje2U.BrEl) {
            el1[k++] = polje2U.el[i];
            bv[c]=true;		 	 	
        }
    }
    objektI.BrEl = k;
    delete []bv;

    for(int i=objektI.BrEl-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(el1[j]>el1[i]){
                int temp = el1[j];
                el1[j]=el1[i];
                el1[i]=temp;
            }
        }
    }

    cout << "Intersect je: ";
    cout << "(";
    for(int i=0;i<objektI.BrEl;i++){
        cout << el1[i] << ", ";
    }
    cout << ")";
    cout << endl;

    set <int> objektS;
    int el2[max];

    bool *bv1 = new bool [polje2U.BrEl] {false};
    int l, s=0;
    for (int i = 0; i<polje1U.BrEl; i++) {
        for (l=0; l<polje2U.BrEl && (!Equal(polje2U.el[l],polje1U.el[i]) || bv1[l]); l++); 
        if (l==polje2U.BrEl) 
        el2[s++] = polje1U.el[i];
        else
            bv1[l]=true;
    }
    objektS.BrEl = s;
    delete []bv1;

    for(int i=objektS.BrEl-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(el2[j]>el2[i]){
                int temp = el2[j];
                el2[j]=el2[i];
                el2[i]=temp;
            }
        }
    }

    cout << "Subtract je: ";
    cout << "(";
    for(int i=0;i<objektS.BrEl;i++){
        cout << el2[i] << ", ";
    }
    cout << ")";
    cout << endl;

    return 0;
}