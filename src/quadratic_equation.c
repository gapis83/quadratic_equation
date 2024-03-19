#include "quadratic_equation.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int solve_equation(double a, double b, double c, double** solutions_equation) {
  int result = 0;
  if (is_zero(a) == 0) {
    if (is_zero(b) == 0) {
      if (is_zero(c) == 0) {
        result = -2;
      } else {
        result = -1;
      }
      *solutions_equation = NULL;
    } else {
      result = allocate_memory(solutions_equation, 1);
      if (result == 1) {
        (*solutions_equation)[0] = (-1) * c / b;
      }
    }
  } else {
    result = solution_quadratic_equation(a, b, c, solutions_equation);
  }
  return result;
}

int is_zero(double number) {
  int result = 1;
  if (fabs(number) <= EPSILON) {
    result = 0;
  }
  return result;
}

int solution_quadratic_equation(double a, double b, double c,
                                double** solutions_equation) {
  double discriminant = b * b - 4 * a * c;
  int result = 0;
  if (discriminant > 0) {
    result = allocate_memory(solutions_equation, 2);
    if (result == 2) {
      double d = sqrt(discriminant) / (2 * a);
      (*solutions_equation)[0] = ((-1) * b / (2 * a)) + d;
      (*solutions_equation)[1] = ((-1) * b / (2 * a)) - d;
    }
  } else if (is_zero(discriminant) == 0) {
    result = allocate_memory(solutions_equation, 1);
    if (result == 1) {
      (*solutions_equation)[0] = -b / (2 * a);
    }
  } else {
    *solutions_equation = NULL;
    result = 0;
  }
  return result;
}

int allocate_memory(double** solutions_equation, int num_cells) {
  *solutions_equation = (double*)malloc(sizeof(double) * num_cells);
  if (*solutions_equation == NULL) {
    num_cells = -2;
  }
  return num_cells;
}
