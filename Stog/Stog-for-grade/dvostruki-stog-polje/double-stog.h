#include <iostream>
#include <cstdlib>
#ifndef MAXS
#define MAXS 100
#endif
template <typename elementtype>
class stog_polje{
	private:
		elementtype e[MAXS];
		int top,bottom;
	public:
		stog_polje(){
			bottom = MAXS-1;
			top = 0;
		}
		bool IsEmpty(int d){
			if(bottom==MAXS-1 && d==1){
				return true;
			}
			else if(top==0 && d==0) return true;
			else return false;
		}
		elementtype Top(int d){
			if(bottom < MAXS-1 && d==1) return e[bottom+1];
			else if(top > 0 && d==0) return e[top-1]; 
			else{
				std::cout<<"Stog je prazan"<<std::endl;
				exit(EXIT_FAILURE);
			}
		}
		void Pop(int d){
			if(top>0 && d==0) top--;
			else if(bottom<MAXS-1 && d==1) bottom++;
			else{
				std::cout<<"Stog je prazan"<<std::endl;
				exit(EXIT_FAILURE);
			}
		}
		void Push(int d, elementtype x){
			if(top<bottom && d==0){
				e[top++]=x;
			}
			else if(bottom>top && d==1) e[bottom--]=x;
			else{
				std::cout<<"Stog je pun"<<std::endl;
				exit(EXIT_FAILURE);
			}
		}
};