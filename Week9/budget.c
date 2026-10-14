
#include <stdio.h>
#include "budget.h"
#include "utilities.h"

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void runBudgetCalculator(void)
{
    float revenue;
    float expenses;
    float balance;

    printf("\n===== BUDGET CALCULATOR =====\n");

    revenue = readFloat("Enter total revenue: ");
    expenses = readFloat("Enter total expenses: ");

    balance = calculateBudget(revenue, expenses);

    printf("Balance: %.2f\n", balance);

    if (balance > 0) {
        printf("SURPLUS\n");
    } else if (balance < 0) {
        printf("DEFICIT\n");
    } else {
        printf("BALANCED\n");
    }
}
