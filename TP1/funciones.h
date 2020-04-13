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
*\brief Recibe tres numeros
*\brief el primer parametro es el dato ingresado por el usuario
*\brief el segundo y tercer parametro son de validacion respecto al primero
*\param mensaje no devuelve un mensaje.
*\return 1 si es valido - 0 si NO es valido.
*
*/
float factorial( float valor );
float elDatoIngresadoEsValido1( float valor );

int elDatoIngresadoEsValido2( float valor , float min );

int elDatoIngresadoEsValido3( float valor , float min , float max );
