//
// Created by rh4f4 on 27/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"

void cadNovClien()
{
    FILE *arq;
    TCliente cliente;
    int qtdCadClien;

    system("cls");
    printf("\n\nCADASTRO DE NOVO CLIENTE: \n");
    arq = fopen ("../Clientes.dat", "ab+");
    if (arq != NULL)
    {
        printf("Quantos clientes quer cadastrar? ");
        scanf(" %d", &qtdCadClien);
        for (int i = 0; i < qtdCadClien; i++)
        {
            //Coleta de informações do cliente.
            system("cls");
            printf("\n\nCPF: ");
            scanf(" %[^\n]s", cliente.cpf);
            printf("Nome completo: ");
            scanf(" %[^\n]s", cliente.nomeClien);
            printf("Data de nascimento (dd/mm/aaaa): ");
            scanf(" %d/%d/%d", &cliente.nasc.dia, &cliente.nasc.mes, &cliente.nasc.ano);
            printf("Idade: ");
            scanf(" %d", &cliente.idade);
            printf("Endereço: ");
            scanf(" %[^\n]s", cliente.end);
            printf("Cidade: ");
            scanf(" %[^\n]s", cliente.cid);
            printf("Estado (EE): ");
            scanf(" %[^\n]s", cliente.est);
            cliente.pontos = 0;

            //Escrever as informações do cliente no arquivo.
            fwrite(&cliente, sizeof(TCliente), 1, arq);
            fflush(arq);

            system("cls");
            printf("CLIENTE CADASTRADO COM SUCESSO! \n");
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}