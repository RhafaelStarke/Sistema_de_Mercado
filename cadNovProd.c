//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"

void cadNovProd()
{
    char cad;
    FILE *arq;
    TProduto produtos, prodLidos;

    arq = fopen ("../Produtos.dat", "ab+");
    if (arq != NULL)
    {
        do
        {
            //COLETA DE INFORMAÇÕES DO NOVO PRODUTO
            system("cls");
            printf ("\n\nCADASTRO DE NOVO PRODUTO: \n");
            do {
                printf("\n\nIdentificação: ");
                scanf(" %d", &produtos.idenProd);
                if (produtos.idenProd < 0) {
                    printf("DIGITE UMA IDENTIFICAÇÃO VÁLIDA! \n");
                }
            } while (produtos.idenProd < 0);
            printf("Setor do produto: ");
            scanf(" %[^\n]s", produtos.setor);
            printf("Nome: ");
            scanf(" %[^\n]s", produtos.nome);
            printf("Preço: ");
            scanf(" %lf", &produtos.preco);
            printf("Data de validade (dd/mm/aaaa): ");
            scanf(" %d/%d/%d", &produtos.dataVal.dia, &produtos.dataVal.mes, &produtos.dataVal.ano);
            do
            {
                printf("Quantidade no estoque: ");
                scanf(" %d", &produtos.qtdEstoq);
                if(produtos.qtdEstoq < 0)
                {
                    printf("DIGITE UMA QUANTIDADE POSITIVA! \n");
                }
            }while(produtos.qtdEstoq < 0);

            //GRAVANDO AS INFORMAÇÕES NO ARQUIVO
            fwrite(&produtos, sizeof(TProduto), 1, arq);
            fflush (arq);

            system("cls");
            printf("PRODUTO CADASTRADO COM SUCESSO! \n");
            printf("Quer cadastrar outro produto? [S/N] ");
            scanf(" %c", &cad);
        } while((cad == 's')||(cad == 'S'));
        fclose (arq);
    }
    else
    {
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}
