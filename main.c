/* ************************************************************************** 

    Library Management System
    Developed in C programming language
    By: Raphael Frei
    Date: 2024/04/04

    Description:
    This program is a library management system that allows the user to add, delete, search, and display books.
    The database behind the system is a SQLite database.

    Features:
    - Add a book
    - Delete a book
    - Search for a book
    - Display all books
    - Add a user
    - Delete a user
    - Search for a user
    - Display all users
    - Borrow a book
    - Return a book

    - Exit the program

    Change Log:
    - 2024/04/04 - Raphael Frei - Initial version
    - 2024/04/05 - Raphael Frei - Added user management functions

************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "util.c"
#include "SQLConn.c"
#include "book_management.c"
#include "user_management.c"

int main(void){

    ClearScreen();

    PrintTitle();
    printf(" Select an option:\n");
    printf(" 1. Book Management\n");
    printf(" 2. User Management\n");
    printf(" 3. Borrow/Return a Book\n");
    printf(" 4. Exit\n");
    printf("---------------------------------\n");
    PrintCopyright();

    int option;
    printf("Enter your choice: ");
    scanf("%d", &option);
    getchar();

    switch(option){
        case 1:
            // Book Management
            BookManMain();
            break;
        case 2:
            // User Management
            UserMainMan();
            break;
        case 3:
            // Borrow/Return a Book
            break;
        case 4:
            // Exit the program
            return 0;
            break;
        default:
            printf(" Invalid option. Please try again.\n");
            break;
    }

    main();

    return 0;
}
