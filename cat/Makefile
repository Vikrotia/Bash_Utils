
all: s21_cat

s21_cat:  
	gcc -Wall -Werror -Wextra s21_cat.c flags.c -o s21_cat

clean:
	rm -rf *.o s21_cat

rebuild: clean all

test_funcs:
	sh test_func_cat.sh

test_leaks:
	sh test_leak_cat.sh
