#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    //------------
    int idCliente;
    int isEmpty;
}Cliente;

int cliente_init(Cliente* arrayCliente,int lenCliente);
int cliente_mostrar(Cliente* arrayCliente,int lenCliente);
int cliente_mostrarDebug(Cliente* arrayCliente,int lenCliente);
int cliente_alta(Cliente* arrayCliente,int lenCliente);
int cliente_baja(Cliente* arrayCliente,int lenCliente, int idCliente);
int cliente_modificacion(Cliente* arrayCliente,int lenCliente, int idCliente);
int cliente_ordenar(Cliente* arrayCliente,int lenCliente, int orden);
int cliente_buscarPorId(Cliente* arrayCliente,int lenCliente, int idCliente);
int cliente_altaForzada(Cliente* arrayCliente,int lenCliente,char* nombre,char* apellido,char* cuit);


#endif // CLIENTE_H_INCLUDED
