

#include "Introsort.h"
#include "Quicksort.h"

//void Introsort(int *tab, int left, int right, int maxdepth) {
//    if (right - left < 16) {
//        Insertionsort(tab, left, right);
//    } else if (maxdepth == 0) {
//        Heapsort(tab, right);
//    } else {
//        int a = Partition(tab, left, right);
//        Introsort(tab, left, a, maxdepth);
//        Introsort(tab, a +1 , right, maxdepth);
//    }
////    }
//}


//***************Sortowanie przez kopcowanie******************//
void HeapMaximum(int *tab, int heapSize, int q) {
    int left = (q + 1) * 2 - 1;
    int right = (q + 1) * 2;
    int biggest = 0;

    if (left < heapSize && tab[left] > tab[q]) {
        biggest = left;
    } else {
        biggest = q;
    }
    if (right < heapSize && tab[right] > tab[biggest]) {
        biggest = right;
    }
    if (biggest != q) {
        int temp = tab[q];
        tab[q] = tab[biggest];
        tab[biggest] = temp;

        HeapMaximum(tab, heapSize, biggest);
    }
}

void Heapsort(int *tab, int right) {
    int heapSize = right + 1;

    for (int p = (heapSize - 1) / 2; p >= 0; --p) {
        HeapMaximum(tab, heapSize, p);
    }
    for (int i = right ; i > 0; --i) {
        int temp = tab[i];
        tab[i] = tab[0];
        tab[0] = temp;

        --heapSize;
        HeapMaximum(tab, heapSize, 0);
    }
}
//************************************************************************//


//void Insertionsort(int * tab, int left, int right) {
//    for (int i = 1; i < right - left + 1; ++i) {
//        int j = i;
//
//        while ((j > 0)) {
//            if (tab[j-1] > tab[j]) {
//                tab[j-1] ^= tab[j];
//                tab[j] ^= tab[j-1];
//                tab[j-1] ^= tab[j];
//
//                --j;
//            }
//            else {
//                break;
//            }
//        }
//    }
//}
//
//
//
