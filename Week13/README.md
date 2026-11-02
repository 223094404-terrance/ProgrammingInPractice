# Week 12 Laboratory – Pointers in the MFMS

## 1. Introduction

This laboratory extends the Municipal Financial Management System (MFMS) by applying pointers to employee and budget records. Pointers allow the program to access and modify data directly through memory addresses.

## 2. Objectives

- Understand pointers, addresses and dereferencing.
- Demonstrate the difference between passing values and passing addresses.
- Swap employee salaries using pointers.
- Display and analyse salary arrays.
- Update employee salaries using pointers.
- Search for employees and return pointers to matching records.
- Swap employee records and sort employees by salary.
- Find the highest-paid employee.
- Display employee memory addresses and record size.
- Increase department budgets using pointers.

## 3. Project Files

- `main.c` – Main menu and program control.
- `employees.c` and `employees.h` – Employee pointer functions and employee operations.
- `budget.c` and `budget.h` – Budget calculations and pointer-based budget updates.
- `records.c` and `records.h` – Record structures and shared record arrays.
- `pointer_basics.c` – Demonstrates pointer declaration, addresses and dereferencing.
- `swap_salaries.c` – Demonstrates salary swapping using pointers.
- `salary_arrays.c` – Demonstrates salary array operations.
- `storage.c` and `storage.h` – Saving and loading employee records.
- `reports.c` and `reports.h` – System reporting.
- `suppliers.c` and `suppliers.h` – Supplier operations.
- `assets.c` and `assets.h` – Asset operations.
- `utilities.c` and `utilities.h` – Input utility functions.
- `data/` – Directory containing saved records.

## 4. Pointer Functions

The laboratory implements the following pointer-based functions:

- `swapSalaries(double *a, double *b)` – Swaps two salary values.
- `displaySalaries(const double salaries[], int n)` – Displays salary values.
- `findHighest(const double salaries[], int n)` – Finds the highest salary.
- `calculateAverage(const double salaries[], int n)` – Calculates the average salary.
- `giveRaise(double salaries[], int n, double percentage)` – Increases salaries.
- `updateSalary(Employee *e, double newSalary)` – Updates an employee's salary.
- `findEmployee(Employee list[], int n, int id)` – Finds an employee and returns a pointer.
- `swapEmployees(Employee *a, Employee *b)` – Swaps two employee records.
- `sortEmployeesBySalary(Employee list[], int n)` – Sorts employees by salary.
- `findHighestPaidEmployee(Employee list[], int n)` – Finds the highest-paid employee.
- `displayEmployeeAddresses(Employee list[], int n)` – Displays employee memory addresses.
- `increaseBudget(Budget *b, double amount)` – Increases an allocated department budget.

## 5. Compilation

Compile the main MFMS program from the Week12 directory using:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c utilities.c reports.c storage.c suppliers.c assets.c records.c -o mfms.exe
```

Run the program using:

```bash
./mfms.exe
```

## 6. Testing

The program was tested to verify:

- Employee records can be loaded and displayed.
- Employee salaries can be updated.
- Missing employee IDs are handled.
- Employee records can be swapped.
- Employees can be sorted by salary.
- The highest-paid employee can be identified.
- Employee memory addresses can be displayed.
- Department budgets can be increased.
- Employee records remain available after saving and restarting the program.

## 7. Conclusion

The Week 12 laboratory demonstrates how pointers are used in C programming to access and modify data efficiently. The MFMS now uses pointer-based functions to update employee records, manipulate salaries, locate employees, and increase department budgets.
