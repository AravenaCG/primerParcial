#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pantalla.h"
#include "contratacion.h"
#include "validar.h"
#include "informes.h"
#define LEN_PANTALLA  50
#define LEN_CONTRATACION 50


int main()
{

   char bufferInt[50];
    char buffIdPantallaABorrar[50];
    char bufferIdPantalla_A_Modificar[50];
    char bEleccionPantalla[50];
    int eleccionPantalla;
    int idPantallaAModificar;
    int idPantallaABorrar;
    char idContratacionAModificar[50];
    int idContraAModificar;
    char buffIdContra_A_Borrar[50];
    int idContra_A_Borrar;
    char bCUIT[50];


    sPantalla listaPantallas[LEN_PANTALLA];
    sContratacion listaCOntrataciones[LEN_CONTRATACION];
    pant_InitLista(listaPantallas, LEN_PANTALLA);
    cont_InitLista(listaCOntrataciones,LEN_CONTRATACION);

    do
    {
        val_getUnsignedInt(bufferInt,"\n1- ALTA PANTALLA \n2- MODIFICAR PANTALLA \n3- BAJA PANTALA\n4- CONTRATAR PUBLICIDAD \n\n5- MODIFICAR COND. PUBLICACION \n \n6- CANCELAR CONTRATACION \n\n7- CONSULTAR FACTURACION \n\n8- LISTAR CONTRATACIONES \n\n9- LISTAR PANTALLAS\n\n10- INFORMAR\n","error",2,40);
        switch(atoi(bufferInt))
        {
        case 1:

            pant_AgregarPantalla(listaPantallas,pant_obtenerEspacioLibre(listaPantallas,LEN_PANTALLA),LEN_PANTALLA);

            break;

        case 2:
            val_getUnsignedInt(bufferIdPantalla_A_Modificar,"\nIngrese el ID de la pantalla a modificar:\n","ID NO VALIDO\n",3,50);
            idPantallaAModificar = atoi(bufferIdPantalla_A_Modificar);
            pant_modificarPantalla(listaPantallas,LEN_PANTALLA ,idPantallaAModificar);


            break;

        case 3:
            val_getUnsignedInt(buffIdPantallaABorrar,"\n Ingrese el ID de la Pantalla a Borrar : \n ", "ID NO VALIDO", 3, 50);
            idPantallaABorrar = atoi(buffIdPantallaABorrar);
            pant_BorrarPantalla(listaPantallas,idPantallaABorrar,LEN_PANTALLA);
            break;

        case 4:
           info_PrintPantallas(listaPantallas,LEN_PANTALLA);
           val_getUnsignedInt(bEleccionPantalla,"\nIngrese la pantalla seleccionada:\n","ERROR",3,50);
           eleccionPantalla= atoi(bEleccionPantalla);
           if (pant_buscarIndexPorId(listaPantallas,LEN_PANTALLA, eleccionPantalla)!= -1)
           {
               cont_AgregarContratacion(listaCOntrataciones, eleccionPantalla,cont_obtenerEspacioLibre(listaCOntrataciones,LEN_CONTRATACION),LEN_CONTRATACION);
           }

            break;

        case 5:
            val_getUnsignedInt(idContratacionAModificar,"\nIngrese el ID de Contratacion a modificar:\n","\nERRORID\n",3,50);
            idContraAModificar =atoi(idContratacionAModificar);
            cont_modificarContratacion(listaCOntrataciones,LEN_CONTRATACION,idContraAModificar);

            break;
        case 6:
            val_getUnsignedInt(buffIdContra_A_Borrar,"\nIngrese el ID de la Contratacion a Cancelar:\n","\nID NO VALIDO!!\n",3,50);
            idContra_A_Borrar= atoi(buffIdContra_A_Borrar);
            cont_BorrarContratacion(listaCOntrataciones,idContra_A_Borrar,LEN_CONTRATACION);
            break;
        case 7:
            val_getUnsignedInt(bCUIT,"\nIngrese el CUIT del Cliente a consultar:\n","\nCLIENTE NO VALIDO!:\n",3,50);

            break;
        case 8:

            break;
        case 9:
           // pant_PrintPantallas(listaPantallas,LEN_PANTALLA);
            break;
        case 10:

            break;
        }
    }
    while(atoi(bufferInt) != 11);

    return 0;
}
