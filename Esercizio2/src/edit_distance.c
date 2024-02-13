#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "edit_distance.h"


/* Ritorna l'edit distance tra due stringhe
 * s1: prima stringa
 * s2: seconda stringa
 */
int edit_distance(char *s1, char *s2) {
    if (s1== NULL) {
    fprintf(stderr,"edit_distance: the first string is a null pointer");
    exit(EXIT_FAILURE);
  }

  if (s2== NULL){
    fprintf(stderr,"edit_distance: the second string is a null pointer");
    exit(EXIT_FAILURE);
  }


    if(strlen(s1) == 0) 
        return  strlen(s2);
    if(strlen(s2) == 0)
        return strlen(s1);

    if(s1[0] == s2[0]) {
        return do_no_op(s1,s2);
    } else {
        
    }

    return min(do_no_op(s1,s2), d_canc(s1,s2),d_ins(s1,s2));
}

/* Funzione che calcola il minimo tra tre interi */
int min(int x, int y, int z) {
    if(x <= y && x <= z) {
        return x;
    } else if(y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}



int do_no_op(char *s1, char *s2) {
    if(s1[0] == s2[0]) {
        return edit_distance(&s1[1],&s2[1]);
    } else {
        return __INT_MAX__;
    }
}

int d_canc(char *s1, char *s2) {
    return 1 + edit_distance(s1,&s2[1]);
}

int d_ins(char *s1, char *s2) {
    return 1 + edit_distance(&s1[1],s2);
}


