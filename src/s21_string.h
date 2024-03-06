#ifndef S21_STRING_H
#define S21_STRING_H

#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool hash;
  int accuracy;
  int is_accuracy_set;
  int width;
  char length;
  char specifier;
} flags;

#define S21_ISNAN(x) ((x) != (x))
#define S21_INF_POS (DBL_MAX + DBL_MAX)
#define S21_INF_NEG (-S21_INF_POS)
#define S21_IS_INFINITY(x) ((x) == S21_INF_POS || (x) == S21_INF_NEG)

#define s21_size_t unsigned long

#define SIZE (512)

#define S21_NULL ((void *)0)

int get_length(int num);

char *int_to_string(int num);

s21_size_t s21_strlen(const char *str);

void *s21_memchr(const void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

void *s21_memcpy(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, s21_size_t n);

char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strchr(const char *str, int c);

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strcspn(const char *str1, const char *str2);

s21_size_t s21_strspn(const char *str1, const char *str2);

char *s21_strerror(int errnum);

char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);

void *s21_to_lower(const char *str);

void *s21_to_upper(const char *str);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void *s21_trim(const char *src, const char *trim_chars);

int s21_sprintf(char *str, const char *format, ...);

#endif