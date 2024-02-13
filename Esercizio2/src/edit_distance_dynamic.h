#ifndef EDIT_DISTANCE_DYN_H
#define EDIT_DISTANCE_DYN_H

/* Returns the edit distance between two strings. This approach is less time-consuming since it uses a dynamic programming technique
 * s1: first non-null string
 * s2: second non-null string
 */
int edit_distance_dyn(char* s1, char* s2);
int edit_distance_helper(char* s1, char* s2, int len_s1, int len_s2, int** m_matrix);
int min(int x, int y, int z);
int do_no_op(char *s1, char *s2,int length_s1,int length_s2,int** matrix);
int do_canc(char *s1, char *s2,int length_s1,int length_s2,int** matrix);
int do_ins(char *s1, char *s2,int length_s1,int length_s2,int** matrix);
#endif 
