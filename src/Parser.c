#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "Controller.h"
#include "Libros.h"
#include "LinkedList.h"
#include "Editorial.h"


int parser_Libro(FILE* pFile, LinkedList* lista)
{
    int todoOk = -1;
    char strId[50];
    char strTitulo[128];
    char strAutor[50];
    char strPrecio[50];
    char strIdEditorial[50];
    int leidos;
    eLibro* pNuevoLibro;
    if(pFile != NULL && lista != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strTitulo,strAutor,strPrecio,strIdEditorial);
        do
        {
            leidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strTitulo,strAutor,strPrecio,strIdEditorial);
            if(leidos == 5)
            {
                pNuevoLibro = libroNuevo_Parametros(strId, strTitulo,strAutor,strPrecio,strIdEditorial);
                ll_add(lista,pNuevoLibro);
                todoOk = 0;
            }
            else
            {
                printf("\nError en la lectura del archivo.\n");
                todoOk = -1;
                break;
            }
        }
        while(!feof(pFile));
    }
    return todoOk;
}

int parser_editorial (FILE* pFile, LinkedList* lista)
{
    int todoOk = -1;
    char strIdEditorial[50];
    char strNombre[128];
    int leidos;
    eEditorial* pNuevaEditorial;
    if(pFile != NULL && lista != NULL)
    {
        fscanf(pFile,"%[^,],%[^\n]\n", strIdEditorial, strNombre);
        do
        {
            leidos = fscanf(pFile,"%[^,],%[^\n]\n", strIdEditorial, strNombre);
            if(leidos == 2)
            {
                pNuevaEditorial = editorialNuevo_Parametros(strIdEditorial, strNombre);
                ll_add(lista,pNuevaEditorial);
                todoOk = 0;
            }
            else
            {
                printf("\nError en la lectura del archivo.\n");
                todoOk = -1;
                break;
            }
        }
        while(!feof(pFile));
    }
    return todoOk;
}
