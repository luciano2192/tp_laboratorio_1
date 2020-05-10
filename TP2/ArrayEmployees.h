typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

/** \brief llena el listado de empleados con algunos datos
* \param list Employee* Pointer to array of employees
* \param len int Array length
*
*/
void harcodeoListadoEmpleados( eEmployee listadoEmpleados[] , int len );

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees( eEmployee* list , int len );

/** \brief Si el listado esta hardcodeado inicializa los espacios libres
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployeesLibres( eEmployee* list , int len );

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees( eEmployee* list , int len );

/** \brief imprime el contenido de un empleado
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printOneEmployee( eEmployee list );

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById( eEmployee* list , int len ,int id );

/** \brief busca un espacio disponible para ingresar datos
*
* \param list Employee*
* \param len int
* \return retorna -1 si hay ERROR y si esta todo OK la posicion
*
*/
int findFreeSpace( eEmployee* list , int len );

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee( eEmployee* list , int len , char name[] , char lastName[] , float salary , int sector );

/** \brief aumenta automaticamente el id de los empleados
*
* \param list Employee*
* \param len int
* \return retorna el id
*
*/
int aumentarID( eEmployee* list , int len );

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee( eEmployee* list , int len , int id );

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees( eEmployee* list , int len , int order );

/** \brief verifica que se haya cargado algun empleado
*
* \param list Employee*
* \param len int
* \return retorna -1 si hay ERROR y si esta todo OK devuelve 0
*
*/
int seCargoEmpleado( eEmployee* list , int len );

/** \brief muestra el menu principal del programa
*
* \param list Employee*
* \param len int
*
*/
void menuAdministracionEmpleados( eEmployee empleados[] , int len );

/** \brief muestra las opciones del menu modificar
*
* \return retorna opcion seleccionada
*
*/
int menuModificar();

/** \brief muestra las opciones del menu informar
*
* \return retorna opcion seleccionada
*
*/
int menuInformar();

/** \brief muestra los empleados que superan el salario promedio
*
* \param list Employee*
* \param len int
* \return retorna listado
*
*/
void empleadosQueSuperanSalarioPromedio( eEmployee listaEmpleados[] , int len );

/** \brief calcula el promedio de todos los salarios ingresados en el listado
*
* \param list Employee*
* \param len int
* \return retorna el promedio
*
*/
float promedioSalarios( eEmployee listaEmpleados[] , int len );

/** \brief calcula el total de todos los salarios ingresados en el listado
*
* \param list Employee*
* \param len int
* \return retorna el total de los salarios
*
*/
float totalSalarios( eEmployee listaEmpleados[] , int len );
