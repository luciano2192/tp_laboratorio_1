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
            printOneEmployee( list[i] );
            salida = 0;
        }
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


