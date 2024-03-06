#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strerror_str_eq_one) {
  int arr = 1;

  char* s21_res = s21_strerror(arr);
  char* res = strerror(arr);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(strerror_str_eq_two) {
  int arr = 5;

  char* s21_res = s21_strerror(arr);
  char* res = strerror(arr);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(strerror_str_eq_three) {
  int arr = 25;

  char* s21_res = s21_strerror(arr);
  char* res = strerror(arr);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(strerror_str_eq_four) {
  int arr = 140;

  char* s21_res = s21_strerror(arr);
  char* res = strerror(arr);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

Suite* s21_strerror_suite(void) {
  Suite* suite = suite_create("s21_suite_strerror");
  TCase* tc_core = tcase_create("s21_tcase_strerror");

  tcase_add_test(tc_core, strerror_str_eq_one);
  tcase_add_test(tc_core, strerror_str_eq_two);
  tcase_add_test(tc_core, strerror_str_eq_three);
  tcase_add_test(tc_core, strerror_str_eq_four);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite* suite = s21_strerror_suite();
  SRunner* runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}