#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Controller.h"
#include "Parser.h"
#include "Libros.h"
#include "LinkedList.h"
#include "utn.h"
#include "Editorial.h"
int main()
{
    setbuf(stdout,NULL);
    int opcion;
    int flagCargaL=0;
    int flagCargaE=0;
    int todoOk;
    char pathL[50];
    char pathE[50];
    int contLibros;
    float acumPrecios;


    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaEditorial = ll_newLinkedList();
    LinkedList* filtrado;

    do
    {
        opcion=menu();
        switch(opcion)
        {

        case 1:
            getString("Ingrese el nombre del archivo a cargar sin extension: ", pathL,50);
            strcat(pathL,".csv");
            todoOk=controller_loadLibro(pathL, listaLibros);
            if(todoOk==0)
            {
                printf("Carga realizada con exito!\n");
                flagCargaL=1;
            }
            else
            {
                printf("-Hubo un problema al realizar la carga\n");
            }

            break;
        case 2:
            getString("Ingrese el nombre del archivo a cargar sin extension: ", pathE,50);
            strcat(pathE,".csv");
            todoOk=controller_loadEditorial(pathE,listaEditorial);

            if(todoOk==0)
            {
                printf("Carga realizada con exito!\n");
                flagCargaE=1;
            }
            else
            {
                printf("-Hubo un problema al realizar la carga\n");
            }
            break;
        case 3:
            if(flagCargaL==1 && flagCargaE==1)
            {
                system("cls");
                todoOk=controller_SortLibros(listaLibros);
                if(!todoOk)
                {
                    printf("Lista ordenada correctamente.\n");
                }
                else
                {
                    printf("La lista no se pudo ordenar. \n");
                }
            }
            else
            {
                printf("Aun no se han cargado los libros y/o editoriales\n");
            }
            break;
        case 4:
            if(flagCargaL==1 && flagCargaE==1)
            {
                controller_ListLibros(listaLibros,listaEditorial);
            }
            else
            {
                printf("Aun no se han cargado los libros y/o editoriales\n");
            }
            break;
        case 5:
            if(flagCargaL==1 && flagCargaE==1)
            {
                filtrado=ll_filter(listaLibros,filterEditorial);
                controller_ListLibros(filtrado,listaEditorial);
                controller_saveAsText("minotauro.csv",filtrado);

            }
            else
            {
                printf("Aun no se han cargado los libros y/o editoriales\n");
            }
            break;

        case 6:
            if(flagCargaL==1 && flagCargaE==1)
            {
                todoOk= controller_mapper(listaLibros,listaEditorial);
                if(todoOk==1)
                {
                    printf("Archivo de mapeado generado con exito\n");
                }
                else
                {
                    printf("Hubo un error al generar el archivo\n");
                }
            }
            else
            {
                printf("Aun no se han cargado los libros y/o editoriales\n");
            }
            break;
        case 7:
            if(flagCargaL==1 && flagCargaE==1)
            {

                contLibros = ll_count(listaLibros,contadorLibrosMasDeQuinientos);
                printf("La cantidad de libros con un valor mayor a $500 es de %d\n",contLibros);
            }
            else
            {
                printf("Aun no se han cargado los libros y/o editoriales\n");
            }
            break;
        case 8:
            if(flagCargaL==1 && flagCargaE==1)
            {
                acumPrecios=ll_floatCount(listaLibros,acumuladorPreciosPearson);
                printf("El valor total de los libros de la editorial Pearson es de $%.2f\n",acumPrecios);
            }
            else
            {
                printf("Aun no se han cargado los libros y/o editoriales\n");
            }
            break;
        case 9:
            printf("Gracias por usar nuestro programa!\n");
            break;
        }
        system("pause");
    }
    while(opcion!=9);
    return 0;
}
