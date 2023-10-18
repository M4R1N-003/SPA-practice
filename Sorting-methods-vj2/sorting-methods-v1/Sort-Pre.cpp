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

	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[i]){
				int temp = a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
}

template <typename T>
void SelectionSort (T a[], int n) {
	for(int i=n-1;i>0;i--){

		int max = 0;
		for(int j=0;j<=i;j++){
			if(a[j] > a[max])
				max=j;
		}

		if(max==i) continue;

		std::swap(a[i],a[max]);
	}

}

template <typename T>
void InsertionSort (T a[], int n) {

	for(int i=1;i<n;i++){
        int j=i-1;
        int pom = a[i];
        while(j>=0 && a[j]>pom){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = pom;
    }

}

void merge1(int *a, int *b, int prvi, int pivot, int zadnji) {
            int h, i, j, k;
            h = prvi;
            i = prvi;
            j = pivot + 1;
			
        while ((h <= pivot) && (j <= zadnji)) {
            if (a[h] <= a[j]) {
                b[i] = a[h];
                h++;
            } 
            else {
                b[i] = a[j];
                j++;
            }
            i++;
        }

        if (h > pivot) {
            for (k = j; k <= zadnji; k++) {
            b[i] = a[k];
            i++;
            }
        } 
        else {
            for (k = h; k <= pivot; k++) {
            b[i] = a[k];
            i++;
            }
        }
    for (k = prvi; k <= zadnji; k++) a[k] = b[k];
    }

 template <typename T>
    void MergeSort(T a[], int *b, int prvi, int zadnji) {
    int pivot;
    if (prvi < zadnji) {
        pivot = (prvi + zadnji) / 2;
        MergeSort(a, b, prvi, pivot);
        MergeSort(a, b, pivot + 1, zadnji);
        merge1(a, b, prvi, pivot, zadnji);
    }
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
	int *b = new int[n];
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
						          MergeSort(a,b,0,n-1);
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
	      	             case 5: 
						 		MergeSort(a,b,0,n-1);
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