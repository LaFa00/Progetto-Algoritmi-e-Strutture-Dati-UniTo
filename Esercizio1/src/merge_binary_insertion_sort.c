#include <stdlib.h>
#include <stdio.h>
#include "merge_binary_insertion_sort.h"

/* Ordina un array usando l'algoritmo MergeBinaryInsertionSort 
 * array: array da ordinare
 * size: dimensione arrray
 * k: se la lunghezza del sottoarray e' <= k, viene usato il BinaryInsertionSort .
 * compare: funzione chiama per determinare se un elemento e' minore di un altro. Ritorna 0, se il primo elemento e' >= del secondo
 */
void merge_binary_insertion_sort(void **array,int array_size,int k,int (*compare)(void*,void*)){
    if (array == NULL){
        fprintf(stderr,"merge_binaryInsertion_sort: the array is a null pointer");
        exit(EXIT_FAILURE);
    }

    if (array_size < 0){
        fprintf(stderr,"merge_binary_insertion_sort: the array size is negative");
        exit(EXIT_FAILURE);
    }

    if (compare == NULL){
        fprintf(stderr,"merge_binary_insertion_sort: compare function is a null pointer");
        exit(EXIT_FAILURE);
    }

    if(array_size <= 1){
        return;
    }

    _merge_binary_insertion_sort(array,0,array_size-1,k,compare);
}

/* Ordina un array usando l'algoritmo BinaryInsertionSort 
 * array: array da ordinare
 * start: indice dal quale l'algoritmo partira'  
 * end: indice nel quale l'algoritmo si fermera'
 * compare: funzione chiama per determinare se un elemento e' minore di un altro. Ritorna 0, se il primo elemento e' >= del secondo
 */
void binary_insertion_sort(void **array,int start, int end, int (*compare)(void*,void*)){
    if (end - start <= 1 )
        return;

    int i,pos,j;
    void *elem;
    for (i = start +1; i < end; i++){
        pos = binary_search(array,start,i-1,i,compare);
       elem = array[i];
        j = i-1;

        while(j >= pos){
            array[j+1] = array[j];
            j--;
        }
        array[pos] = elem;
    }
}

/* Ricerca l'indice corretto per l'algoritmo InsertionSort
 * array: array da ordinare
 * elem: elemento da inserire nella posizione cercata 
 * start: indice dal quale l'algoritmo partira'  
 * end: indice nel quale l'algoritmo si fermera'
 * compare: funzione chiama per determinare se un elemento e' minore di un altro. Ritorna 0, se il primo elemento e' >= del secondo
 */
int binary_search(void **array,int start, int end, int elem, int (*compare)(void*,void*)){
    if (end <= start){
        if (compare(array[start],array[elem]) > 0 ){
            return start +1;
        }else{
            return start;
        }
    }

    int m = (start + end) /2;

    if (compare(array[m],array[elem]) > 0 )
        return binary_search(array,m+1,end,elem,compare);
    else if (compare(array[elem],array[m]) > 0){
        return binary_search(array,start,m-1,elem,compare);
    }else{
        return m;
    }
}

/* Ordina un array usando l'algoritmo MergeBinaryInsertionSort 
 * array: array da ordinare
 * start: indice dal quale l'algoritmo partira'  
 * end: indice nel quale l'algoritmo si fermera'
 * k: se la lunghezza del sottoarray e' <= k, viene usato il  BinaryInsertionSort 
 * compare: funzione chiama per determinare se un elemento e' minore di un altro. Ritorna 0, se il primo elemento e' >= del secondo
 */
void _merge_binary_insertion_sort(void **array,int start, int end, int k, int (*compare)(void*,void*)){
  
  
  if (end - start <= 0)
    return;
  
  int m = (start + end)/2;
  
  if (m - start > k){
    _merge_binary_insertion_sort(array,start,m,k,compare);
  
  }else {
    binary_insertion_sort(array,start,m+1,compare);
  }

  if (end - (m+1) > k) {
    _merge_binary_insertion_sort(array,m+1,end,k,compare);
  
  } else {
    binary_insertion_sort(array,m+1,end+1,compare);
  }

  merge(array,start,m,end,compare);

}

/* Unisce 2 sottoarray ordinati
 * array: array da ordinare
 * start: indice dal quale l'algoritmo partira'  
 * end: indice nel quale l'algoritmo si fermera'
 * m: fine del primo sottoarray, inizio del secondo 
 * compare: funzione chiama per determinare se un elemento e' minore di un altro. Ritorna 0, se il primo elemento e' >= del secondo
 */
 
void merge(void **array,int start, int m, int end, int (*compare)(void*,void*)){
  
  int i,j, k;
  void **helper_array = (void**)malloc(sizeof(void**)* (end-start + 2) );

  i= start;
  j = m+1;
  k=0;

  while(i<=m && j <=end){
    if ( compare(array[i],array[j]) > 0 ){
      helper_array[k] = array[i];
      i++;
    }else{
      helper_array[k] = array[j];
      j++;
    }
    k++;
  }

  while (i<= m){
    helper_array[k] = array[i];
    i++;
    k++;
  }

  while (j<= end){
    helper_array[k] = array[j];
    j++;
    k++;
  }

  for (k = start; k <= end; k++){
    array[k] = helper_array[k-start];
  }

  free(helper_array);

}


