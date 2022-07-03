//
// Created by rh4f4 on 03/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "registros.h"
#include "funcoes.h"

void listarVendas(){
    FILE *arqCliente;
    FILE *arqVendas;
    TVenda vendas;
    TCliente cliente;
    bool flag=false;

    system("cls");
    printf("\n\nLISTA DE COMPRAS DO CLIENTE: \n\n");
    printf("Entre com o CPF do cliente: ");
    scanf(" %[^\n]s", cliente.cpf);

    arqCliente = fopen("../Clientes.dat", "rb");
    if(arqCliente!=NULL){
        arqVendas = fopen("../Vendas.dat", "rb");
        if (arqVendas!=NULL){
            while (fread(&cliente, sizeof(TCliente), 1, arqCliente)){
                while (fread(&vendas, sizeof(TVenda), 1, arqVendas)){
                    if (strcmp(cliente.cpf, vendas.cpf)==0){
                        flag=true;
                        system("cls");
                        printf("COMPRA ENCONTRADA! \n");
                        printf("Data da compra: %d/%d/%d; Valor Total: %.2f; Qtd Total: %d \n", vendas.dataCompr.dia, vendas.dataCompr.mes, vendas.dataCompr.ano, vendas.valorTot, vendas.qtdProd);
                    }
                }
            }
            if (flag==false){
                system("cls");
                printf("NENHUMA COMPRA NESSE CPF FOI ENCONTRADA! \n");
            }
            system("pause");
            fclose(arqVendas);
            fclose(arqCliente);
        }
        else{
            system("cls");
            printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
            system("pause");
        }
    }
    else{
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}