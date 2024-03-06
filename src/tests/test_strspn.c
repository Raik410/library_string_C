#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strspn_str_eq_default) {
  char arr[50] = "Aboba10";
  char arr_reject[50] = "10";

  size_t s21_res = s21_strspn(arr, arr_reject);
  size_t res = strspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strspn_str_eq_empty) {
  char arr[50] = "Aboba10";
  char arr_reject[50] = "";

  size_t s21_res = s21_strspn(arr, arr_reject);
  size_t res = strspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strspn_str_eq_long) {
  char arr[50] = "AbobaGogogogogogo51gogoGibaGibaBoba";
  char arr_reject[50] = "51";

  size_t s21_res = s21_strspn(arr, arr_reject);
  size_t res = strspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strspn_str_eq_ru) {
  char arr[50] = "Ярусский10Яебалн";
  char arr_reject[50] = "10";

  size_t s21_res = s21_strspn(arr, arr_reject);
  size_t res = strspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strspn_str_eq_empty_src_arr) {
  char arr[50] = "";
  char arr_reject[50] = "10";

  size_t s21_res = s21_strspn(arr, arr_reject);
  size_t res = strspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strspn_str_eq_default_second) {
  char arr[50] = "Aboba10115";
  char arr_reject[50] = "10";

  size_t s21_res = s21_strspn(arr, arr_reject);
  size_t res = strspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strspn_str_eq_digits) {
  const char *str = "1234567890";
  const char *accept = "0123456789";

  size_t s21_res = s21_strspn(str, accept);
  size_t res = strspn(str, accept);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strspn_str_eq_letters) {
  const char *str = "HelloWorld";
  const char *accept = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  size_t s21_res = s21_strspn(str, accept);
  size_t res = strspn(str, accept);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strspn_str_eq_symbol) {
  const char *str = "!@#$%^&*()";
  const char *accept = "!@#$%^&*()";

  size_t s21_res = s21_strspn(str, accept);
  size_t res = strspn(str, accept);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *s21_strspn_suite(void) {
  Suite *suite = suite_create("s21_suite_strspn");
  TCase *tc_core = tcase_create("s21_tcase_strspn");

  tcase_add_test(tc_core, strspn_str_eq_default);
  tcase_add_test(tc_core, strspn_str_eq_empty);
  tcase_add_test(tc_core, strspn_str_eq_empty_src_arr);
  tcase_add_test(tc_core, strspn_str_eq_default_second);
  tcase_add_test(tc_core, strspn_str_eq_long);
  tcase_add_test(tc_core, strspn_str_eq_ru);
  tcase_add_test(tc_core, strspn_str_eq_digits);
  tcase_add_test(tc_core, strspn_str_eq_letters);
  tcase_add_test(tc_core, strspn_str_eq_symbol);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_strspn_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}