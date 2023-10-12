#ifndef MAXB
#define MAXB 1000
#endif

#ifndef EqualB
#define EqulB(a,b) (a == b ? true : false)
#endif

#ifndef CompB
#define CompB(a,b) (a<b ? -1: (a == b ? 0 : 1))
#endif

#include <cstdlib>
#include <iostream>
using namespace std;
template <typename elementtype>
class bag {
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
      
      private:
      int BinSearch(elementtype K) {
      	  if (NoEl == 0) return -1;
          int i = 0, j = NoEl-1, k = (i+j)/2;
          while (i < j && CompB(el[k], K)) {
                if (CompB(el[k],K) == -1)
                   i = k+1;
                else
                    j = k-1;
                k = (i+j)/2;
          } 
          if (CompB(el[k], K) == 0)
             return k;
          else
              return -1;
      }

      public:
      bool IsElement(elementtype x) {
           return BinSearch(x) != -1;
      }

      unsigned int Count(elementtype x) {
                   int i = BinSearch(x);
                   int no;
                   if (i == -1)
                      no = 0;
                   else {
             	        no = 1;
                        int j = i-1;
                        while (j >= 0 && 
                               CompB(el[j],x) == 0) {
                              no++;
                              j--;
      	                }
                        j = i+1;
                        while (j <NoEl && 
                               CompB(el[j], x) == 0) {
						       no++;
						       j++;
				        } 
                    }
                    return no;
      }

      void Insert(elementtype x) {
           if (NoEl == MAXB) {
              std::cout << "Multiskup je prepunjen";
              exit(EXIT_FAILURE);
           }
           else {
          	    int i;
                for (i = NoEl++ - 1; i >= 0 && 
                    CompB(el[i], x) == 1; i--)
                    el[i+1] = el[i];
                el[i+1] = x;
           }
      }

      void Delete(elementtype x) {
           int i = BinSearch(x);
           if (i != -1)
              for (; i < NoEl-1; i++)
                  el[i] = el[i+1];
              NoEl--;
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

          for(int i=NoEl-1;i>=0;i--){
            for(int j=0;j<i;j++){
                  if(el[j]>el[i]){
                     int temp = el[j];
                     el[j]=el[i];
                     el[i]=temp;
                  }
            }
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

          int i = 0; 
          int j = 0;

          while (i < M.NoEl && j < N.NoEl) {
               if (M.el[i] == N.el[j]) {
                    temp.Insert(M.el[i]);
                    i++;
                    j++; 
               } 
               else if (M.el[i] < N.el[j]) {
                    i++; 
               } 
               else {
                    j++; 
               }
          }

          cout << "(";
          for (int k = 0; k < temp.NoEl-1; k++) {
               cout << temp.el[k] << ", ";
          }
          cout << ")";
          cout << endl;
          }

};
