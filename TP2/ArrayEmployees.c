#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "./ArrayEmployees.h"
#include "./utn_funciones.h"

#define TRUE 1
#define FALSE 0

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees( eEmployee* list , int len ) {
    int salida = -1;
    if( list != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            list[i].isEmpty = TRUE;
        }
        salida = 0;
    }
    return salida;
};

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployeesLibres( eEmployee* list , int len ) {
    int salida = -1;
    if( list != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( list[i].isEmpty != FALSE ) {
                list[i].isEmpty = TRUE;
            }
        }
        salida = 0;
    }
    return salida;
};

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees( eEmployee* list , int len ) {
    int salida = -1;
    if( list != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( list[i].isEmpty == FALSE ) {
                printOneEmployee( list[i] );
            }
        }
        salida = 0;
    }
    return salida;
};

int printOneEmployee( eEmployee list ) {
    int salida = -1;
    if( list.isEmpty == FALSE ) {
        printf( "\n%d | %s\t | %s\t | %f\t | %d" , list.id , list.name , list.lastName , list.salary , list.sector );
        salida = 0;
    }
    return salida;
};

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById( eEmployee* list , int len , int id ) {
    int salida = -1;
    if( list != NULL && len > 0 && id >= 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( list[i].id == id ) {
                salida = i;
                break;
            }
        }
    }
    return salida;
}

int findFreeSpace( eEmployee* list , int len ) {
    int salida = -1;
    if( list != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( list[i].isEmpty == TRUE ) {
                salida = i;
                break;
            }
        }
    }
    return salida;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/

int addEmployee( eEmployee* list , int len , char name[] , char lastName[] , float salary , int sector ) {
    int salida = -1;
    int index = findFreeSpace( list , len );
    if( index != salida && list != NULL && name != NULL && lastName != NULL && salary > 0 && sector > 0 ) {
        list[index].id = aumentarID( list , len );
        formatearString( name );
        formatearString( lastName );
        strcpy( list[index].name , name );
        strcpy( list[index].lastName , lastName );
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].isEmpty = 0;
        salida = 0;
    }

    if( salida == 0 ) {
        printf("\nEmpleado agregado con exito !\n");
    } else {
        printf("\nERROR ! No se agrego el empleado !\n");
    }
    return salida;
}

int aumentarID( eEmployee* list , int len ) {
    int maximo = 0;
    for( int i = 0 ; i < len ; i++ ) {
        if( (list[i].isEmpty == 0) && (list[i].id > maximo) ) {
            maximo = list[i].id;
        }
    }
    return maximo+1;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee( eEmployee* list , int len , int id ) {
    int salida = -1;
    int index = findEmployeeById( list , len , id );
    if( index != -1 ) {
        list[index].isEmpty = 1;
        salida = 0;
    }
    return salida;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees( eEmployee* list , int len , int order ) {
    int salida = -1;
    eEmployee aux;
    for( int i = 0 ; i < len-1 ; i++ ) {
        for( int j = i+1 ; j < len ; j++ ) {
            if( order == 0 ) {
                if( list[i].sector < list[j].sector ) {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                } else {
                    if( strcmp(list[i].lastName,list[j].lastName) < 0 ) {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            } else {
                if( list[i].sector > list[j].sector ) {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                } else {
                    if( strcmp(list[i].lastName,list[j].lastName) > 0 ) {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        salida = 0;
    }
    return salida;
}

int seCargoEmpleado( eEmployee* list , int len ) {
    int salida = -1;
    if( list != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            list[i].isEmpty = FALSE;
            break;
        }
        salida = 0;
    }
    return salida;
};

int menuModificar() {
    int menu;
    printf( "\n" );
    printf( "\n1) Nombre" );
    printf( "\n2) Apellido" );
    printf( "\n3) Salario" );
    printf( "\n4) Sector" );
    printf( "\n5) Salir.\n" );
    printf( "\nSeleccionar una opcion <1-5>: " );
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

int menuInformar() {
    int menu;
    printf( "\n" );
    printf( "\n1) Listado de los empleados ordenados alfabéticamente por Apellido y Sector." );
    printf( "\n2) Total y promedio de los salarios, y cuántos empleados superan el salario promedio" );
    printf( "\n3) Salir.\n" );
    printf( "\nSeleccionar una opcion <1-3>: " );
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

float totalSalarios( eEmployee listaEmpleados[] , int len ) {
    float total = 0;
    for(int i = 0 ; i < len ; i++ ) {
        total += listaEmpleados[i].salary;
    }
    return total;
}

float promedioSalarios( eEmployee listaEmpleados[] , int len ) {
    float promedio;
    int cantidadEmpleados = 0;
    float totalSalary = totalSalarios( listaEmpleados , len );
    for(int i = 0 ; i < len ; i++ ) {
        if( listaEmpleados[i].isEmpty == FALSE ) {
            cantidadEmpleados++;
        }
    }
    promedio = totalSalary / cantidadEmpleados;
    return promedio;
}

void empleadosQueSuperanSalarioPromedio( eEmployee listaEmpleados[] , int len ) {
    float salarioPromedio = promedioSalarios( listaEmpleados , len );
    printf( "\n------------LISTADO DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO------------\n" );
    for(int i = 0 ; i < len ; i++ ) {
        if( listaEmpleados[i].salary > salarioPromedio ) {
            printOneEmployee( listaEmpleados[i] );
        }
    }
}

void menuAdministracionEmpleados( eEmployee listaEmpleados[] , int len ) {
    int menuEmpleados;
    int menuMod;
    int menuInf;
    int empleadoCargado;
    int indexEmpleado;
    int auxID;
    char auxName[30];
    char auxLastName[30];
    float auxSalary;
    int auxSector;
    int empleadoEliminado;
    float totalSalary;
    float promedioSalary;
    do{
        menuEmpleados = menu();
        empleadoCargado = seCargoEmpleado( listaEmpleados , len );
        switch( menuEmpleados ) {
            case 1:
                getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 30 );
                getDatoGenericoString( auxLastName , "Ingrese apellido: " , "ERROR ! ingrese nuevamente su apellido" , 30 );
                formatearString( auxName );
                formatearString( auxLastName );
                getDatoGenericoFloat( &auxSalary , "Ingrese salario: " , "ERROR ! ingrese nuevamente el salario" , 0.0 , 20000.0 , 3 );
                getDatoGenericoInt( &auxSector , "Ingrese sector: " , "ERROR ! ingrese nuevamente el sector" , 0 , 3 , 3 );
                addEmployee( listaEmpleados , len , auxName , auxLastName , auxSalary , auxSector );
                printEmployees( listaEmpleados , len );
                break;
            if( empleadoCargado == 0 ) {
                case 2:
                    printEmployees( listaEmpleados , len );
                    getDatoGenericoInt( &auxID , "\nIngrese ID del empleado: " , "ERROR ! ingrese nuevamente el ID" , 0 , len , 3 );
                    menuMod = menuModificar();
                    indexEmpleado = findEmployeeById( listaEmpleados , len , auxID );
                    switch(menuMod) {
                        case 1:
                            getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 30 );
                            formatearString(auxName);
                            strcpy( listaEmpleados[indexEmpleado].name , auxName );
                            printf( "\nNombre modificado con exito.\n" );
                            printOneEmployee( listaEmpleados[indexEmpleado] );
                            break;
                        case 2:
                            getDatoGenericoString( auxLastName , "Ingrese apellido: " , "ERROR ! ingrese nuevamente su apellido" , 30 );
                            formatearString(auxLastName);
                            strcpy( listaEmpleados[indexEmpleado].lastName , auxLastName );
                            printf( "\nApellido modificado con exito.\n" );
                            printOneEmployee( listaEmpleados[indexEmpleado] );
                            break;
                        case 3:
                            getDatoGenericoFloat( &auxSalary , "Ingrese salario: " , "ERROR ! ingrese nuevamente el salario" , 0.0 , 20000.0 , 3 );
                            listaEmpleados[indexEmpleado].salary = auxSalary;
                            printf( "\nSalario modificado con exito.\n" );
                            printOneEmployee( listaEmpleados[indexEmpleado] );
                            break;
                        case 4:
                            getDatoGenericoInt( &auxSector , "Ingrese sector: " , "ERROR ! ingrese nuevamente el sector" , 0 , 3 , 3 );
                            listaEmpleados[indexEmpleado].sector = auxSector;
                            printf( "\nSector modificado con exito.\n" );
                            printOneEmployee( listaEmpleados[indexEmpleado] );
                            break;
                        case 5:
                            break;
                    }
                    break;
                case 3:
                    printEmployees( listaEmpleados , len );
                    getDatoGenericoInt( &auxID , "\nIngrese ID del empleado: " , "ERROR ! ingrese nuevamente el ID" , 0 , len , 3 );
                    indexEmpleado = findEmployeeById( listaEmpleados , len , auxID );
                    printOneEmployee( listaEmpleados[indexEmpleado] );
                    empleadoEliminado = removeEmployee( listaEmpleados , len , auxID );
                    if( empleadoEliminado == 0 ) {
                        printf( "\nEmpleado elimanado con exito.\n" );
                    } else {
                        printf( "\nERROR ! no se elimino el empleado.\n" );
                    }
                    break;
                case 4:
                    menuInf = menuInformar();
                    switch( menuInf ) {
                        case 1:
                            printf( "\n------------LISTADO DE EMPLEADOS------------\n" );
                            printEmployees( listaEmpleados , len );
                            break;
                        case 2:
                            totalSalary = totalSalarios( listaEmpleados , len );
                            promedioSalary = promedioSalarios( listaEmpleados , len );
                            printf( "\nTOTAL SALARIOS----------->%f\n" , totalSalary );
                            printf( "\nPROMEDIO SALARIOS----------->%f\n" , promedioSalary );
                            empleadosQueSuperanSalarioPromedio( listaEmpleados , len );
                            break;
                        case 3:
                            break;
                    }
                    break;
            }
            case 5:
                break;
        }

    } while( menuEmpleados != 5 );
}



