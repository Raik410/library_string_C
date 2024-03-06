#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *strc2) {
  const char *first;
  const char *second;

  s21_size_t count = 0;
  int found = 0;

  for (first = str1; *first != '\0'; ++first) {
    for (second = strc2; *second != '\0'; ++second) {
      if (*first == *second) {
        found = 1;
        break;
      }
    }
    if (!found) {
      return count;
    }
    count++;
  }
  return count;
}
