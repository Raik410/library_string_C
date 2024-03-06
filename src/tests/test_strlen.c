#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strlen_empty_string) {
  const char *str = "";
  s21_size_t len = s21_strlen(str);
  ck_assert_int_eq(len, 0);
}
END_TEST

START_TEST(test_s21_strlen_single_char) {
  const char *str = "a";
  s21_size_t len = s21_strlen(str);
  ck_assert_int_eq(len, 1);
}
END_TEST

START_TEST(test_s21_strlen_multiple_chars) {
  const char *str = "Hello, world!";
  s21_size_t len = s21_strlen(str);
  ck_assert_int_eq(len, 13);
}
END_TEST

START_TEST(test_s21_strlen_with_spaces) {
  const char *str = "   Hello   ";
  s21_size_t len = s21_strlen(str);
  ck_assert_int_eq(len, 11);
}
END_TEST

START_TEST(test_s21_strlen_with_special_chars) {
  const char *str = "!@#$%^&*()";
  s21_size_t len = s21_strlen(str);
  ck_assert_int_eq(len, 10);
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *suite = suite_create("s21_strlen_suite");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strlen_empty_string);
  tcase_add_test(tc_core, test_s21_strlen_single_char);
  tcase_add_test(tc_core, test_s21_strlen_multiple_chars);
  tcase_add_test(tc_core, test_s21_strlen_with_spaces);
  tcase_add_test(tc_core, test_s21_strlen_with_special_chars);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_strlen_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);

  int num_failed = srunner_ntests_failed(runner);

  srunner_free(runner);

  return num_failed == 0 ? 0 : 1;
}