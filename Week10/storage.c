#include <stdio.h>
#include "storage.h"

void saveEmployeesText(void)
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int count = 5;
    int i;

    FILE *fp = fopen("data/employees.txt", "w");

    if (fp == NULL) {
        perror("data/employees.txt");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%d\n", employeeIDs[i]);
    }

    if (fclose(fp) != 0) {
        perror("Error closing employees.txt");
        return;
    }

    printf("Employee IDs saved successfully.\n");
}

void loadEmployeesText(void)
{
    int id;
    FILE *fp = fopen("data/employees.txt", "r");

    if (fp == NULL) {
        perror("data/employees.txt");
        return;
    }

    printf("\n===== SAVED EMPLOYEE IDs =====\n");

    while (fscanf(fp, "%d", &id) == 1) {
        printf("Employee ID: %d\n", id);
    }

    fclose(fp);
}

void saveBudgetText(float revenue, float expenses)
{
    FILE *fp = fopen("data/budget.txt", "w");

    if (fp == NULL) {
        perror("data/budget.txt");
        return;
    }

    fprintf(fp, "%.2f %.2f\n", revenue, expenses);

    if (fclose(fp) != 0) {
        perror("Error closing budget.txt");
        return;
    }

    printf("Budget data saved successfully.\n");
}

void loadBudgetText(void)
{
    float revenue;
    float expenses;
    FILE *fp = fopen("data/budget.txt", "r");

    if (fp == NULL) {
        perror("data/budget.txt");
        return;
    }

    if (fscanf(fp, "%f %f", &revenue, &expenses) == 2) {
        printf("\n===== SAVED BUDGET =====\n");
        printf("Revenue: %.2f\n", revenue);
        printf("Expenses: %.2f\n", expenses);
        printf("Balance: %.2f\n", revenue - expenses);
    } else {
        printf("The budget file contains invalid data.\n");
    }

    fclose(fp);
}

void saveEmployeesBinary(void)
{
    int employeeIDs[] = {101, 102, 103, 104, 105};

    FILE *fp = fopen("data/employees.dat", "wb");

    if (fp == NULL) {
        perror("data/employees.dat");
        return;
    }

    if (fwrite(employeeIDs, sizeof employeeIDs, 1, fp) != 1) {
        perror("Error writing binary employee data");
        fclose(fp);
        return;
    }

    if (fclose(fp) != 0) {
        perror("Error closing employees.dat");
        return;
    }

    printf("Binary employee data saved successfully.\n");
}
void loadEmployeesBinary(void)
{
    int employeeIDs[5];
    FILE *fp = fopen("data/employees.dat", "rb");
    size_t count;
    int i;

    if (fp == NULL) {
        perror("data/employees.dat");
        return;
    }

    count = fread(employeeIDs, sizeof employeeIDs, 1, fp);

    if (count != 1) {
        if (ferror(fp)) {
            perror("Error reading binary employee data");
        } else {
            printf("Binary employee file is empty or incomplete.\n");
        }

        fclose(fp);
        return;
    }

    printf("\n===== BINARY EMPLOYEE DATA =====\n");

    for (i = 0; i < 5; i++) {
        printf("Employee ID: %d\n", employeeIDs[i]);
    }

    fclose(fp);
}
