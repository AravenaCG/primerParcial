#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pantalla.h"
#include "contratacion.h"
#include "validar.h"

/** \brief imprime la estructura
 *
 * \param listaAutomoviles es el array
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int info_PrintPantallas(sPantalla listaPantallas[], int limite)
{
    int retorno = -1;
    int i;
    if(listaPantallas != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaPantallas[i].flag_ocupado == INDICE_OCUPADO)
            {
                printf("\n-ID PANTALLA\n:%d\n\nDIRECCION:%s\n\nPRECIO:%f\n\n ",listaPantallas[i].idPantalla, listaPantallas[i].direccion,listaPantallas[i].precio);
            }
        }

    }
    return retorno;
}


int info_BuscarCUIT(sContratacion listaContrataciones[],int len, char texto[])
{
    int i;
    int retorno =-1;
    for (i=0; i<len; i++)
    {
        if (listaContrataciones[i].flag_ocupado == INDICE_OCUPADO )
        {
            if (strcmp(listaContrataciones[i].cuitCliente, texto) == 0)
            {
                retorno = i;
                break;

            }
        }
    }
    return retorno;
}




/**info_CalcularMonto(sContratacion listaContrataciones[],sPantalla listaPantallas[], int lenContrataciones,int lenPantallas, float* );
{
    int indexE2;
    for (indexE2=0;indexE2<lenEntidad2;indexE2++)
    {
        if (listaContrataciones[indexE2].flag_ocupado == INDICE_OCUPADO && listaContrataciones[indexE2].cuit == cuitCliente)
        {
            int idE1 = listaPantallas[indexE2].idPantalla;
            int indexE1= enti1_buscarIndicePorId(arrayEntidad1,lenEntidad1,idE1);

            printf("EL ID ES:%d \n EL PRECIO ES: %.2f \n %s%d\t%s , "listaPantallas[indexE1].id,listaPantallas[indexE1].precio,arrayEntidad2[indexE2].id")
        }
    }

}
*/
