
/* records.h - The five MFMS record types */

#ifndef RECORDS_H
#define RECORDS_H

#define MAX_RECORDS 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

typedef struct {
    int id;
    char name[40];
    char email[40];
    char phone[15];
    char town[20];
} Supplier;

typedef struct {
    int id;
    char description[40];
    double value;
    Date acquired;
} Asset;

typedef struct {
    char department[20];
    double allocated;
    double spent;
} Budget;

typedef struct {
    int id;
    char title[40];
    double budget;
    Date startDate;
    Date endDate;
} Project;

/* Shared record arrays and counters */
extern Employee employees[MAX_RECORDS];
extern int employeeCount;

extern Supplier suppliers[MAX_RECORDS];
extern int supplierCount;

extern Asset assets[MAX_RECORDS];
extern int assetCount;

extern Budget budgets[MAX_RECORDS];
extern int budgetCount;

extern Project projects[MAX_RECORDS];
extern int projectCount;

#endif
