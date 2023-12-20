#include <iostream>
#include <cstdlib>
#ifndef MAXR
#define MAXR 100
#endif
template <typename elementtype>
class red_kursori{
	private:
		elementtype e[MAXR];
		int kursor;
		int front,rear;
		int AddOne(int a){
			return (a==MAXR-1 ? 0 : a+1);
		}
		int Oduzmi(int x){
			if(x==0) return MAXR-1;
			else return x-1;
		}
		
	public:
		red_kursori(){
			front=0;
			rear=MAXR-1;
			kursor=Oduzmi(rear);
		}
		bool IsEmpty(){
			return (AddOne(rear)==front && kursor);
		}
		elementtype Front(){
			if(AddOne(rear)==front && kursor){
				std::cout<<"Red je prazan!"<<std::endl;
				exit(EXIT_FAILURE);
			}
			else 
			return e[front];
		}
		void Enqueue(elementtype x){
			if(AddOne(rear)==front && !kursor){
				std::cout<<"Red je pun"<<std::endl;
				exit(EXIT_FAILURE);
			}
			else{
				rear=AddOne(rear);
				e[rear]=x;
				kursor=Oduzmi(rear);
			}
			
		}
		
		void Dequeue(){
			if(AddOne(rear)==front && kursor){
				std::cout<<"Red je prazan"<<std::endl;
				exit(EXIT_FAILURE);
			}
			else{
				front=AddOne(front);
				kursor=Oduzmi(front);
			}
		}
		
};
