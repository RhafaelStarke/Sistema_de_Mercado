//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include "Estruturas.h"
#include <stdlib.h>
#include <windows.h>

void cadNovProd()
{
    FILE *arq;
    TProduto produtos;

    system("cls");
    printf ("\n\nCADASTRO DE NOVO PRODUTO: \n");
    arq = fopen ("../Produtos.csv", "a+");
    if (arq != NULL)
    {
        int qtdCadProd;
        printf ("Quantos produtos quer cadastrar? \n");
        scanf (" %d", &qtdCadProd);
        for (int i = 0; i < qtdCadProd; i++)
        {
            system("cls");
            printf ("\n\nIdentificação: \n");
            scanf (" %d", &produtos.idenProd);
            printf ("Setor do produto: \n");
            scanf (" %[^\n]s", produtos.setor);
            printf ("Nome: \n");
            scanf (" %[^\n]s", produtos.nome);
            printf ("Preço: \n");
            scanf (" %lf", &produtos.preco);
            printf ("Data de válidade: \n");
            printf ("Dia: \n");
            scanf (" %d", &produtos.dataVal.dia);
            printf ("Mês: \n");
            scanf (" %d", &produtos.dataVal.mes);
            printf ("Ano: \n");
            scanf (" %d", &produtos.dataVal.ano);
            printf ("Quantidade no estoque: \n");
            scanf (" %d", &produtos.qtdEstoq);

            fprintf (arq, "%d; ", produtos.idenProd);
            fprintf (arq, "%s; ", produtos.setor);
            fprintf (arq, "%s; ", produtos.nome);
            fprintf (arq, "%.2lf; ", produtos.preco);
            fprintf (arq, "%d/%d/%d; ", produtos.dataVal.dia, produtos.dataVal.mes, produtos.dataVal.ano);
            fprintf (arq, "%d; \n", produtos.qtdEstoq);
            fflush (arq);

            system("cls");
            printf("Produto Cadastrado com Sucesso! \n");
            system("pause");
        }
        fclose (arq);
    }
    else
    {
        printf ("Erro na abertura do arquivo! \n");
    }
}
