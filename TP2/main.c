#include <stdio.h>
#include <stdlib.h>
#include "./ArrayEmployees.h"
#include "./utn_funciones.h"

#define TRUE 1
#define FALSE 0

eEmployee empleado[3] = {
    { 1 , "luciano" , "greco" , 456.6 , 2 , 0 },
    { 2 , "agustina" , "virun" , 678.3 , 1 , 0 },
    { 3 , "agustina" , "virun" , 678.3 , 1 , 1 },
};

int main()
{
    //int r = initEmployees( empleado , 2 );
    //printf("\nR----> %d",r);
    int emp = printEmployees( empleado , 3 );
    printf( "\nEMP----> %d" , emp );

    /*
    printf( "\n---------------------------------------------------------\n" );

    //  PROBANDO TOINT
    char numero[] = "345";
    int esNumero = toInt(numero);
    printf( "\nES NUMERO----> %d" , esNumero );

    printf( "\n---------------------------------------------------------\n" );

    int pedirInt;
    getDatoGenericoInt( &pedirInt , "ingrese edad: " , "ERROR !" , 0 , 100 , 3 );
    printf( "\nEDAD----> %d" , pedirInt );

    printf( "\n---------------------------------------------------------\n" );

    float pedirFloat;
    getDatoGenericoFloat( &pedirFloat , "ingrese precio: " , "ERROR !" , 0 , 1500.50 , 3 );
    printf( "\nPRECIO----> %f" , pedirFloat );

    printf( "\n---------------------------------------------------------\n" );

    char pedirString[50];
    getDatoGenericoString( pedirString , "ingrese nombre: " , "ERROR !" , 50 );
    formatearString(pedirString);
    printf( "\nPRECIO----> %s" , pedirString );

    printf( "\n---------------------------------------------------------\n" );

    int index = findEmployeeById(empleado,2,2);
    printf( "\nEMPLEADO POR ID----> %d" , index );

    printf( "\n---------------------------------------------------------\n" );

    int free = findFreeSpace(empleado,3);
    printf( "\nESPACIO LIBRE----> %d" , free );

    printf( "\n---------------------------------------------------------\n" );

    removeEmployee(empleado,3,1);
    printEmployees( empleado , 3 );

    printf( "\n---------------------------------------------------------\n" );

    char nombre[] = "naruto";
    char ape[] = "usumaki";
    float sal = 45.6;
    int sec = 3;
    addEmployee(empleado,3,nombre,ape,sal,sec);
    printEmployees( empleado , 3 );

    printf( "\n---------------------------------------------------------\n" );
    */

    char nombre[] = "naruto";
    char ape[] = "usumaki";
    float sal = 45.6;
    int sec = 3;
    addEmployee(empleado,3,nombre,ape,sal,sec);
    printEmployees( empleado , 3 );
    printf( "\n...................................................................\n" );
    sortEmployees(empleado,3,1);
    printEmployees( empleado , 3 );
    printf( "\n...................................................................\n" );
    sortEmployees(empleado,3,0);
    printEmployees( empleado , 3 );
    return 0;
}
