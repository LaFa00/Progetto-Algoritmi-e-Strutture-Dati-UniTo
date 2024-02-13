#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "merge_binary_insertion_sort.h"

int n_element = 0;
int capacity = 0;
typedef struct Record{
    int id;
    char* field1;
    int field2;
    float field3;
}Record;

/* Funzioni di confronto, prendono in input 2 puntatori al Record
 * Ritornano 1, se il campo del primo puntatore e' minore del secondo   
 *  0 altrimenti
 */

int compare_record_string(void* r1, void* r2) {
    if(r1 == NULL) {
        fprintf(stderr,"compare_record_string: the first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(r2 == NULL) {
        fprintf(stderr,"compare_record_string: the second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    Record *rec_1 = (Record*)r1;
    Record *rec_2 = (Record*)r2;
    if(strcmp(rec_1->field1,rec_2->field1) < 0)
        return 1;   
    return 0;
}

int compare_record_int(void* r1,void* r2) {
    if(r1 == NULL) {
        fprintf(stderr,"compare_record_int: the first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(r2 == NULL) {
        fprintf(stderr,"compare_record_int: the second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }

    Record *rec_1 = (Record*)r1;
    Record *rec_2 = (Record*)r2;
    if(rec_1->field2 < rec_2 ->field2)
        return 1;
    return 0;
}

int compare_record_float(void* r1,void* r2) {
    if(r1 == NULL) {
        fprintf(stderr,"compare_record_float: the first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(r2 == NULL) {
        fprintf(stderr,"compare_record_float: the second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    Record *rec_1 = (Record*)r1;
    Record *rec_2 = (Record*)r2;
    if(rec_1->field3 < rec_2 ->field3)
        return 1;
    return 0;
}

/* Stampo il contenuto del record */
void print_array(Record** record, int record_size) {
    if(record == NULL) {
         fprintf(stderr,"Array to print cannot be null");
    }
    for(int i = 0; i < record_size; i++) {
        printf("Record %d: field1 = %s, field2 = %d, field3 = %f",record[i]->id,record[i]->field1,record[i]->field2,record[i]->field3);
    }
}

/* Funzione che alloca il record leggendo i dati da un file
*/
void **load_array(const char* file) {
    char *read_line;
    char buffer[1024];
    void **array;
    FILE *fp;
    
    
    printf("Loading data from file\n");
    fp = fopen(file,"r");
    if(fp == NULL) {
         fprintf(stderr, "main: unable to open the file");
        exit(EXIT_FAILURE);
    }
    while(fgets(buffer,1024,fp) != NULL) {
        read_line = malloc((strlen(buffer)+1)* sizeof(char));
        if(read_line == NULL) {
             fprintf(stderr, "main: unable to allocate memory");
            exit(EXIT_FAILURE);
        }
        strcpy(read_line,buffer);
    
    char* id_field = strtok(read_line,",");
    char* string_field = strtok(NULL,",");
    char* int_field = strtok(NULL,",");
    char* float_field = strtok(NULL,",");

    char *field1 = malloc((strlen(string_field) + 1) * sizeof(char));
    if(field1 == NULL) {
         fprintf(stderr, "main: unable to allocate memory for the string field");
            exit(EXIT_FAILURE);
    }
      int id = atoi(id_field);
      strcpy(field1, string_field);
      int field2 = atoi(int_field);
      float field3 = (float)atof(float_field);
      Record *record = malloc(sizeof(Record));
       if (record == NULL)
        {
            fprintf(stderr, "main: unable to allocate memory for the read record");
            exit(EXIT_FAILURE);
        }
        record->id = id;
        record->field1 = field1;
        record->field2 = field2;
        record->field3 = field3;

        
        if (n_element == 0)
        {
            array = (void **)malloc(sizeof(void *));
            capacity = 1;
            array[0] = record;
            n_element++;
        }
        else if (n_element == capacity)
        {
            array = (void **)realloc(array, (capacity * 2) * sizeof(void *));
            capacity = capacity * 2;
            array[n_element] = record;
            n_element++;
        }
        else
        {
            array[n_element] = record;
            n_element++;
        }

        free(read_line);
    }   
    fclose(fp);
    printf("\nData loaded\n");
    return array;
}


/* Crea e alloca un array con il record allocato dal file.csv
 * Viene richiamato il MergeBinaryInsertionSort e vengono stampati i tempi di esecuzione
 */
void comparison_function(const char* file, int k, int(*compare)(void*,void*)) {
    
    void** array;
    
    array = load_array(file);
    printf("\nSto per fare il merge\n");
    float startTime = (float)clock() / CLOCKS_PER_SEC;
    merge_binary_insertion_sort(array,n_element,k,compare);
    float endTime = (float)clock() / CLOCKS_PER_SEC;
    printf("\nFatto\n");
    float timeElapsed = endTime - startTime;
    printf("%.3f", timeElapsed);
    n_element = 0;
    free(array);
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ordered_array_main <file_name>\n");
        exit(EXIT_FAILURE);
    }
    printf("Ordino il campo string\n");
    comparison_function(argv[1], atoi(argv[2]), compare_record_string);
    printf("\n");
    printf("Ordino il campo int\n");
    comparison_function(argv[1], atoi(argv[2]), compare_record_int);
    printf("\n");
    printf("Ordino il campo float\n");
    comparison_function(argv[1], atoi(argv[2]),  compare_record_float);

    return (EXIT_SUCCESS);
}

