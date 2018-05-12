#ifndef AVISO_H_INCLUDED
#define AVISO_H_INCLUDED
#include "Cliente.h"
typedef struct
{
    int idCliente;
    int numeroRubro;
    char textoDelAviso[50];
    char estado[20];
    //------------
    int idAviso;
    int isEmpty;
}Aviso;

int aviso_init(Aviso* arrayAviso,int lenAviso);
int aviso_mostrar(Aviso* arrayAviso,int lenAviso);
int aviso_mostrarDebug(Aviso* arrayAviso,int lenAviso);
int aviso_alta(Cliente* arrayCliente,int lenCliente,Aviso* arrayAviso,int lenAviso);
int buscarLugarLibreAviso(Aviso* arrayAviso,int lenAviso);
int pausarPublicacion(Aviso* arrayAviso, int lenAviso,Cliente* arrayCliente,int lenCliente,int idPublicacion);
int renaudarPublicacion(Aviso* arrayAviso, int lenAviso,Cliente* arrayCliente,int lenCliente,int idPublicacion);
#endif // AVISO_H_INCLUDED
