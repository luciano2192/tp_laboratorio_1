#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int cantidadDatos = 0;
    int flag = 0;
    char a[200];
	char b[200];
	char c[200];
	char d[200];
    Employee* nuevoEmpleado = NULL;
    if( pFile != NULL && pArrayListEmployee != NULL ) {
        while( !feof(pFile) ) {
            if( flag == 0 ) {
                fscanf( pFile , "%[^,],%[^,],%[^,],%[^\n]\n" , a , b , c , d );
                flag = 1;
            }
            if( feof(pFile) ) {
                break;
            }
            cantidadDatos = fscanf( pFile , "%[^,],%[^,],%[^,],%[^\n]\n" , a , b , c , d );
            if( cantidadDatos == 4 ) {
                nuevoEmpleado = employee_newParametros( a , b , c , d );
                if( nuevoEmpleado != NULL ) {
                    ll_add( pArrayListEmployee , nuevoEmpleado );
                    salida = 0;
                }
            }
        }
    }
    return salida;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int leido;
    Employee* nuevoEmpleado = NULL;

    if( pFile != NULL && pArrayListEmployee != NULL ) {
        while( !feof(pFile) ) {
            if( feof(pFile) ) {
                break;
            }
            nuevoEmpleado = employee_new();
            leido = fread( nuevoEmpleado , sizeof(Employee) , 1 , pFile );
            if( leido != 0 ) {
                ll_add( pArrayListEmployee , nuevoEmpleado );
                salida = 0;
            }
        }
    }
    return salida;
}
