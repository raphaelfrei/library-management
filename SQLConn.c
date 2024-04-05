/* ************************************************************************** 

    Library Management System
    Developed in C programming language
    By: Raphael Frei
    Date: 2024/04/04

    Description:
    This program is used to control all SQL Operations. No SQL code is written outside this file.

    Features:
    - Connect to the database
    - Disconnect from the database
    - Execute a query
    - Display the result of a query

    Change Log:
    - 2024/04/04 - Raphael Frei - Initial version
    - 2024/04/05 - Raphael Frei - Delete Book/Get Single Book function added

************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

char* DBName = "/Users/raphaelfrei/Projects/C/LibraryControl/database.db";
int RegisterMaxShow = 2;
int CountPrint = 0;

sqlite3* DB;

/* ----- Attempt to connect the database ----- */
/* - Raphael Frei - 2024/04/04 - */
/* This is currently not in use, only create for initial database setup */
int Connect(){

    int exit = 0;
    exit = sqlite3_open(DBName, &DB);
  
    if (exit) {
        printf("Error open DB %s", sqlite3_errmsg(DB));
        return (-1);
    }
    else
        printf("Opened Database Successfully!");

    sqlite3_close(DB);
    return 0;
}

/* ----- BOOKS Table ----- */

/* ----- PRINT BOOK(S) QUERY ----- */
/* - Raphael Frei - 2024/04/04 - */
/* Print books database into pair of records - After 2 attemps, ask user if wants to continue */
/* This query can be used for one or more items */
static int PrintBooksQuery(void* data, int argc, char** argv, char** columnName) {
    CountPrint++;

    if (CountPrint % RegisterMaxShow == 1)
        system("clear");

    printf("Book ID...: %s\n", argv[0] ? argv[0] : "NULL");
    printf("ISBN Code.: %s\n", argv[1] ? argv[1] : "NULL");
    printf("Title.....: %s\n", argv[2] ? argv[2] : "NULL");
    printf("Author....: %s\n", argv[3] ? argv[3] : "NULL");
    printf("Publisher.: %s\n", argv[4] ? argv[4] : "NULL");

    printf("\n");

    if (CountPrint % RegisterMaxShow == 0) {
        char choice;
        printf("Keep showing? (Y/N): ");
        scanf(" %c", &choice);

        if (choice != 'Y' && choice != 'y') {
            return 1;
        }
    }

    return 0;
}

/* ----- ADD BOOK TO TABLE ----- */
/* - Raphael Frei - 2024/04/04 - */
int AddBookToTable(char* ISBN, char* Title, char* Author, char* Publisher){

    int exit = 0;
    exit = sqlite3_open(DBName, &DB);

    char query[1000];
    
    snprintf(query, sizeof(query), "INSERT INTO books (book_isbn, book_title, book_author, book_publisher) VALUES ('%s', '%s', '%s', '%s')", ISBN, Title, Author, Publisher);

    int result = sqlite3_exec(DB, query, NULL, 0, NULL);

    sqlite3_close(DB);

    if (result != SQLITE_OK) {
        printf("Error inserting data into the database\n");
        return -1;
    } else {
        printf("Data inserted successfully\n");
    }

    return 0;
}

/* ----- GET SINGLE BOOK ----- */
/* - Raphael Frei - 2024/04/05 - */
/* If ID won't match, return -1 and the warning message */
int GetSingleBook(int id){
    int exit = 0;
    CountPrint = 0;
    exit = sqlite3_open(DBName, &DB);
    
    char query[100];
    snprintf(query, sizeof(query), "SELECT * FROM books WHERE book_id = %d", id);

    int result = sqlite3_exec(DB, query, PrintBooksQuery, 0, NULL);

    if (result != SQLITE_OK) {
        printf("There is no book with this ID.\n");
        return -1;
    }

    sqlite3_close(DB);

    return 0;
}

/* ----- DELETE BOOK FROM TABLE ----- */
/* - Raphael Frei - 2024/04/05 - */
int DeleteBookFromTable(int id){
    
    int exit = 0;
    exit = sqlite3_open(DBName, &DB);
    char query[100];
    snprintf(query, sizeof(query), "DELETE FROM books where book_id = %d", id);

    int result = sqlite3_exec(DB, query, NULL, 0, NULL);

    if (result != SQLITE_OK) {
        printf("Error deleting data from the database\n");
        return -1;
    } else {
        printf("Data deleted successfully\n");
    }

    sqlite3_close(DB);

    return 0;
    
}

/* ----- GET LIST OF BOOKS ----- */
/* - Raphael Frei - 2024/04/04 - */
int GetListOfBooks(){
    CountPrint = 0;
    int exit = 0;
    exit = sqlite3_open(DBName, &DB);
    char query[] = "SELECT * FROM books";

    sqlite3_exec(DB, query, PrintBooksQuery, 0, NULL);

    sqlite3_close(DB);

    return 0;
}