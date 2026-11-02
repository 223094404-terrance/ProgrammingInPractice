
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"
#include "storage.h"
#include "employees.h"
#include "reports.h"
#include "budget.h"

void addEmployee(void);
void displayEmployees(void);
void addSupplier(void);
void displaySuppliers(void);
void addAsset(void);
void displayAssets(void);
void addBudget(void);
void displayBudgets(void);
void addProject(void);
void displayProjects(void);

int main(void)
{
    int choice;
    int id;
    int firstID;
    int secondID;
    int i;
    int exitStatus = 0;

    double newSalary;
    double increaseAmount;
    char department[20];

    Employee *foundEmployee;
    Employee *firstEmployee;
    Employee *secondEmployee;
    Employee *highestEmployee;

    Budget *foundBudget = NULL;

    do {
        printf("\n====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf(" WEEK 13 DYNAMIC EMPLOYEE SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Add Supplier\n");
        printf("4. Display Suppliers\n");
        printf("5. Add Asset\n");
        printf("6. Display Assets\n");
        printf("7. Add Budget\n");
        printf("8. Display Budgets\n");
        printf("9. Add Project\n");
        printf("10. Display Projects\n");
        printf("11. Save Employee Records\n");
        printf("12. Load Employee Records\n");
        printf("13. Display System Report\n");
        printf("14. Update Employee Salary\n");
        printf("15. Swap Two Employees\n");
        printf("16. Sort Employees by Salary\n");
        printf("17. Find Highest-Paid Employee\n");
        printf("18. Display Employee Addresses\n");
        printf("19. Search Employee by ID\n");
        printf("20. Increase Department Budget\n");
        printf("21. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            exitStatus = 1;
            goto cleanup;
        }

        switch (choice) {

            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                printf("Current capacity: %d\n", employeeCapacity);
                break;

            case 3:
                addSupplier();
                break;

            case 4:
                displaySuppliers();
                break;

            case 5:
                addAsset();
                break;

            case 6:
                displayAssets();
                break;

            case 7:
                addBudget();
                break;

            case 8:
                displayBudgets();
                break;

            case 9:
                addProject();
                break;

            case 10:
                displayProjects();
                break;

            case 11:
                saveEmployeeRecordsBinary();
                break;

            case 12:
                loadEmployeeRecordsBinary();
                break;

            case 13:
                displaySystemReport();
                break;

            case 14:
                printf("\n--- UPDATE EMPLOYEE SALARY ---\n");
                printf("Enter employee ID: ");

                if (scanf("%d", &id) != 1) {
                    printf("Invalid employee ID.\n");
                    exitStatus = 1;
                    goto cleanup;
                }

                foundEmployee = findEmployee(
                    employees, employeeCount, id
                );

                if (foundEmployee == NULL) {
                    printf("Employee not found!\n");
                } else {
                    printf("Employee found: %s\n",
                           foundEmployee->name);

                    printf("Current salary: N$%.2f\n",
                           foundEmployee->salary);

                    printf("Enter new salary: N$");

                    if (scanf("%lf", &newSalary) != 1 ||
                        newSalary < 0) {
                        printf("Invalid salary.\n");
                        exitStatus = 1;
                        goto cleanup;
                    }

                    updateSalary(foundEmployee, newSalary);
                }
                break;

            case 15:
                printf("\n--- SWAP TWO EMPLOYEES ---\n");
                printf("Enter first employee ID: ");

                if (scanf("%d", &firstID) != 1) {
                    printf("Invalid ID.\n");
                    exitStatus = 1;
                    goto cleanup;
                }

                printf("Enter second employee ID: ");

                if (scanf("%d", &secondID) != 1) {
                    printf("Invalid ID.\n");
                    exitStatus = 1;
                    goto cleanup;
                }

                firstEmployee = findEmployee(
                    employees, employeeCount, firstID
                );

                secondEmployee = findEmployee(
                    employees, employeeCount, secondID
                );

                if (firstEmployee == NULL ||
                    secondEmployee == NULL) {
                    printf("One or both employees were not found.\n");
                } else {
                    swapEmployees(firstEmployee, secondEmployee);
                    printf("Employee records swapped successfully!\n");
                }
                break;

            case 16:
                sortEmployeesBySalary(employees, employeeCount);
                printf("Employees sorted by salary (highest first).\n");
                break;

            case 17:
                highestEmployee = findHighestPaidEmployee(
                    employees, employeeCount
                );

                if (highestEmployee == NULL) {
                    printf("No employee records available.\n");
                } else {
                    printf("\n--- HIGHEST-PAID EMPLOYEE ---\n");
                    printf("ID: %d\n", highestEmployee->id);
                    printf("Name: %s\n", highestEmployee->name);
                    printf("Department: %s\n",
                           highestEmployee->department);
                    printf("Salary: N$%.2f\n",
                           highestEmployee->salary);
                }
                break;

            case 18:
                displayEmployeeAddresses(employees, employeeCount);
                break;

            case 19:
                printf("\n--- SEARCH EMPLOYEE BY ID ---\n");
                printf("Enter employee ID: ");

                if (scanf("%d", &id) != 1) {
                    printf("Invalid employee ID.\n");
                    exitStatus = 1;
                    goto cleanup;
                }

                foundEmployee = findEmployee(
                    employees, employeeCount, id
                );

                if (foundEmployee == NULL) {
                    printf("Employee not found!\n");
                } else {
                    printf("\nEmployee found successfully!\n");
                    printf("ID: %d\n", foundEmployee->id);
                    printf("Name: %s\n", foundEmployee->name);
                    printf("Department: %s\n",
                           foundEmployee->department);
                    printf("Salary: N$%.2f\n",
                           foundEmployee->salary);
                }
                break;

            case 20:
                printf("\n--- INCREASE DEPARTMENT BUDGET ---\n");

                if (budgetCount == 0) {
                    printf("No budget records available. Add a budget first.\n");
                    break;
                }

                printf("Enter department name: ");

                if (scanf("%19s", department) != 1) {
                    printf("Invalid department name.\n");
                    exitStatus = 1;
                    goto cleanup;
                }

                foundBudget = NULL;

                for (i = 0; i < budgetCount; i++) {
                    if (strcmp(budgets[i].department, department) == 0) {
                        foundBudget = &budgets[i];
                        break;
                    }
                }

                if (foundBudget == NULL) {
                    printf("Department budget not found!\n");
                } else {
                    printf("Current allocated budget: N$%.2f\n",
                           foundBudget->allocated);

                    printf("Enter increase amount: N$");

                    if (scanf("%lf", &increaseAmount) != 1 ||
                        increaseAmount <= 0) {
                        printf("Invalid increase amount.\n");
                        exitStatus = 1;
                        goto cleanup;
                    }

                    increaseBudget(foundBudget, increaseAmount);
                }
                break;

            case 21:
                printf("Thank you for using MFMS. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }

    } while (choice != 21);

cleanup:
    /* Release dynamically allocated employee memory */
    free(employees);
    employees = NULL;
    employeeCount = 0;
    employeeCapacity = 0;

    printf("Employee memory released successfully.\n");

    return exitStatus;
}
