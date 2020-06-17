#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_funciones.h"

int menuLinkedList() {
    int opcion = -1;
    printf("\nMenu:"
        "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
        "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
        "\n3. Alta de empleado"
        "\n4. Modificar datos de empleado"
        "\n5. Baja de empleado"
        "\n6. Listar empleados"
        "\n7. Ordenar empleados"
        "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
        "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
        "\n10. Salir");
    getDatoGenericoInt(&opcion,"Seleccione una opcion del menu<1-10>: ","ERROR! ingrese nuevamente una opcion valida.",1,10,3);
    return opcion;
}

int menuModificacion() {
    int opcion = -1;
    printf("\n\nMenu modificacion:"
        "\nQue desea modificar ?"
        "\n1. Nombre."
        "\n2. Horas trabajadas."
        "\n3. Sueldo."
        "\n4. Salir.");
    getDatoGenericoInt(&opcion,"Seleccione una opcion del menu<1-4>: ","ERROR! ingrese nuevamente una opcion valida.",1,4,3);
    return opcion;
}

void employee_columnasTabla() {
    printf("\n------------------------LISTADO DE EMPLEADOS-----------------------------");
    printf("\n-------------------------------------------------------------------------");
    printf("\n| ID |        NOMBRE         |   HS. TRABAJADAS   |        SUELDO       |");
    printf("\n-------------------------------------------------------------------------");
}

void employee_columnasTablaModificacion() {
    printf("\n------------------------EMPLEADO A MODIFICAR-----------------------------");
    printf("\n-------------------------------------------------------------------------");
    printf("\n| ID |        NOMBRE         |   HS. TRABAJADAS   |        SUELDO       |");
    printf("\n-------------------------------------------------------------------------");
}

void employee_columnasTablaEliminar() {
    printf("\n------------------------EMPLEADO A ELIMINAR------------------------------");
    printf("\n-------------------------------------------------------------------------");
    printf("\n| ID |        NOMBRE         |   HS. TRABAJADAS   |        SUELDO       |");
    printf("\n-------------------------------------------------------------------------");
}

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    if( nuevoEmpleado != NULL ) {
        employee_setId( nuevoEmpleado , 0 );
        employee_setNombre( nuevoEmpleado , "" );
        employee_setHorasTrabajadas( nuevoEmpleado , 0 );
        employee_setSueldo( nuevoEmpleado , 0 );
    }
    return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado = NULL;
    if( idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL ) {
        nuevoEmpleado = employee_new();
        employee_setId(nuevoEmpleado,atoi(idStr));
        employee_setNombre(nuevoEmpleado,nombreStr);
        employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr));
        employee_setSueldo(nuevoEmpleado,atoi(sueldoStr));
    }
    return nuevoEmpleado;
}

void employee_delete(Employee* this) {
    if( this != NULL ) {
        free( this );
    }
}

int employee_setNombre(Employee* this,char* nombre)
{
    int salida = -1;
    if( this != NULL && nombre != NULL ) {
        /*if( employee_validarNombre(nombre,128) ) {
        }*/
            strcpy(this->nombre,nombre);
            salida = 0;
    }
    return salida;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int salida = -1;
	if( this != NULL && nombre != NULL )
	{
		strcpy(nombre,this->nombre);
		salida = 0;
	}
	return salida;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int salida = -1;
	if( this != NULL && sueldo > 0 )
	{
		this->sueldo = sueldo;
		salida = 0;
	}
	return salida;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int salida = -1;
	if( this != NULL && sueldo != NULL )
	{
		*sueldo = this->sueldo;
		salida = 0;
	}
	return salida;
}

int employee_setId(Employee* this,int id)
{
    int salida = -1;
	if( this != NULL && id >= 1 )
	{
		this->id = id;
		salida = 0;
	}
	return salida;
}
int employee_getId(Employee* this,int* id)
{
    int salida = -1;
	if( this != NULL && id != NULL )
	{
		*id = this->id;
		salida = 0;
	}
	return salida;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int salida = -1;
	if( this != NULL && horasTrabajadas > 0 )
	{
		this->horasTrabajadas = horasTrabajadas;
		salida = 0;
	}
	return salida;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int salida = -1;
	if( this != NULL && horasTrabajadas != NULL )
	{
		*horasTrabajadas = this->horasTrabajadas;
		salida = 0;
	}
	return salida;
}

/*
int employee_CompareByName(Employee* e1, Employee* e2)
{
    int salida = -1;
    if( e1 != NULL && e2 != NULL ) {
        strcmp(e1->nombre, e2->nombre);
        salida = 0;
    }
    return salida;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    if( e1 != NULL && e2 != NULL ) {
        if(e1->id > e2->id)
        {
            return 1;
        }
        else
        {
            if(e1->id < e2->id)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        return strcmp(e1->nombre, e2->nombre);
    }
}
*/

int employee_validarNombre( char* nombre , int len ) {
    int salida = -1;
    if( nombre != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( isalpha(nombre[i]) || isspace(nombre[i]) ) {
                salida = 0;
            }
        }
    }
    return salida;
}

int employee_buscarEmpleadoPorID( LinkedList* pArrayListEmployee , int id ) {
    int indice = -1;
    int idEmpleado;
    Employee* empleado;
    int lista = ll_len(pArrayListEmployee);
    if( pArrayListEmployee != NULL )
    {
        for( int i = 0 ; i < lista ; i++ )
        {
            empleado = ll_get(pArrayListEmployee, i);
            employee_getId( empleado , &idEmpleado );
            if( idEmpleado == id ) {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

