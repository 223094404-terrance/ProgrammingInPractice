#include <stdio.h>
#include <string.h>

int main(void) {
    float salaries[50];
    float budgets[10];
    char registrations[20][20];
    float totalSalary = 0, averageSalary;
    float highestSalary, lowestSalary;
    float totalBudget = 0, averageBudget;
    float searchSalary;
    char searchRegistration[20];
    int found;

    /* A. Employee Salaries */
    printf("=== EMPLOYEE SALARY MANAGEMENT ===\n");

    for (int i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);

        if (scanf("%f", &salaries[i]) != 1 || salaries[i] <= 0) {
            printf("Invalid salary. Please enter a positive number.\n");
            return 1;
        }

        totalSalary += salaries[i];

        if (i == 0) {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        }

        if (salaries[i] > highestSalary) {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary) {
            lowestSalary = salaries[i];
        }
    }

    averageSalary = totalSalary / 50;

    printf("\n--- All Employee Salaries ---\n");
    for (int i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    printf("Total salaries: %.2f\n", totalSalary);
    printf("Average salary: %.2f\n", averageSalary);
    printf("Highest salary: %.2f\n", highestSalary);
    printf("Lowest salary: %.2f\n", lowestSalary);

    printf("\nEnter a salary to search for: ");
    if (scanf("%f", &searchSalary) != 1) {
        printf("Invalid salary input.\n");
        return 1;
    }

    found = 0;
    for (int i = 0; i < 50; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary %.2f found for employee %d.\n",
                   searchSalary, i + 1);
            found = 1;
        }
    }

    if (!found) {
        printf("Salary not found.\n");
    }

    /* B. Department Budgets */
    printf("\n=== DEPARTMENT BUDGET MANAGEMENT ===\n");

    for (int i = 0; i < 10; i++) {
        printf("Enter budget for department %d: ", i + 1);

        if (scanf("%f", &budgets[i]) != 1 || budgets[i] < 0) {
            printf("Invalid budget. Please enter zero or a positive number.\n");
            return 1;
        }

        totalBudget += budgets[i];
    }

    averageBudget = totalBudget / 10;

    printf("\n--- Department Budgets ---\n");
    for (int i = 0; i < 10; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    printf("Total budget: %.2f\n", totalBudget);
    printf("Average budget: %.2f\n", averageBudget);

    /* Sort budgets from lowest to highest */
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (budgets[j] > budgets[j + 1]) {
                float temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Budgets Sorted: Lowest to Highest ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    /* C. Vehicle Registrations */
    printf("\n=== VEHICLE REGISTRATION MANAGEMENT ===\n");

    for (int i = 0; i < 20; i++) {
        printf("Enter registration number for vehicle %d: ", i + 1);

        if (scanf("%19s", registrations[i]) != 1) {
            printf("Invalid registration input.\n");
            return 1;
        }
    }

    printf("\n--- All Vehicle Registrations ---\n");
    for (int i = 0; i < 20; i++) {
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");
    if (scanf("%19s", searchRegistration) != 1) {
        printf("Invalid registration input.\n");
        return 1;
    }

    found = 0;
    for (int i = 0; i < 20; i++) {
        if (strcmp(registrations[i], searchRegistration) == 0) {
            printf("Registration %s found for vehicle %d.\n",
                   searchRegistration, i + 1);
            found = 1;
        }
    }

    if (!found) {
        printf("Registration number not found.\n");
    }

    printf("\nMunicipal Information Management System completed.\n");

    return 0;
}
