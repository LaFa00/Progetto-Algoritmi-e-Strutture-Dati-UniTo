#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#include "edit_distance_dynamic.h"
#include <time.h>

typedef struct word{
    char array_word[50];
}Word;

int main(int argc, char const *argv[]) {
    int elem_dictionary =  700000;
    int elem_string = 100000;
    if(argc < 2) {
        printf("Inserire file \n");
        exit(EXIT_FAILURE);
    }

    FILE *file;
    char buffer[2048];
    char *p;
    int i = 0;
    int r = 0;

    Word* array = malloc(sizeof(Word)* elem_string);
    file = fopen(argv[1],"r");
    while(fgets(buffer,sizeof(buffer),file) != NULL) {}

    p = strtok(buffer," ,.-:\n\0");
    while(p != NULL && i < elem_string) {
        strcpy(array[i].array_word,p);
        p = strtok(NULL, " ,.-:\n\0");
        r++;
        i++;
    }
    fclose(file);

    file = fopen(argv[2],"r");
    char* p_2;
    char buffer_2[1024];
    int j = 0;

    Word* dictionary = malloc(sizeof(Word) * elem_dictionary);
    while((fgets(buffer_2,sizeof(buffer_2),file) != NULL) && j < elem_dictionary) {
        strcpy(dictionary[j].array_word,buffer_2);
        j++;
    }
    fclose(file);
    
    clock_t start_t = clock();
    for(int i = 0; i < r; i++) {
        int *array_2 = malloc(sizeof(int) * j);
        int min = __INT_MAX__;
        for(int k = 0; k < j; k++) {
            array_2[k] = edit_distance_dyn(array[i].array_word,dictionary[k].array_word);
            if(array_2[k] < min) {
                min = array_2[k];
            }
        }
        for(int index = 0; index < j; index++) {
            if(array_2[index] == min) {
                printf("Parola: %s, forse intendevi %s\n",array[i].array_word,dictionary[index].array_word);
            }
        }
        free(array_2);
    }
    clock_t end_t = clock();
    printf("Approximate time: %.3f\n", ((double)(end_t - start_t) / CLOCKS_PER_SEC));
    return 0;
}