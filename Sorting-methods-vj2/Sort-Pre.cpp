#include <iostream>
#include <ctime>

template <typename T>
void BubbleSort (T a[], int n) {
     int i=1;
     bool sw;
     do {
        sw = false;
        for (int j=0; j<n-i; j++) {
            if (a[j] > a[j+1]) {
               std::swap(a[j], a[j+1]);
               sw = true;
            }
        }
        i++;
     } while (i < n-1 && sw);
}

template <typename T>
void ExchangeSort (T a[], int n) {
}

template <typename T>
void SelectionSort (T a[], int n) {
}

template <typename T>
void InsertionSort (T a[], int n) {
}

template <typename T>
void MergeSort (T a[], int n) {
}


int main () {
	srand(time(0));
	int n, test, alg, bt, t;
	std::cout << "Testovi:" << std::endl;
	std::cout << "\t 1. Korektnost" << std::endl << "\t 2. Brzina" << std::endl; 
	std::cout << "Test: ";
	std::cin >> test;
	std::cout << "Algoritam: " << std::endl;
	std::cout << "\t 1. Bubble sort" << std::endl;
	std::cout << "\t 2. Exchange sort" << std::endl;
	std::cout << "\t 3. Selection sort" << std::endl;
	std::cout << "\t 4. Insertion sort" << std::endl;
	std::cout << "\t 5. Merge sort" << std::endl;
	std::cin >> alg;
	std::cout << "Broj elemenata polja: ";
	std::cin >> n;
	int *a = new int [n];
	for (int i = 0; i < n; i++)
	    a[i] = test==1?rand():rand()*rand();
	switch (test) {
	       case 2: switch (alg) {
						  case 1: bt = clock();
						          BubbleSort(a,n);
						          t = clock() - bt;
						          break;
						  case 2: bt = clock();
						          ExchangeSort(a,n);
						          t = clock() - bt;
						          break;
						  case 3: bt = clock();
						          SelectionSort(a,n);
						          t = clock() - bt;
						          break;
						  case 4: bt = clock();
						          InsertionSort(a,n);
						          t = clock() - bt;
						          break;
						  case 5: bt = clock();
						          MergeSort(a,n);
						          t = clock() - bt;
						          break;
						  default: std::cout << "Pogresan algoritam" << std::endl;
	               }
	               std::cout << t << std::endl;
	               break;
	      case 1: switch (alg) {
	      	             case 1: BubbleSort(a,n);
	      	                     break;
	      	             case 2: ExchangeSort(a,n);
	      	                     break;
	      	             case 3: SelectionSort(a,n);
	      	                     break;
	      	             case 4: InsertionSort(a,n);
	      	                     break;
	      	             case 5: MergeSort(a,n);
	      	                     break;
						 default: std::cout << "Pogresan algoritam" << std::endl;
		          }
                  for (int i=0; i<n; i++)
                      std::cout << a[i] << " ";
                  std::cout << std::endl;
                  break;
          default: std::cout << "Pogresan test" << std::endl;
    }
    return 0;
}