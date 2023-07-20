#include "define.h"
int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    char searchItem[50];

    // Load contacts from the file at the beginning of the program
    if (loadContacts(contacts, &numContacts)) {
        printf("Contacts loaded successfully from the file.\n");
    }

    do {
        printf("***Contact Management System****\n");
        printf(" ------------------------------------------------------- \n");
        printf("          1. Add Contact\n");
        printf("          2. Display All Contacts\n");
        printf("          3. Search Contacts\n");
        printf("          4. Exit\n");
        printf("          Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                printf("Enter name, phone, or email for search: ");
                scanf("%s", searchItem);
                int searchResult = searchContacts(contacts, numContacts, searchItem);
                if (searchResult == 0) {
                    printf("No matching contacts found.\n");
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
