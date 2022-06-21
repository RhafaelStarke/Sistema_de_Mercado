#include <stdio.h>
#include "Estruturas.h"
#include "subMenu.h"
#include <stdlib.h>
#include <windows.h>

void subMenuProdutos()
{
    int subMenu3;
    TProduto produtos;
    FILE *arq;

    do
    {
        system("cls");
        printf ("\n\n**********MENU DE PRODUTOS*********\n");
        printf ("1. Cadastrar Novo Produto\n");
        printf ("2. Atualizar Informações de Produto\n");
        printf ("3. Estoque Por Setor\n");
        printf ("4. Produtos Com Estoque Baixo\n");
        printf ("9. Sair\n");
        printf ("***********************************\n");
        printf ("\nSelecione o número correspondente: ");
        scanf (" %d", &subMenu3);
        switch (subMenu3)
        {
            case 1:
                cadNovProd();
                break;
            case 2:
                atualizar();
                break;
            case 3:
                system("cls");
                printf ("\n\nLista de Estoque por setor: \n");

                system("pause");
                break;
            case 4:
                system("cls");
                printf ("Lista de Produtos Com Estoque Baixo: \n");

                system("pause");
                break;
            case 9:
                system("cls");
                printf ("Voltando para o menu principal... \n");
                system("pause");
                return;
            default:
                system ("cls");
                printf("Comando Inválido! \n");
                system("pause");
                break;
        }
    } while (1);
}