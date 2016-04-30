#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

#define QTY_PEOPLE 20

/**
 * \brief Inicializa el status en un array de persona
 * \param personArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a estatus
 * \return -
 *
 */
void setearEstado(EPersona arrayPersona[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        arrayPersona[i].estado = value;
    }
}
/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param personArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int BuscarLugarLibre(EPersona arrayPersona[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(arrayPersona[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca la primer ocurrencia de una persona mediante su dni
 * \param personArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int BuscarPersonaPorDni(EPersona arrayPersona[],int arrayLenght,int dni)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(arrayPersona[i].dni == dni && arrayPersona[i].estado == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Es la funcion padre para armar el grafico,
    Resuelve los 3 rangos necesarios para graficar.
 * \param Array de personas
 * \param logintud del array de personas
 * \return
 *
 */
void Graficar(EPersona arrayPersona[],int arrayLenght)
{
      int i ,hasta18=0, de19a35=0, mayorDe35=0,mayor;

      for(i=0; i < arrayLenght - 1; i++)
      {
        if(arrayPersona[i].estado == 0)
        {
            continue;
        }
        if(arrayPersona[i].edad <= 18){
            hasta18 = hasta18+1;
        }else if(arrayPersona[i].edad >18 && arrayPersona[i].edad <= 35){
            de19a35 = de19a35+1;
        }else{
            mayorDe35 = mayorDe35+1;
        }
      }
      //Busco Mayor rango
      mayor = BuscoMayorRango(hasta18,de19a35,mayorDe35);
      MuestroGrafico(mayor,hasta18,de19a35,mayorDe35);

}
/**
 * \brief Busca el mayor de los rangos de edades
 * \param variable de edad hasta18
 * \param variable de edad de19a35
 * \param variable de edad mayorDe35
 * \return la cantidad de personas que tiene el rango de edad con mas personas
 *
 */
int BuscoMayorRango(int hasta18,int de19a35,int mayorDe35)
{
    int resp=0;

     if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        resp = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            resp = de19a35;
        }
        else{
        resp = mayorDe35;
        }
    }
    return resp;
}
/**
 * \brief Dibuja y muestra el grafico de edades
 * \param cantidad de personas que tiene el rango de edad con mas personas
 * \param variable de edad hasta18
 * \param variable de edad de19a35
 * \param variable de edad mayorDe35
 * \return
 *
 */
void MuestroGrafico(int mayor,int hasta18, int de19a35, int mayorDe35)
{
    int i,flag = 0;

     for(i=mayor; i>0; i--){
        printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);
}

