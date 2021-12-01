#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
#include "LinkedList.h"
/** \brief Parsea los archivos recibidos y los añade a la estructura linkedlist
 *
 * \param pFile FILE*
 * \param lista LinkedList*
 * \return int
 *
 */
int parser_Libro(FILE* pFile , LinkedList* lista);
/** \brief Parsea los archivos recibidos y los añade a la estructura linkedlist
 *
 * \param pFile FILE*
 * \param lista LinkedList*
 * \return int
 *
 */
int parser_editorial (FILE* pFile , LinkedList* lista);
