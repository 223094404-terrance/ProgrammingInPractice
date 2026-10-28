
#ifndef STORAGE_H
#define STORAGE_H

/* Existing Week 10 storage functions */
void saveEmployeesText(void);
void loadEmployeesText(void);
void saveBudgetText(float revenue, float expenses);
void loadBudgetText(void);
void saveEmployeesBinary(void);
void loadEmployeesBinary(void);

/* Week 11 employee record storage */
void saveEmployeeRecordsBinary(void);
void loadEmployeeRecordsBinary(void);

#endif
