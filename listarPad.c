//
// Created by rh4f4 on 02/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"

void listarPad(){
    FILE *arq;
    TProduto produtos;

    system("cls");
    printf("LISTA DE ESTOQUE DO SETOR PADARIA: \n\n");
    arq = fopen("../Produtos.dat", "rb");
    if(arq!=NULL){
        char setor[20]="Padaria";
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            if(strcmp(setor, produtos.setor)==0) {

                //LISTAGEM DE ESTOQUE DO SETOR DE PADARIA
                printf("Identificação: %d; Nome: %s; Preço: R$ %.2lf; Vencimento: %d/%d/%d; Estoque: %d; \n", produtos.idenProd, produtos.nome, produtos.preco, produtos.dataVal.dia, produtos.dataVal.mes, produtos.dataVal.ano, produtos.qtdEstoq);
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