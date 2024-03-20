# Quadratic_equation

Это простая библиотека на языке C для решения квадратных уравнений вида ''ax^2 + bx + c = 0.''

## Использование

Включите заголовочный файл `quadratic_equation.h` в свой проект:

```c
#include "quadratic_equation.h"
```

Вызовите функцию solve_equation с коэффициентами a, b и c, чтобы получить корни уравнения:
```c
double* solutions;
int num_solutions = solve_equation(a, b, c, &solutions);

if (num_solutions == 0) {
    printf("Уравнение не имеет решений.\n");
} else if (num_solutions == 1) {
    printf("Уравнение имеет один корень: %.2f\n", solutions[0]);
} else if (num_solutions == 2) {
    printf("Уравнение имеет два корня: %.2f и %.2f\n", solutions[0], solutions[1]);
} else if (num_solutions == -1) {
    printf("Уравнение имеет бесконечное количество решений.\n");
} else if (num_solutions == -2) {
    printf("Ошибка выделения памяти.\n");
} else if (num_solutions == -3) {
    printf("Некорректное выражение.\n");
}

free(solutions); // Освобождаем память после использования
```
## Зависимости
Данная библиотека не имеет внешних зависимостей.


