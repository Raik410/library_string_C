#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strrchr_str_eq_default) {
  char arr[50] = "Abo.ba";
  char ch = '.';

  char* s21_res = s21_strrchr(arr, ch);
  char* res = strrchr(arr, ch);

  ck_assert_pstr_eq(s21_res, res);
}
END_TEST

START_TEST(strrchr_str_eq_empty) {
  char arr[50] = "Abo.ba";
  char ch = ' ';

  char* s21_res = s21_strrchr(arr, ch);
  char* res = strrchr(arr, ch);

  ck_assert_pstr_eq(s21_res, res);
}
END_TEST

START_TEST(strrchr_str_eq_empty_src) {
  char arr[50] = "  ";
  char ch = '.';

  char* s21_res = s21_strrchr(arr, ch);
  char* res = strrchr(arr, ch);

  ck_assert_pstr_eq(s21_res, res);
}
END_TEST

START_TEST(strrchr_str_eq_long) {
  char arr[50] = "Abo.baJAJAJJARHA";
  char ch = 'R';

  char* s21_res = s21_strrchr(arr, ch);
  char* res = strrchr(arr, ch);

  ck_assert_pstr_eq(s21_res, res);
}
END_TEST

Suite* s21_strrchr_suite(void) {
  Suite* suite = suite_create("s21_suite_strrchr");
  TCase* tc_core = tcase_create("s21_tcase_strrchr");

  tcase_add_test(tc_core, strrchr_str_eq_default);
  tcase_add_test(tc_core, strrchr_str_eq_empty);
  tcase_add_test(tc_core, strrchr_str_eq_empty_src);
  tcase_add_test(tc_core, strrchr_str_eq_long);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite* suite = s21_strrchr_suite();
  SRunner* runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}