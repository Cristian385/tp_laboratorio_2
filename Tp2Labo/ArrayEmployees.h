#include <stdio.h>
#include <stdlib.h>

#define CANT 51
typedef struct
{
    int id;
    char name [CANT];
    char surname [CANT];
    float salary;
    int sector;
    int isEmpty;
}eEmployees;


void initEmployees (eEmployees[], int);

void modifyEmployee (eEmployees[], int);

void deleteEmployees (eEmployees[], int);

void printEmployees (eEmployees[]);

void initEmployee (eEmployees[]);

int validationIdEmployees (eEmployees[], int);

void orderEmployees (eEmployees[]);

void salaries (eEmployees[]);

int validationName (char[]);

int validationSurname (char[]);

int validationSalary (char[]);

int validationSector (char[]);
