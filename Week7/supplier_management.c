
#include <stdio.h>
#include <string.h>

int main(void) {
    char supplierName[100] = "";
    char email[100] = "";
    char phone[30] = "";
    char town[50] = "";
    char searchName[100];
    int choice;
    int supplierAdded = 0;

    do {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }

            continue;
        }

        getchar(); // Remove newline after the number

        switch (choice) {
            case 1:
                printf("Enter supplier name: ");
                fgets(supplierName, sizeof(supplierName), stdin);
                supplierName[strcspn(supplierName, "\n")] = '\0';

                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                printf("Enter phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0';

                printf("Enter town: ");
                fgets(town, sizeof(town), stdin);
                town[strcspn(town, "\n")] = '\0';

                supplierAdded = 1;
                printf("Supplier added successfully!\n");
                break;

            case 2:
                if (supplierAdded) {
                    printf("\n--- SUPPLIER DETAILS ---\n");
                    printf("Name : %s\n", supplierName);
                    printf("Email: %s\n", email);
                    printf("Phone: %s\n", phone);
                    printf("Town : %s\n", town);
                } else {
                    printf("Please add a supplier first.\n");
                }
                break;

            case 3:
                if (supplierAdded) {
                    printf("Enter supplier name to search: ");
                    fgets(searchName, sizeof(searchName), stdin);
                    searchName[strcspn(searchName, "\n")] = '\0';

                    if (strcmp(searchName, supplierName) == 0) {
                        printf("Supplier found.\n");
                    } else {
                        printf("Supplier not found.\n");
                    }
                } else {
                    printf("Please add a supplier first.\n");
                }
                break;

            case 4:
                if (supplierAdded) {
                    printf("Supplier name length: %zu\n",
                           strlen(supplierName));
                } else {
                    printf("Please add a supplier first.\n");
                }
                break;

            case 5:
                printf("Exiting Supplier Management. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}
