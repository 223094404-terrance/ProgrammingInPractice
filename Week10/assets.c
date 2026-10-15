
#include <stdio.h>
#include "assets.h"

typedef struct {
    int id;
    char name[50];
    float value;
} Asset;

void saveAssetsText(void)
{
    Asset assets[] = {
        {201, "OfficeComputer", 8500.00f},
        {202, "OfficePrinter", 3200.00f}
    };

    int count = sizeof assets / sizeof assets[0];
    int i;
    FILE *fp = fopen("data/assets.txt", "w");

    if (fp == NULL) {
        perror("data/assets.txt");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%d %s %.2f\n",
                assets[i].id,
                assets[i].name,
                assets[i].value);
    }

    if (fclose(fp) != 0) {
        perror("Error closing assets.txt");
        return;
    }

    printf("Asset data saved successfully.\n");
}

void loadAssetsText(void)
{
    Asset asset;
    FILE *fp = fopen("data/assets.txt", "r");

    if (fp == NULL) {
        perror("data/assets.txt");
        return;
    }

    printf("\n===== SAVED ASSETS =====\n");

    while (fscanf(fp, "%d %49s %f",
                  &asset.id,
                  asset.name,
                  &asset.value) == 3) {
        printf("ID: %d | Name: %s | Value: %.2f\n",
               asset.id,
               asset.name,
               asset.value);
    }

    if (ferror(fp)) {
        perror("Error reading assets.txt");
    }

    fclose(fp);
}
