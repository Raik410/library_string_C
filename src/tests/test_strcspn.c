#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strcspn_str_eq_default) {
  char arr[50] = "Aboba10";
  char arr_reject[50] = "10";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_empty) {
  char arr[50] = "Aboba10";
  char arr_reject[50] = "";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_long) {
  char arr[50] = "AbobaGogogogogogo51gogoGibaGibaBoba";
  char arr_reject[50] = "51";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_ru) {
  char arr[50] = "Ярусский10Яебалн";
  char arr_reject[50] = "10";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_empty_src_arr) {
  char arr[50] = "";
  char arr_reject[50] = "10";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_default_second) {
  char arr[50] = "Aboba10115";
  char arr_reject[50] = "10";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_reject_is_not_in_source) {
  char arr[50] = "AbobaGogogogogogo51gogoGibaGibaBoba";
  char arr_reject[50] = "XYZ";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_reject_is_only_in_beginning) {
  char arr[50] = "AbobaGogogogogogo51gogoGibaGibaBoba";
  char arr_reject[50] = "Ab";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_reject_is_only_in_end) {
  char arr[50] = "AbobaGogogogogogo51gogoGibaGibaBoba";
  char arr_reject[50] = "ba";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_reject_is_full_string) {
  char arr[50] = "AbobaGogogogogogo51gogoGibaGibaBoba";
  char arr_reject[50] = "AbobaGogogogogogo51gogoGibaGibaBoba";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_with_special_chars) {
  char arr[50] = "AbobaGogogogogogo51gogoGibaGibaBoba";
  char arr_reject[50] = "@$&*";

  size_t s21_res = s21_strcspn(arr, arr_reject);
  size_t res = strcspn(arr, arr_reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_one) {
  const char *str = "Hello, World!";
  const char *reject = "o";

  size_t s21_res = s21_strcspn(str, reject);
  size_t res = strcspn(str, reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_two) {
  const char *str = "Hello, World!";
  const char *reject = "qwerty";

  size_t s21_res = s21_strcspn(str, reject);
  size_t res = strcspn(str, reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_three) {
  const char *str = "Hello, World!";
  const char *reject = "H";

  size_t s21_res = s21_strcspn(str, reject);
  size_t res = strcspn(str, reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_four) {
  const char *str = "Hello, World!";
  const char *reject = "Z";

  size_t s21_res = s21_strcspn(str, reject);
  size_t res = strcspn(str, reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_five) {
  const char *str = "Hello, World!";
  const char *reject = "oH";

  size_t s21_res = s21_strcspn(str, reject);
  size_t res = strcspn(str, reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_six) {
  const char *str = "abcde";
  const char *reject = "edcba";

  size_t s21_res = s21_strcspn(str, reject);
  size_t res = strcspn(str, reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_seven) {
  const char *str = "12345";
  const char *reject = "67890";

  size_t s21_res = s21_strcspn(str, reject);
  size_t res = strcspn(str, reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(strcspn_str_eq_eight) {
  const char *str = "abcdefg";
  const char *reject = "";

  size_t s21_res = s21_strcspn(str, reject);
  size_t res = strcspn(str, reject);

  ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *suite = suite_create("s21_suite_strcspn");
  TCase *tc_core = tcase_create("s21_tcase_strcspn");

  tcase_add_test(tc_core, strcspn_str_eq_default);
  tcase_add_test(tc_core, strcspn_str_eq_empty);
  tcase_add_test(tc_core, strcspn_str_eq_empty_src_arr);
  tcase_add_test(tc_core, strcspn_str_eq_default_second);
  tcase_add_test(tc_core, strcspn_str_eq_long);
  tcase_add_test(tc_core, strcspn_str_eq_ru);
  tcase_add_test(tc_core, strcspn_with_special_chars);
  tcase_add_test(tc_core, strcspn_reject_is_full_string);
  tcase_add_test(tc_core, strcspn_reject_is_only_in_end);
  tcase_add_test(tc_core, strcspn_reject_is_only_in_beginning);
  tcase_add_test(tc_core, strcspn_reject_is_not_in_source);
  tcase_add_test(tc_core, strcspn_str_eq_one);
  tcase_add_test(tc_core, strcspn_str_eq_two);
  tcase_add_test(tc_core, strcspn_str_eq_three);
  tcase_add_test(tc_core, strcspn_str_eq_four);
  tcase_add_test(tc_core, strcspn_str_eq_five);
  tcase_add_test(tc_core, strcspn_str_eq_six);
  tcase_add_test(tc_core, strcspn_str_eq_seven);
  tcase_add_test(tc_core, strcspn_str_eq_eight);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_strcspn_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}