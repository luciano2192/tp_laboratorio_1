#define TRUE 1
#define FALSE 0

int menuCalculadora( float operandoUno , float operandoDos ) {
    int menu;
    printf("\n1) Ingresar el primero operando. A=%f" , operandoUno);
    printf("\n2) Ingresar el segundo operando. B=%f" , operandoDos);
    printf("\n3) Calcular todas las operaciones.");
    printf("\n4) Informar los resultados.");
    printf("\n5) Salir.\n");
    printf("\nSeleccionar una opcion <1-5>: ");
    scanf( "%d" , &menu );
}

float getDatoGenericoFloat( char mensaje[] , char error[] , float min , float max , int tipoValidacion ) {
    float valor;
    int datoValido;

    printf( "%s\n" , mensaje );
    scanf( "%f" , &valor );

    switch( validacion ) {
        case 1:
            datoValido = elDatoIngresadoEsValido( float valor , float min , float max );
            break;
        case 2:
            datoValido = elDatoIngresadoEsValido( float valor , float min );
            break;
        case 3:
            datoValido = elDatoIngresadoEsValido( float valor );
            break;
    }

    while( datoValido == FALSE  ) {
        printf( "%s\n" , error );
        scanf( "%f" , &valor );
    }

    return valor;
}

int elDatoIngresadoEsValido( float valor , float min , float max ) {
    int boolean = TRUE;
    if( valor < min || valor > max ) {
        boolean = FALSE;
    }
    return boolean;
}

int elDatoIngresadoEsValido( float valor , float min ) {
    int boolean = TRUE;
    if( valor < min ) {
        boolean = FALSE;
    }
    return boolean;
}

int elDatoIngresadoEsValido( float valor ) {
    int boolean = TRUE;
    if( valor == NULL ) {
        boolean = FALSE;
    }
    return boolean;
}

float suma( float valorUno , float valorDos ) {
    return valorUno + valorDos;
}

float resta( float valorUno , float valorDos ) {
    return valorUno - valorDos;
}

float division( float valorUno , float valorDos ) {
    return valorUno / valorDos;
}

float multiplicacion( float valorUno , float valorDos ) {
    return valorUno * valorDos;
}
