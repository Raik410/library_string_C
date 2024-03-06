#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memchr_ptr_eq_null) {
  const char *str = "Hello, world!";
  int c = 'A';
  s21_size_t n = strlen(str);

  void *result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(memchr_ptr_eq_default) {
  const char *str = "Hello, world!";
  int c = 'e';
  s21_size_t n = strlen(str);

  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
  ck_assert_pstr_eq(s21_result, result);
}
END_TEST

START_TEST(memchr_ptr_eq_default_second) {
  const char *str = "Hello, world!";
  int c = 'w';
  s21_size_t n = strlen(str);

  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *suite = suite_create("s21_suite_memchr");
  TCase *tc_core = tcase_create("s21_tcase_memchr");

  tcase_add_test(tc_core, memchr_ptr_eq_null);
  tcase_add_test(tc_core, memchr_ptr_eq_default);
  tcase_add_test(tc_core, memchr_ptr_eq_default_second);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_memchr_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}