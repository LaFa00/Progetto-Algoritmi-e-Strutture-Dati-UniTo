#ifndef MERGE_BINARYINSERTION_SORT_H
#define MERGE_BINARYINSERTION_SORT_H

void merge_binary_insertion_sort(void **array,int array_size,int k,int (*compare)(void*,void*));
void binaryInsertion_sort(void **array,int start, int end, int (*compare)(void*,void*));
void _merge_binary_insertion_sort(void **array,int start, int end, int k, int (*compare)(void*,void*));
int binary_search(void **array,int start, int end, int elem, int (*compare)(void*,void*));
void merge(void **array,int start, int m, int end, int (*compare)(void*,void*));

#endif //MERGE_BINARYINSERTION_SORT_H
