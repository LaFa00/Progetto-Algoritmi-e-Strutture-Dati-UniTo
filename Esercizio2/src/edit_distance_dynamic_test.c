#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edit_distance_dynamic.h"
#include "unity.h"


void setUp(void) {
}

void tearDown(void) {
}

void test_empty_string_dyn() { 
  char *s1 = "";
  char *s2 = "";

  TEST_ASSERT_EQUAL_INT(0, edit_distance_dyn(s1, s2));
}

void test_edit_distance_string_dyn() {
  char *s1 = "cassa";
  char *s2 = "casa";

  TEST_ASSERT_EQUAL_INT(1, edit_distance_dyn(s1, s2));
}

void test_first_empty_string_dyn() {
  char *s1 = "";
  char *s2 = "casa";

  TEST_ASSERT_EQUAL_INT(4, edit_distance_dyn(s1, s2));
}

void test_second_empty_string_dyn() {
  char *s1 = "cassa";
  char *s2 = "";

  TEST_ASSERT_EQUAL_INT(5, edit_distance_dyn(s1, s2));
}

void test_edit_distance2_string_dyn() {
  char *s1 = "tassa";
  char *s2 = "passato";

  TEST_ASSERT_EQUAL_INT(4, edit_distance_dyn(s1, s2));
}

void test_different_string_dyn() {
  char *s1 = "casa";
  char *s2 = "libro";

  TEST_ASSERT_EQUAL_INT(9, edit_distance_dyn(s1, s2));
}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_empty_string_dyn);
  RUN_TEST(test_edit_distance_string_dyn);
  RUN_TEST(test_first_empty_string_dyn);
  RUN_TEST(test_second_empty_string_dyn);
  RUN_TEST(test_edit_distance2_string_dyn);
  RUN_TEST(test_different_string_dyn);

  return UNITY_END();
}
