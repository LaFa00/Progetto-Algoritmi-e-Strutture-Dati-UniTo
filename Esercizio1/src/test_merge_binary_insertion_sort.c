#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge_binary_insertion_sort.h"
#include "unity.h"

#define STRING_SIZE 64

void setUp(void) {

}

int comp_int(void *a, void *b){
  return *(int*)a < *(int*)b;
}

int comp_float(void *a, void *b){
  return *(float*)a < *(float*)b;
}

int comp_string(void *a, void *b){
  return strcmp(*(char**)a , *(char**)b) < 0;
}

void tearDown(void) {
}

void test_sorted_int_array() { 
  int arr[] = {1,2,3,4,5,6,7};
  int* array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};
  int* correct_array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};
  
 merge_binary_insertion_sort((void**)array,7,3,comp_int);
  TEST_ASSERT_EQUAL_PTR_ARRAY((void**)correct_array, (void**)array,7);
}

void test_unsorted_int_array() {
  int arr[] = {1,2,3,4,5,6,7};
  int* array[] = {&arr[0],&arr[4],&arr[1],&arr[6],&arr[2],&arr[5],&arr[3]};
  int* correct_array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};

 merge_binary_insertion_sort((void**)array,7,3,comp_int);
  TEST_ASSERT_EQUAL_PTR_ARRAY((void**)correct_array,(void**) array,7);
}

void test_sorted_float_array() { 
  float arr[] = {1.5, 2.3, 2.8, 3.15, 5.89, 5.95, 6.22};
  float* array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};
  float* correct_array[] ={&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};

 merge_binary_insertion_sort((void**)array,7,3,comp_float);
  TEST_ASSERT_EQUAL_PTR_ARRAY((void**)correct_array, (void**)array,7);
}

void test_unsorted_float_array() {
  float arr[] = {1.5, 2.3, 2.8, 3.15, 5.89, 5.95, 6.22};
  float* array[] = {&arr[0],&arr[4],&arr[1],&arr[6],&arr[2],&arr[5],&arr[3]};
  float* correct_array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};

 merge_binary_insertion_sort((void**)array,7,3,comp_float);
  TEST_ASSERT_EQUAL_PTR_ARRAY((void**)correct_array, (void**)array,7);
}

void test_sorted_string_array() { 
  char *arr[] = {"acqua","ciao","elefante","formica","nave","orologio","zattera"};
  char** array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};
  char** correct_array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};

 merge_binary_insertion_sort((void**)array,7,3,comp_string);
  TEST_ASSERT_EQUAL_PTR_ARRAY((void**)correct_array, (void**)array, 7);
}

void test_unsorted_string_array() {
  char *arr[] = {"acqua","ciao","elefante","formica","nave","orologio","zattera"};
  char** array[] = {&arr[0],&arr[4],&arr[1],&arr[6],&arr[2],&arr[5],&arr[3]};
  char** correct_array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};
 merge_binary_insertion_sort((void**)array,7,3,comp_string);
  TEST_ASSERT_EQUAL_PTR_ARRAY((void**)correct_array, (void**)array, 7);
}


int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_sorted_int_array);
  RUN_TEST(test_unsorted_int_array);
  RUN_TEST(test_sorted_float_array);
  RUN_TEST(test_unsorted_float_array);
  RUN_TEST(test_sorted_string_array);
  RUN_TEST(test_unsorted_string_array);

  return UNITY_END();
}
