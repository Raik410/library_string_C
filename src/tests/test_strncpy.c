#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strncpy_str_eq_default) {
  char arr[50] = "A";
  char arr_origin[50] = "Aboba";
  s21_size_t len = strlen(arr_origin);

  char* s21_res = s21_strncpy(arr, arr_origin, len);
  char* res = strncpy(arr, arr_origin, len);

  ck_assert_pstr_eq(s21_res, res);
}
END_TEST

START_TEST(strncpy_str_eq_second) {
  char arr[50] = "Abo";
  char arr_origin[50] = "Aboba";
  s21_size_t len = strlen(arr_origin);

  char* s21_res = s21_strncpy(arr, arr_origin, len);
  char* res = strncpy(arr, arr_origin, len);

  ck_assert_pstr_eq(s21_res, res);
}
END_TEST

START_TEST(strncpy_str_eq_true_anotherone) {
  char arr[50] = "Aboba";
  char arr_origin[50] = "Ab";
  s21_size_t len = strlen(arr_origin);

  char* s21_res = s21_strncpy(arr, arr_origin, len);
  char* res = strncpy(arr, arr_origin, len);

  ck_assert_pstr_eq(s21_res, res);
}
END_TEST

Suite* s21_strncpy_suite(void) {
  Suite* suite = suite_create("s21_suite_strncpy");
  TCase* tc_core = tcase_create("s21_tcase_strncpy");

  tcase_add_test(tc_core, strncpy_str_eq_default);
  tcase_add_test(tc_core, strncpy_str_eq_second);
  tcase_add_test(tc_core, strncpy_str_eq_true_anotherone);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite* suite = s21_strncpy_suite();
  SRunner* runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}