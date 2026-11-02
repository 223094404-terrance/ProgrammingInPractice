
#include <stdio.h>
#include "employees.h"
#include "utilities.h"

/* Display employee menu */
void displayEmployeeMenu(void)
{
    printf("\n===== EMPLOYEE MENU =====\n");
    printf("1. Search Employee\n");
    printf("2. Return to Main Menu\n");
}

/* Search employee */
void searchEmployee(void)
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id;
    int i;
    int found = 0;

    id = readInt("Enter employee ID: ");

    for (i = 0; i < 5; i++) {
        if (employeeIDs[i] == id) {
            printf("Employee found at position %d.\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

/* Return employee count */
int getEmployeeCount(void)
{
    return 5;
}

/* Update employee salary using a pointer */
void updateSalary(Employee *e, double newSalary)
{
    if (e != NULL) {
        e->salary = newSalary;
        printf("Employee salary updated successfully!\n");
    }
}

/* Find employee by ID */
Employee *findEmployee(Employee list[], int n, int id)
{
    int i;

    for (i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i];
        }
    }

    return NULL;
}

/* Challenge 1: Swap two employee records */
void swapEmployees(Employee *a, Employee *b)
{
    Employee temp;

    if (a != NULL && b != NULL) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

/* Challenge 2: Sort employees by salary (highest first) */
void sortEmployeesBySalary(Employee list[], int n)
{
    int i;
    int j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (list[j].salary < list[j + 1].salary) {
                swapEmployees(&list[j], &list[j + 1]);
            }
        }
    }
}

/* Challenge 3: Find the highest-paid employee */
Employee *findHighestPaidEmployee(Employee list[], int n)
{
    int i;
    Employee *highest;

    if (n <= 0) {
        return NULL;
    }

    highest = &list[0];

    for (i = 1; i < n; i++) {
        if (list[i].salary > highest->salary) {
            highest = &list[i];
        }
    }

    return highest;
}

/* Challenge 4: Display employee memory addresses */
void displayEmployeeAddresses(Employee list[], int n)
{
    int i;

    printf("\n===== EMPLOYEE MEMORY ADDRESSES =====\n");

    for (i = 0; i < n; i++) {
        printf("Employee ID: %d\n", list[i].id);
        printf("Memory address: %p\n", (void *)&list[i]);
        printf("-----------------------------\n");
    }

    printf("Size of one Employee record: %zu bytes\n",
           sizeof(Employee));
}
