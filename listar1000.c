//
// Created by rh4f4 on 02/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"
#include "funcoes.h"

void listar1000(){
    FILE *arq;
    TCliente listCliente;

    system("cls");
    printf("LISTA DE CLIENTES COM PONTOS ACIMA DE 1000: \n\n");
    arq = fopen("../Clientes.dat", "rb");
    if(arq!=NULL){
        while (fread(&listCliente, sizeof(TCliente), 1, arq)){
            if(listCliente.pontos>1000) {

                //LISTAGEM DE CLIENTES COM MAIS DE 1000 PONTOS
                printf("CPF: %s; Nome: %s; Nascimento: %d/%d/%d; Idade: %d; End: %s; Cidade: %s; Estado: %s; Pontos: %d \n",
                       listCliente.cpf, listCliente.nomeClien, listCliente.nasc.dia, listCliente.nasc.mes,
                       listCliente.nasc.ano, listCliente.idade, listCliente.end, listCliente.cid, listCliente.est,
                       listCliente.pontos);
            }
        }
        system("pause");
    }
    else{
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}