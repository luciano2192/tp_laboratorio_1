/**
*\brief Recibe dos numeros y los muestra junto al menu de opciones.
*\param no devuelve un mensaje.
*\return El valor ingresado por el usuario.
*
*/
int menuCalculadora( float operandoUno , float operandoDos );

/**
*\brief Recibe dos cadenas de texto y dos numeros.
*\param no devuelve un mensaje.
*\return El valor ingresado por el usuario.
*
*/
float getDatoGenericoFloat( char mensaje[] , char error[] , float min , float max , int tipoValidacion );

/**
*\brief Recibe dos numeros y realiza la suma de los mismos.
*\param mensaje no devuelve un mensaje.
*\return El resultado de la suma de los valores.
*
*/
float sumar( float valorUno , float valorDos );

/**
*\brief Recibe dos numeros y realiza la resta de los mismos.
*\param mensaje no devuelve un mensaje.
*\return El resultado de la resta de los valores.
*
*/
float restar( float valorUno , float valorDos );

/**
*\brief Recibe dos numeros y realiza la division de los mismos.
*\param mensaje no devuelve un mensaje.
*\return El resultado de la division de los valores.
*
*/
float dividir( float valorUno , float valorDos );

/**
*\brief Recibe dos numeros y realiza la multiplicacion de los mismos.
*\param mensaje no devuelve un mensaje.
*\return El resultado de la multiplicacion de los valores.
*
*/
float multiplicar( float valorUno , float valorDos );

/**
*\brief Recibe un numero y realiza el factorial del mismo.
*\param mensaje no devuelve un mensaje.
*\return El resultado del factorial del numero.
*
*/
float factorial( float valor );

/**
*\brief Recibe un numero.
*\param mensaje no devuelve un mensaje.
*\return retorna el valor ingresado.
*
*/
float elDatoIngresadoEsValido1( float valor );

/**
*\brief Recibe el valor ingresado por el usuario y un limite minimo.
*\param mensaje no devuelve un mensaje.
*\return retorna 1 si el valor es correcto - 0 si no es correcto.
*
*/
int elDatoIngresadoEsValido2( float valor , float min );

/**
*\brief Recibe el valor ingresado por el usuario, un limite minimo y un limite maximo.
*\param mensaje no devuelve un mensaje.
*\return retorna 1 si el valor es correcto - 0 si no es correcto.
*
*/
int elDatoIngresadoEsValido3( float valor , float min , float max );
