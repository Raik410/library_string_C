#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memcpy_str_eq_default) {
  char s21_dest[100] = "";
  char s21_src[] = "Aboba";
  char dest[100] = "";
  char src[] = "Aboba";

  s21_size_t s21_len = s21_strlen(s21_src);
  s21_size_t len = s21_strlen(src);

  s21_memcpy(s21_dest, s21_src, s21_len);
  memcpy(dest, src, len);

  ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(memcpy_str_eq_empty_string) {
  char s21_dest[] = "";
  char s21_src[] = "";
  char dest[] = "";
  char src[] = "";

  s21_size_t s21_len = s21_strlen(s21_src);
  s21_size_t len = s21_strlen(s21_src);

  s21_memcpy(s21_dest, s21_src, s21_len);
  memcpy(dest, src, len);

  ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(memcpy_str_eq_long_string) {
  char s21_dest[100] = "";
  char s21_src[] = "AbobaBobaBaba";
  char dest[100] = "";
  char src[] = "AbobaBobaBaba";

  s21_size_t s21_len = s21_strlen(s21_src);
  s21_size_t len = s21_strlen(s21_src);

  s21_memcpy(s21_dest, s21_src, s21_len);
  memcpy(dest, src, len);

  ck_assert_str_eq(s21_dest, dest);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *suite = suite_create("s21_suite_memcpy");
  TCase *tc_core = tcase_create("s21_tcase_memcpy");

  tcase_add_test(tc_core, memcpy_str_eq_default);
  tcase_add_test(tc_core, memcpy_str_eq_empty_string);
  tcase_add_test(tc_core, memcpy_str_eq_long_string);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_memcpy_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}