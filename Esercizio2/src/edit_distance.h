#ifndef __EDIT_DISTANCE_H__
#define __EDIT_DISTANCE_H__

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

char *rest(char *s);
int do_no_op(char *s1, char *s2);
int d_canc(char* s1, char* s2);
int d_ins(char* s1, char* s2);
int min(int x, int y, int z);
int edit_distance(char *s1, char *s2);

// It accept two string s1 and s2 and return their edit distance.
int edit_distance(char* s1, char* s2);

#endif // __EDIT_DISTANCE_H__
