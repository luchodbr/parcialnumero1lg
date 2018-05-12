#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "aviso.h"
#include "Cliente.h"

int informar_Clientes(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente)//(punto 6)
{
    int i;
    int j;
    int retorno=-1;
    int contadorPublicaciones=0;
    if(lenAvisos>0 && lenCliente>0 && arrayAvisos!=NULL && arrayCliente != NULL)
    {
        for(i=0;i<lenCliente;i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                contadorPublicaciones=0;
                for(j=0; j<lenAvisos;j++)
                {
                    if(arrayCliente[i].idCliente==arrayAvisos[j].idCliente && !arrayCliente[i].isEmpty && !arrayAvisos[j].isEmpty && (strcmp(arrayAvisos[j].estado,"activa")==0))
                    {
                        contadorPublicaciones++;
                    }
                }

                retorno=0;
                printf("\n[RELEASE] - nombre %s -apellido %s -cuit%s -idCliente%d -isEmpty %d -Cantidad de publi activas %d\n",arrayCliente[i].nombre, arrayCliente[i].apellido,arrayCliente[i].cuit,arrayCliente[i].idCliente,arrayCliente[i].isEmpty,contadorPublicaciones);
            }
        }
    }
    return retorno;
}
int informar_baja(Cliente* arrayCliente,int lenCliente, int idCliente,Aviso* arrayAviso,int lenAviso)
{
    int i;
    int j;
    int indiceAEliminar;
    int retorno=-1;
    int auxElim;
    for(i=0;i<lenCliente;i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                printf("idUsuario %d",arrayCliente[i].idCliente);
                for(j=0; j<lenAviso;j++)
                {
                    if(arrayCliente[i].idCliente==arrayAviso[j].idCliente && !arrayCliente[i].isEmpty && !arrayAviso[j].isEmpty && (strcmp(arrayAviso[j].estado,"activa")==0))
                    {
                        printf("\nPublicaciones del cliente %d", arrayAviso[j].idAviso);
                    }
                }
                getValidInt("Desea eliminar?1 es si/ 0 es no","error",&auxElim,0,1,2);
                if(auxElim==1)
                {
                    indiceAEliminar = cliente_buscarPorId(arrayCliente,lenCliente,idCliente);
                    if(indiceAEliminar>=0)
                        {
                            arrayCliente[indiceAEliminar].isEmpty=1;
                            arrayAviso[j].isEmpty=1;
                            retorno=0;
                        }
                }
            }
        }
    return retorno;
}
/*int informar_publicaciones(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente)
{
    for(j=0; j<lenAviso;j++)
    {
        if((strcmp(arrayAviso[j].estado,"activa")==0))
            {
                printf("\nLista publicaciones %d - Cuit cliente %", arrayAviso[j].idAviso);
}
*/
