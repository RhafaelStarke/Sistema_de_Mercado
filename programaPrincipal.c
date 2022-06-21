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
            case 1: //Vendas
                subMenuVendas();
                break;
            case 2: //Clientes
                subMenuClientes();
                break;
            case 3: //Produtos
                subMenuProdutos();
                break;
            case 9: //Sair
                system ("cls");
                printf ("\nPrograma Encerrado Pelo Usuário! \n");
                system ("pause");
                return;
                break;
            default:
                system ("cls");
                printf ("\nComando inválido! \n");
                system ("pause");
                break;
        }
    } while (1);
    
    return 0;
}