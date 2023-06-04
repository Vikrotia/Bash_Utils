all: s21_grep

s21_grep:
	gcc -Wall -Werror -Wextra s21_grep.c -o s21_grep
	rm -rf *.o

clean:
	rm -rf *.o s21_grep

rebuild: clean all

test_funcs:
	sh test_func_grep.sh

test_leaks:
	sh test_leak_grep.sh
