/* ************************************************************************** 

    Library Management System
    Developed in C programming language
    By: Raphael Frei
    Date: 2024/04/04

    Description:
    This file includes multiple purposes functions that can be used in any part of the program.

************************************************************************** */

int HoldLine(void){

    printf("Press any to continue...\n");
    scanf(" %*c");

    return 0;
}

int PrintTitle(void){

    printf("---------------------------------\n");
    printf("- Library Management System\n");
    printf("---------------------------------\n");

    return 0;

}

int PrintCopyright(void){
    
    printf("---------------------------------\n");
    printf("- Developed by Raphael Frei\n");
    printf("---------------------------------\n");

    return 0;
}