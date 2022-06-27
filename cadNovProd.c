//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Estruturas.h"

void cadNovProd()
{
    int qtdCadProd;
    FILE *arq;
    TProduto produtos, prodLidos;

    system("cls");
    printf ("\n\nCADASTRO DE NOVO PRODUTO: \n");
    arq = fopen ("../Produtos.dat", "ab+");
    if (arq != NULL)
    {
        printf ("Quantos produtos quer cadastrar? \n");
        scanf (" %d", &qtdCadProd);
        for (int i = 0; i < qtdCadProd; i++)
        {
            //Coleta de informações do novo produto.
            system("cls");
            printf ("\n\nIdentificação: ");
            scanf (" %d", &produtos.idenProd);
            printf ("Setor do produto: ");
            scanf (" %[^\n]s", produtos.setor);
            printf ("Nome: ");
            scanf (" %[^\n]s", produtos.nome);
            printf ("Preço: ");
            scanf (" %lf", &produtos.preco);
            printf ("Data de validade (dd/mm/aaaa): ");
            scanf (" %d/%d/%d", &produtos.dataVal.dia, &produtos.dataVal.mes, &produtos.dataVal.ano);
            printf ("Quantidade no estoque: ");
            scanf (" %d", &produtos.qtdEstoq);

            //Escrever as informações no arquivo.
            fwrite(&produtos, sizeof(TProduto), 1, arq);
            fflush (arq);

            system("cls");
            printf("PRODUTO CADASTRADO COM SUCESSO! \n");
            system("pause");
        }
        fclose (arq);
    }
    else
    {
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}
