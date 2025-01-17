#include <stdio.h>
#include <stdlib.h>
#include "contact.h"
#include "file.h"
int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book
    int flag=0;

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                createContact(&addressBook);
                flag=1;
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                flag=1;
                break;
            case 4:
                deleteContact(&addressBook);
                flag=1;
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                printf("Saving contacts...\n");
                saveContactsToFile(&addressBook);
                flag=0;
                break;
            case 7:
                if(flag==0){
                    printf("Exiting...\n");
                    exit(0);
                }
                exit1(&addressBook);    
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
       return 0;
}



