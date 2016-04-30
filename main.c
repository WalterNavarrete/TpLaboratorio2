#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

#define QTY_PEOPLE 20

int main()
{
    //Inicializo la estructura
    EPersona arrayPersona[QTY_PEOPLE];
    //_________________________________________________
    EPersona personaAux;

    char auxNombreStr[50];
    char auxDniStr[50];
    int auxDni;
    char auxEdadStr[50];
    int auxEdad;
    int IndexLibre;
    int IndexEncontrado;
    //Seteo el estado
    int i,j;
    setearEstado(arrayPersona,QTY_PEOPLE,0);/**< Se indica con -1 que esa posicion esta vacia */

    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
        //Solicito la opcion y armo el Menu
        opcion = getInt("\n\n1 - Agregar persona \n2 - Borrar persona \n3 - Imprimir lista ordenada por  nombre\n4 - Imprimir grafico de edades\n5 - SALIR\n\n\n");

        switch(opcion)
        {
            case 1:
                //Busco lugares libres
                IndexLibre = BuscarLugarLibre(arrayPersona,QTY_PEOPLE);
                if(IndexLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }
                //SOLICITO LOS DATOS
                printf("\AGREGAR PERSONA\n\n");
                if (!getStringLetras("Ingrese el nombre: ",auxNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if(!getStringNumeros("Ingrese la edad: ",auxEdadStr))
                {
                    printf ("La edad debe ser numerica\n");
                    break;
                }
                auxEdad = atoi(auxEdadStr);

                if (!getStringNumeros("Ingrese el dni: ",auxDniStr))
                {
                    printf ("El dni debe ser numerico\n");
                    break;
                }
                auxDni = atoi(auxDniStr);

                if(BuscarPersonaPorDni(arrayPersona,QTY_PEOPLE,auxDni) != -1)
                {
                    printf("\n\nEL DNI YA EXISTE!!!\n");
                    break;
                }
                //GUARDO EN LA ESTRUCTURA
                arrayPersona[IndexLibre].dni = auxDni;
                strcpy(arrayPersona[IndexLibre].nombre,auxNombreStr);
                arrayPersona[IndexLibre].edad = auxEdad;
                arrayPersona[IndexLibre].estado = 1;

                break;
            case 2:
                printf("\nBORRAR PERSONA\n\n");
                 if (!getStringNumeros("Ingrese el dni de la persona a dar de baja: ",auxDniStr))
                {
                    printf ("El dni de la persona debe ser numerico\n");
                    break;
                }
                auxDni = atoi(auxDniStr);
                IndexEncontrado = BuscarPersonaPorDni(arrayPersona,QTY_PEOPLE,auxDni);
                if(IndexEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE DNI\n");
                    break;
                }
                arrayPersona[IndexEncontrado].estado = 0;
                break;
            case 3:
                printf("\nLISTAR PERSONAS\n\n");
                //RECORRRO EL ARRAY DE PERSONAS
                for(i=0; i < QTY_PEOPLE - 1; i++)
                {
                    if(arrayPersona[i].estado == 0)
                    {
                        continue;
                    }
                    for(j=i+1; j < QTY_PEOPLE; j++)
                    {
                        if(arrayPersona[i].estado == 0)
                        {
                            continue;
                        }
                        if(strcmp(arrayPersona[i].nombre,arrayPersona[j].nombre)>0)
                        {
                            personaAux = arrayPersona[j];
                            arrayPersona[j] = arrayPersona[i];
                            arrayPersona[i] = personaAux;
                        }
                    }
                }
                //RECORRO Y ARMO LA LISTA
                 for(i=0;i < QTY_PEOPLE; i++)
                {
                    if(arrayPersona[i].estado != 0)
                    {
                        printf("\n %s - %d - %d", arrayPersona[i].nombre,arrayPersona[i].dni,arrayPersona[i].edad);
                    }
                }
                break;
            case 4:
                //ARMAR GRAFICO
                //RECORRO EL ARRAY DE PERSONAS
                Graficar(arrayPersona,QTY_PEOPLE);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

