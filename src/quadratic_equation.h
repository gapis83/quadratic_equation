#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static const double EPSILON = 1e-7;

int solve_equation(double a, double b, double c, double** solutions_equation);
int solution_quadratic_equation(double a, double b, double c,
                                double** solutions_equation);
int is_zero(double number);
int allocate_memory(double** solutions_equation, int num_cells);

#endif  // QUADRATIC_EQUATION_H