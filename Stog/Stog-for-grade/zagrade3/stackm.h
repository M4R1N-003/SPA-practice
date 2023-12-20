#include<iostream>
#include<cstdlib>

#define maks 1000

template <typename elementtype>
class stack{
    private:
    elementtype polje[maks];
    int top;
    public:
    stack(){
        top = maks-1;
    }

    bool Prazno(){
        return top==maks-1;
    }

    void Gurni(int x){
        if(top==-1){
            std::cout << "Stog je pun!" << std::endl;
            exit(0);
        }
        else{
            polje[top--]=x;
        }
    }

    void Odvuci(){
        if(top==maks-1){
            std::cout << "Stog je prazan!" << std::endl;
            exit(0);
        }
        else{
            top++;
        }
    }

    elementtype Vrh(){
        if(top==maks-1){
            std::cout << "Stog je prazan!" << std::endl;
            exit(0);
        }
        else{
            return polje[top+1];
        }
    }
};