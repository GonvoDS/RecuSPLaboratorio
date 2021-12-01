#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "Parser.h"
#include "Controller.h"
#include "utn.h"
#include "Libros.h"
#include "LinkedList.h"
#include "Editorial.h"


eEditorial* nuevaEditorial()
{

    eEditorial* NuevaEditorial;
    NuevaEditorial = (eEditorial*)malloc(sizeof(eEditorial));

    return NuevaEditorial;
}
eEditorial* editorialNuevo_Parametros(char* strIdEditorial,char* strNombreEditorial)
{
    eEditorial *pBufferEditorial;

    pBufferEditorial = nuevaEditorial();

    if(pBufferEditorial != NULL)
    {
        editorial_setId(pBufferEditorial,atoi(strIdEditorial));
        editorial_setNombre(pBufferEditorial,strNombreEditorial);

        return pBufferEditorial;
    }
    return NULL;
}
int editorial_setId(eEditorial* editorial, int id)
{
    int todoOk=0;
    if(editorial!=NULL)
    {
        todoOk=1;
        editorial->idEditorial=id;
    }
    return todoOk;
}
int editorial_getId(eEditorial* editorial, int* id)
{
    int todoOk=0;
    if(editorial!=NULL)
    {
        todoOk=1;
        *id=editorial->idEditorial;
    }
    return todoOk;
}
int editorial_setNombre(eEditorial* editorial, char* nombre)
{
    int todoOk = 0;
    if(editorial!=NULL)
    {
        todoOk = 1;
        strcpy(editorial->nombre, nombre);
    }
    return todoOk;
}
int editorial_getNombre(eEditorial* editorial, char* nombre)
{
    int todoOk = 0;
    if(editorial!=NULL)
    {
        todoOk = 1;
        strcpy(nombre,editorial->nombre);
    }
    return todoOk;
}
int cargarNombreEditorial(LinkedList* listaE, int tam, int idEditorial, char* descripcion)
{
    int todoOk=0;
    eEditorial* aux;
    if(listaE!=NULL && tam>0 && descripcion != NULL)
    {
        for(int i= 0; i<tam; i++)
        {
            aux = ll_get(listaE, i);
            if(aux->idEditorial==idEditorial)
            {

                strcpy(descripcion,aux->nombre);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
int filterEditorial (void* pElement)
{
    return ((eLibro*)pElement)->idEditorial == 4;
}
void* descuentosPorEditorial(void* pElement)
{
    eLibro* aux=NULL;
    int idEditorial;
    float precio;
    float precioConDescuento;

    aux = (eLibro*) pElement;
    if(aux !=NULL)
    {
        libro_getIdEditorial(aux,&idEditorial);
        libro_getPrecio(aux,&precio);
        if(idEditorial==1 && precio>=300)
        {
            precioConDescuento=precio*0.8;
            aux->precio=precioConDescuento;

        }
        else if(idEditorial==2 && precio <=200)
        {
            precioConDescuento=precio*0.9;
            aux->precio=precioConDescuento;
        }
    }
    return aux;
}
float acumuladorPreciosPearson(void* pElement)
{
    eLibro* aux=NULL;
    int idEditorial;
    float precio;
    float acumuladorPrecio=0;

    aux = (eLibro*) pElement;
    if (aux!=NULL)
    {
        libro_getIdEditorial(aux,&idEditorial);
        libro_getPrecio(aux,&precio);
        if(idEditorial==3)
        {
            acumuladorPrecio+=precio;
        }
    }
    return acumuladorPrecio;
}
