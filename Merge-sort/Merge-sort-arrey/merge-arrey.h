#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>

class merge{
    public:
    void merge1(int *a, int *b, int prvi, int pivot, int zadnji) {
            int h, i, j, k;
            h = prvi;
            i = prvi;
            j = pivot + 1;
            // spajanje nizova u niz b
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

        // dodavanje ostatka podniza u glavni niz
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
    // kopiranje niza b u pocetni niz a
    for (k = prvi; k <= zadnji; k++) a[k] = b[k];
    }
 
    void mergesort(int *a, int *b, int prvi, int zadnji) {
    int pivot;
    if (prvi < zadnji) {
        pivot = (prvi + zadnji) / 2;
        mergesort(a, b, prvi, pivot);
        mergesort(a, b, pivot + 1, zadnji);
        merge1(a, b, prvi, pivot, zadnji);
    }
    }
};

#endif