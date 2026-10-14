
#include <stdio.h>
#include "reports.h"
#include "budget.h"
#include "employees.h"

void displaySystemReport(void)
{
    float revenue = 10000.0f;
    float expenses = 7000.0f;
    float balance;
    int employeeCount;

    balance = calculateBudget(revenue, expenses);
    employeeCount = getEmployeeCount();

    printf("\n===== MFMS SYSTEM REPORT =====\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Total Revenue: %.2f\n", revenue);
    printf("Total Expenses: %.2f\n", expenses);
    printf("Budget Balance: %.2f\n", balance);

    if (balance > 0) {
        printf("Budget Status: SURPLUS\n");
    } else if (balance < 0) {
        printf("Budget Status: DEFICIT\n");
    } else {
        printf("Budget Status: BALANCED\n");
    }

    printf("\n===== END OF REPORT =====\n");
}
