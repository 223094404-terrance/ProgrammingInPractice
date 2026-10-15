
#include <stdio.h>
#include "employees.h"
#include "utilities.h"

void displayEmployeeMenu(void)
{
    printf("\n===== EMPLOYEE MENU =====\n");
    printf("1. Search Employee\n");
    printf("2. Return to Main Menu\n");
}

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

int getEmployeeCount(void)
{
    return 5;
}
