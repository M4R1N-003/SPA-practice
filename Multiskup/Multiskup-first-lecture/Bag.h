#ifndef MAXB
#define MAXB 1000
#endif

#ifndef EqualB
#define EqualB(a,b) (a == b? true: false)
#endif

#include <cstdlib>
#include <iostream>

template <typename elementtype>
class bag  {
	private:
    elementtype el[MAXB];
    unsigned short NoEl;
    
    public:
    bag () {
  	    NoEl = 0;
    }

    bool IsEmpty() {
         return NoEl == 0;
    }

    bool IsElement(elementtype x) {
         int i;
         for (i = 0; i < NoEl && !EqualB(el[i],x); i++); 
         return i < NoEl;
    }

    unsigned int Count(elementtype x) {
             unsigned short no = 0;
             for (int i=0; i<NoEl; i++)
                 if (EqualB(el[i],x)) no++;
             return no;
}

    void Insert(elementtype x) {
         if (NoEl == MAXB) {
            std::cout << "multiskup je prepunjen" 
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else 
             el[NoEl++] = x;
}

    void Delete(elementtype x) {
         int i;
         for (i = 0; i < NoEl && 
              !EqualB(el[i],x); i++); 
         if (i < NoEl) {
            for (; i < NoEl-1; i++)
                el[i] = el[i+1];
            NoEl--;
         }
    }

    void DeleteAll() {
         NoEl = 0;
    }
};

