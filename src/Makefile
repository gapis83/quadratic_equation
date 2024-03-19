CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11

all: clean quadratic_equation.a tests

tests: quadratic_equation.a
	@$(CC) $(FLAGS) tests.c quadratic_equation.a -lcheck -lsubunit -lm -o tests.out
	@./tests.out

quadratic_equation.a: quadratic_equation.o
	@ar rc $@ $^
	@ranlib $@

quadratic_equation.o: quadratic_equation.c quadratic_equation.h
	@$(CC) $(FLAGS) -c $<

clean:
	@rm -rf *.o
	@rm -rf *.a
	@rm -rf *.out
	@rm -rf gcov_*
	@rm -rf ./report

gcov_report: gcov_report_build
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	
gcov_report_build: 
	@$(CC) $(FLAGS) --coverage tests.c quadratic_equation.c -o gcov_report -lcheck -lsubunit -lm
	@./gcov_report
	@lcov -t "./gcov_report" -o gcov_report.info -c -d .
	@genhtml -o report gcov_report.info
	open ./report/index.html
