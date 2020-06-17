#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_funciones.h"
#include "controller.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int leido;
    FILE* pFile;

    if( path != NULL && pArrayListEmployee != NULL ) {
        pFile = fopen( path , "r" );
        if( pFile != NULL ) {
            leido = parser_EmployeeFromText( pFile , pArrayListEmployee );
            if( leido == 0 ) {
                printf("\nDATOS CARGADOS CORRECTAMENTE.\n");
                salida = 1;
            } else {
                printf("\nERROR AL CARGAR LOS DATOS.");
            }
        }
        fclose( pFile );
    }
    return salida;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int leido;
    FILE* pFile;

    if( path != NULL && pArrayListEmployee != NULL ) {
        pFile = fopen( path , "rb" );
        if( pFile != NULL ) {
            leido = parser_EmployeeFromBinary( pFile , pArrayListEmployee );
            if( leido == 0 ) {
                printf("\nDATOS CARGADOS CORRECTAMENTE.\n");
                salida = 1;
            } else {
                printf("\nERROR AL CARGAR LOS DATOS.");
            }
        }
        fclose( pFile );
    }
    return salida;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int auxID;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* nuevoEmpleado = NULL;

    if( pArrayListEmployee != NULL ) {
        nuevoEmpleado = employee_new();
        if( nuevoEmpleado != NULL ) {
            auxID = controller_asignarID( pArrayListEmployee );
            getDatoGenericoString( auxNombre , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 128 );
            getDatoGenericoInt( &auxHorasTrabajadas , "Ingrese horas trabajadas: " , "ERROR ! ingrese nuevamente la cantidad de horas" , 0 , 200 , 3 );
            getDatoGenericoInt( &auxSueldo , "Ingrese sueldo: " , "ERROR ! ingrese nuevamente el sueldo" , 0 , 80000 , 3 );
            employee_setId(nuevoEmpleado,auxID);
            employee_setNombre(nuevoEmpleado,auxNombre);
            employee_setHorasTrabajadas(nuevoEmpleado,auxHorasTrabajadas);
            employee_setSueldo(nuevoEmpleado,auxSueldo);
            ll_add( pArrayListEmployee , nuevoEmpleado );
            salida = 0;
        }
    }
    if( salida == 0 ) {
        printf("\nEMPLEADO CARGADO CORRECTAMENTE.\n");
    } else {
        printf("\nERROR AL CARGAR EMPLEADO.");
    }
    return salida;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int opcion;
    int auxID;
    int indice;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* empleado = NULL;

    if( pArrayListEmployee != NULL ) {
        printf("\nMODIFICANDO EMPLEADO...\n");
        getDatoGenericoInt( &auxID , "Ingrese id del empleado: " , "ERROR ! ingrese nuevamente el id" , 0 , 2000 , 3 );
        indice = employee_buscarEmpleadoPorID( pArrayListEmployee , auxID );
        empleado = ll_get( pArrayListEmployee , indice );
        employee_columnasTablaModificacion();
        printf( "\n%4d %17s %20d %20d" , empleado->id , empleado->nombre , empleado->horasTrabajadas , empleado->sueldo );
        if( empleado != NULL ) {
            do{
                opcion = menuModificacion();
                switch(opcion)
                {
                    case 1:
                        getDatoGenericoString( auxNombre , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 128 );
                        employee_setNombre( empleado , auxNombre );
                        printf("\nNombre modificado con exito.\n");
                        salida = 0;
                        break;
                    case 2:
                        getDatoGenericoInt( &auxHorasTrabajadas , "Ingrese horas trabajadas: " , "ERROR ! ingrese nuevamente la cantidad de horas" , 0 , 200 , 3 );
                        employee_setHorasTrabajadas( empleado , auxHorasTrabajadas );
                        printf("\nHoras trabajadas modificadas con exito.\n");
                        salida = 0;
                        break;
                    case 3:
                        getDatoGenericoInt( &auxSueldo , "Ingrese sueldo: " , "ERROR ! ingrese nuevamente el sueldo" , 0 , 80000 , 3 );
                        employee_setSueldo( empleado , auxSueldo );
                        printf("\nSueldo modificado con exito.\n");
                        salida = 0;
                        break;
                    case 4:
                        break;
                }
            }while(opcion != 4);
        }
    }

    return salida;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int auxID;
    int indice;
    Employee* empleado = NULL;

    if( pArrayListEmployee != NULL ) {
        getDatoGenericoInt( &auxID , "Ingrese id del empleado: " , "ERROR ! ingrese nuevamente el id" , 0 , 2000 , 3 );
        indice = employee_buscarEmpleadoPorID( pArrayListEmployee , auxID );
        empleado = ll_get( pArrayListEmployee , indice );
        employee_columnasTablaEliminar();
        printf( "\n%4d %17s %20d %20d" , empleado->id , empleado->nombre , empleado->horasTrabajadas , empleado->sueldo );
        printf("\n");
        system("pause");
        printf("\nEMPLEADO ELIMINADO CON EXITO.");
        ll_remove( pArrayListEmployee , indice );
        salida = 0;
    }
    return salida;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int lista;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int cantidadEmpleados = 0;
    Employee* empleado = NULL;

    if( pArrayListEmployee != NULL ){
        lista = ll_len(pArrayListEmployee);
        employee_columnasTabla();
        for( int i = 0 ; i < lista ; i++ ) {
            empleado = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&id);
            employee_getNombre(empleado,nombre);
            employee_getHorasTrabajadas(empleado,&horasTrabajadas);
            employee_getSueldo(empleado,&sueldo);
            printf( "\n%4d %17s %20d %20d" , id , nombre , horasTrabajadas , sueldo );
            cantidadEmpleados++;
            if( cantidadEmpleados%100 == 0 ) {
                printf( "\n\n");
                system("pause");
            }
        }
        salida = 0;
    }
    return salida;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int opcion;

    if( pArrayListEmployee != NULL ) {
        do{
            opcion = menuOrdenar();
            switch(opcion)
            {
                case 1:
                    ll_sort( pArrayListEmployee , employee_ordenarPorNombre , 1 );
                    printf("\nORDENAMIENTO FINALIZADO.\n");
                    salida = 0;
                    break;
                case 2:
                    ll_sort( pArrayListEmployee , employee_ordenarPorHoras , 1 );
                    printf("\nORDENAMIENTO FINALIZADO.\n");
                    salida = 0;
                case 3:
                    ll_sort( pArrayListEmployee , employee_ordenarPorSueldo , 1 );
                    printf("\nORDENAMIENTO FINALIZADO.\n");
                    salida = 0;
                    break;
                case 4:
                    break;
            }
        }while(opcion != 4);
    }
    return salida;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int lista;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];
    FILE* pFile;
    Employee* empleado = NULL;

    if( path != NULL && pArrayListEmployee != NULL ) {
        lista = ll_len( pArrayListEmployee );
        if( lista > 0 ) {
            pFile = fopen( path , "w");
            if( pFile != NULL ) {
                fprintf( pFile , "id,nombre,horasTrabajadas,sueldo\n" );
                for( int i = 0 ; i < lista ; i++ ) {
                    empleado = (Employee*)ll_get( pArrayListEmployee , i );
                    if( empleado != NULL ) {
                        employee_getId( empleado , &id );
                        employee_getNombre( empleado , nombre );
                        employee_getHorasTrabajadas( empleado , &horasTrabajadas );
                        employee_getSueldo( empleado , &sueldo );
                        fprintf( pFile , "%d,%s,%d,%d\n" , id , nombre , horasTrabajadas , sueldo );
                        salida = 0;
                    } else {
                        break;
                    }
                }
                fclose( pFile );
            }
        }
    }
    if( salida == 0 ) {
        printf("\nDATOS GUARDADOS CON EXITO.");
    } else {
        printf("\nERROR AL GUARDAR LOS DATOS.");
    }
    return salida;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int lista;
    FILE* pFile;
    Employee* empleado = NULL;

    if( path != NULL && pArrayListEmployee != NULL ) {
        lista = ll_len( pArrayListEmployee );
        if( lista > 0 ) {
            pFile = fopen( path , "wb");
            if( pFile != NULL ) {
                for( int i = 0 ; i < lista ; i++ ) {
                    empleado = (Employee*)ll_get( pArrayListEmployee , i );
                    if( empleado != NULL ) {
                        fwrite( empleado , sizeof(Employee) , 1 , pFile );
                        salida = 0;
                    } else {
                        break;
                    }
                }
                fclose( pFile );
            }
        }
    }
    if( salida == 0 ) {
        printf("\nDATOS GUARDADOS CON EXITO.");
    } else {
        printf("\nERROR AL GUARDAR LOS DATOS.");
    }
    return salida;
}

int controller_asignarID( LinkedList* pArrayListEmployee ) {
    int id = 0;
    int lista;
    Employee* empleado;

    if( pArrayListEmployee != NULL ) {
        lista = ll_len( pArrayListEmployee );
        if( lista > 0 ) {
            for( int i = 0 ; i < lista ; i++ ) {
                empleado = (Employee*)ll_get( pArrayListEmployee , i );
                if( empleado != NULL ) {
                    if( empleado->id > id ) {
                        id = empleado->id;
                    }
                }
            }
            id+=1;
        } else {
            id = 1;
        }
    }
    return id;
}

