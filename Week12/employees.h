#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "records.h"

void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id);

/* Week 12 pointer challenges */
void swapEmployees(Employee *a, Employee *b);
void sortEmployeesBySalary(Employee list[], int n);
Employee *findHighestPaidEmployee(Employee list[], int n);
void displayEmployeeAddresses(Employee list[], int n);

#endif
