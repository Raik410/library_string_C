#include "s21_string.h"

char *s21_strcat(char *dest, const char *src);

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) {
    return S21_NULL;
  }

  if (start_index > s21_strlen(src)) {
    return S21_NULL;
  }

  char *result = malloc(s21_strlen(src) + s21_strlen(str) + 1);

  if (!result) {
    return S21_NULL;
  }

  s21_strncpy(result, src, start_index);  // "Hello"
  result[start_index] = '\0';
  s21_strcat(result, str);  // "Hello Biba"
  s21_strcat(result, src + start_index);

  return (void *)result;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i, j;

  for (i = 0; dest[i] != '\0'; i++)
    ;

  for (j = 0; src[j] != '\0'; j++) dest[i + j] = src[j];

  dest[i + j] = '\0';

  return dest;
}