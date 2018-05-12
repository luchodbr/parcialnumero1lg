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
#define LEN_CLIENTE 10
#define LEN_AVISOS 1000

int main()
{
    Cliente clientes[LEN_CLIENTE];
    Aviso avisos[LEN_AVISOS];
    int menu;
    int auxId;
    int auxIdPubl;
    cliente_init(clientes,LEN_CLIENTE);
  //  contratacion_init(avisos,LEN_CONT);
    aviso_init(avisos,LEN_AVISOS);
    cliente_altaForzada(clientes,LEN_CLIENTE,"carlos","Las Flores","50");
    cliente_altaForzada(clientes,LEN_CLIENTE,"pepe","Belgrano ","2000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"raul","Cerrito","3000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"ATapita","PalermoHollywood","4000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"flaco","Lavalle","1000");
    cliente_altaForzada(clientes,LEN_CLIENTE,"gordo","Mitre","5000");

    do
    {
        getValidInt("\n\n1.\n2.\n3.\n4.---\n5.-----\n6.\n7.\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
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
            case 11:
                break;
            case 12:
                break;
        }
    }while(menu != 9);


    return 0;
}
