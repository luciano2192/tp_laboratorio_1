#include <stdio.h>
#include <stdlib.h>
#include "./funciones.h"

#define TRUE 1
#define FALSE 0

int menuCalculadora( float operandoUno , float operandoDos ) {
    int menu;
    printf("\n");
    printf("\n1) Ingresar el primero operando. A=%.2f" , operandoUno);
    printf("\n2) Ingresar el segundo operando. B=%.2f" , operandoDos);
    printf("\n3) Calcular todas las operaciones.");
    printf("\n4) Informar los resultados.");
    printf("\n5) Salir.\n");
    printf("\nSeleccionar una opcion <1-5>: ");
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

float getDatoGenericoFloat( char mensaje[] , char error[] , float min , float max , int tipoValidacion ) {
    float valor;
    int datoValido;

    printf( "%s\n" , mensaje );
    scanf( "%f" , &valor );

    switch( tipoValidacion ) {
        case 1:
            datoValido = elDatoIngresadoEsValido1( valor );
            break;
        case 2:
            datoValido = elDatoIngresadoEsValido2( valor , min );
            break;
        case 3:
            datoValido = elDatoIngresadoEsValido3( valor , min , max );
            break;
    }

    while( datoValido == FALSE  ) {
        printf( "%s\n" , error );
        scanf( "%f" , &valor );
    }

    return valor;
}

float elDatoIngresadoEsValido1( float valor ) {
    return valor;
}

int elDatoIngresadoEsValido2( float valor , float min ) {
    int boolean = TRUE;
    if( valor < min ) {
        boolean = FALSE;
    }
    return boolean;
}

int elDatoIngresadoEsValido3( float valor , float min , float max ) {
    int boolean = TRUE;
    if( valor < min || valor > max ) {
        boolean = FALSE;
    }
    return boolean;
}

float sumar( float valorUno , float valorDos ) {
    return valorUno + valorDos;
}

float restar( float valorUno , float valorDos ) {
    return valorUno - valorDos;
}

float dividir( float valorUno , float valorDos ) {
    float resultado;
    if( valorDos != 0 ) {
        resultado = valorUno / valorDos;
    } else {
        printf("ERROR ! no se puede dividir por cero.");
        resultado = 0;
    }
    return resultado;
}

float multiplicar( float valorUno , float valorDos ) {
    return valorUno * valorDos;
}

float factorial( float valor ) {
    int factorial = 1;

    for( int i = valor; i > 0; i--) {
        factorial *= i;
    }

    return (factorial);
}
