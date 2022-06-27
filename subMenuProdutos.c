#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funcoes.h"

void subMenuProdutos()
{
    int subMenu3;
    FILE *arq;

    do
    {
        //Escolha de submenu de produtos.
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
            case 1: //Caso escolha 1, a função para realizar cadastro de novo cliente é chamada.
                cadNovProd();
                break;
            case 2: //Caso escolha 2, a função para atualizar informações do cliente é chamada.
                atualProd();
                break;
            case 3: //Caso escolha 3, a função para listar estoque por setor é chamada.
                system("cls");
                printf ("\n\nLISTA DE ESTOQUE POR SETOR: \n");

                system("pause");
                break;
            case 4: //Caso escolha 4, a função para listar produtos com estoque baixo é chamada.
                system("cls");
                printf ("LISTA DE PRODUTOS COM ESTOQUE BAIXO: \n");

                system("pause");
                break;
            case 9: //Caso escolha 9, volta para o menu principal.
                system("cls");
                printf ("Voltando para o menu principal... \n");
                system("pause");
                return;
            default: //Caso entre com uma opção inválida, o usuário é avisado.
                system ("cls");
                printf("COMANDO INVÁLIDO! \n");
                system("pause");
                break;
        }
    } while (1);
}