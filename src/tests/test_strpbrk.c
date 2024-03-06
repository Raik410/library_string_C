#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strpbrk_str_eq_one) {
  char arr[50] = "Aboba410";
  char arr_origin[50] = "4";

  char* s21_res = s21_strpbrk(arr, arr_origin);
  char* res = strpbrk(arr, arr_origin);

  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(strpbrk_str_eq_two) {
  char arr[50] = "A";
  char arr_origin[50] = "A";

  char* s21_res = s21_strpbrk(arr, arr_origin);
  char* res = strpbrk(arr, arr_origin);

  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(strpbrk_str_eq_three) {
  char arr[50] = "A";
  char arr_origin[50] = "Aogo";

  char* s21_res = s21_strpbrk(arr, arr_origin);
  char* res = strpbrk(arr, arr_origin);

  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(strpbrk_str_eq_four) {
  char arr[50] = "Abob";
  char arr_origin[50] = "b";

  char* s21_res = s21_strpbrk(arr, arr_origin);
  char* res = strpbrk(arr, arr_origin);

  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(strpbrk_str_eq_five) {
  char arr[50] = "Hello, World!";
  char arr_origin[50] = "o";

  char* s21_res = s21_strpbrk(arr, arr_origin);
  char* res = strpbrk(arr, arr_origin);

  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(strpbrk_str_eq_six) {
  char arr[50] = "Hello, World!";
  char arr_origin[50] = "qwerty";

  char* s21_res = s21_strpbrk(arr, arr_origin);
  char* res = strpbrk(arr, arr_origin);

  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(strpbrk_str_eq_seven) {
  char arr[50] = "Hello, World!";
  char arr_origin[50] = "H";

  char* s21_res = s21_strpbrk(arr, arr_origin);
  char* res = strpbrk(arr, arr_origin);

  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(strpbrk_str_eq_eight) {
  char arr[50] = "Hello, World!";
  char arr_origin[50] = "Z";

  char* s21_res = s21_strpbrk(arr, arr_origin);
  char* res = strpbrk(arr, arr_origin);

  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

Suite* s21_strpbrk_suite(void) {
  Suite* suite = suite_create("s21_suite_strpbrk");
  TCase* tc_core = tcase_create("s21_tcase_strpbrk");

  tcase_add_test(tc_core, strpbrk_str_eq_one);
  tcase_add_test(tc_core, strpbrk_str_eq_two);
  tcase_add_test(tc_core, strpbrk_str_eq_three);
  tcase_add_test(tc_core, strpbrk_str_eq_four);
  tcase_add_test(tc_core, strpbrk_str_eq_five);
  tcase_add_test(tc_core, strpbrk_str_eq_six);
  tcase_add_test(tc_core, strpbrk_str_eq_seven);
  tcase_add_test(tc_core, strpbrk_str_eq_eight);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite* suite = s21_strpbrk_suite();
  SRunner* runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}