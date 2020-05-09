typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;


int initEmployees( eEmployee* list , int len );

int initEmployeesLibres( eEmployee* list , int len );

int printEmployees( eEmployee* list , int len );

int printOneEmployee( eEmployee list );

int findEmployeeById( eEmployee* list , int len ,int id );

int findFreeSpace( eEmployee* list , int len );

int addEmployee( eEmployee* list , int len , char name[] , char lastName[] , float salary , int sector );

int aumentarID( eEmployee* list , int len );

int removeEmployee( eEmployee* list , int len , int id );

int sortEmployees( eEmployee* list , int len , int order );

int seCargoEmpleado( eEmployee* list , int len );

void menuAdministracionEmpleados( eEmployee empleados[] , int len );

int menuModificar();

int menuInformar();

void empleadosQueSuperanSalarioPromedio( eEmployee listaEmpleados[] , int len );

float promedioSalarios( eEmployee listaEmpleados[] , int len );

float totalSalarios( eEmployee listaEmpleados[] , int len );
