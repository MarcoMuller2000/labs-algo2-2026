#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i, unsigned int length) {

    unsigned int j = i;  

    while (j > 0 && !goes_before(a[j-1], a[j])) {
        swap(a,j,j-1);
        j = j-1;
        array_dump(a, length);
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
    }
    assert (array_is_sorted(a, length));
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i = izq + 1;
    unsigned int j = der;
    unsigned int ppiv = izq;

    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i++;

        } else if (goes_before(a[ppiv], a[j])) {
            j--;
        } else {
            swap (a,i,j);

        }
    }
    swap(a, ppiv, j);
    return j;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;
    if (der > izq) {
        ppiv = partition (a, izq, der);

        if (ppiv > izq) {
            quick_sort_rec (a, izq, ppiv - 1);
        }

        if (ppiv < der) {
            quick_sort_rec (a, ppiv + 1, der);
        }

    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
