//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Estruturas.h"

void atualizar()
{
    FILE *arq;

    system("cls");
    printf ("\n\nATUALIZAÇÃO DE DADOS DOS PRODUTOS: \n");
    arq = fopen ("../Produtos.dat", "r+wb");
    if (arq != NULL)
    {
        int iden;
        TProduto produto, novoProduto;
        char edit = 'n';

        do{
            //Usuário entra com a identificação do produto que será atualizado.
            system("cls");
            printf("\n\nEntre com a identificação do produto que quer atualizar as informações: \n");
            scanf(" %d", &iden);
            fseek(arq, sizeof(TProduto) * (iden - 1), SEEK_SET);
            fread(&novoProduto, sizeof(TProduto), 1, arq);

            //Mostrar produto que será atualizado.
            system("cls");
            printf("PRODUTO COM IDENTIFICAÇÃO CORRESPONDENTE: \n");
            printf("Identificação: %d \n", novoProduto.idenProd);
            printf("Setor: %s \n", novoProduto.setor);
            printf("Nome: %s \n", novoProduto.nome);
            printf("Preço: R$ %.2lf \n", novoProduto.preco);
            printf("Data de validade: %d/%d/%d \n", novoProduto.dataVal.dia, novoProduto.dataVal.mes,novoProduto.dataVal.ano);
            printf("Quantidade no estoque: %d \n", novoProduto.qtdEstoq);
            printf("Confirmar Mesmo Editar Este Produto [S/N]? ");
            scanf(" %c", &edit);

            //Atualização do produto.
            if ((edit == 'S') || (edit == 's')) {
                system("cls");
                printf("\n\nNova identificação: ");
                scanf(" %d", &novoProduto.idenProd);
                printf("Novo setor do produto: ");
                scanf(" %[^\n]s", novoProduto.setor);
                printf("Novo nome: ");
                scanf(" %[^\n]s", novoProduto.nome);
                printf("Novo preço: ");
                scanf(" %lf", &novoProduto.preco);
                printf("Nova data de válidade (dd/mm/aaaa): ");
                scanf(" %d/%d/%d", &novoProduto.dataVal.dia, &novoProduto.dataVal.mes, &novoProduto.dataVal.ano);
                printf("Nova quantidade no estoque: ");
                scanf(" %d", &novoProduto.qtdEstoq);
                fseek(arq, sizeof(TProduto) * (iden - 1), SEEK_SET);
                fwrite(&novoProduto, sizeof(TProduto), 1, arq);
                fflush(arq);
                system("cls");
                printf("\n\nInformações do Produto Modificadas com Sucesso! \n");
                system("pause");
            }
        }while ((edit == 'N') || (edit == 'n'));
    }
    else
    {
        printf ("Erro na Abertura do Arquivo! \n");
    }
}
