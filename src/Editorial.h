#ifndef EDITORIAL_H_INCLUDED
#define EDITORIAL_H_INCLUDED

typedef struct
{
    int idEditorial;
    char nombre[50];
}eEditorial;


#endif // EDITORIAL_H_INCLUDED

/** \brief Pide espacio en la memoria dinamica y devuelve una estructura eEditorial
 *
 * \return eEditorial*
 *
 */
eEditorial* nuevaEditorial();
/** \brief Recibe los parametros para la estructura eEditorial y las carga en una estructura auxiliar, de ser todo correcto devuelve la estructura
 *
 * \param strIdEditorial char*
 * \param strNombreEditorial char*
 * \return eEditorial*
 *
 */
eEditorial* editorialNuevo_Parametros(char* strIdEditorial,char* strNombreEditorial);
/** \brief Compara un linked list con una fk que recibe mediante idEditorial, en caso de ser iguales la copia y la carga en la funcion
 *
 * \param listaE LinkedList*
 * \param tam int
 * \param idEditorial int
 * \param descripcion char*
 * \return int devuelve 0 en caso de errores y 1 si se realizo la operacion
 *
 */
int cargarNombreEditorial(LinkedList* listaE, int tam, int idEditorial, char* descripcion);
/** \brief Filtra la editorial segun el numero de ID de la misma
 *
 * \param element void*
 * \return int
 *
 */
int filterEditorial(void* element);
/** \brief Asigna un entero al campo idEditorial
 *
 * \param editorial eEditorial*
 * \param id int
 * \return int
 *
 */
int editorial_setId(eEditorial* editorial, int id);
/** \brief Obtiene el valor del campo idEditorial y lo retorna mediante un puntero
 *
 * \param editorial eEditorial*
 * \param id int*
 * \return int
 *
 */
int editorial_getId(eEditorial* editorial, int* id);
/** \brief Asigna una cadena al campo nombre
 *
 * \param editorial eEditorial*
 * \param nombre char*
 * \return int
 *
 */
int editorial_setNombre(eEditorial* editorial, char* nombre);
/** \brief Obtiene la cadena del campo nombre y la retorna mediante un puntero
 *
 * \param editorial eEditorial*
 * \param nombre char*
 * \return int
 *
 */
int editorial_getNombre(eEditorial* editorial, char* nombre);
/** \brief Crea un auxiliar de la estructura eLibro, consigue los idEditoriales y aplica los descuentos al valor de los libros segun los parametros pedidos
 *
 * \param pElement void*
 * \return void*
 *
 */
void* descuentosPorEditorial(void* pElement);
float acumuladorPreciosPearson(void* pElement);
