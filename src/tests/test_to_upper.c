#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(to_upper_str_eq_one) {
  const char *str = "Hello, World!";
  const char *expected_result = "HELLO, WORLD!";

  void *s21_res = s21_to_upper(str);

  ck_assert_str_eq(s21_res, expected_result);

  free(s21_res);
}
END_TEST

START_TEST(to_upper_str_eq_two) {
  const char *str = "abc123";
  const char *expected_result = "ABC123";

  void *s21_res = s21_to_upper(str);

  ck_assert_str_eq(s21_res, expected_result);

  free(s21_res);
}
END_TEST

START_TEST(to_upper_str_eq_three) {
  const char *str = "12345";
  const char *expected_result = "12345";

  void *s21_res = s21_to_upper(str);

  ck_assert_str_eq(s21_res, expected_result);

  free(s21_res);
}
END_TEST

START_TEST(to_upper_str_eq_four) {
  const char *str = "HeLlO";
  const char *expected_result = "HELLO";

  void *s21_res = s21_to_upper(str);

  ck_assert_str_eq(s21_res, expected_result);

  free(s21_res);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *suite = suite_create("s21_to_upper_suite");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, to_upper_str_eq_one);
  tcase_add_test(tc_core, to_upper_str_eq_two);
  tcase_add_test(tc_core, to_upper_str_eq_three);
  tcase_add_test(tc_core, to_upper_str_eq_four);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_to_upper_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}
