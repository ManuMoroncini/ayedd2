#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */

    unsigned int i = izq+1;
    unsigned int j = der;

    while (i <= j){
        /* if izq & der are bad located */
        if(goes_before(a[izq], a[i]) && goes_before(a[j], a[izq])) {
          swap(a, i, j);
          i++;
          j--;
        }
        else {
          /* if izq is good located */
          if(goes_before(a[i], a[izq])) {
            i++;
          }
          /* if der is good located */
          if(goes_before(a[izq], a[j])) {
            j--;
          }
        }
    }

    /* swap ppiv */
    swap(a, izq, j);

    return j;
    
    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
     - i name pivot as ppiv, manu note
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    
    unsigned int ppiv = partition(a, izq, der); 
    if(ppiv > izq) {
        quick_sort_rec(a, izq, ppiv-1);
    }
    if(ppiv < der) {
    quick_sort_rec(a, ppiv+1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

