
#include <stdio.h>

// Wrong version: uses ordinary parameters
void wrongSwap(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
}

// Correct version: uses pointers
void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    double salary1 = 15000.00;
    double salary2 = 20000.00;

    printf("SALARY SWAPPING DEMONSTRATION\n");
    printf("-----------------------------\n");

    // Demonstrate the wrong version
    printf("\nBefore wrongSwap:\n");
    printf("Salary 1: N$%.2f\n", salary1);
    printf("Salary 2: N$%.2f\n", salary2);

    wrongSwap(salary1, salary2);

    printf("\nAfter wrongSwap:\n");
    printf("Salary 1: N$%.2f\n", salary1);
    printf("Salary 2: N$%.2f\n", salary2);

    // Demonstrate the correct version
    swapSalaries(&salary1, &salary2);

    printf("\nAfter correct swapSalaries:\n");
    printf("Salary 1: N$%.2f\n", salary1);
    printf("Salary 2: N$%.2f\n", salary2);

    return 0;
}
