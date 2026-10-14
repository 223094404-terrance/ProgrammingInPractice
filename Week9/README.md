
# Week 9 - Modularising the MFMS

## Project Description
The Municipal Financial Management System (MFMS) is a C program
organised into separate modules to make the code easier to maintain,
test, and reuse.

## Project Files

- main.c: Displays the main menu and connects the modules.
- employees.c: Handles employee menu operations and employee searches.
- employees.h: Contains employee function declarations.
- budget.c: Calculates budget balances and identifies surpluses or deficits.
- budget.h: Contains budget function declarations.
- utilities.c: Provides reusable integer and floating-point input functions.
- utilities.h: Contains utility function declarations.
- reports.c: Displays a system report using employee and budget functions.
- reports.h: Contains the report function declaration.

## Compilation

Compile each source file separately:

    gcc -std=c99 -Wall -Wextra -pedantic -c main.c
    gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
    gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
    gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
    gcc -std=c99 -Wall -Wextra -pedantic -c reports.c

Link the object files:

    gcc main.o employees.o budget.o utilities.o reports.o -o mfms

Run the program in MSYS2 UCRT64:

    ./mfms.exe

## Testing Evidence

The following tests were performed:

1. Employee Management: Searching for employee ID 101 returned a successful result.
2. Budget Calculator: Revenue of 10000 and expenses of 7000 produced a balance of 3000.00 and a SURPLUS status.
3. System Report: Displayed employee count, revenue, expenses, budget balance, and budget status.
4. Exit: Selecting option 4 displayed the goodbye message and ended the program.

## Conclusion

The MFMS was compiled and linked successfully using separate C source
files and header files. The employee, budget, report, and exit functions
were tested successfully.
