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
    float suma , resta , multiplicacion , division;

    int menu;

    do {
        menu = menuCalculadora( operandoUno , operandoDos );
        switch( menu ) {
            case 1:
                operandoUno = getDatoGenericoFloat( "Ingrese el primer numero: " , "ERROR ! ingrese nuevamente el valor" , 0 , 0 , 3 );
                break;
            case 2:
                operandoDos = getDatoGenericoFloat( "Ingrese el segundo numero: " , "ERROR ! ingrese nuevamente el valor" , 0 , 0 , 3 );
                break;
            case 3:
                suma = suma( operandoUno , operandoDos );
                resta = resta( operandoUno , operandoDos );
                multiplicacion = multiplicacion( operandoUno , operandoDos );
                division = division( operandoUno , operandoDos );
                break;
        }
    } while( menu != SALIR );

    return 0;
}
