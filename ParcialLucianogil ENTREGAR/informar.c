#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "aviso.h"
#include "Cliente.h"

/** \brief lista todos los clientes junto a sus publicaciones.
 *
 * \return int informar_Clientes(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int
 *
 */
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
/** \brief da de baja un cliente, incluyendo todas sus publicaciones si es que tenia
 *
 * \param arrayCliente Cliente*
 * \param lenCliente int
 * \param idCliente int
 * \param arrayAviso Aviso*
 * \param lenAviso int
 * \return int
 *
 */
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
int informar_publicaciones(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente)
{
    int retorno=-1;
    int i;
    int j;

    if(lenAvisos>0 && lenCliente>0 && arrayAvisos !=NULL && arrayCliente != NULL)
    {
        for(i=0;i<lenCliente;i++)
        {
            arrayCliente[i].contadorAvisosPausados=0;

            for(j=0; j<lenAvisos;j++)
            {
                if(!(arrayCliente[i].isEmpty) && !(arrayAvisos[j].isEmpty))
                {

                    if((arrayCliente[i].idCliente==arrayAvisos[j].idCliente) && (strcmp(arrayAvisos[j].estado,"Pausado")==0))
                        {
                            arrayCliente[i].contadorAvisosPausados++;
                            retorno=0;
                        }
                    else if((arrayCliente[i].idCliente==arrayAvisos[j].idCliente) && (strcmp(arrayAvisos[j].estado,"activa")==0))
                        {
                            arrayCliente[i].contadorAvisosActivos++;
                            retorno=0;
                        }
                }
            }
        }
    }
    return retorno;
}

/** \brief muestra los avisos activos y y el cuit correspondiente al cliente que lo postulo
 *
 * \param arrayAvisos Aviso*
 * \param lenAvisos int
 * \param arrayCliente Cliente*
 * \param lenCliente int
 * \return int
 *
 */
int informar_mostrarActivos(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente)
{
    int retorno=-1;
    int i;
    int j;

    if(lenAvisos>0 && lenCliente>0 && arrayAvisos !=NULL && arrayCliente != NULL)
    {
        for(i=0;i<lenCliente;i++)
        {

            for(j=0; j<lenAvisos;j++)
            {
                if(!(arrayCliente[i].isEmpty) && !(arrayAvisos[j].isEmpty))
                {


                    if((arrayCliente[i].idCliente==arrayAvisos[j].idCliente) && (strcmp(arrayAvisos[j].estado,"activa")==0))
                        {
                            printf("\n id cliente %d -Rubro %d -TextoAviso %s - Id Aviso%d   -Cuit Persona  %s",arrayAvisos[j].idCliente,arrayAvisos[j].numeroRubro,arrayAvisos[j].textoDelAviso,arrayAvisos[j].idAviso,arrayCliente[i].cuit);
                            retorno=0;
                        }
                }
            }
        }
    }
    return retorno;
}
int informar_ClientesMasAvisos(Cliente* arrayCliente, int lenCliente)
{

int i;
int retorno =-1;
int idMaximo=0;
int cantavisosMax=0;

    if(lenCliente>0 && arrayCliente != NULL)
    {
        for(i=0;i<lenCliente;i++)
        {
            if((arrayCliente[i].contadorAvisosActivos+arrayCliente[i].contadorAvisosPausados)>cantavisosMax && !arrayCliente[i].isEmpty)
            {
                idMaximo=i;
                cantavisosMax=arrayCliente[i].contadorAvisosActivos+arrayCliente[i].contadorAvisosPausados;
                retorno=0;
            }
        }
        printf("\n-Nombre %s  -Cant Avisos %d  -idCliente%d",arrayCliente[idMaximo].nombre,cantavisosMax,arrayCliente[idMaximo].idCliente);
    }

    return retorno;

}

/** \brief muestra el cliente con mas avisos activos
 *
 * \param arrayCliente Cliente*
 * \param lenCliente int
 * \return int
 *
 */
int informar_ClientesMasAvisosActivos(Cliente* arrayCliente, int lenCliente)
{

int i;
int retorno =-1;
int idMaximo=0;
int cantavisosMax=0;

    if(lenCliente>0 && arrayCliente != NULL)
    {
        for(i=0;i<lenCliente;i++)
        {
            if((arrayCliente[i].contadorAvisosActivos)>cantavisosMax && !arrayCliente[i].isEmpty)
            {
                idMaximo=i;
                cantavisosMax=arrayCliente[i].contadorAvisosActivos;
                retorno=0;
            }
        }
        printf("\n-Nombre %s  -Cant Avisos %d  -idCliente%d",arrayCliente[idMaximo].nombre,cantavisosMax,arrayCliente[idMaximo].idCliente);
    }

    return retorno;

}
/** \brief muestra cliente con mas avisos pausados
 *
 * \param arrayCliente Cliente*
 * \param lenCliente int
 * \return int
 *
 */
int informar_ClientesMasAvisosPausados(Cliente* arrayCliente, int lenCliente)
{

int i;
int retorno =-1;
int idMaximo=0;
int cantavisosMax=0;

    if(lenCliente>0 && arrayCliente != NULL )
    {
        for(i=0;i<lenCliente;i++)
        {
            if((arrayCliente[i].contadorAvisosPausados)>cantavisosMax && !arrayCliente[i].isEmpty)
            {
                idMaximo=i;
                cantavisosMax=arrayCliente[i].contadorAvisosPausados;
                retorno=0;
            }
        }
        printf("\n-Nombre %s  -Cant Avisos %d  -idCliente%d",arrayCliente[idMaximo].nombre,cantavisosMax,arrayCliente[idMaximo].idCliente);
    }

    return retorno;

}
/** \brief se ingresa un numero de rubro y se busca cuantos avisos tienen ese mismo numero de rubro
 *
 * \param arrayAvisos Aviso*
 * \param lenAvisos int
 * \param arrayCliente Cliente*
 * \param lenCliente int
 * \param numeroRubroIngresado int
 * \return int
 *
 */
int informar_publicacionesPorRubro(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente, int numeroRubroIngresado)
{
    int i;
    int retorno=-1;
    int contadorRubro=0;

    if(lenAvisos>0 && lenCliente>0 && arrayAvisos !=NULL && arrayCliente != NULL)
    {
        for(i=0;i<lenAvisos;i++)
        {
            if((arrayAvisos[i].numeroRubro==numeroRubroIngresado) && strcmp(arrayAvisos[i].estado,"activa")==0)
            {
                contadorRubro++;
                retorno=0;
            }

        }
        printf("\nNumero rubro%d  La cantidad de avisos de este rubro es %d",numeroRubroIngresado,contadorRubro);
    }
    return retorno;

}
/** \brief muestra los rubros con mas cantidad de avisos y con menos cant de avisos
 *
 * \param arrayAviso Aviso*
 * \param lenAviso int
 * \param cantRubros int
 * \return int
 *
 */
int informar_MaxYMinPublicacionesRubro(Aviso* arrayAviso,int lenAviso,int cantRubros)
{
    int retorno=-1;
    int cantPublicaciones=0;
    int i;
    int j;
    int flag=0;
    int auxRubMax;
    int auxRubMin;
    int valorMax;
    int valorMin;

    if(lenAviso>0 && arrayAviso != NULL)
    {
        retorno=0;
        for(i=0;i<cantRubros;i++)
        {
            cantPublicaciones=0;
            for(j=0;j<lenAviso;j++)
            {
                if(!arrayAviso[j].isEmpty && (strcmp(arrayAviso[i].estado,"activa")==0) && arrayAviso[j].numeroRubro==i)
                    cantPublicaciones++;
            }

            if(valorMax<cantPublicaciones || flag==0)
            {
                valorMax=cantPublicaciones;
                auxRubMax=i;
            }
            if(valorMin>cantPublicaciones || flag==0)
            {
                valorMin=cantPublicaciones;
                auxRubMin=i;
                flag=1;
            }
        }
        printf("\nCantidad de publicaciones maximas es el rubro %d: %d",auxRubMax,valorMax);
        printf("\nCantidad de publicaciones minimas es el rubro %d: %d",auxRubMin,valorMin);
    }
    return retorno;
}
