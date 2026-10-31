
#include <stdio.h>

int main(void)
{
    int number = 25;

    // Declare a pointer to number
    int *p = &number;

    printf("POINTER BASICS\n");
    printf("----------------------\n");

    // Print the original value
    printf("Original value: %d\n", number);

    // Print the memory address
    printf("Memory address: %p\n", (void *)p);

    // Print the value using the pointer
    printf("Value using pointer: %d\n", *p);

    // Change the value through the pointer
    *p = 50;

    printf("\nAfter changing the value:\n");
    printf("New value: %d\n", number);
    printf("New value using pointer: %d\n", *p);

    return 0;
}
