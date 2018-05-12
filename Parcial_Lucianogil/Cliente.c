#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"


//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Cliente* arrayCliente,int lenCliente);
//__________________


int cliente_init(Cliente* arrayCliente,int lenCliente)
{
    int retorno = -1;
    int i;
    if(lenCliente > 0 && arrayCliente != NULL)
    {
        retorno = 0;
        for(i=0;i<lenCliente;i++)
        {
            arrayCliente[i].isEmpty=1;
        }
    }
    return retorno;
}


int cliente_mostrarDebug(Cliente* arrayCliente,int lenCliente)
{
    int retorno = -1;
    int i;
    if(lenCliente > 0 && arrayCliente != NULL)
    {
        retorno = 0;
        for(i=0;i<lenCliente;i++)
        {
            printf("[DEBUG] - %s - %s - %s - %d - %d\n",arrayCliente[i].nombre,arrayCliente[i].apellido,arrayCliente[i].cuit,arrayCliente[i].idCliente,arrayCliente[i].isEmpty);
        }
    }
    return retorno;
}


int cliente_mostrar(Cliente* arrayCliente,int lenCliente)
{
    int retorno = -1;
    int i;
    if(lenCliente > 0 && arrayCliente != NULL)
    {
        retorno = 0;
        for(i=0;i<lenCliente;i++)
        {
            if(!arrayCliente[i].isEmpty)
                printf("[RELEASE] -Nombre %s -Apellido %s -Cuit %s -idcliente %d -isEmpty %d\n",arrayCliente[i].nombre, arrayCliente[i].apellido, arrayCliente[i].cuit,arrayCliente[i].idCliente, arrayCliente[i].isEmpty);
        }
    }
    return retorno;
}


int cliente_alta(Cliente* arrayCliente,int lenCliente)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    if(lenCliente > 0 && arrayCliente != NULL)
    {
        i = buscarLugarLibre(arrayCliente,lenCliente);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,40,2))
                {
                    if(getStringNumeros("\nCuit?",cuit));

                            retorno = 0;
                            strcpy(arrayCliente[i].nombre,nombre);
                            strcpy(arrayCliente[i].apellido,apellido);
                            strcpy(arrayCliente[i].cuit,cuit);
                            //------------------------------
                            //------------------------------
                            arrayCliente[i].idCliente = proximoId();
                            arrayCliente[i].isEmpty = 0;


                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int cliente_baja(Cliente* arrayCliente,int lenCliente, int idCliente)
{
    int indiceAEliminar;
    int retorno=-1;

    //listar todas las publicaciones de este cliente pregntar si se quiere borrar y eliminar publicaciones y cliente
    indiceAEliminar = cliente_buscarPorId(arrayCliente,lenCliente,idCliente);
    if(indiceAEliminar>=0)
    {
        arrayCliente[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


int cliente_modificacion(Cliente* arrayCliente,int lenCliente, int idCliente)
{
    int retorno = -1;
    int indiceAModificar;
    char buffer[50];
    char apellido[50];
    char cuit[50];
    indiceAModificar = cliente_buscarPorId(arrayCliente,lenCliente,idCliente);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
        {
            if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,40,2))
            {
                if(getStringNumeros("\nCuit? ",cuit));
                {
                retorno = 0;
                strcpy(arrayCliente[indiceAModificar].nombre,buffer);
                strcpy(arrayCliente[indiceAModificar].apellido,apellido);
                strcpy(arrayCliente[indiceAModificar].cuit,cuit);
                //------------------------------
                //TODO
                }
            }
        }

        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

int cliente_ordenar(Cliente* arrayCliente,int lenCliente, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(lenCliente > 0 && arrayCliente != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<lenCliente-1;i++)
            {
                if(!arrayCliente[i].isEmpty && !arrayCliente[i+1].isEmpty)
                {
                    if((strcmp(arrayCliente[i].nombre,arrayCliente[i+1].nombre) > 0 && orden) || (strcmp(arrayCliente[i].nombre,arrayCliente[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayCliente[i];
                        arrayCliente[i] = arrayCliente[i+1];
                        arrayCliente[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


static int buscarLugarLibre(Cliente* arrayCliente,int lenCliente)
{
    int retorno = -1;
    int i;
    if(lenCliente > 0 && arrayCliente != NULL)
    {
        for(i=0;i<lenCliente;i++)
        {
            if(arrayCliente[i].isEmpty==1)
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


int cliente_buscarPorId(Cliente* arrayCliente,int lenCliente, int idCliente)
{
    int retorno = -1;
    int i;
    if(lenCliente > 0 && arrayCliente != NULL)
    {
        retorno = -2;
        for(i=0;i<lenCliente;i++)
        {
            if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==idCliente)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int cliente_altaForzada(Cliente* arrayCliente,int lenCliente,char* nombre,char* apellido,char* cuit)
{
    int retorno = -1;
    int i;

    if(lenCliente > 0 && arrayCliente != NULL)
    {
        i = buscarLugarLibre(arrayCliente,lenCliente);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayCliente[i].nombre,nombre);
            strcpy(arrayCliente[i].apellido,apellido);
            strcpy(arrayCliente[i].cuit,cuit);

            //------------------------------
            //------------------------------
            arrayCliente[i].idCliente = proximoId();
            arrayCliente[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

