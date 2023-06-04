#include "s21_cat.h"

void func_flag_b(char *str, int flag_b, int *non_empty_str_val) {
  if (flag_b) {
    if (strcmp(str, "\n") != 0) {
      (*non_empty_str_val)++;
      printf("%6.d	", *non_empty_str_val);
    }
  }
}
void func_flag_n(int flag_n, int flag_b, int *str_val) {
  if (flag_n && flag_b == 0) {
    (*str_val)++;
    printf("%6.d	", *str_val);
  }
}
int func_flag_s(int flag_s, char *str, int *empty_str) {
  int res = 1;
  if (flag_s) {
    if (str[0] == '\n') {
      (*empty_str)++;
    } else {
      *empty_str = 0;
    }
    if (*empty_str > 1) {
      res = 0;
    }
  }
  return res;
}
int func_flag_t(int flag_t, char str) {
  int res = 0;
  if (flag_t) {
    if (str == '\t') {
      printf("^I");
      res = 1;
    }
  }
  return res;
}
int func_flag_e(int flag_e, char str) {
  int res = 0;
  if (flag_e) {
    if (str == '\n') {
      printf("$");
      printf("\n");
      res = 1;
    }
  }
  return res;
}
int func_flag_v(int flag_v, char str) {
  int res = 0;
  if (flag_v) {
    if ((str >= 0 && str < 9) || (str > 10 && str < 32) || (str > 126)) {
      printf("^");
      if (str > 126) {
        str -= 64;
        printf("%c", str);
      } else {
        str += 64;
        printf("%c", str);
      }
      res = 1;
    }
  }
  return res;
}
void menu(int parametr, int *flags) {
  switch (parametr) {
    case 'b':
      flags[0] = 1;
      break;
    case 'n':
      flags[1] = 1;
      break;
    case 's':
      flags[2] = 1;
      break;
    case 't':
      flags[3] = 1;
      flags[5] = 1;
      break;
    case 'e':
      flags[4] = 1;
      flags[5] = 1;
      break;
    case 'v':
      flags[5] = 1;

      break;
    default:
      break;
  }
}