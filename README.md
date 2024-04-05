# Library Management System in C
Software created to understand (and remember) more about programming in C and SQLite database connection.

The program was created using MacOS as operating system - So some commands may not work perfectly on Windows.

## Why?
This software was not developed with the intention on being used - Created to remember somethings about programming with C language.

## How To Compile?
The main script that you need to compile is the ````main.c```` file.

On MacOS you'll need to have the GCC installed.

The compile command is:
````
gcc PathToMainCFile -o OutputEXEFile -lsqlite3
````

Example:
````
gcc /PathToFile/.../main.c -o /PathToFile/.../main -lsqlite3
````

Change database file path at ````SQLConn.c````:
````c
char* DBName = "/PathToFile/.../database.db";
````
