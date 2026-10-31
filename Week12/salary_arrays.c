
#include <stdio.h>

// Function 1: Display all salaries
void displaySalaries(const double salaries[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

// Function 2: Find the highest salary
double findHighest(const double salaries[], int n)
{
    double highest = salaries[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
    }

    return highest;
}

// Function 3: Calculate average salary
double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;
    int i;

    for (i = 0; i < n; i++)
    {
        total += salaries[i];
    }

    return total / n;
}

// Function 4: Give employees a salary raise
void giveRaise(double salaries[], int n, double percent)
{
    int i;

    for (i = 0; i < n; i++)
    {
        salaries[i] = salaries[i] + (salaries[i] * percent / 100);
    }
}

int main(void)
{
    double salaries[3] = {15000.00, 18500.50, 21000.75};
    int count = 3;
    double average;

    printf("EMPLOYEE SALARY ANALYSIS\n");
    printf("========================\n");

    // Display original salaries
    printf("\nOriginal salaries:\n");
    displaySalaries(salaries, count);

    // Find highest salary
    printf("\nHighest salary: N$%.2f\n",
           findHighest(salaries, count));

    // Calculate average
    average = calculateAverage(salaries, count);
    printf("Average salary: N$%.2f\n", average);

    // Give a 10% raise
    printf("\nGiving employees a 10%% raise...\n");
    giveRaise(salaries, count, 10.0);

    // Display updated salaries
    printf("\nUpdated salaries:\n");
    displaySalaries(salaries, count);

    return 0;
}
