#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define strLength 1000

int comp_paterns(regex_t *regex_str, int *flags, char *template);
int regex_read_file(char temptates[][strLength], int *number_of_templates,
                    char optarg[]);
int file_check(FILE *file, char *argv[], int i, int *flags);
int func_flag_e(int *flags, regex_t regex_str, char *str);
int func_flag_v(int *flags, regex_t regex_str, char *str);
int menu(int argc, char *argv[]);
void application_of_flags(int files, int argc, char *argv[], int flags[10],
                          int number_of_templates, int numbers_of_files,
                          char temptates[][strLength]);

#endif  // SRC_GREP_S21_GREP_H_
