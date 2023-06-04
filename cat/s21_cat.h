#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int parametr, int *flags);
void func_flag_b(char *str, int flag_b, int *non_empty_str_val);
void func_flag_n(int flag_n, int flag_b, int *str_val);
int func_flag_v(int flag_v, char str);
int func_flag_s(int flag_s, char *str, int *empty_str);
int func_flag_t(int flag_t, char str);
int func_flag_e(int flag_e, char str);
#endif  // SRC_CAT_S21_CAT_H_
