#ifndef MAXB
#define MAXB 1000
#endif

#ifndef EqualB
#define EqualB(a,b) (a == b? true: false)
#endif

#include <cstdlib>
#include <iostream>
using namespace std;

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
            cout << "multiskup je prepunjen" 
                      << endl;
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

    void Union(bag <elementtype > &M,bag <elementtype > &N){
          if (M.NoEl + N.NoEl > MAXB) {
               cout << " Multiskupovi su preveliki " << endl;
               exit( EXIT_FAILURE );
          }
          else {
               int i,j;
               for (i = 0; i<M.NoEl; i++)
                    el[i] = M.el[i];
               for (j = 0; j < N.NoEl; j++)
                    el[i+j] = N.el[j];
               NoEl = i+j;
          }

          cout << "(";
          for(int i=0;i<NoEl;i++){
               cout << el[i] << ", ";
          }
          cout << ")";
          cout << endl;
     }

     void Intersect(bag<elementtype> &M, bag<elementtype> &N) {
          bag<elementtype> temp;
          bag<elementtype> priv;
          for(int i=0;i<N.NoEl;i++){
               priv.Insert(N.el[i]);
          }
          for (int i = 0; i < M.NoEl; i++) {
               if (N.IsElement(M.el[i])) {
                    temp.Insert(M.el[i]);
                    N.Delete(M.el[i]);
               }
          }

          cout << "(";
          for (int i = 0; i < temp.NoEl; i++) {
               cout << temp.el[i] << ", ";
          }
          cout << ")";
          cout << endl;

          for(int i=0;i<N.NoEl;i++){
               N.Delete(N.el[i]);
          }

          for(int i=0;i<priv.NoEl;i++){
               N.Insert(priv.el[i]);
          }


     }


};

