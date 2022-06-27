#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "subMenu.h"
#include "Estruturas.h"

int main ()
{
    SetConsoleOutputCP(65001);

    int menu;

    do
    {
        //Menu principal do programa.
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
            case 1: //Submenu de vendas.
                subMenuVendas();
                break;
            case 2: //Submenu de clientes.
                subMenuClientes();
                break;
            case 3: //Submenu de produtos.
                subMenuProdutos();
                break;
            case 9: //Opção de sair.
                system ("cls");
                printf ("\nPROGRAMA ENCERRADO PELO USUÁRIO! \n");
                system ("pause");
                return;
                break;
            default: //Opção caso entre com outro valor.
                system ("cls");
                printf ("\nCOMANDO INVÁLIDO! \n");
                system ("pause");
                break;
        }
    } while (1);
    
    return 0;
}