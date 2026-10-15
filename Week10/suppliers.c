
#include <stdio.h>
#include "suppliers.h"

typedef struct {
    int id;
    char name[50];
    float price;
} Supplier;

void saveSuppliersText(void)
{
    Supplier suppliers[] = {
        {101, "Windhoek Supplies", 4500.00f},
        {102, "Swakopmund Traders", 5200.00f}
    };

    int count = sizeof suppliers / sizeof suppliers[0];
    int i;
    FILE *fp = fopen("data/suppliers.txt", "w");

    if (fp == NULL) {
        perror("data/suppliers.txt");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%d %s %.2f\n",
                suppliers[i].id,
                suppliers[i].name,
                suppliers[i].price);
    }

    if (fclose(fp) != 0) {
        perror("Error closing suppliers.txt");
        return;
    }

    printf("Supplier data saved successfully.\n");
}

void loadSuppliersText(void)
{
    Supplier supplier;
    FILE *fp = fopen("data/suppliers.txt", "r");

    if (fp == NULL) {
        perror("data/suppliers.txt");
        return;
    }

    printf("\n===== SAVED SUPPLIERS =====\n");

    while (fscanf(fp, "%d %49s %f",
                  &supplier.id,
                  supplier.name,
                  &supplier.price) == 3) {
        printf("ID: %d | Name: %s | Price: %.2f\n",
               supplier.id,
               supplier.name,
               supplier.price);
    }

    if (ferror(fp)) {
        perror("Error reading suppliers.txt");
    }

    fclose(fp);
}
