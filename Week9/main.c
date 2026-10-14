
#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void)
{
    int choice;
    int employeeChoice;

    do {
        printf("\n================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Calculator\n");
        printf("3. System Report\n");
        printf("4. Exit\n");

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                displayEmployeeMenu();
                employeeChoice = readInt("Enter your choice: ");

                if (employeeChoice == 1) {
                    searchEmployee();
                } else if (employeeChoice == 2) {
                    printf("Returning to main menu...\n");
                } else {
                    printf("Invalid employee menu choice.\n");
                }
                break;

            case 2:
                runBudgetCalculator();
                break;

            case 3:
                displaySystemReport();
                break;

            case 4:
                printf("Thank you for using MFMS. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}
