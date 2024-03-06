#include "s21_string.h"

char *s21_strrchr(const char *str, int n) {
  const char *result = S21_NULL;
  int lenght = s21_strlen(str);
  for (int i = lenght; i >= 0; i--) {
    if (str[i] == n) {
      result = (str + i);
      break;
    }
  }
  return (char *)result;
}