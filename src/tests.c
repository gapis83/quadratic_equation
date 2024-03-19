#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "quadratic_equation.h"

START_TEST(test_basic_with_integer_values_1) {
  double a = 1.0, b = -6.0, c = 9.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);
  double expected_solution = 3.0;

  ck_assert_int_eq(num_solutions, 1);
  ck_assert_ptr_nonnull(solutions);
  ck_assert_double_eq(*solutions, expected_solution);

  free(solutions);
}
END_TEST

START_TEST(test_basic_with_integer_values_2) {
  double a = 1.0, b = -5.0, c = 6.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);
  double expected_solution_1 = 3.0;
  double expected_solution_2 = 2.0;

  ck_assert_int_eq(num_solutions, 2);
  ck_assert_ptr_nonnull(solutions);
  ck_assert_double_eq(*solutions, expected_solution_1);
  ck_assert_double_eq(*(solutions + 1), expected_solution_2);

  free(solutions);
}
END_TEST

START_TEST(test_basic_with_integer_values_3) {
  double a = -1.0, b = 5.0, c = -6.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);
  double expected_solution_1 = 2.0;
  double expected_solution_2 = 3.0;

  ck_assert_int_eq(num_solutions, 2);
  ck_assert_ptr_nonnull(solutions);
  ck_assert_double_eq(*solutions, expected_solution_1);
  ck_assert_double_eq(*(solutions + 1), expected_solution_2);

  free(solutions);
}
END_TEST

START_TEST(test_basic_with_integer_values_4) {
  double a = 2.0, b = 3.0, c = -5.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);
  double expected_solution_1 = 1.0;
  double expected_solution_2 = -2.5;

  ck_assert_int_eq(num_solutions, 2);
  ck_assert_ptr_nonnull(solutions);
  ck_assert_double_eq(*solutions, expected_solution_1);
  ck_assert_double_eq(*(solutions + 1), expected_solution_2);

  free(solutions);
}
END_TEST

START_TEST(test_no_solutions_1) {
  double a = 1.0, b = 2.0, c = 3.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);

  ck_assert_int_eq(num_solutions, 0);
  ck_assert_ptr_null(solutions);
}
END_TEST

START_TEST(test_linear_equation) {
  double a = 0.0, b = 2.0, c = 3.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);

  ck_assert_int_eq(num_solutions, 1);
  ck_assert_ptr_nonnull(solutions);

  ck_assert_double_eq(*solutions, -c / b);

  free(solutions);
}
END_TEST

START_TEST(test_no_solutions_2) {
  double a = 0.0, b = 0.0, c = 3.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);

  ck_assert_int_eq(num_solutions, -1);
  ck_assert_ptr_null(solutions);
}
END_TEST

START_TEST(test_infinite_solutions) {
  double a = 0.0, b = 0.0, c = 0.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);

  ck_assert_int_eq(num_solutions, -2);
  ck_assert_ptr_null(solutions);
}
END_TEST

START_TEST(test_fractional_values_1) {
  double a = 0.5, b = -1.5, c = 0.5;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);
  double expected_solution_1 = 2.61803;
  double expected_solution_2 = 0.381966;

  ck_assert_int_eq(num_solutions, 2);
  ck_assert_ptr_nonnull(solutions);
  ck_assert_double_eq_tol(*solutions, expected_solution_1, 1e-4);
  ck_assert_double_eq_tol(*(solutions + 1), expected_solution_2, 1e-4);

  free(solutions);
}
END_TEST

START_TEST(test_fractional_values_2) {
  double a = 0.25, b = -1.0, c = 1.0;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);
  double expected_solution_1 = 2.0;

  ck_assert_int_eq(num_solutions, 1);
  ck_assert_ptr_nonnull(solutions);
  ck_assert_double_eq(*solutions, expected_solution_1);

  free(solutions);
}
END_TEST

START_TEST(test_fractional_values_3) {
  double a = -0.2, b = 2.6, c = -1.2;
  double *solutions = NULL;
  int num_solutions = solve_equation(a, b, c, &solutions);
  double expected_solution_1 = 0.4792027106038521;
  double expected_solution_2 = 12.520797289396148;

  ck_assert_int_eq(num_solutions, 2);
  ck_assert_ptr_nonnull(solutions);
  ck_assert_double_eq_tol(*solutions, expected_solution_1, 1e-10);
  ck_assert_double_eq_tol(*(solutions + 1), expected_solution_2, 1e-10);

  free(solutions);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int a;

  suite_add_tcase(s1, tc_1);

  tcase_add_test(tc_1, test_basic_with_integer_values_1);
  tcase_add_test(tc_1, test_basic_with_integer_values_2);
  tcase_add_test(tc_1, test_basic_with_integer_values_3);
  tcase_add_test(tc_1, test_basic_with_integer_values_4);
  tcase_add_test(tc_1, test_no_solutions_1);
  tcase_add_test(tc_1, test_linear_equation);
  tcase_add_test(tc_1, test_no_solutions_2);
  tcase_add_test(tc_1, test_infinite_solutions);
  tcase_add_test(tc_1, test_fractional_values_1);
  tcase_add_test(tc_1, test_fractional_values_2);
  tcase_add_test(tc_1, test_fractional_values_3);

  srunner_run_all(sr, CK_ENV);
  a = srunner_ntests_failed(sr);
  srunner_free(sr);

  return a == 0 ? 0 : 1;
}
