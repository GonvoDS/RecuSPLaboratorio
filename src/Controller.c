#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Controller.h"
#include "Parser.h"
#include "Libros.h"
#include "LinkedList.h"
#include "Editorial.h"


int controller_loadLibro(char* path, LinkedList* lista)
{
    int todoOk = -1;
    FILE* pFile;

    if (path != NULL && lista != NULL)
    {
        pFile = fopen(path, "r");

        if (pFile != NULL)
        {
            ll_clear(lista);
            todoOk = parser_Libro(pFile, lista);
        }

        fclose(pFile);
    }
    return todoOk;
}
int controller_loadEditorial(char* path, LinkedList* lista)
{
    int todoOk = -1;
    FILE* pFile;

    if (path != NULL && lista != NULL)
    {
        pFile = fopen(path, "r");

        if (pFile != NULL)
        {
            ll_clear(lista);
            todoOk = parser_editorial(pFile, lista);
        }

        fclose(pFile);
    }
    return todoOk;
}
int controller_ListLibros (LinkedList *listaLibros, LinkedList* listaEditoriales)
{
    int todoOk = 0;
    int largo;
    int largoEd;
    eLibro* auxLib = nuevoLibro();



    if (listaLibros != NULL && listaEditoriales!= NULL )
    {
        largoEd= ll_len(listaEditoriales);
        largo = ll_len(listaLibros);
        if (largo > 0)
        {
            todoOk = 1;
            printf("			                                                                       ***LISTA DE LIBROS***	                \n");
            printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("         ID       TITULO                                                                            AUTOR                 PRECIO                                      EDITORIAL   \n");
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

            for (int i = 0; i < largo; i++)
            {
                auxLib = (eLibro*) ll_get(listaLibros, i);

                mostrar_Libro(auxLib,listaEditoriales,largoEd);
            }
        }
    }
    return todoOk;
}
int controller_SortLibros(LinkedList* listaL)
{
    int todoOk=0;
    int check;

    check = ll_sort(listaL,ordernarLibrosPorAutor,1);
    if(check)
    {
        todoOk=1;
    }

    return todoOk;
}
int controller_saveAsText(char *path, LinkedList *listaLibros) {
	int todoOk = 0;
	int largo;

	FILE *pFile;
	eLibro *aux;

	if (path != NULL && listaLibros != NULL) {
		largo = ll_len(listaLibros);

		pFile = fopen(path, "w");

		if (pFile != NULL) {
			fprintf(pFile, "Id,Titulo,Autor,Precio,idEditorial\n");
			for (int i = 0; i < largo; i++) {
				aux = (eLibro*) ll_get(listaLibros, i);
				if (aux != NULL) {
					fprintf(pFile, "%d,%s,%s,%.2f,%d\n", aux->id, aux->titulo,
							aux->autor, aux->precio, aux->idEditorial);
				}
			}
			todoOk = 1;
		}
		fclose(pFile);
	}
	return todoOk;
}
int controller_mapper(LinkedList* listaLibros, LinkedList* listaEditoriales)
{
    int todoOk=0;
    LinkedList* map;
    if(listaLibros!=NULL && listaEditoriales!=NULL)
    {
        map=ll_map(listaLibros,descuentosPorEditorial);
        controller_saveAsText("mapeado.csv",map);
        controller_ListLibros(map,listaEditoriales);
        todoOk=1;
    }
    return todoOk;
}
/*int controller_counter(LinkedList* listaLibros)
{
    int todoOk=0;
}*/
