//
// Created by rh4f4 on 02/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"

void listarFrios(){
    FILE *arq;
    TProduto produtos;

    system("cls");
    printf("LISTA DE ESTOQUE DO SETOR DE FRIOS: \n\n");
    arq = fopen("../Produtos.dat", "rb");
    if(arq!=NULL){
        char setor[20]="Frios";
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            if(strcmp(setor, produtos.setor)==0) {

                //LISTAGEM DE ESTOQUE DO SETOR DE FRIOS
                printf("Identificação: %d; \tNome: %s; \tPreço: R$ %.2lf; \tVencimento: %d/%d/%d; \tEstoque: %d; \n", produtos.idenProd, produtos.nome, produtos.preco, produtos.dataVal.dia, produtos.dataVal.mes, produtos.dataVal.ano, produtos.qtdEstoq);
            }
        }
        system("pause");
        fclose(arq);
    }
    else{
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}