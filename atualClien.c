//
// Created by rh4f4 on 27/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "registros.h"

void atualClien()
{
    FILE *arq;

    system("cls");
    printf("ATUALIZAÇÃO DE DADOS DO CLIENTE: \n");
    arq = fopen("../Clientes.dat", "r+wb");
    if (arq != NULL)
    {
        char cpf;
        int flag = 0;
        TCliente cliente;

        //Usuário entra com o CPF do cliente que terá suas informações modificadas.
        printf("Entre com o CPF do cliente que quer modificar as informações: \n");
        scanf(" %[^\n]s", cpf);

        //Procurar CPF compatível.
        do
        {
            fseek(arq, sizeof(TCliente) * flag, SEEK_SET);
            fread(&cliente, sizeof(TCliente), 1, arq);
            if (strcmp(cpf, cliente.cpf) == 0)
            {
                char edit = 'n';
                do
                {
                    //Mostrar, caso encontre, o cliente que terá seus dados atualizados.
                    system("cls");
                    printf("CPF encontrado! \n");
                    printf("CPF: %s \n", cliente.cpf);
                    printf("Nome: %s \n", cliente.nomeClien);
                    printf("Data de nascimento: %d/%d/%d \n", cliente.nasc.dia, cliente.nasc.mes, cliente.nasc.ano);
                    printf("Idade: %d \n", cliente.idade);
                    printf("Endereço: %s \n", cliente.end);
                    printf("Cidade: %s \n", cliente.cid);
                    printf("Estado: %s \n", cliente.est);
                    printf("Pontos: %d \n", cliente.pontos);
                    printf("QUER MESMO EDITAR INFORMAÇÕES DESTE CLIENTE [S/N]? ");
                    scanf(" %c", &edit);
                    if ((edit == 's') || (edit == 'S'))
                    {
                        //Atualização de dados do cliente.
                        system("cls");
                        printf("\n\nATUALIZAÇÃO DOS DADOS DO CLIENTE %s \n", cliente.nomeClien);
                        printf("CPF: ");
                        scanf(" %[^\n]s", cliente.cpf);
                        printf("Nome: ");
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
                        printf("Pontos: ");
                        scanf(" %d", &cliente.pontos);
                        fseek(arq, sizeof(TCliente) * flag, SEEK_SET);
                        fwrite(&cliente, sizeof(TCliente), 1, arq);
                        fflush(arq);
                        system("cls");
                        printf("DADOS DO CLIENTE ATUALIZADO COM SUCESSO! \n");
                        system("pause");
                        return;
                    }
                } while ((edit == 'n') || (edit == 'N'));
            }
            flag += 1;
        }while(feof(arq) == true);
    }
    else
    {
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}