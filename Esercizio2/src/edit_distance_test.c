#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "edit_distance.h"

void setUp() {

}

void tearDown() {
    
}

void test_edit_distance_equal_words(void) {
    TEST_ASSERT_EQUAL_INT(0,edit_distance("distanza","distanza"));
}

void test_edit_distance_empty_words(void) {
    TEST_ASSERT_EQUAL_INT(8,edit_distance("martello",""));
}


void test_edit_distance_normal_words(void) {
    TEST_ASSERT_EQUAL_INT(1,edit_distance("casa","cassa"));
    TEST_ASSERT_EQUAL_INT(2,edit_distance("casa","cara"));
    TEST_ASSERT_EQUAL_INT(4,edit_distance("tassa","passato"));
    TEST_ASSERT_EQUAL_INT(1,edit_distance("made","madre"));
    TEST_ASSERT_EQUAL_INT(2,edit_distance("squola","scuola"));
}

void test_edit_distance_totally_different_words(void) {
    TEST_ASSERT_EQUAL_INT(8,edit_distance("becco","cassa"));
    TEST_ASSERT_EQUAL_INT(8,edit_distance("martello","albero"));
    TEST_ASSERT_EQUAL_INT(13,edit_distance("tetto","longobardo"));
}

void test_edit_distance_single_char_strings(void) {
    TEST_ASSERT_EQUAL_INT(2,edit_distance("a","d"));
}

int main(void) {
    UNITY_BEGIN();
  
  RUN_TEST(test_edit_distance_equal_words);
  RUN_TEST(test_edit_distance_empty_words);
  RUN_TEST(test_edit_distance_single_char_strings);
  RUN_TEST(test_edit_distance_normal_words);
  RUN_TEST(test_edit_distance_totally_different_words);
  
  return UNITY_END();

}
