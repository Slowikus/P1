#include "Mergesort.h"


void Mergesort(int *tab, int *q, int left, int right) {
    if(right <= left) {
        return;
    }

    int mid   = (left + right) / 2;
    Mergesort(tab, q, left, mid);
    Mergesort(tab, q, mid + 1, right);
    Merge(tab, q, left, mid, right);
}

void Merge(int *tab, int *q, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;

    for(int k = left; k <= right ; k++) {
        q[k] = tab[k];
    }

    for(int l = left; l <= right; l++){
        if (i <= mid)
            if (j <= right)
                if(q[j] < q[i])
                    tab[l] = q[j++];
                else
                    tab[l] = q[i++];
            else
                tab[l] = q[i++];
        else
            tab[l] = q[j++];
    }

}

