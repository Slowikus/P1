

#include "Quicksort.h"
#include <algorithm>

void Quicksort(int *tab, int left, int right) {
    if (left < right)
    {
        int a = Partition(tab, left, right);
        Quicksort(tab, left, a);
        Quicksort(tab, a + 1, right);
    }
}

int Partition(int *tab, int left, int right){
    int midVal = tab[(left + right) / 2];
    int l = left;
    int r = right;

    while(true) {
        while(tab[r] > midVal) {
            r--;
        }
        while(tab[l] < midVal) {
            l++;
        }
        if (l < r) {
            std::swap(tab[l++], tab[r--]);

        } else {
            return r;
        }
    }
}





