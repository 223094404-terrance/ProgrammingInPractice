
#include <stdio.h>
#include "records.h"

/* Arrays and counters for all five record types */
Employee employees[MAX_RECORDS];
int employeeCount = 0;

Supplier suppliers[MAX_RECORDS];
int supplierCount = 0;

Asset assets[MAX_RECORDS];
int assetCount = 0;

Budget budgets[MAX_RECORDS];
int budgetCount = 0;

Project projects[MAX_RECORDS];
int projectCount = 0;

/* Add an employee */
void addEmployee(void)
{
    if (employeeCount >= MAX_RECORDS) {
        printf("Employee records are full!\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

    printf("Enter employee ID: ");
    if (scanf("%d", &employees[employeeCount].id) != 1) {
        printf("Invalid ID.\n");
        return;
    }

    printf("Enter employee name (one word): ");
    if (scanf("%29s", employees[employeeCount].name) != 1) {
        printf("Invalid name.\n");
        return;
    }

    printf("Enter department (one word): ");
    if (scanf("%19s", employees[employeeCount].department) != 1) {
        printf("Invalid department.\n");
        return;
    }

    printf("Enter salary: ");
    if (scanf("%lf", &employees[employeeCount].salary) != 1 ||
        employees[employeeCount].salary < 0) {
        printf("Invalid salary. Enter a non-negative number.\n");
        return;
    }

    employeeCount++;
    printf("Employee added successfully!\n");
}

/* Display employees */
void displayEmployees(void)
{
    int i;

    printf("\n========== EMPLOYEE RECORDS ==========\n");

    if (employeeCount == 0) {
        printf("No employee records available.\n");
        return;
    }

    printf("%-8s %-20s %-15s %12s\n",
           "ID", "Name", "Department", "Salary");

    for (i = 0; i < employeeCount; i++) {
        printf("%-8d %-20s %-15s %12.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }

    printf("Total employees: %d\n", employeeCount);
}

/* Add a supplier */
void addSupplier(void)
{
    if (supplierCount >= MAX_RECORDS) {
        printf("Supplier records are full!\n");
        return;
    }

    printf("\n--- Add Supplier ---\n");

    printf("Enter supplier ID: ");
    if (scanf("%d", &suppliers[supplierCount].id) != 1) {
        printf("Invalid ID.\n");
        return;
    }

    printf("Enter supplier name (one word): ");
    if (scanf("%39s", suppliers[supplierCount].name) != 1) {
        printf("Invalid name.\n");
        return;
    }

    printf("Enter email: ");
    if (scanf("%39s", suppliers[supplierCount].email) != 1) {
        printf("Invalid email.\n");
        return;
    }

    printf("Enter phone number: ");
    if (scanf("%14s", suppliers[supplierCount].phone) != 1) {
        printf("Invalid phone number.\n");
        return;
    }

    printf("Enter town (one word): ");
    if (scanf("%19s", suppliers[supplierCount].town) != 1) {
        printf("Invalid town.\n");
        return;
    }

    supplierCount++;
    printf("Supplier added successfully!\n");
}

/* Display suppliers */
void displaySuppliers(void)
{
    int i;

    printf("\n================ SUPPLIER RECORDS ================\n");

    if (supplierCount == 0) {
        printf("No supplier records available.\n");
        return;
    }

    printf("%-6s %-15s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");

    for (i = 0; i < supplierCount; i++) {
        printf("%-6d %-15s %-25s %-15s %-15s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }

    printf("Total suppliers: %d\n", supplierCount);
}

/* Add an asset */
void addAsset(void)
{
    if (assetCount >= MAX_RECORDS) {
        printf("Asset records are full!\n");
        return;
    }

    printf("\n--- Add Asset ---\n");

    printf("Enter asset ID: ");
    if (scanf("%d", &assets[assetCount].id) != 1) {
        printf("Invalid ID.\n");
        return;
    }

    printf("Enter asset description (one word): ");
    if (scanf("%39s", assets[assetCount].description) != 1) {
        printf("Invalid description.\n");
        return;
    }

    printf("Enter asset value: ");
    if (scanf("%lf", &assets[assetCount].value) != 1 ||
        assets[assetCount].value < 0) {
        printf("Invalid asset value.\n");
        return;
    }

    printf("Enter acquisition day: ");
    if (scanf("%d", &assets[assetCount].acquired.day) != 1 ||
        assets[assetCount].acquired.day < 1 ||
        assets[assetCount].acquired.day > 31) {
        printf("Invalid day.\n");
        return;
    }

    printf("Enter acquisition month: ");
    if (scanf("%d", &assets[assetCount].acquired.month) != 1 ||
        assets[assetCount].acquired.month < 1 ||
        assets[assetCount].acquired.month > 12) {
        printf("Invalid month.\n");
        return;
    }

    printf("Enter acquisition year: ");
    if (scanf("%d", &assets[assetCount].acquired.year) != 1 ||
        assets[assetCount].acquired.year < 1) {
        printf("Invalid year.\n");
        return;
    }

    assetCount++;
    printf("Asset added successfully!\n");
}

/* Display assets */
void displayAssets(void)
{
    int i;

    printf("\n================ ASSET RECORDS ================\n");

    if (assetCount == 0) {
        printf("No asset records available.\n");
        return;
    }

    printf("%-8s %-20s %12s %-12s\n",
           "ID", "Description", "Value", "Date Acquired");

    for (i = 0; i < assetCount; i++) {
        printf("%-8d %-20s %12.2f %02d/%02d/%04d\n",
               assets[i].id,
               assets[i].description,
               assets[i].value,
               assets[i].acquired.day,
               assets[i].acquired.month,
               assets[i].acquired.year);
    }

    printf("Total assets: %d\n", assetCount);
}

/* Add a budget */
void addBudget(void)
{
    if (budgetCount >= MAX_RECORDS) {
        printf("Budget records are full!\n");
        return;
    }

    printf("\n--- Add Budget ---\n");

    printf("Enter department (one word): ");
    if (scanf("%19s", budgets[budgetCount].department) != 1) {
        printf("Invalid department.\n");
        return;
    }

    printf("Enter allocated budget: ");
    if (scanf("%lf", &budgets[budgetCount].allocated) != 1 ||
        budgets[budgetCount].allocated < 0) {
        printf("Invalid allocated budget.\n");
        return;
    }

    printf("Enter amount spent: ");
    if (scanf("%lf", &budgets[budgetCount].spent) != 1 ||
        budgets[budgetCount].spent < 0) {
        printf("Invalid amount spent.\n");
        return;
    }

    budgetCount++;
    printf("Budget added successfully!\n");
}

/* Display budgets and calculate balances */
void displayBudgets(void)
{
    int i;
    double balance;

    printf("\n================ BUDGET RECORDS ================\n");

    if (budgetCount == 0) {
        printf("No budget records available.\n");
        return;
    }

    printf("%-20s %15s %15s %15s\n",
           "Department", "Allocated", "Spent", "Balance");

    for (i = 0; i < budgetCount; i++) {
        balance = budgets[i].allocated - budgets[i].spent;

        printf("%-20s %15.2f %15.2f %15.2f\n",
               budgets[i].department,
               budgets[i].allocated,
               budgets[i].spent,
               balance);
    }

    printf("Total budgets: %d\n", budgetCount);
}

/* Add a project */
void addProject(void)
{
    if (projectCount >= MAX_RECORDS) {
        printf("Project records are full!\n");
        return;
    }

    printf("\n--- Add Project ---\n");

    printf("Enter project ID: ");
    if (scanf("%d", &projects[projectCount].id) != 1) {
        printf("Invalid project ID.\n");
        return;
    }

    printf("Enter project title (one word): ");
    if (scanf("%39s", projects[projectCount].title) != 1) {
        printf("Invalid project title.\n");
        return;
    }

    printf("Enter project budget: ");
    if (scanf("%lf", &projects[projectCount].budget) != 1 ||
        projects[projectCount].budget < 0) {
        printf("Invalid project budget.\n");
        return;
    }

    printf("Enter start day: ");
    if (scanf("%d", &projects[projectCount].startDate.day) != 1 ||
        projects[projectCount].startDate.day < 1 ||
        projects[projectCount].startDate.day > 31) {
        printf("Invalid start day.\n");
        return;
    }

    printf("Enter start month: ");
    if (scanf("%d", &projects[projectCount].startDate.month) != 1 ||
        projects[projectCount].startDate.month < 1 ||
        projects[projectCount].startDate.month > 12) {
        printf("Invalid start month.\n");
        return;
    }

    printf("Enter start year: ");
    if (scanf("%d", &projects[projectCount].startDate.year) != 1 ||
        projects[projectCount].startDate.year < 1) {
        printf("Invalid start year.\n");
        return;
    }

    printf("Enter end day: ");
    if (scanf("%d", &projects[projectCount].endDate.day) != 1 ||
        projects[projectCount].endDate.day < 1 ||
        projects[projectCount].endDate.day > 31) {
        printf("Invalid end day.\n");
        return;
    }

    printf("Enter end month: ");
    if (scanf("%d", &projects[projectCount].endDate.month) != 1 ||
        projects[projectCount].endDate.month < 1 ||
        projects[projectCount].endDate.month > 12) {
        printf("Invalid end month.\n");
        return;
    }

    printf("Enter end year: ");
    if (scanf("%d", &projects[projectCount].endDate.year) != 1 ||
        projects[projectCount].endDate.year < 1) {
        printf("Invalid end year.\n");
        return;
    }

    projectCount++;
    printf("Project added successfully!\n");
}

/* Display projects */
void displayProjects(void)
{
    int i;

    printf("\n================ PROJECT RECORDS ================\n");

    if (projectCount == 0) {
        printf("No project records available.\n");
        return;
    }

    printf("%-6s %-20s %12s %-12s %-12s\n",
           "ID", "Title", "Budget", "Start Date", "End Date");

    for (i = 0; i < projectCount; i++) {
        printf("%-6d %-20s %12.2f %02d/%02d/%04d %02d/%02d/%04d\n",
               projects[i].id,
               projects[i].title,
               projects[i].budget,
               projects[i].startDate.day,
               projects[i].startDate.month,
               projects[i].startDate.year,
               projects[i].endDate.day,
               projects[i].endDate.month,
               projects[i].endDate.year);
    }

    printf("Total projects: %d\n", projectCount);
}
