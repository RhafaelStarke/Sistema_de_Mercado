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
    printf("LISTA DE CLIENTES COM IDADE ENTRE 18 A 25 ANOS: \n\n");
    arq = fopen("../Clientes.dat", "rb");
    if(arq!=NULL){
        while (fread(&listCliente, sizeof(TCliente), 1, arq)){
            if((listCliente.idade>=18)&&(listCliente.idade<=25)) {

                //LISTAGEM DE CLIENTES COM A IDADE ENTRE 18 E 25
                flag=true;
                printf("CPF: %s; Nome: %s; Nascimento: %d/%d/%d; Idade: %d; End: %s; Cidade: %s; Estado: %s; Pontos: %d \n",
                       listCliente.cpf, listCliente.nomeClien, listCliente.nasc.dia, listCliente.nasc.mes,
                       listCliente.nasc.ano, listCliente.idade, listCliente.end, listCliente.cid, listCliente.est,
                       listCliente.pontos);
            }
        }
        if (flag==false){
            printf("Nenhum cliente com idade entre 18 a 25 anos! \n\n");
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