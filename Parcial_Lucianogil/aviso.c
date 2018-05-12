#include "Cliente.h"
#include "aviso.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
//Funciones privadas
static int proximoId(void);
static int buscarPorId(Aviso* arrayAviso,int lenAviso, int idAviso);
//__________________


int aviso_init(Aviso* arrayAviso,int lenAviso)
{
    int retorno = -1;
    int i;
    if(lenAviso > 0 && arrayAviso != NULL)
    {
        retorno = 0;
        for(i=0;i<lenAviso;i++)
        {
            arrayAviso[i].isEmpty=1;
        }
    }
    return retorno;
}

/*
int aviso_mostrarDebug(Aviso* arrayAviso,int lenAviso)
{
    int retorno = -1;
    int i;
    if(lenAviso > 0 && arrayAviso != NULL)
    {
        retorno = 0;
        for(i=0;i<lenAviso;i++)
        {
            //printf("[DEBUG] - %d - %s - %s - %d - %d\n",arrayAviso[i].id, arrayAviso[i].cuit,arrayAviso[i].archivo,arrayAviso[i].dias, arrayAviso[i].isEmpty);
        }
    }
    return retorno;
}


int aviso_mostrar(Aviso* arrayAviso,int lenAviso)
{
    int retorno = -1;
    int i;
    if(lenAviso > 0 && arrayAviso != NULL)
    {
        retorno = 0;
        for(i=0;i<lenAviso;i++)
        {
            if(!arrayAviso[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %d - %d\n",arrayAviso[i].id,arrayAviso[i].cuit,arrayAviso[i].archivo,arrayAviso[i].dias,arrayAviso[i].isEmpty);
        }
    }
    return retorno;
}
*/

int aviso_alta(Cliente* arrayCliente,int lenCliente,Aviso* arrayAviso,int lenAviso)
{
    int retorno = -1;
    int i;
    int idCliente;
    int posCliente;
    int numeroRubroAux;
    char textoAviso[64];

    if(lenAviso > 0 && arrayAviso != NULL)
    {
        i = buscarLugarLibreAviso(arrayAviso,lenAviso);
        if(i >= 0)
        {
            // alta
            //TODO
            fflush(stdin);
            getValidInt("ID?","\nNumero no valido\n",&idCliente,0,999999,2);
            printf("su id es %d",idCliente);
            posCliente = cliente_buscarPorId(arrayCliente,lenCliente,idCliente);
            if(posCliente>=0)
            {
                // la pantalla existe
                if(!getValidInt("\nNumero Rubro","Error",&numeroRubroAux,0,1000,2))
                {
                    if(!getValidString("\nTexto aviso? ","\nEso no es un texto","El maximo es 64",textoAviso,64,2))
                    {

                        arrayAviso[i].numeroRubro = numeroRubroAux;
                        arrayAviso[i].idCliente = idCliente;// relacion
                        strcpy(arrayAviso[i].textoDelAviso,textoAviso);
                        arrayAviso[i].isEmpty=0;
                        arrayAviso[i].idAviso = proximoId();
                        printf("-Texto%s  -NumeroRubro%d    -idAviso%d  -idCliente%d",arrayAviso[i].textoDelAviso,arrayAviso[i].numeroRubro,arrayAviso[i].idAviso,arrayAviso[i].idCliente);
                    }
                }
            }

        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}

/*
int aviso_baja(Aviso* arrayAviso,int lenAviso, int idAviso)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(arrayAviso,lenAviso,idAviso);
    if(indiceAEliminar>=0)
    {
        arrayAviso[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

*/
int buscarLugarLibreAviso(Aviso* arrayAviso,int lenAviso)
{
    int retorno = -1;
    int i;
    if(lenAviso > 0 && arrayAviso != NULL)
    {
        for(i=0;i<lenAviso;i++)
        {
            if(arrayAviso[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


static int buscarPorId(Aviso* arrayAviso,int lenAviso,int idAviso)
{
    int retorno = -1;
    int i;
    if(lenAviso > 0 && arrayAviso != NULL)
    {
        retorno = -2;
        for(i=0;i<lenAviso;i++)
        {
            if(!arrayAviso[i].isEmpty && arrayAviso[i].idAviso==idAviso)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/*
int aviso_altaForzada(Aviso* arrayAviso,int lenAviso,Aviso* arrayAviso,int lenAviso,int idAviso,char* archivo,char* cuit,int dias)
{
    int retorno = -1;
    int i;
    int posPant;
    if(lenAviso > 0 && arrayAviso != NULL)
    {
        i = buscarLugarLibre(arrayAviso,lenAviso);
        if(i >= 0)
        {

            posPant = pantalla_buscarPorId(arrayAviso,lenAviso,idAviso);
            if(posPant>=0)
            {
                arrayAviso[i].dias = dias;
                strcpy(arrayAviso[i].cuit,cuit);
                strcpy(arrayAviso[i].archivo,archivo);
                //TODO
                arrayAviso[i].idAviso = idAviso; // relacion
                arrayAviso[i].isEmpty=0;
                arrayAviso[i].id = proximoId();
            }
        }
        retorno = 0;
    }
    return retorno;
}


int aviso_ordenarCuit(Aviso* arrayAviso,int lenAviso,int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Aviso auxiliarEstructura;

    if(lenAviso > 0 && arrayAviso != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<lenAviso-1;i++)
            {
                if(!arrayAviso[i].isEmpty && !arrayAviso[i+1].isEmpty)
                {
                                    if((strcmp(arrayAviso[i].cuit,arrayAviso[i+1].cuit) > 0 && orden) || (strcmp(arrayAviso[i].cuit,arrayAviso[i+1].cuit) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayAviso[i];
                        arrayAviso[i] = arrayAviso[i+1];
                        arrayAviso[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
*/
int pausarPublicacion(Aviso* arrayAviso, int lenAviso,Cliente* arrayCliente,int lenCliente,int idPublicacion)
 {
    int retorno = -1;
    int i;
    int j;
    int auxiliar;
    for(i=0; i<lenAviso;i++)
    {
        if(idPublicacion==arrayAviso[i].idAviso)
        {
            for(j=0;j<lenCliente;j++)
            {
                if(arrayAviso[i].idCliente==arrayCliente[j].idCliente)
                {
                    printf(" Nombre %s  -Apellido %s -Cuit %s -IdCliente %d",arrayCliente[j].nombre,arrayCliente[j].apellido,arrayCliente[j].cuit,arrayCliente[j].idCliente);
                    getValidInt("desea cambiar estado a Pausado 0 es si/1 es no?","error",&auxiliar,0,1,2);
                    if(auxiliar==1)
                    {
                        strcpy(arrayAviso[i].estado,"Pausado");
                        retorno=0;
                    }

                }
            }
        }
    }

    return retorno;

}
int renaudarPublicacion(Aviso* arrayAviso, int lenAviso,Cliente* arrayCliente,int lenCliente,int idPublicacion)
{
    int retorno = -1;
    int i;
    int j;
    int auxiliar;
    for(i=0; i<lenAviso;i++)
    {
        if(idPublicacion==arrayAviso[i].idAviso)
        {
            for(j=0;j<lenCliente;j++)
            {
                if(arrayAviso[i].idCliente==arrayCliente[j].idCliente)
                {
                    printf(" Nombre %s  -Apellido %s -Cuit %s -IdCliente %d",arrayCliente[j].nombre,arrayCliente[j].apellido,arrayCliente[j].cuit,arrayCliente[j].idCliente);
                    getValidInt("desea cambiar estado a Pausado 0 es si/1 es no?","error",&auxiliar,0,1,2);
                    if(auxiliar==1)
                    {
                        strcpy(arrayAviso[i].estado,"activa");
                        retorno=0;
                    }

                }
            }
        }
    }

    return retorno;

}




