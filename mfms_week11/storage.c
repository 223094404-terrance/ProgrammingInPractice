
#include <stdio.h>
#include "storage.h"
#include "records.h"

/* Week 10: Save employee IDs as text */
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

    fclose(fp);
    printf("Employee IDs saved successfully.\n");
}

/* Week 10: Load employee IDs from text */
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

/* Week 10: Save budget as text */
void saveBudgetText(float revenue, float expenses)
{
    FILE *fp = fopen("data/budget.txt", "w");

    if (fp == NULL) {
        perror("data/budget.txt");
        return;
    }

    fprintf(fp, "%.2f %.2f\n", revenue, expenses);
    fclose(fp);

    printf("Budget data saved successfully.\n");
}

/* Week 10: Load budget from text */
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

/* Week 10: Save fixed employee IDs in binary */
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

    fclose(fp);
    printf("Binary employee data saved successfully.\n");
}

/* Week 10: Load fixed employee IDs from binary */
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
        printf("Binary employee file is empty or incomplete.\n");
        fclose(fp);
        return;
    }

    printf("\n===== BINARY EMPLOYEE DATA =====\n");

    for (i = 0; i < 5; i++) {
        printf("Employee ID: %d\n", employeeIDs[i]);
    }

    fclose(fp);
}

/* Week 11: Save actual employee records */
void saveEmployeeRecordsBinary(void)
{
    FILE *fp = fopen("data/employee_records.dat", "wb");

    if (fp == NULL) {
        perror("data/employee_records.dat");
        return;
    }

    if (fwrite(&employeeCount, sizeof employeeCount, 1, fp) != 1) {
        perror("Error saving employee count");
        fclose(fp);
        return;
    }

    if (fwrite(employees, sizeof(Employee),
               (size_t)employeeCount, fp) != (size_t)employeeCount) {
        perror("Error saving employee records");
        fclose(fp);
        return;
    }

    fclose(fp);
    printf("Employee records saved successfully.\n");
}

/* Week 11: Load actual employee records */
void loadEmployeeRecordsBinary(void)
{
    FILE *fp = fopen("data/employee_records.dat", "rb");
    int savedCount;

    if (fp == NULL) {
        perror("data/employee_records.dat");
        return;
    }

    if (fread(&savedCount, sizeof savedCount, 1, fp) != 1) {
        printf("Could not read the saved employee count.\n");
        fclose(fp);
        return;
    }

    if (savedCount < 0 || savedCount > MAX_RECORDS) {
        printf("Invalid employee count in file.\n");
        fclose(fp);
        return;
    }

    if (fread(employees, sizeof(Employee),
              (size_t)savedCount, fp) != (size_t)savedCount) {
        printf("Could not read all employee records.\n");
        fclose(fp);
        return;
    }

    fclose(fp);
    employeeCount = savedCount;

    printf("Employee records loaded successfully.\n");
}
