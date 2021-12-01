#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
typedef struct
{
    int id;
    char titulo[128];
    char autor[50];
    float precio;
    int idEditorial;
}eLibro;



#endif // LIBROS_H_INCLUDED
/** \brief Pide espacio en la memoria dinamica y devuelve una estructura eLibro
 *
 * \return eLibro*
 *
 */
eLibro* nuevoLibro();

/** \brief Recibe los parametros para la estructura eLibro y las carga en una estructura auxiliar, de ser todo correcto devuelve la estructura
 *
 * \param strId char*
 * \param strTitulo char*
 * \param strAutor char*
 * \param strPrecio char*
 * \param strIdEditorial char*
 * \return eLibro*
 *
 */
eLibro* libroNuevo_Parametros(char* strId,char* strTitulo,char* strAutor,char* strPrecio,char* strIdEditorial);
/** \brief  Muestra un libro cargado de la estructura eLibro
 *
 * \param listaL eLibro*
 * \param listaE LinkedList*
 * \param tam int
 * \return void
 *
 */
void mostrar_Libro(eLibro* listaL, LinkedList* listaE,int tam);
/** \brief Compara 2 strings y devuelve el resultado del mismo
 *
 * \param autor1 void*
 * \param autor2 void*
 * \return int Retorna 0 si los strings son iguales, 1 si autor1 es mayor y -1 si autor2 es mayor
 *
 */
int ordernarLibrosPorAutor(void* autor1, void* autor2);

/** \brief Menu de opciones para el programa
 *
 * \return int
 *
 */
int menu();
/** \brief Asigna un valor al campo precio
 *
 * \param libro eLibro*
 * \param precio float
 * \return int
 *
 */
int libro_setPrecio(eLibro* libro, float precio);
/** \brief Consigue el valor del campo precio y lo retorna mediante un puntero
 *
 * \param libro eLibro*
 * \param precio float*
 * \return int
 *
 */
int libro_getPrecio(eLibro* libro, float* precio);
/** \brief Asigna una cadena al campo autor
 *
 * \param libro eLibro*
 * \param autor char*
 * \return int
 *
 */
int libro_setAutor(eLibro* libro, char* autor);
/** \brief Obtiene la cadena del campo autor y la retorna mediante un puntero
 *
 * \param libro eLibro*
 * \param autor char*
 * \return int
 *
 */
int libro_getAutor(eLibro* libro, char* autor);
/** \brief Asigna una cadena al campo titulo
 *
 * \param libro eLibro*
 * \param titulo char*
 * \return int
 *
 */
int libro_setTitulo(eLibro* libro, char* titulo);
/** \brief Obtiene la cadena del campo titulo y la retorna mediante un puntero
 *
 * \param libro eLibro*
 * \param titulo char*
 * \return int
 *
 */
int libro_getTitulo(eLibro* libro, char* titulo);
/** \brief Asigna un entero al campo ID
 *
 * \param libro eLibro*
 * \param id int
 * \return int
 *
 */
int libro_setId(eLibro* libro, int id);
/** \brief Obtiene el valor del campo ID y lo retorna mediante un puntero
 *
 * \param libro eLibro*
 * \param id int*
 * \return int
 *
 */
int libro_getId(eLibro* libro, int* id);
/** \brief Asigna un entero al campo idEditorial
 *
 * \param libro eLibro*
 * \param idEditorial int
 * \return int
 *
 */
int libro_setIdEditorial(eLibro* libro, int idEditorial);
/** \brief Consigue el valor del campo idEditorial y lo retorna mediante un puntero
 *
 * \param libro eLibro*
 * \param idEditorial int*
 * \return int
 *
 */
int libro_getIdEditorial(eLibro* libro, int* idEditorial);
int contadorLibrosMasDeQuinientos(void* pElement);
