#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define MAX 100

int main()
{
    char menu;
    int salir = 1;
    char respuesta = 's';
    eEmployees arrEmployees[MAX];
    int employeesId;
    int validate;
    int idMax = 4;
    initEmployee (arrEmployees);
    do
    {
        printf("Bienvenido al sistema de trabajo de Cristian Fumacoo \n \n");
        printf("Presione 1 para ingresar el empleado. \n");
        printf("Presione 2 para modificar un empleado. \n");
        printf("presione 3 para eliminar a un empleado. \n");
        printf("Presione 4 para informar los datos. \n");
        printf("Presione 5 para salir. \n");
        fflush(stdin);
        scanf("%c", &menu);

        switch(menu)
        {
        case '1':
            initEmployees (arrEmployees, idMax);
            idMax++;
            printf("Se ha cargado correctamente. \n");
            system("pause");
            break;

        case '2':

            printf("Seleccione el empleado a modificar \n");

            printEmployees(arrEmployees);

            scanf("%d", &employeesId);

            //solo si el ID seleccionado es valido, entramos a modificar el usuario
            validate = validationIdEmployees(arrEmployees, employeesId);
            while(validate == 0)
            {
                printf("Id del empleado incorrecto, vuelva a seleccionar");
                scanf("%d", &employeesId);
                validate = validationIdEmployees(arrEmployees, employeesId);
            }

            modifyEmployee (arrEmployees, employeesId);

            printf("Se ha modificado con exito. \n");
            system("pause");

            break;
        case '3':

            printf("Seleccione el empleado a eliminar \n");

            printEmployees(arrEmployees);

            scanf("%d", &employeesId);

            //solo si el ID seleccionado es valido, entramos a eliminar el usuario
            validate = validationIdEmployees(arrEmployees, employeesId);
            while(validate == 0)
            {
                printf("Id del empleado incorrecto, vuelva a seleccionar");
                scanf("%d", &employeesId);
                validate = validationIdEmployees(arrEmployees, employeesId);
            }

            deleteEmployees (arrEmployees, employeesId);

            printf("Se ha eliminado con exito \n");
            system("pause");

            break;

        case '4':
        {
            int reportOption;

            printf("¿Que informe quiere saber? \n");
            printf("1.Mostrar Empleados. \n");
            printf("2.Mostrar promedios. \n");
            fflush(stdin);
            scanf("%d", &reportOption);


            switch (reportOption)
            {
                case 1:
                    orderEmployees(arrEmployees);
                    printEmployees (arrEmployees);

                    break;
                case 2:
                    salaries (arrEmployees);

                    break;
                default:
                    printf("Opcion incorrecta, intente nuevamente");

                    break;
            }

            system("pause");
            break;
        }

        case '5':
            printf("¿Seguro que quiere salir? s/n");
            fflush(stdin);
            scanf("%c", &respuesta);

            if(respuesta == 's')
                salir = 0;

            break;
        default:
            printf("Opcion incorrecta. Vuelva a seleccionar \n");
            system("pause");
            break;
        }

        system("cls");

    }
    while(salir == 1);
}
