/* ************************************************************************** 

    Library Management System
    Developed in C programming language
    By: Raphael Frei
    Date: 2024/04/04

    Description:
    This file includes multiple purposes functions that can be used in any part of the program.

    Change Log:
    - 2024/04/04 - Raphael Frei - Initial version

************************************************************************** */

/* ----- HOLD THE LINE ----- */
/* - Raphael Frei - 2024/04/04 - */
/* Waits for user to input anything */
int HoldLine(void){

    printf("Press any to continue...\n");
    scanf(" %*c");

    return 0;
}

/* ----- CLEAR SCREEN ----- */
/* - Raphael Frei - 2024/04/05 - */
/* Clear the screen depending of the OS */
int ClearScreen(void){

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    return 0;
}

/* ----- PRINT TITLE ----- */
/* - Raphael Frei - 2024/04/04 - */
/* Print the title of the program */
int PrintTitle(void){

    printf("---------------------------------\n");
    printf("- Library Management System\n");
    printf("---------------------------------\n");

    return 0;

}

/* ----- PRINT COPYRIGHT ----- */
/* - Raphael Frei - 2024/04/04 - */
/* Print the copyright */
int PrintCopyright(void){
    
    printf("---------------------------------\n");
    printf("- Developed by Raphael Frei\n");
    printf("---------------------------------\n");

    return 0;
}