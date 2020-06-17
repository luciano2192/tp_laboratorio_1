#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "./ArrayEmployees.h"
#include "./utn_funciones.h"

#define TRUE 1
#define FALSE 0

void harcodeoListadoEmpleados( eEmployee listadoEmpleados[] , int len ) {
    int id[2] = { 1 , 2 };
    char name[2][30] = { "nombreUNO" , "nombreDOS" };
    char lastName[2][30] = { "apellidoUNO" , "apellidoDOS" };
    float salary[2] = { 100.5 , 200.5 };
    int sector[2] = { 1 , 2 };
    int isEmpty[2] = { FALSE , FALSE };

    for( int i = 0 ; i < len ; i++ ) {
        listadoEmpleados[i].id = id[i];
        formatearString( listadoEmpleados[i].name );
        formatearString( listadoEmpleados[i].lastName );
        strcpy( listadoEmpleados[i].name , name[i] );
        strcpy( listadoEmpleados[i].lastName , lastName[i] );
        listadoEmpleados[i].salary = salary[i];
        listadoEmpleados[i].sector = sector[i];
        listadoEmpleados[i].isEmpty = isEmpty[i];
    };
}

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

int cantidadLugaresDisponibles( eEmployee* list , int len ) {
    int lugaresDisponibles = 0;
    if( list != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( list[i].isEmpty == TRUE ) {
                lugaresDisponibles++;
            }
        }
    }
    return lugaresDisponibles;
}

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
    /*
    if( salida == 0 ) {
        printf("\nEmpleado agregado con exito !\n");
    } else {
        printf("\nERROR ! No se agrego el empleado !\n");
    }
    */
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


int removeEmployee( eEmployee* list , int len , int id ) {
    int salida = -1;
    int index = findEmployeeById( list , len , id );
    if( index != -1 ) {
        list[index].isEmpty = 1;
        salida = 0;
    }
    return salida;
}


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
                    if( list[i].sector == list[j].sector ){
                        if( strcmp(list[i].lastName,list[j].lastName) < 0 ) {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
            } else {
                if( list[i].sector > list[j].sector ) {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                } else {
                    if( list[i].sector == list[j].sector ) {
                        if( strcmp(list[i].lastName,list[j].lastName) > 0 ) {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
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
        if( listaEmpleados[i].isEmpty == FALSE ) {
            total = total + listaEmpleados[i].salary;
        }
    }
    return total;
}

float promedioSalarios( eEmployee listaEmpleados[] , int len ) {
    float promedio = 0;
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

int ingresarDatosDeUnEmpleado( eEmployee listaEmpleados[] , int len ) {
    int salida = -1;
    char auxName[30];
    char auxLastName[30];
    float auxSalary;
    int auxSector;
    if( listaEmpleados != NULL && len > 0 ) {
        if( cantidadLugaresDisponibles(listaEmpleados,len) > 0 ) {
            getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 30 );
            getDatoGenericoString( auxLastName , "Ingrese apellido: " , "ERROR ! ingrese nuevamente su apellido" , 30 );
            formatearString( auxName );
            formatearString( auxLastName );
            getDatoGenericoFloat( &auxSalary , "Ingrese salario: " , "ERROR ! ingrese nuevamente el salario" , 0.0 , 20000.0 , 3 );
            getDatoGenericoInt( &auxSector , "Ingrese sector: " , "ERROR ! ingrese nuevamente el sector" , 0 , 3 , 3 );
            addEmployee( listaEmpleados , len , auxName , auxLastName , auxSalary , auxSector );
            salida = 0;
        } else {
            printf("\nERROR ! No hay lugar disponible.\n");
        }
    }
    return salida;
}

int ingresarDatosDeXEmpleados( eEmployee listaEmpleados[] , int len ) {
    int salida = -1;
    char respuesta;
    if( listaEmpleados != NULL && len > 0 ) {
        do{
            if( ingresarDatosDeUnEmpleado(listaEmpleados,len) == 0 ) {
                printf("\nEmpleado ingresado con exito.\n");
            }
            if( cantidadLugaresDisponibles(listaEmpleados,len) > 0 ){
                respuesta = getDatoGenericoChar("Desea ingresar otro empleado? <s-n>: ","ERROR ! ingrese el caracter correspondiente",'s','n');
                if( respuesta == 'N' || cantidadLugaresDisponibles(listaEmpleados,len) == 0 ) {
                    salida = 0;
                }
            } else {
                salida = 0;
            }
        } while( salida != 0 );
    }
    return salida;
}

int modificarEmpleado( eEmployee listaEmpleados[] , int len ) {
    int salida = -1;
    int menuMod;
    int indexEmpleado;
    int auxID;
    char auxName[30];
    char auxLastName[30];
    float auxSalary;
    int auxSector;
    printEmployees( listaEmpleados , len );
    getDatoGenericoInt( &auxID , "\nIngrese ID del empleado: " , "ERROR ! ingrese nuevamente el ID" , 0 , len , 3 );
    printf( "\nQue desea modificar ?\n" );
    menuMod = menuModificar();
    indexEmpleado = findEmployeeById( listaEmpleados , len , auxID );
    switch(menuMod) {
        case 1:
            getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 30 );
            formatearString(auxName);
            strcpy( listaEmpleados[indexEmpleado].name , auxName );
            printf( "\nNombre modificado con exito.\n" );
            printOneEmployee( listaEmpleados[indexEmpleado] );
            salida = 0;
            break;
        case 2:
            getDatoGenericoString( auxLastName , "Ingrese apellido: " , "ERROR ! ingrese nuevamente su apellido" , 30 );
            formatearString(auxLastName);
            strcpy( listaEmpleados[indexEmpleado].lastName , auxLastName );
            printf( "\nApellido modificado con exito.\n" );
            printOneEmployee( listaEmpleados[indexEmpleado] );
            salida = 0;
            break;
        case 3:
            getDatoGenericoFloat( &auxSalary , "Ingrese salario: " , "ERROR ! ingrese nuevamente el salario" , 0.0 , 20000.0 , 3 );
            listaEmpleados[indexEmpleado].salary = auxSalary;
            printf( "\nSalario modificado con exito.\n" );
            printOneEmployee( listaEmpleados[indexEmpleado] );
            salida = 0;
            break;
        case 4:
            getDatoGenericoInt( &auxSector , "Ingrese sector: " , "ERROR ! ingrese nuevamente el sector" , 0 , 3 , 3 );
            listaEmpleados[indexEmpleado].sector = auxSector;
            printf( "\nSector modificado con exito.\n" );
            printOneEmployee( listaEmpleados[indexEmpleado] );
            salida = 0;
            break;
        case 5:
            salida = 0;
            break;
    }
    return salida;
}

int eliminarEmpleado( eEmployee listaEmpleados[] , int len ) {
    int salida = -1;
    int auxID;
    int indexEmpleado;
    int empleadoEliminado;
    printEmployees( listaEmpleados , len );
    getDatoGenericoInt( &auxID , "\nIngrese ID del empleado: " , "ERROR ! ingrese nuevamente el ID" , 0 , len , 3 );
    indexEmpleado = findEmployeeById( listaEmpleados , len , auxID );
    printOneEmployee( listaEmpleados[indexEmpleado] );
    empleadoEliminado = removeEmployee( listaEmpleados , len , auxID );
    if( empleadoEliminado == 0 ) {
        salida = 0;
        printf( "\nEmpleado elimanado con exito.\n" );
    } else {
        printf( "\nERROR ! no se elimino el empleado.\n" );
    }

    return salida;
}


void menuAdministracionEmpleados( eEmployee listaEmpleados[] , int len ) {
    int menuEmpleados;
    int menuInf;
    int empleadoCargado;
    float totalSalary;
    float promedioSalary;
    do{
        menuEmpleados = menu( cantidadLugaresDisponibles(listaEmpleados,len) );
        empleadoCargado = seCargoEmpleado( listaEmpleados , len );
        switch( menuEmpleados ) {
            case 1:
                ingresarDatosDeXEmpleados( listaEmpleados , len );
                printEmployees( listaEmpleados , len );
                break;
            if( empleadoCargado == 0 ) {
                case 2:
                    modificarEmpleado( listaEmpleados , len );
                    break;
                case 3:
                    eliminarEmpleado( listaEmpleados , len );
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



