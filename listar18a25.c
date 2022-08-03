//
// Created by rh4f4 on 02/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "registros.h"
#include "funcoes.h"

void listar18a25(){
    FILE *arq;
    TCliente listCliente;
    bool flag=false;

    system("cls");
    printf("\n\nCLIENTES COM IDADE ENTRE 18 A 25 ANOS: \n");
    arq = fopen("../Clientes.dat", "rb");
    if(arq!=NULL){
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&listCliente, sizeof(TCliente), 1, arq)){
            if((listCliente.idade>=18)&&(listCliente.idade<=25)) {

                //LISTAGEM DE CLIENTES COM A IDADE ENTRE 18 E 25
                flag=true;
                printf("CPF: %s; Nome: %s; Nascimento: %d/%d/%d; Idade: %d; End: %s; Cidade: %s; Estado: %s; Pontos: %d \n\n",
                       listCliente.cpf, listCliente.nomeClien, listCliente.nasc.dia, listCliente.nasc.mes,
                       listCliente.nasc.ano, listCliente.idade, listCliente.end, listCliente.cid, listCliente.est,
                       listCliente.pontos);
            }
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        if (flag==false){
            printf("\n\nNenhum cliente com idade entre 18 a 25 anos! \n\n");
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