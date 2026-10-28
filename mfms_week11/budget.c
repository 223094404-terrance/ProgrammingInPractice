#include <stdio.h>
#include "budget.h"
#include "utilities.h"

static float lastRevenue = 0.0f;
static float lastExpenses = 0.0f;

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void runBudgetCalculator(void)
{
    float balance;

    printf("\n===== BUDGET CALCULATOR =====\n");

    lastRevenue = readFloat("Enter total revenue: ");
    lastExpenses = readFloat("Enter total expenses: ");

    balance = calculateBudget(lastRevenue, lastExpenses);

    printf("Balance: %.2f\n", balance);

    if (balance > 0) {
        printf("SURPLUS\n");
    } else if (balance < 0) {
        printf("DEFICIT\n");
    } else {
        printf("BALANCED\n");
    }
}

float getLastRevenue(void)
{
    return lastRevenue;
}

float getLastExpenses(void)
{
    return lastExpenses;
}