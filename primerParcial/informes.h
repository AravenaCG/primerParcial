#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

#include "pantalla.h"
#include "contratacion.h"
#include "validar.h"

int info_PrintAutos(sContratacion listaContrataciones[], int limite);
int info_PrintPantallas(sPantalla listaPantallas[], int limite);
int info_BuscarCUIT(sContratacion listaContrataciones[],int len, char texto[]);
int info_ListarFacturacion(sContratacion listaContrataciones[],sPantalla listaPantallas[], int lenEntidad1,int lenEntidad2, char cuitCliente);
