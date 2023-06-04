#include "s21_cat.h"

int main_menu(int argc, char *argv[]);
int application_of_flags(int *optind, int argc, char *argv[], int *flags);

int main(int argc, char *argv[]) {
  main_menu(argc, argv);
  return 0;
}

int main_menu(int argc, char *argv[]) {
  int flags[6] = {0};
  const char *short_options = "+benstv";
  int parametr;
  const struct option long_options[] = {
      // длинные параметры
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};
  while (
      (parametr = getopt_long(argc, argv, short_options, long_options, NULL)) !=
      -1) {  // сопостваление параметров флагам
    menu(parametr, flags);  //  подсчет переданных флагов
  }
  application_of_flags(&optind, argc, argv, flags);
  return 0;
}

int application_of_flags(int *optind, int argc, char *argv[], int *flags) {
  FILE *file;
  int empty_str = 0;
  for (; *optind < argc; (*optind)++) {
    file = fopen(argv[*optind], "r");
    if (file == NULL) {
      fprintf(stderr, "No such file or directory\n");
    } else {
      int non_empty_str_val = 0;  // количество непустых строк
      int str_val = 0;            // количество строк
      char str[1000] = {0};
      while (fgets(str, 1000, file)) {  // считывание строки из файла
        if (func_flag_s(flags[2], str, &empty_str)) {
          func_flag_b(str, flags[0], &non_empty_str_val);
          func_flag_n(flags[1], flags[0], &str_val);
          for (long unsigned int j = 0; j < sizeof(str);
               j++) {  // преобразование каждого сивола из строки
            if (func_flag_t(flags[3], str[j]) == 0 &&
                func_flag_e(flags[4], str[j]) == 0 &&
                func_flag_v(flags[5], str[j]) == 0) {
              printf("%c", str[j]);
            }
            if (str[j + 1] == 0 && str[j + 2] == 0) {
              break;
            }
          }
        }
        for (int i = 0; i < 1000; i++) {
          str[i] = 0;
        }
      }
    }
    fclose(file);
  }
  return 0;
}
