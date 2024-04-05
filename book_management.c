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

************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BookManMain(void);
int AddBook(void);
int DisplayBook(void);
int DeleteBook(void);

int BookManMain(void){
    
    system("clear");
    
    PrintTitle();
    printf(" Select an option:\n");
    printf(" 1. Add a book\n");
    printf(" 2. Delete a book\n");
    printf(" 3. Search for a book\n");
    printf(" 4. Display all books\n");
    printf(" 5. Return to menu\n");
    printf("---------------------------------\n");

    int option = 0;
    printf("Enter your choice: ");
    scanf("%d", &option);
    getchar();

    switch(option){
        case 1:
            // Add a book
            AddBook();
            break;
        case 2:
            // Delete a book
            DeleteBook();
            break;
        case 3:
            // Search for a book
            break;
        case 4:
            DisplayBook();
            // Display all books
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    BookManMain();

    return 0;
}

int DisplayBook(void){
    GetListOfBooks();

    printf("Select an option:\n");
    printf("1. Show list again\n");
    printf("2. Return to menu\n");

    int option = 0;
    printf("Enter your choice: ");
    scanf("%d", &option);
    getchar();

    if (option == 1){
        DisplayBook();
    } 

    return 0;
}

int DeleteBook(void){

    system("clear");
    PrintTitle();
    printf("Delete a book\n");
    printf("---------------------------------\n");
    printf("Enter the book ID to delete: ");
    int id;
    scanf("%d", &id);
    getchar();

    int result = GetSingleBook(id);
    id = 0;

    if (result != -1){
        printf("Do you want to delete this book?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("3. Return to menu\n");
        printf("Enter your choice: ");
        scanf("%d", &id);
        getchar();
    }

    if (id == 1){
        DeleteBookFromTable(id);
        sleep(2);
    } else if (id == 2){
        DeleteBook();
    }

    return 0;

}

int AddBook(void) {

    char ISBN[100];
    char Title[100];
    char Author[100];
    char Publisher[100];
    
    system("clear");
    PrintTitle();
    printf("Add a book\n");
    printf("---------------------------------\n");

    // ISBN
    printf("Insert the ISBN code:\n");
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';

    // Title
    printf("Insert the title:\n");
    fgets(Title, sizeof(Title), stdin);
    Title[strcspn(Title, "\n")] = '\0';

    // Author
    printf("Insert the author:\n");
    fgets(Author, sizeof(Author), stdin);
    Author[strcspn(Author, "\n")] = '\0'; 

    // Publisher
    printf("Insert the publisher:\n");
    fgets(Publisher, sizeof(Publisher), stdin);
    Publisher[strcspn(Publisher, "\n")] = '\0';

    printf("Processing...");
    sleep(2);

    system("clear");
    PrintTitle();
    printf("Is the following information correct?\n");
    printf("---------------------------------\n");
    printf("ISBN Code: %s\n", ISBN);
    printf("Title: %s\n", Title);
    printf("Author: %s\n", Author);
    printf("Publisher: %s\n", Publisher);
    printf("---------------------------------\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("3. Return to menu\n");
    printf("---------------------------------\n");

    char option_str[10];
    printf("Enter your choice: ");
    fgets(option_str, sizeof(option_str), stdin);
    int option = atoi(option_str);
    
    if (option == 1){
        AddBookToTable(ISBN, Title, Author, Publisher);
        sleep(2);
        
        system("clear");
        PrintTitle();
        printf("Do you want to add a new book?\n");
        printf("---------------------------------\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("---------------------------------\n");

        printf("Enter your choice: ");
        fgets(option_str, sizeof(option_str), stdin);
        option = atoi(option_str);

        if (option == 1){
            AddBook();
        } else {
            BookManMain();
        }

    } else if (option == 2) {
        system("clear");
        PrintTitle();
        printf("Book not added. Please try again.\n");
        sleep(2);
        AddBook();
    }

    return 0;
}