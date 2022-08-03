//
// Created by rh4f4 on 02/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"
#include <stdbool.h>
#include "funcoes.h"

void listar1000(){
    FILE *arq;
    TCliente listCliente;
    bool flag=false;

    system("cls");
    printf("\n\nLISTA DE CLIENTES COM PONTOS ACIMA DE 1000: \n");
    arq = fopen("../Clientes.dat", "rb");
    if(arq!=NULL){
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&listCliente, sizeof(TCliente), 1, arq)){
            if(listCliente.pontos>1000) {

                //LISTAGEM DE CLIENTES COM MAIS DE 1000 PONTOS
                flag=true;
                printf("CPF: %s; Nome: %s; Nascimento: %d/%d/%d; Idade: %d; End: %s; Cidade: %s; Estado: %s; Pontos: %d \n\n",
                       listCliente.cpf, listCliente.nomeClien, listCliente.nasc.dia, listCliente.nasc.mes,
                       listCliente.nasc.ano, listCliente.idade, listCliente.end, listCliente.cid, listCliente.est,
                       listCliente.pontos);
            }
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        if (flag==false){
            printf("\nNenhum cliente com pontuação maior que 1000! \n\n");
        }
        printf("\n");
        system("pause");
        fclose(arq);
    }
    else{
        system("cls");
        printf ("\n\nERRO NA ABERTURA DO ARQUIVO! \n\n");
        system("pause");
    }
}