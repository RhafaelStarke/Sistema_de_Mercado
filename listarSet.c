//
// Created by rh4f4 on 02/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registros.h"
#include "funcoes.h"

void listarSet(){
    FILE *arq;
    TProduto produtos;

    system("cls");
    printf("LISTA DE ESTOQUE POR SETOR: \n\n");
    arq = fopen("../Produtos.dat", "rb");
    if (arq != NULL){
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            if(strcmp("Higiene e limpeza", produtos.setor)==0) {

                //LISTAGEM DE ESTOQUE DO SETOR DE HIGIENE E LIMPEZA
                printf("Identificação: %d; \tSetor: %s; \tNome: %s; \tPreço: R$ %.2lf; \tVencimento: %d/%d/%d; \tEstoque: %d; \n",
                       produtos.idenProd, produtos.setor, produtos.nome, produtos.preco, produtos.dataVal.dia, produtos.dataVal.mes,
                       produtos.dataVal.ano, produtos.qtdEstoq);
            }
        }
        rewind(arq);
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            if(strcmp("Bebidas", produtos.setor)==0) {

                //LISTAGEM DE ESTOQUE DO SETOR DE BEBIDAS
                printf("Identificação: %d; \tSetor: %s; \tNome: %s; \tPreço: R$ %.2lf; \tVencimento: %d/%d/%d; \tEstoque: %d; \n",
                       produtos.idenProd, produtos.setor, produtos.nome, produtos.preco, produtos.dataVal.dia, produtos.dataVal.mes,
                       produtos.dataVal.ano, produtos.qtdEstoq);
            }
        }
        rewind(arq);
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            if(strcmp("Frios", produtos.setor)==0) {

                //LISTAGEM DE ESTOQUE DO SETOR DE FRIOS
                printf("Identificação: %d; \tSetor: %s; \tNome: %s; \tPreço: R$ %.2lf; \tVencimento: %d/%d/%d; \tEstoque: %d; \n",
                       produtos.idenProd, produtos.setor, produtos.nome, produtos.preco, produtos.dataVal.dia, produtos.dataVal.mes,
                       produtos.dataVal.ano, produtos.qtdEstoq);
            }
        }
        rewind(arq);
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            if(strcmp("Padaria", produtos.setor)==0) {

                //LISTAGEM DE ESTOQUE DO SETOR PADARIA
                printf("Identificação: %d; \tSetor: %s; \tNome: %s; \tPreço: R$ %.2lf; \tVencimento: %d/%d/%d; \tEstoque: %d; \n",
                       produtos.idenProd, produtos.setor, produtos.nome, produtos.preco, produtos.dataVal.dia, produtos.dataVal.mes,
                       produtos.dataVal.ano, produtos.qtdEstoq);
            }
        }
        rewind(arq);
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            if(strcmp("Acougue", produtos.setor)==0) {

                //LISTAGEM DE ESTOQUE DO SETOR AÇOUGUE
                printf("Identificação: %d; \tSetor: %s; \tNome: %s; \tPreço: R$ %.2lf; \tVencimento: %d/%d/%d; \tEstoque: %d; \n",
                       produtos.idenProd, produtos.setor, produtos.nome, produtos.preco, produtos.dataVal.dia, produtos.dataVal.mes,
                       produtos.dataVal.ano, produtos.qtdEstoq);
            }
        }
        system("pause");
        fclose(arq);
    }else{
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}