#include <stdio.h>
#include <stdlib.h>
#include "./ArrayEmployees.h"
#include "./utn_funciones.h"

#define TRUE 1
#define FALSE 0


eEmployee listadoEmpleados[4] = {
    { 1 , "nombreUNO" , "apellidoUNO" , 456.6 , 2 , FALSE },
    { 2 , "nombreDOS" , "apellidoDOS" , 678.3 , 1 , FALSE },
    { 2 , "nombreTRES" , "apellidoTRES" , 678.3 , 1 , 3 },
    { 2 , "nombreCUATRO" , "apellidoCUATRO" , 678.3 , 1 , 4 },
};

int main()
{
    initEmployeesLibres( listadoEmpleados,4 );
    printEmployees( listadoEmpleados , 4 );
    menuAdministracionEmpleados( listadoEmpleados , 4 );
    return 0;
}
