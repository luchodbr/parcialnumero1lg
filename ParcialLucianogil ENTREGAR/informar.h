#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED
int informar_Clientes(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente);
int informar_baja(Cliente* arrayCliente,int lenCliente, int idCliente,Aviso* arrayAviso,int lenAviso);
int informar_publicaciones(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente);
int informar_mostrarActivos(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente);
int informar_ClientesMasAvisos(Cliente* arrayCliente, int lenCliente);
int informar_ClientesMasAvisosActivos(Cliente* arrayCliente, int lenCliente);
int informar_ClientesMasAvisosPausados(Cliente* arrayCliente, int lenCliente);
int informar_publicacionesPorRubro(Aviso* arrayAvisos,int lenAvisos,Cliente* arrayCliente, int lenCliente, int numeroRubroIngresado);
int informar_MaxYMinPublicacionesRubro(Aviso* arrayAviso,int lenAviso,int cantRubros);
#endif // INFORMAR_H_INCLUDED
