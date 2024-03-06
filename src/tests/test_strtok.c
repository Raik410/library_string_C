#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strtok_str_eq_one) {
  char str[100] = "Dyshni5laLala5Boba";
  char delim[100] = "1";

  char* s21_res = s21_strtok(str, delim);
  char* res = strtok(str, delim);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(strtok_str_eq_two) {
  char str[100] = "Dyshni53laLala53Boba";
  char delim[100] = "53";

  char* s21_res = s21_strtok(str, delim);
  char* res = strtok(str, delim);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(strtok_str_eq_three) {
  char str[100] = "Dyshni5laLala5Boba";
  char delim[100] = "5";

  char* s21_res = s21_strtok(str, delim);
  char* res = strtok(str, delim);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(strtok_str_eq_four) {
  char str[100] = "Dyshni5laLala5Boba";
  char delim[100] = "o";

  char* s21_res = s21_strtok(str, delim);
  char* res = strtok(str, delim);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

Suite* s21_strtok_suite(void) {
  Suite* suite = suite_create("s21_suite_strtok");
  TCase* tc_core = tcase_create("s21_tcase_strtok");

  tcase_add_test(tc_core, strtok_str_eq_one);
  tcase_add_test(tc_core, strtok_str_eq_two);
  tcase_add_test(tc_core, strtok_str_eq_three);
  tcase_add_test(tc_core, strtok_str_eq_four);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite* suite = s21_strtok_suite();
  SRunner* runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}