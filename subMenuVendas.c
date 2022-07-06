#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funcoes.h"

void subMenuVendas()
{
    int subMenu1;

    do
    {
        system("cls");
        printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t********MENU VENDAS********\n");
        printf ("\n\t\t\t\t\t\t\t\t\t1. Nova Venda \n");
        printf ("\t\t\t\t\t\t\t\t\t2. Listar Venda do Cliente \n");
        printf ("\t\t\t\t\t\t\t\t\t9. Sair \n");
        printf ("\n\t\t\t\t\t\t\t\t\t***************************\n");
        printf ("\n\t\t\t\t\t\t\t\t\tSelecione o número correspondente: ");
        scanf (" %d", &subMenu1);

        switch (subMenu1)
        {
            case 1:
                venda();
                break;
            case 2:
                listarVendas();
                break;
            case 9:
                return;
            default:
                system("cls");
                printf ("COMANDO INVÁLIDO! \n");
                system("pause");
                break;
        }
    } while (1);
}