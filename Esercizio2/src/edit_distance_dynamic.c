#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edit_distance_dynamic.h"
#include <unistd.h>

 
/*Ritorna l'edit distance tra 2 stringhe
 * Questo approccio utilizza la programmazione dinamica
 * s1: first non-null string
 * s2: second non-null string
 */
int edit_distance_dyn(char* s1, char* s2) {
  int length_s1;
  int length_s2;
  int **matrix;
  int result;

  if (s1== NULL){
    fprintf(stderr,"edit_distance: the first string is a null pointer");
    exit(EXIT_FAILURE);
  }

  if (s2== NULL){
    fprintf(stderr,"edit_distance: the second string is a null pointer");
    exit(EXIT_FAILURE);
  }

  length_s1 = (int)strlen(s1);
  length_s2 = (int)strlen(s2);

  matrix = (int**) malloc(sizeof(int*) * (length_s1 + 1));

  for (int i = 0; i <length_s1 + 1; i++) {
    matrix[i] = (int*) malloc(sizeof(int) * (length_s2 + 1));
    for (int j = 0; j < length_s2 + 1; j++) {
      matrix[i][j] = -1;
    }
  }

  result = edit_distance_helper(s1, s2, length_s1, length_s2, matrix);

  for (int k = 0; k < length_s1 + 1; k++) {
    free (matrix[k]);
  }
 
  free(matrix);
  return result;
}

/* Funzione ausiliaria per calcolare l'edit distance tra 2 stringhe.
 * s1: prima stringa
 * s2: seconda stringa
 * length_s1: Lunghezza prima stringa
 * length_s2: Lunghezza seconda stringa
 * matrix: matrice usata per memorizzare temporaneamente i risultati
 */
int edit_distance_helper(char* s1, char* s2, int length_s1, int length_s2, int** matrix){
  int dno_op;
  int dcanc;
  int dins;
  int result;

  if (matrix[length_s1][length_s2] >= 0)
    return matrix[length_s1][length_s2];

  if (length_s1 == 0) {
    matrix[length_s1][length_s2] = length_s2;
    return length_s2;
  }

  if (length_s2 == 0) {
    matrix[length_s1][length_s2] = length_s1;
    return length_s1;
  }

  if (s1[0] == s2[0]){
    dno_op = do_no_op(s1,s2,length_s1,length_s2,matrix);
  } else {
   dno_op = __INT_MAX__;
  }

  dcanc = do_canc(s1,s2,length_s1,length_s2,matrix);

  dins = do_ins(s1,s2,length_s1,length_s2,matrix);

  result = min(dno_op,dcanc,dins);
  matrix[length_s1][length_s2] = result;
  
  return result;
}

/*Ritorna il valore minimo
 */
 int min(int x, int y, int z){
  if(x <= y && x <= z) {
    return x;
  }
  else if(y <= x && y <= z) { 
    return y;
  } else {
      return z;
  }
} 


int do_no_op(char *s1, char *s2,int length_s1,int length_s2,int** matrix) {
    if(s1[0] == s2[0]) {
        return edit_distance_helper(&s1[1], &s2[1], length_s1 - 1, length_s2 -1, matrix);
    } else {

    }
}

int do_canc(char *s1, char *s2,int length_s1,int length_s2,int** matrix) {
     return 1 + edit_distance_helper(s1,&s2[1],length_s1,length_s2-1,matrix);
}

int do_ins(char *s1, char *s2,int length_s1,int length_s2,int** matrix) {
   return 1 + edit_distance_helper(&s1[1],s2,length_s1-1,length_s2,matrix);
}
