#include "declare.h"
void saveContacts(struct Contact contacts[], int numContacts) {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
}

// Function to load contacts from a text file
int loadContacts(struct Contact contacts[], int *numContacts) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        return 0; // File doesn't exist or couldn't be opened
    }

    *numContacts = 0;
    char line[150]; // Assuming the maximum line length is 150 characters

    while (fgets(line, sizeof(line), file)) {
        if (*numContacts == MAX_CONTACTS) {
            printf("Contact list is full. Cannot load more contacts from the file.\n");
            break;
        }

        sscanf(line, "%[^,],%[^,],%[^\n]", contacts[*numContacts].name, contacts[*numContacts].phone, contacts[*numContacts].email);
        (*numContacts)++;
    }

    fclose(file);
    return 1;
}

void addContact(struct Contact contacts[], int *numContacts) {
    if (*numContacts == MAX_CONTACTS) {
        printf("Contact list is full. Cannot add more contacts.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter contact name: ");
    scanf("%s", newContact.name);

    printf("Enter contact phone number: ");
    scanf("%s", newContact.phone);

    printf("Enter contact email: ");
    scanf("%s", newContact.email);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");

    // Save contacts to the file after adding a new contact
    saveContacts(contacts, *numContacts);
}

void displayContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("Contact List\n");
    printf("------------\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("------------\n");
    }
}

int searchContacts(struct Contact contacts[], int numContacts, char searchItem[]) {
    int count = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchItem) == 0 ||
            strcmp(contacts[i].phone, searchItem) == 0 ||
            strcmp(contacts[i].email, searchItem) == 0) {
            printf("Contact found:\n");
            printf("1.Name: %s\n", contacts[i].name);
            printf("2.Phone: %s\n", contacts[i].phone);
            printf("3.Email: %s\n", contacts[i].email);
            printf("------------\n");
            count++;
        }
    }
    return count;
}