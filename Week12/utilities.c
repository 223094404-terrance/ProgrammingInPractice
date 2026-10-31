
#include <stdio.h>
#include "utilities.h"

void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int readInt(const char *prompt)
{
    int value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == 1) {
            clearInputBuffer();
            return value;
        }

        if (result == EOF) {
            return 0;
        }

        printf("Invalid input. Please enter a whole number.\n");
        clearInputBuffer();
    }
}

float readFloat(const char *prompt)
{
    float value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%f", &value);

        if (result == 1) {
            clearInputBuffer();
            return value;
        }

        if (result == EOF) {
            return 0.0f;
        }

        printf("Invalid input. Please enter a number.\n");
        clearInputBuffer();
    }
}
