#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Parser.h"
#include "Controller.h"
#include "utn.h"
#include "Libros.h"
#include "LinkedList.h"
#include "Editorial.h"

eLibro* nuevoLibro()
{

    eLibro* NuevoLibro;
    NuevoLibro = (eLibro*)malloc(sizeof(eLibro));

    return NuevoLibro;
}

eLibro* libroNuevo_Parametros(char* strId,char* strTitulo,char* strAutor,char* strPrecio,char* strIdEditorial)
{
    eLibro *pBufferLibro;

    pBufferLibro = nuevoLibro();

    if(pBufferLibro != NULL)
    {
        libro_setId(pBufferLibro,atoi(strId));
       libro_setTitulo(pBufferLibro,strTitulo);
        libro_setAutor(pBufferLibro,strAutor);
        libro_setPrecio(pBufferLibro,atof(strPrecio));
        libro_setIdEditorial(pBufferLibro,atoi(strIdEditorial));
    }
    return pBufferLibro;
}
int libro_setId(eLibro* libro, int id)
{
    int todoOk=0;
    if(libro!=NULL)
    {
        todoOk=1;
        libro->id=id;
    }
    return todoOk;
}
int libro_getId(eLibro* libro, int* id)
{
    int todoOk=0;

    if(libro!=NULL)
    {
        todoOk=1;
        *id=libro->id;
    }
    return todoOk;
}
int libro_setTitulo(eLibro* libro, char* titulo)
{
    int todoOk = 0;
    if(libro!=NULL)
    {
        todoOk = 1;
        strcpy(libro->titulo, titulo);
    }
    return todoOk;
}
int libro_getTitulo(eLibro* libro, char* titulo)
{
    int todoOk = 0;
    if(libro!=NULL)
    {
        todoOk = 1;
        strcpy(titulo,libro->titulo);
    }
    return todoOk;
}
int libro_setAutor(eLibro* libro, char* autor)
{
    int todoOk = 0;
    if(libro!=NULL)
    {
        todoOk = 1;
        strcpy(libro->autor, autor);
    }
    return todoOk;
}
int libro_getAutor(eLibro* libro, char* autor)
{
    int todoOk = 0;
    if(libro!=NULL)
    {
        todoOk = 1;
        strcpy(autor,libro->autor);
    }
    return todoOk;
}
int libro_setPrecio(eLibro* libro, float precio)
{
    int todoOk=0;
    if(libro!=NULL)
    {
        todoOk=1;
        libro->precio=precio;
    }
    return todoOk;
}
int libro_getPrecio(eLibro* libro, float* precio)
{
    int todoOk=0;
    if(libro!=NULL)
    {
        todoOk=1;
        *precio=libro->precio;
    }
    return todoOk;
}
int libro_setIdEditorial(eLibro* libro, int idEditorial)
{
    int todoOk=0;
    if(libro!=NULL)
    {
        todoOk=1;
        libro->idEditorial=idEditorial;
    }
    return todoOk;
}
int libro_getIdEditorial(eLibro* libro, int* idEditorial)
{
    int todoOk=0;
    if(libro!=NULL)
    {
        todoOk=1;
        *idEditorial=libro->idEditorial;
    }
    return todoOk;
}

int menu()
{
    int opcion;

    system("cls");
    printf("                            ***Menu principal***                                    \n\n\n");
    printf(" 1. Cargar datos de los libros\n");
    printf(" 2. Cargar datos de las editoriales\n");
    printf(" 3. Ordenar libros por autor \n");
    printf(" 4. Mostrar datos de los libros\n");
    printf(" 5. Listado libros editorial minotauro\n");
    printf(" 6. Generar archivo 'mapeado.csv' con los descuentos\n");
    printf(" 7. Mostrar cuantos libros cuestan mas de $500\n");
    printf(" 8. Precio total libros editorial pearson\n");
    printf(" 9. Salir\n");

    opcion=getInt(" Ingrese una opcion: ",1,9);

    return opcion;
}


void mostrar_Libro(eLibro* listaL, LinkedList* listaE,int tam)
{
    char nombreEditorial[60];
    cargarNombreEditorial(listaE,tam,listaL->idEditorial,nombreEditorial);

    if (listaL != NULL)
    {
        printf("%10d    %-60s     %30s     %15.2f      %40s\n", listaL->id, listaL->titulo,
               listaL->autor, listaL->precio,nombreEditorial);
    }
}
int ordernarLibrosPorAutor(void* autor1, void* autor2)
{
    int todoOk;
    eLibro* autorUno;
    eLibro* autorDos;
    if(autor1 !=NULL && autor2 !=NULL)
    {
        autorUno= (eLibro*) autor1;
        autorDos= (eLibro*) autor2;
        todoOk= strcmp(autorUno->autor,autorDos->autor);
    }
    return todoOk;
}
int contadorLibrosMasDeQuinientos(void* pElement)
{
    eLibro* aux=NULL;
    int acumulador=0;
    float precio;
    aux = (eLibro*)pElement;

    if(aux!=NULL)
    {
        libro_getPrecio(aux,&precio);
        if(precio>500)
        {
            acumulador++;
        }
    }
    return acumulador;
}
