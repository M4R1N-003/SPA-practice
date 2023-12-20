#include<iostream>
#include "stackp.h"
using namespace std;
int main(){
    stack<int> stog;
    string zagrade;
    int n;
    cin >> zagrade;
    n=zagrade.length();

    for(int i=0;i<n;i++){
        stog.Push(zagrade[i]);
    }

    int oble = 0, uglate = 0, viticaste = 0;
    bool greska=false;
    for(int i=0;i<n;i++){
        switch(stog.Top()){
            case '(':
                oble++;
                break;
            case ')':
                oble--;
                break;
            case '[':
            if(oble) greska=true;
                uglate++;
                break;
            case ']':
            if(oble) greska=true;
                uglate--;
                break;
            case '{':
            if(oble||uglate)greska=true;
                viticaste++;
                break;
            case '}':
            if(oble||uglate)greska=true;
                viticaste--;
                break;
        }
        stog.Pop();
    }

    if(greska){
        cout << "false";
    }
    else{
        cout << "true";
    }
    return 0;
}