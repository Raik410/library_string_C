#include "s21_string.h"

int get_length(int num) {
  int length = 0;

  while (num != 0) {
    num /= 10;
    length++;
  }

  return length;
}

char* int_to_string(int num) {
  int length = get_length(num);
  static char str[200] = "";
  int index = length - 1;

  while (num != 0) {
    int digit = num % 10;
    str[index] = digit + '0';  // Не понял да? А все потому что '0' по аски
                               // начинается с 48, интересует? :D
    num /= 10;
    index--;
  }

  str[length] = '\0';

  return str;
}