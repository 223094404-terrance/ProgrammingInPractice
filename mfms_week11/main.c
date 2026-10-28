
#include <stdio.h>
#include "records.h"
#include "storage.h"

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

    do {
        printf("\n====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf(" WEEK 11 RECORD SYSTEM\n");
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
        printf("13. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
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
                printf("Thank you for using MFMS. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select 1 to 13.\n");
        }

    } while (choice != 13);

    return 0;
}
