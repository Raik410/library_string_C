#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memset_str_eq_0_byted) {
  char arr[] = "Aboba";
  char arr_origin[] = "Aboba";
  s21_size_t len = 0;

  s21_memset(arr, '$', len);
  memset(arr_origin, '$', len);

  ck_assert_str_eq(arr, arr_origin);
  ck_assert_pstr_eq(memset(arr_origin, '$', len), s21_memset(arr, '$', len));
}
END_TEST

START_TEST(memset_str_eq_3_byted) {
  char arr[] = "Aboba";
  char arr_origin[] = "Aboba";
  s21_size_t len = 3;

  s21_memset(arr, '$', len);
  memset(arr_origin, '$', len);

  ck_assert_str_eq(arr, arr_origin);
}
END_TEST

START_TEST(memset_str_eq_5_byted) {
  char arr[] = "Aboba";
  char arr_origin[] = "Aboba";
  s21_size_t len = 5;

  s21_memset(arr, '$', len);
  memset(arr_origin, '$', len);

  ck_assert_str_eq(arr, arr_origin);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *suite = suite_create("s21_suite_memset");
  TCase *tc_core = tcase_create("s21_tcase_memset");

  tcase_add_test(tc_core, memset_str_eq_0_byted);
  tcase_add_test(tc_core, memset_str_eq_3_byted);
  tcase_add_test(tc_core, memset_str_eq_5_byted);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_memset_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}