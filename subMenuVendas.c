#include <stdio.h>
#include "Estruturas.h"
#include <stdlib.h>
#include <windows.h>

void subMenuVendas()
{
    int subMenu1;
    TVenda vendas;

    do
    {
        system("cls");
        printf ("\n\n********MENU VENDAS********\n");
        printf ("1. Nova Venda \n");
        printf ("2. Listar Venda do Cliente \n");
        printf ("9. Sair \n");
        printf ("***************************\n");
        printf ("\nSelecione o número correspondente: ");
        scanf (" %d", &subMenu1);

        switch (subMenu1)
        {
            case 1:
                system("cls");
                printf ("\n\nREALIZAR NOVA VENDA: \n");

                system("pause");
                break;
            case 2:
                system("cls");
                printf ("\n\nLISTA DE NOVA VENDA DO CLIENTE: \n");

                system("pause");
                break;
            case 9:
                system("cls");
                printf("Voltando para o menu principal... \n");
                system("pause");
                return;
                break;
            default:
                system("cls");
                printf ("COMANDO INVÁLIDO! \n");
                system("pause");
                break;
        }
    } while (1);
}