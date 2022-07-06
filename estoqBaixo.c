//
// Created by rh4f4 on 02/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "registros.h"

void estoqBaixo(){
    FILE *arq;
    TProduto produtos;
    bool flag=false;

    system("cls");
    printf("LISTA DE ESTOQUE BAIXO: \n\n");
    arq = fopen("../Produtos.dat", "rb");
    if(arq!=NULL){
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            if(produtos.qtdEstoq<5) {

                //LISTAGEM DE PRODUTOS COM ESTOQUE BAIXO
                flag=true;
                printf("Identificação: %d; \tSetor: %s; \tNome: %s; \tPreço: R$ %.2lf; \tVencimento: %d/%d/%d; \tEstoque: %d; \n", produtos.idenProd, produtos.setor, produtos.nome, produtos.preco, produtos.dataVal.dia, produtos.dataVal.mes, produtos.dataVal.ano, produtos.qtdEstoq);
            }
        }
        if(flag==false){
            printf("Nenhum produto com estoque baixo! \n\n");
        }
        printf("\n");
        system("pause");
        fclose(arq);
    }
    else{
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}