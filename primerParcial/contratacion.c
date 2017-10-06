#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "validar.h"
#include "contratacion.h"
#include "pantalla.h"




/** \brief idAutoincrementable
 *
 * \param arrayLista recibe puntero al inicio del array
 * \param len es la cantidad de elementos del array
 * \return retorna el ultimo valor para utilizar en Id
 *
 */

int cont_generar_Proximo_Id(sContratacion listaContrataciones[], int len)
{
    static int ultimoValorIdAutoincrementable = -1;
    ultimoValorIdAutoincrementable ++;
    return ultimoValorIdAutoincrementable;

}


/** \brief Inicializa la lista
 *
 * \param arrayLista recibe puntero al inicio del array
 * \param limite es la cantidad de elementos del array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int cont_InitLista(sContratacion  listaContrataciones[], int limite)
{
    int retorno = -1;
    int i;

    if( listaContrataciones != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            listaContrataciones[i].flag_ocupado = INDICE_LIBRE;
            retorno=0;
        }

    }

    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int cont_obtenerEspacioLibre(sContratacion  listaContrataciones[],int limite)
{

    int retorno = -1;
    int i;
    if(listaContrataciones != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaContrataciones[i].flag_ocupado == INDICE_LIBRE)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;

}

/**--------------------------------------------------------------------------------------------------
*-----------------------------------------------------------------------------------------------*/


/** \brief Agrega persona a la lista
 *
 * @param  index el indice en el array, es decir la posicion.
 * @param  limite cantidad de elementos en el array
 * @return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int cont_AgregarContratacion(sContratacion listaContrataciones[], int idPantalla,int index, int limite)
{
    int retorno = -1;
    char bDias[50];
    char cuit[50];
    char nombreArchivo[50];

    if(listaContrataciones != NULL && index >= 0 && index <limite)
    {

            if  (val_getUnsignedInt(bDias,"\nIngrese cantidad de dias:\n","\nError:\n",3,50)==0 )
            {


                if (val_getAlfanumerico(cuit,"\n Ingrese el CUIT del Cliente: \n","CUIT NO VALIDO\n",3,50)== 0)
                {
                    if (val_getAlfanumerico(nombreArchivo,"\nIngrese el nombre del archivo para reproducir\n","\nArchivo no valido\n",3,50)==0)

                    {
                        if (esNumerico(cuit)==0 )
                        {

                                listaContrataciones[index].dias = atoi(bDias);
                                strncpy(listaContrataciones[index].archivo,nombreArchivo,50);
                                strncpy(listaContrataciones[index].cuitCliente,cuit,50);
                                listaContrataciones[index].idContratacion = cont_generar_Proximo_Id(listaContrataciones,limite);
                                listaContrataciones[index].flag_ocupado = INDICE_OCUPADO;
                                listaContrataciones[index].idPantallaRelacion = idPantalla;
                                retorno=0;

                        }
                    }

            }
        }
    }



return retorno;
}

/** \brief modifica un elemento del array
 *
 * @param  index el indice en el array, es decir la posicion.
 * @param  len cantidad de elementos en el array
 * @param  id elementos a modificar en el array
 * @return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int cont_modificarContratacion(sContratacion listaContrataciones[],int len, int id )
{

    int retorno=-1;
    int index;
    char bIdPantalla[50];
    int idPantallaRelacion;
    char bDias[50];
    char cuit[50];
    char nombreArchivo[50];


    if (cont_buscarIndexPorId(listaContrataciones,len, id) != -1)
    {
        index = cont_buscarIndexPorId(listaContrataciones,len,id);
    }
    if (index >=0)
    {
        if(val_getNombre(bIdPantalla,"\nIngrese el ID de la PANTALLA a Contratar\n","\nError:\n",3,50)==0)
        {
            if  (val_getUnsignedInt(bDias,"\nIngrese cantidad de dias:\n","\nError:\n",3,50)==0 )
            {


                if (val_getAlfanumerico(cuit,"\n Ingrese el CUIT del Cliente: \n","CUIT NO VALIDO\n",3,50)== 0)
                {
                    if (val_getAlfanumerico(nombreArchivo,"\nIngrese el nombre del archivo para reproducir\n","\nArchivo no valido\n",3,50)==0)

                    {
                        if (esNumerico(cuit)==0 )
                        {
                            idPantallaRelacion= atoi(bIdPantalla);

                                listaContrataciones[index].dias = atoi(bDias);
                                strncpy(listaContrataciones[index].archivo,nombreArchivo,50);
                                strncpy(listaContrataciones[index].cuitCliente,cuit,50);
                                listaContrataciones[index].idContratacion = cont_generar_Proximo_Id(listaContrataciones,len);
                                listaContrataciones[index].flag_ocupado = INDICE_OCUPADO;
                                listaContrataciones[index].idPantallaRelacion = idPantallaRelacion;
                                retorno=0;
                        }

                    }
                }
            }
        }
    }



    return retorno;


}



/** \brief busca un id en la lista
 * @param  listaDuenios el array donde busca
 * @param  len cantidad de elementos en el array
 * @return retorno :posicion donde se encontro o -1 si no se encontro
 *
 */
int cont_buscarIndexPorId(sContratacion listaContrataciones[],int len,int id)
{
    int i;
    int retorno=-1;
    if (listaContrataciones != NULL && len >0 && id >0 )
    {
        for (i=0; i<len; i++)
        {
            if (listaContrataciones[i].flag_ocupado == INDICE_OCUPADO)
            {


                if (id == listaContrataciones[i].idContratacion)
                {
                    retorno=i;
                    break;

                }
            }
        }
    }
    return retorno;
}

/** \brief pone el estado del elemento en libre para "borrarlo"
 *
 * \param listaDuenios es el array que recibe
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int cont_BorrarContratacion(sContratacion listaContrataciones[], int idABorrar,int limite)
{
    int retorno = -1;
    int i = 0;

    if(listaContrataciones != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaContrataciones[i].flag_ocupado == INDICE_OCUPADO && listaContrataciones[i].idContratacion == idABorrar)
            {
                listaContrataciones[i].flag_ocupado = INDICE_LIBRE;
                printf("\nContratacion Eliminada!!!\n");
                retorno=0;
            }
        }

    }



    return retorno;
}

