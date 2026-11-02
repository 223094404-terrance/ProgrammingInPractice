#ifndef BUDGET_H
#define BUDGET_H

#include "records.h"

float calculateBudget(float revenue, float expenses);
void runBudgetCalculator(void);
float getLastRevenue(void);
float getLastExpenses(void);

/* Week 12 pointer challenge */
void increaseBudget(Budget *b, double amount);

#endif
