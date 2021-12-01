#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED




#endif // CONTROLLER_H_INCLUDED
#include "LinkedList.h"

/** \brief Recibe por linea de comandos el nombre del archivo, lo abre en modo lectura y envia el mismo al parser(en este caso de los archivos para libros)
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int Retorna 1 en caso de haber podido cargar y parsear el archivo y 0 en caso de error
 *
 */
int controller_loadLibro(char* path, LinkedList* lista);
/** \brief Recibe por linea de comandos el nombre del archivo, lo abre en modo lectura y envia el mismo al parser(en este caso de los archivos para editoriales)
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int Retorna 1 en caso de haber podido cargar y parsear el archivo y 0 en caso de error
 *
 */
int controller_loadEditorial(char* path, LinkedList* lista);

/** \brief Muestra por pantalla los libros que fueron cargados en las listas
 *
 * \param
 * \param
 * \return int retorna 1 en caso de poder mostrar los libros por pantalla, 0 si no es posible
 *
 */
int controller_ListLibros (LinkedList *listaLibros, LinkedList* listaEditoriales);
/** \brief Ordena los libros por autor de manera ascendente
 *
 * \param listaL LinkedList*
 * \return int retorna 0 en caso de error, 1 en caso de ser posible
 *
 */
int controller_SortLibros(LinkedList* listaL);
/** \brief Guarda la lista de libros en el archivo que le es pasado por parametros
 *
 * \param path char*
 * \param listaLibros LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *listaLibros);
/** \brief Guarda una lista mapeada y luego la muestra por pantalla
 *
 * \param listaLibros LinkedList*
 * \param listaEditoriales LinkedList*
 * \return int
 *
 */
int controller_mapper(LinkedList* listaLibros, LinkedList* listaEditoriales);
