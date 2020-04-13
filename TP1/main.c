#include <stdio.h>
#include <stdlib.h>
#include "./funciones.h"

#define TRUE 1
#define FALSE 0
#define SALIR 5

int main()
{
    float operandoUno = 0;
    float operandoDos = 0;
    float suma , resta , multiplicacion , division , factorialOperandoUno , factorialOperandoDos;

    int menu;
    int flagDatosCalculados = FALSE;

    do {
        menu = menuCalculadora( operandoUno , operandoDos );
        switch( menu ) {
            case 1:
                operandoUno = getDatoGenericoFloat( "Ingrese el primer numero: " , "ERROR ! ingrese nuevamente el valor" , 0 , 0 , 1 );
                break;
            case 2:
                operandoDos = getDatoGenericoFloat( "Ingrese el segundo numero: " , "ERROR ! ingrese nuevamente el valor" , 0 , 0 , 1 );
                break;
            case 3:
                suma = sumar( operandoUno , operandoDos );
                resta = restar( operandoUno , operandoDos );
                multiplicacion = multiplicar( operandoUno , operandoDos );
                division = dividir( operandoUno , operandoDos );
                factorialOperandoUno = factorial( operandoUno );
                factorialOperandoDos = factorial( operandoDos );
                printf("Operaciones calculadas");
                flagDatosCalculados = TRUE;
                break;
            case 4:
                system("cls");
                if ( flagDatosCalculados == TRUE ) {
                    printf( "\nEl resultado de A+B es: %.2f" , suma );
                    printf( "\nEl resultado de A-B es: %.2f" , resta );
                    printf( "\nEl resultado de A/B es: %.2f" , division );
                    printf( "\nEl resultado de A*B es: %.2f" , multiplicacion );
                    printf( "\nEl factorial de A es: %.2f y El factorial de B es: %.2f" , factorialOperandoUno , factorialOperandoDos );

                    suma = 0;
                    resta = 0;
                    division = 0;
                    multiplicacion = 0;
                } else {
                    printf("ERROR ! Primero debe calcular las operaciones (opcion 3)");
                }
                break;
            case 5:
                break;
        }
    } while( menu != SALIR );

    return 0;
}
