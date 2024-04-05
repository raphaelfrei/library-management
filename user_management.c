/* ************************************************************************** 

    Library Management System
    Developed in C programming language
    By: Raphael Frei
    Date: 2024/04/05

    Description:
    This program is a library management system that allows the user to add, delete, search, and display users.
    The database behind the system is a SQLite database.

    Features:
    - Add a user
    - Delete a user
    - Search for a user
    - Display all users

    Change Log:
    - 2024/04/05 - Raphael Frei - Initial version

************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int UserMainMan(void);

/* ----- USER MANAGEMENT MENU ----- */
/* - Raphael Frei - 2024/04/05 - */
int UserMainMan(void){

    ClearScreen();
    PrintTitle();

    printf(" Select an option:\n");
    printf(" 1. Add a user\n");
    printf(" 2. Delete a user\n");
    printf(" 3. Search for a user\n");
    printf(" 4. Display all users\n");
    printf(" 5. Return to menu\n");
    printf("---------------------------------\n");

    int option = 0;
    printf("Enter your choice: ");
    scanf("%d", &option);
    getchar();

    switch(option){
        case 1:
            // Add a book
            //AddBook();
            break;
        case 2:
            // Delete a book
            //DeleteBook();
            break;
        case 3:
            // Search for a book
            //SearchBook();
            break;
        case 4:
            // Display all books
            //DisplayBook();
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    UserMainMan();

    return 0;
}

/* ----- SUBMENU 1 - ADD A USER ----- */
/* - Raphael Frei - 2024/04/05 - */
int AddUser(void){

    ClearScreen();
    PrintTitle();

    printf("Add a user\n");
    printf("---------------------------------\n");

    return 0;
}