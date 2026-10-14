
#include <stdio.h>

void displayWelcome(void) {
    printf("Welcome to the Municipal Financial Management System\n");
}

float calculateVAT(float amount) {
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

void displayMenu(void) {
    printf("\n==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

int searchEmployee(int id, int ids[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id, position;
    float amount, vat;
    float basic, housing, transport, grossSalary;
    float revenue, expenses, balance;

    displayWelcome();

    do {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter amount: ");
                scanf("%f", &amount);

                vat = calculateVAT(amount);
                printf("VAT: %.2f\n", vat);
                break;

            case 2:
                printf("Enter basic salary: ");
                scanf("%f", &basic);

                printf("Enter housing allowance: ");
                scanf("%f", &housing);

                printf("Enter transport allowance: ");
                scanf("%f", &transport);

                grossSalary = calculateSalary(
                    basic, housing, transport
                );

                printf("Gross salary: %.2f\n", grossSalary);
                break;

            case 3:
                printf("Enter total revenue: ");
                scanf("%f", &revenue);

                printf("Enter total expenses: ");
                scanf("%f", &expenses);

                balance = calculateBudget(revenue, expenses);
                printf("Balance: %.2f\n", balance);

                if (balance > 0) {
                    printf("SURPLUS\n");
                } else if (balance < 0) {
                    printf("DEFICIT\n");
                } else {
                    printf("BALANCED\n");
                }
                break;

            case 4:
                printf("Enter employee ID: ");
                scanf("%d", &id);

                position = searchEmployee(
                    id, employeeIDs,
                    sizeof(employeeIDs) / sizeof(employeeIDs[0])
                );

                if (position != -1) {
                    printf("Employee found at position %d.\n",
                           position);
                } else {
                    printf("Employee not found.\n");
                }
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
