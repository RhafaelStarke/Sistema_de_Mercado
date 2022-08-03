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

    TCliente cliente;
    TVenda venda;
    char cpf[13];
    int cad;
    FILE *arqCliente;
    FILE *arqVenda;

    //ENTRADA DO CPF DO CLIENTE
    system("cls");
    printf("\nBUSCAR COMPRAS DE CLIENTE: \n\n");
    printf("CPF: ");
    scanf(" %[^\n]s", cpf);
    system("cls");
    cad = 0;
    arqCliente = fopen("../Clientes.dat", "rb");

    //VERIFICAÇÃO SE O CLIENTE É CADASTRADO
    if(arqCliente){
        while(fread(&cliente, sizeof(TCliente), 1, arqCliente)){
            if(strcmp(cpf, cliente.cpf) == 0){
                cad = 1;
            }
        }
        fclose(arqCliente);
    }

    //SE SIM, PROCURA AS VENDAS
    if(cad == 1){
        arqVenda = fopen("../Vendas.dat", "rb");

        if(arqVenda) {
            printf("\nCOMPRAS DO CLIENTE:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            while (fread(&venda, sizeof(TVenda), 1, arqVenda)) {
                if (strcmp(cpf, venda.cpf) == 0) {
                    printf("%d/%d/%d\tR$ %.2f\t%d produtos\n\n", venda.dataCompr.dia, venda.dataCompr.mes,
                           venda.dataCompr.ano, venda.valorTot, venda.qtdProd);
                }
            }
            printf("----------------------------------------------------------------------------------------------------------\n\n\n");
            system("pause");
            fclose(arqVenda);
        }else{
            system("cls");
            printf("\nNENHUMA COMPRA FOI ENCONTRADA!\n\n");
            system("pause");
        }
    }else{
        system("cls");
        printf("\nCLIENTE NÃO ENCONTRADO!\n\n");
        system("pause");
    }

}