//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include "Estruturas.h"
#include <stdlib.h>
#include <windows.h>

void atualizar()
{
    FILE *arq;
    TProduto produtos;

    system("cls");
    printf ("\n\nAtualização de Informações dos Produtos: \n");
    arq = fopen ("../Produtos.csv", "a+");
    if (arq != NULL)
    {
        int iden;
        TProduto novoProduto;
        printf ("Entre com a identificação do produto: \n");
        scanf (" %d", &iden);
        fseek (arq, sizeof(TProduto)*(iden-1), SEEK_SET);
        fread (&novoProduto, sizeof(TProduto), 1, arq);
        printf (" %d, %s, %s, %lf, %d/%d/%d, %d \n", novoProduto.idenProd, novoProduto.setor, novoProduto.nome, novoProduto.preco, novoProduto.dataVal.dia, novoProduto.dataVal.mes, novoProduto.dataVal.ano, novoProduto.qtdEstoq);
        printf ("\n\nIdentificação: \n");
        scanf (" %d", &novoProduto.idenProd);
        printf ("Setor do produto: \n");
        scanf (" %[^\n]s", novoProduto.setor);
        printf ("Nome: \n");
        scanf (" %[^\n]s", novoProduto.nome);
        printf ("Preço: \n");
        scanf (" %lf", &novoProduto.preco);
        printf ("Data de válidade: \n");
        printf ("Dia: \n");
        scanf (" %d", &novoProduto.dataVal.dia);
        printf ("Mês: \n");
        scanf (" %d", &novoProduto.dataVal.mes);
        printf ("Ano: \n");
        scanf (" %d", &novoProduto.dataVal.ano);
        printf ("Quantidade no estoque: \n");
        scanf (" %d", &novoProduto.qtdEstoq);
        fseek (arq, sizeof(TProduto)*(iden-1), SEEK_SET);
        fwrite (&novoProduto, sizeof(TProduto), 1, arq);
        fflush (arq);
        fclose (arq);
        printf ("\n\nInformações do Produto Modificadas com Sucesso! \n");
    }
    else
    {
        printf ("Erro na Abertura do Arquivo! \n");
    }
}
