#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "aviso.h"
#include "Cliente.h"
#include "informar.h"
#define LEN_CLIENTE 100
#define LEN_AVISOS 1000

int main()
{
    Cliente clientes[LEN_CLIENTE];
    Aviso avisos[LEN_AVISOS];
    int menu;
    int auxId;
    int auxIdPubl;
    int auxOpc;
    int numRubro;
    cliente_init(clientes,LEN_CLIENTE);

    aviso_init(avisos,LEN_AVISOS);
    cliente_altaForzada(clientes,LEN_CLIENTE,"pepe","Belgrano ","2000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"raul","Cerrito","3000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"ATapita","PalermoHollywood","4000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"flaco","Lavalle","1000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"gordo","Mitre","5000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"carlos","Las Flores","50");


    aviso_altaForzada(avisos,LEN_AVISOS,0,1,"que frio hace");
    aviso_altaForzada(avisos,LEN_AVISOS,0,1,"cuando vuelve el verano");
    aviso_altaForzada(avisos,LEN_AVISOS,1,1,"esta fresco pa chomba");
    aviso_altaForzada(avisos,LEN_AVISOS,1,3,"a ver si aprobamo");
    aviso_altaForzada(avisos,LEN_AVISOS,2,3,"la hamburguesa mas cara");
    aviso_altaForzada(avisos,LEN_AVISOS,3,5,"buenas plantillas");
    aviso_altaForzada(avisos,LEN_AVISOS,3,5,"asdasd");



    do
    {
        getValidInt("\n\n1 ALTA.\n2 MODIFICACION.\n3 BAJA.\n4 ALTA AVISO.\n5 PAUSAR AVISO.\n6 RENAUDAR AVISO.\n7 IMPRIMIR CLIENTES.\n8 IMPRIMIR PUBLICACIONES. \n9 INFORMAR CLIENTES. \n10 INFORMAR PUBLICACIONES. \n0 Salir\n","\nNo valida\n",&menu,0,10,1);
        switch(menu)
        {
            case 1:
                cliente_alta(clientes,LEN_CLIENTE);
                break;
            case 2:
                getValidInt("ingrese id cliente","Eso no es un id",&auxId,0,LEN_CLIENTE,2);
                cliente_modificacion(clientes,LEN_CLIENTE,auxId);
                break;
            case 3:
                getValidInt("ingrese id cliente","Eso no es un id",&auxId,0,LEN_CLIENTE,2);
                informar_baja(clientes,LEN_CLIENTE,auxId,avisos,LEN_AVISOS);
                break;
            case 4:
                aviso_alta(clientes,LEN_CLIENTE,avisos,LEN_AVISOS);
                break;
            case 5:
                getValidInt("ingrese id publicacion","Eso no es un id",&auxIdPubl,0,LEN_CLIENTE,2);
                pausarPublicacion(avisos,LEN_AVISOS,clientes,LEN_CLIENTE,auxIdPubl);
                break;
            case 6:
                getValidInt("ingrese id publicacion","Eso no es un id",&auxIdPubl,0,LEN_CLIENTE,2);
                renaudarPublicacion(avisos,LEN_AVISOS,clientes,LEN_CLIENTE,auxIdPubl);
                break;
            case 7:
                informar_Clientes(avisos,LEN_AVISOS,clientes,LEN_CLIENTE);
                break;
            case 8:
                informar_mostrarActivos(avisos,LEN_AVISOS,clientes,LEN_CLIENTE);
                break;
            case 9:
                informar_publicaciones(avisos,LEN_AVISOS,clientes,LEN_CLIENTE);
                getValidInt("Ingrese opcion/n1 para ver cliente con mas avisos activos/n2 para ver cliente con mas avisos pausados \n3 Para ver cliente con mas avisos","error",&auxOpc,1,3,2);
                if(auxOpc==1)
                    informar_ClientesMasAvisosActivos(clientes,LEN_CLIENTE);
                else if(auxOpc==2)
                    informar_ClientesMasAvisosPausados(clientes,LEN_CLIENTE);
                else
                     informar_ClientesMasAvisos(clientes,LEN_CLIENTE);
                break;
            case 10:
                getValidInt("ingrese numero Rubro","Eso no es un numero",&numRubro,0,LEN_CLIENTE,2);
                informar_publicacionesPorRubro(avisos,LEN_AVISOS,clientes,LEN_CLIENTE,numRubro);
                informar_MaxYMinPublicacionesRubro(avisos,LEN_AVISOS,6);
                break;
        }
    }while(menu != 0);


    return 0;
}
