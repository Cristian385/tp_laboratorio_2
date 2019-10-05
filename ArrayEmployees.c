#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"

#define MAX 100
#define CANT 51


void initEmployees (eEmployees arremployees[MAX], int idMax)
{
    //int correctData = 0;

    for(int i = 0; i < MAX; i++)
    {
        if(arremployees[i].isEmpty == 0)
        {
            printf("Ingrese un nombre: ");
            fflush(stdin);
            scanf("%s", &arremployees[i].name);

            while(validationName(arremployees[i].name) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(arremployees[i].name);
            }

            printf("Ingrese un apellido: ");
            fflush(stdin);
            scanf("%s", &arremployees[i].surname);

            while(validationSurname(arremployees[i].surname) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(arremployees[i].surname);
            }

            char auxSalary[MAX];
            printf("Ingrese un salario: ");
            fflush(stdin);
            scanf("%s", &auxSalary);

            while(validationSalary(auxSalary) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxSalary);
            }//end while
            arremployees[i].salary=atoi(auxSalary);

            char auxSector[MAX];
            printf("Ingrese un sector: ");
            fflush(stdin);
            scanf("%s", &auxSector);

            while(validationSector(auxSector) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxSector);
            }//end while
            arremployees[i].sector=atoi(auxSector);

            arremployees[i].id = idMax;

            arremployees[i].isEmpty = 1;

            break;
        }
    }
}


void modifyEmployee (eEmployees arrEmployees[MAX], int EmployeesId)//recibe el ID del empleado que va a modificar
{
    int fieldModify;//Campo a modificar
    char respuesta = 's';//Para verificar si quiere seguir modificando

    eEmployees modifyEmployees;//Empleado que se esta modificando

    for(int i = 0; i < MAX; i++)
    {
        if(arrEmployees[i].id == EmployeesId)
        {
            modifyEmployees = arrEmployees[i];
            break;
        }
    }

    do
    {
        int i;

        printf("¿Que es lo que quiere modificar? \n");
        printf("1.Nombre. \n");
        printf("2.Apellido. \n");
        printf("3.Salario. \n");
        printf("4.Sector. \n");
        printf("5.Salir. \n");

        scanf("%d", &fieldModify);

        switch(fieldModify)
        {
        case 1:

            printf("Ingrese nuevo nombre: ");
            scanf("%s", &modifyEmployees.name);
            printf("Nombre modificado con exito \n \n");
            break;

        case 2:
            printf("Ingrese nuevo apellido: ");
            scanf("%s", &modifyEmployees.surname);
            printf("Apellido modificado con exito \n \n");
            break;

        case 3:

            printf("Ingrese nuevo Salario: ");
            scanf("%f", &modifyEmployees.salary);
            printf("Salario modificado con exito \n \n");
            break;

        case 4:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &modifyEmployees.sector);
            printf("Sector modificado con exito \n \n");
            break;

        case 5:
            respuesta = 'n';
            break;

        }
        system ("pause");
        system("cls");

    }
    while(respuesta == 's');

    for(int i = 0; i < MAX; i++)
    {
        if(arrEmployees[i].id == EmployeesId)
        {
            arrEmployees[i] = modifyEmployees;
            break;

        }
    }
}

int validationIdEmployees(eEmployees arrEmployees[MAX], int employeesId)
{
    int result = 0;

    for(int i = 0; i < MAX; i++)
    {
        if(arrEmployees[i].id == employeesId)
        {
            result = 1;
            break;
        }
    }
    return result;
}

void deleteEmployees (eEmployees arrEmployees[MAX], int EmployeeesId)
{
    printf("Ingrese el id del empleado que quiere eliminar");

    for(int i = 0; i < MAX; i++)
    {
        if(arrEmployees[i].id == EmployeeesId)
        {
            arrEmployees[i].isEmpty = 0;
            break;
        }
    }
}

void printEmployees (eEmployees arrEmployees[MAX])
{
    for (int i = 0; i<MAX; i++)
    {
        if (arrEmployees[i].isEmpty == 1)
        {
            printf("Id: %d \t Nombre: %s \t Apellido: %s \t Salario: %f \t Sector: %d \n", arrEmployees[i].id,
                   arrEmployees[i].name,
                   arrEmployees[i].surname,
                   arrEmployees[i].salary,
                   arrEmployees[i].sector);
        }
    }
}

void initEmployee (eEmployees employees[MAX])
{
    for (int i = 0; i<MAX; i++)
    {
        employees[i].isEmpty = 0;
    }
}

void orderEmployees(eEmployees employees[MAX])
{
    eEmployees employee;

    int orderColum;

    printf("¿Por que desea ordenar? \n");
    printf("1.Alfabeticamente por apellido.\n");
    printf("2.Por sector. \n");
    scanf("%d", &orderColum);

    for (int i = 0; i < MAX-1; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            switch(orderColum)
            {
                case 1:
                    if (strcmp(employees[i].surname, employees[j].surname)<0)
                    {
                        employee = employees[j];
                        employees[j] = employees[i];
                        employees[i] = employee;
                    }
                    break;

                case 2:
                    if (employees[i].sector < employees[j].sector)
                    {
                        employee = employees[j];
                        employees[j] = employees[i];
                        employees[i] = employee;
                    }
                    break;
            }
        }
    }
}

void salaries (eEmployees employees[])
{
    float sumSalaries = 0;
    int countEmployeesAVG = 0;
    int countEmployeesTot = 0;
    float resultAVG;
    int i;

    for(i = 0;i < MAX; i++)
    {
        if(employees[i].isEmpty == 1)
        {
            sumSalaries += employees[i].salary;
            countEmployeesTot ++;
        }
    }

    resultAVG = sumSalaries / countEmployeesTot;

    for(i = 0;i < MAX; i++)
    {
        if(employees[i].salary > resultAVG && employees[i].isEmpty == 1)
        {
            countEmployeesAVG ++;
        }
    }

    printf("El promedio es: %2.f \n", resultAVG);
    printf("El numero de empleados que superan el promedio son: %d \n", countEmployeesAVG);
}

int validationName(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }//end while
    return 1;
}//end

int validationSurname(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }//end while
    return 1;
}//end

int validationSalary(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }//end while
    return 1;
}//end

int validationSector(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }//end while
    return 1;
}//end
