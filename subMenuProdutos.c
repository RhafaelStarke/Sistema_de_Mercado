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
            case 1: //CHAMA A FUNÇÃO PARA CADASTRAR UM NOVO PRODUTO
                cadNovProd();
                break;
            case 2: //CHAMA A FUNÇÃO PARA ATUALIZAR AS INFORMAÇÕES DE UM PRODUTO
                atualProd();
                break;
            case 3: //CHAMA A FUNÇÃO PARA LISTAR PRODUTOS POR SETORES
                listarSet();
                break;
            case 4: //CHAMA A FUNÇÃO PARA LISTAR PRODUTOS COM ESTOQUE BAIXO
                estoqBaixo();
                break;
            case 9: //VOLTA PARA O MENU PRINCIPAL
                return;
            default: //OPÇÃO CASO ENTRE COM O VALOR DESCONHECIDO
                system ("cls");
                printf("COMANDO INVÁLIDO! \n");
                system("pause");
                break;
        }
    } while (1);
}