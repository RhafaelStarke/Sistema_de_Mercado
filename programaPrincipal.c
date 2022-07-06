#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "subMenu.h"

int main ()
{
    SetConsoleOutputCP(65001);

    int menu;

    do
    {
        //MENU PRINCIPAL DO PROGRAMA
        system ("cls");
        printf ("\n\n*****MENU*****\n");
        printf ("1. Vendas \n");
        printf ("2. Clientes \n");
        printf ("3. Produtos \n");
        printf ("9. Sair \n");
        printf ("**************\n");
        printf ("\nSelecione o número correspondente: ");
        scanf (" %d", &menu);

        switch (menu)
        {
            case 1: //CHAMA A FUNÇÃO PARA SUBMENU DE VENDAS
                subMenuVendas();
                break;
            case 2: //CHAMA A FUNÇÃO PARA SUBMENU DE CLIENTES
                subMenuClientes();
                break;
            case 3: //CHAMA A FUNÇÃO PARA SUBMENU DE PRODUTOS
                subMenuProdutos();
                break;
            case 9: //OPÇÃO PARA SAIR
                return;
                break;
            default: //OPÇÃO CASO ENTRE COM UM VALOR DESCONHECIDO
                system ("cls");
                printf ("\nCOMANDO INVÁLIDO! \n");
                system ("pause");
                break;
        }
    } while (1);
    
    return 0;
}