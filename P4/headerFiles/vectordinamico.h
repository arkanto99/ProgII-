typedef short TELEMENTO;

/*Tipo opaco, los detalles de la implementación están ocultos al usuario*/
typedef void * vectorP;

/*Función crear: asigna memoria y devuelve la asignación al vector. Recibe v1 por referencia para devolver al programa principal la dirección de memoria reservada por este procedimiento*/
void crear(vectorP *v1,unsigned long tam1);

/*Función asignar: Llena una posición del vector con un valor. Recibe una copia de la dirección de memoria reservada para el vector v1*/
void asignar(vectorP *v1,unsigned long posicion,TELEMENTO valor);

TELEMENTO recuperar(vectorP v1,unsigned long posicion);

unsigned long int tamano(vectorP v1);

void liberar(vectorP *v1);
