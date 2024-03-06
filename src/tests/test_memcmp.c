#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memcmp_str_eq_true) {
  char arr[] = "Aboba";
  char arr_origin[] = "Aboba";
  s21_size_t len = strlen(arr_origin);

  int s21_res = s21_memcmp(arr, arr_origin, len);
  int res = memcmp(arr, arr_origin, len);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(memcmp_str_eq_false_neg) {
  char arr[] = "Abo";
  char arr_origin[] = "Aboba";
  s21_size_t len = strlen(arr_origin);

  int s21_res = s21_memcmp(arr, arr_origin, len);

  ck_assert_int_eq(s21_res, -1);
}
END_TEST

START_TEST(memcmp_str_eq_false_pos) {
  char arr[] = "Aboba";
  char arr_origin[] = "Abo";
  s21_size_t len = strlen(arr_origin);

  int s21_res = s21_memcmp(arr, arr_origin, len);

  ck_assert_int_eq(s21_res, 1);
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *suite = suite_create("s21_suite_memcmp");
  TCase *tc_core = tcase_create("s21_tcase_memcmp");

  tcase_add_test(tc_core, memcmp_str_eq_true);
  tcase_add_test(tc_core, memcmp_str_eq_false_pos);
  tcase_add_test(tc_core, memcmp_str_eq_false_neg);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_memcmp_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}