#include <stdlib.h>

#ifndef max
#define max 1000
#endif

#ifndef Equal
#define Equal(a,b) (a == b? true: false)
#endif

template <typename elementtype>
class set{
    public:
    int BrEl;
    set(){
        BrEl = 0;
    }

    elementtype el[max];

    bool IsEmpty(){
        return BrEl==0;
    }

    bool IsElement(elementtype x){
        for(int i=0;i<BrEl;i++){
            if(el[i]==x){
                return true;
            }
        }
        return false;
    }

    void Insert(elementtype x) {
        if (BrEl == max) {
        std::cout << "skup je prepunjen" << std::endl;
        exit(EXIT_FAILURE);
        }
        if(!IsElement(x)){
            el[BrEl++] = x;
        }
        else{
            std::cout << "Element " << x << " vec postoji!" << std::endl;
        }
    }

    void Delete(elementtype x) {
         int i;
         for (i = 0; i < BrEl && 
              !Equal(el[i],x); i++); 
         if (i < BrEl) {
            for (; i < BrEl-1; i++)
                el[i] = el[i+1];
            BrEl--;
         }
    }

};