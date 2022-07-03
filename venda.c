//
// Created by rh4f4 on 03/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "registros.h"
#include "funcoes.h"

void venda(){
    FILE *arqProduto;
    FILE *arqCliente;
    char cpf[13];
    TCliente cliente;
    bool flag=false;

    //ENTRADA DO CPF DO CLIENTE
    system("cls");
    printf("REALIZAR NOVA VENDA: \n");
    printf("CPF do cliente: ");
    scanf(" %[^\n]s", cpf);
    arqCliente = fopen("../Clientes.dat", "rb");
    if (arqCliente!=NULL){
        while (fread(&cliente, sizeof(TCliente), 1, arqCliente)){

            //VERIFICAÇÃO SE O CLIENTE É CADASTRADO
            if (strcmp(cpf, cliente.cpf) == 0){
                flag=true;

                

                return;
            }
        }
        if(flag==false){

            //CASO NÃO SEJA, PODE SER REDIRECIONADO PARA A FUNÇÃO QUE CADASTRA
            char cad;
            system("cls");
            printf ("CPF NÃO ENCONTRADO! \n");
            printf("Deseja cadastrar o cliente? [S/N] ");
            scanf(" %c", &cad);
            if((cad=='s')||(cad=='S')){
                cadNovClien();
            }
        }
    }
    else{
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}