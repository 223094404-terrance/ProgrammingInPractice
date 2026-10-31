
#include <stdio.h>
#include "records.h"

int main(void)
{
    Employee employee;
    Supplier supplier;
    Asset asset;
    Budget budget;
    Project project;

    printf("MFMS Week 11 Records Test\n");
    printf("Maximum records: %d\n", MAX_RECORDS);
    printf("Employee size: %zu bytes\n", sizeof(employee));
    printf("Supplier size: %zu bytes\n", sizeof(supplier));
    printf("Asset size: %zu bytes\n", sizeof(asset));
    printf("Budget size: %zu bytes\n", sizeof(budget));
    printf("Project size: %zu bytes\n", sizeof(project));

    printf("All five record structures work!\n");

    return 0;
}
