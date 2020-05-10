#include <stdio.h>
#include <stdlib.h>
#include "./ArrayEmployees.h"
#include "./utn_funciones.h"

#define TRUE 1
#define FALSE 0
#define TLISTADO 4

int main()
{
    eEmployee listadoEmpleados[TLISTADO];
    harcodeoListadoEmpleados( listadoEmpleados , TLISTADO );
    initEmployeesLibres( listadoEmpleados, TLISTADO );
    printEmployees( listadoEmpleados , TLISTADO );
    menuAdministracionEmpleados( listadoEmpleados , TLISTADO );
    return 0;
}
