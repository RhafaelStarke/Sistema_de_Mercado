//
// Created by rh4f4 on 27/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "registros.h"
#include "funcoes.h"

void atualClien()
{
    FILE *arq;

    system("cls");
    printf("ATUALIZAÇÃO DE DADOS DO CLIENTE: \n");
    arq = fopen("../Clientes.dat", "r+b");
    if (arq != NULL)
    {
        char cpf[13];
        int flag = 0;
        TCliente cliente;
        bool flag2 = false;
        time_t dataSist;
        dataSist = time(NULL);
        struct tm tm = *localtime(&dataSist);

        //USUÁRIO ENTRA COM O CPF QUE TERÁ SEUS DADOS EDITADOS
        printf("Entre com o CPF do cliente que quer modificar as informações: \n");
        scanf(" %[^\n]s", cpf);
        do
        {
            //PROCURAR CPF COMPATÍVEL
            fseek(arq, sizeof(TCliente) * flag, SEEK_SET);
            fread(&cliente, sizeof(TCliente), 1, arq);
            if (strcmp(cpf, cliente.cpf) == 0){
                flag2 = true;
                char edit = 'n';

                //MOSTRAR, CASO ENCONTRE, O CLIENTE QUE TERÁ SEUS DADOS ATUALIZADOS
                system("cls");
                printf("CPF encontrado! \n");
                printf("CPF: %s \n", cliente.cpf);
                printf("Nome: %s \n", cliente.nomeClien);
                printf("Data de nascimento: %d/%d/%d \n", cliente.nasc.dia, cliente.nasc.mes, cliente.nasc.ano);
                printf("Idade: %d Anos \n", cliente.idade);
                printf("Endereço: %s \n", cliente.end);
                printf("Cidade: %s \n", cliente.cid);
                printf("Estado: %s \n", cliente.est);
                printf("Pontos: %d \n", cliente.pontos);
                do {
                    printf("QUER MESMO EDITAR INFORMAÇÕES DESTE CLIENTE [S/N]? ");
                    scanf(" %c", &edit);
                    if ((edit == 's') || (edit == 'S')) {

                        //ATUALIZAÇÃO DOS DADOS DO CLIENTE
                        system("cls");
                        printf("\n\nATUALIZAÇÃO DOS DADOS DO CLIENTE: %s \n", cliente.nomeClien);
                        printf("CPF: ");
                        scanf(" %[^\n]s", cliente.cpf);
                        printf("Nome: ");
                        scanf(" %[^\n]s", cliente.nomeClien);
                        do {
                            printf("Data de nascimento (dd/mm/aaaa): ");
                            scanf(" %d/%d/%d", &cliente.nasc.dia, &cliente.nasc.mes, &cliente.nasc.ano);
                            if ((cliente.nasc.dia < 0) || (cliente.nasc.dia > 31)) {
                                printf("DIGITE UM DIA VÁLIDO! \n");
                            } else if ((cliente.nasc.mes < 0) || (cliente.nasc.mes > 12)) {
                                printf("DIGITE UM MÊS VÁLIDO! \n");
                            } else if ((cliente.nasc.ano < 0)) {
                                printf("DIGITE UM ANO VÁLIDO! \n");
                            }
                        } while ((cliente.nasc.dia < 0) || (cliente.nasc.dia > 31) || (cliente.nasc.mes < 0) ||
                                 (cliente.nasc.mes > 12) || (cliente.nasc.ano < 0));
                        if ((cliente.nasc.dia <= tm.tm_mday) || (cliente.nasc.mes <= (tm.tm_mon + 1))) {
                            cliente.idade = (tm.tm_year + 1900) - cliente.nasc.ano;
                        } else {
                            cliente.idade = ((tm.tm_year + 1900) - cliente.nasc.ano) - 1;
                        }
                        printf("Idade: %d Anos \n", cliente.idade);
                        printf("Endereço: ");
                        scanf(" %[^\n]s", cliente.end);
                        printf("Cidade: ");
                        scanf(" %[^\n]s", cliente.cid);
                        printf("Estado (EE): ");
                        scanf(" %[^\n]s", cliente.est);

                        //GRAVANDO OS DADOS ATUALIZADOS NO ARQUIVO
                        fseek(arq, sizeof(TCliente) * flag, SEEK_SET);
                        fwrite(&cliente, sizeof(TCliente), 1, arq);
                        fflush(arq);
                        system("cls");
                        printf("DADOS DO CLIENTE ATUALIZADO COM SUCESSO! \n");
                        system("pause");
                        fclose(arq);
                        return;
                    } else if ((edit == 'n') || (edit == 'N')) {
                        fclose(arq);
                        return;
                    } else {
                        printf("COMANDO INVÁLIDO! \n");
                    }
                } while(1);
            }
            flag += 1;
        }while(feof(arq) == false);
        fclose(arq);

        //CASO NÃO ENCONTRE NENHUM CPF, PODE SER REDIRECIONADO PARA A FUNÇÃO QUE CADASTRA CLIENTES
        if (flag2 == false)
        {
            char cad;
            system("cls");
            printf ("NENHUM CPF ENCONTRADO! \n");
            do {
                printf("Deseja cadastrar um novo cliente [S/N]? ");
                scanf(" %c", &cad);
                if ((cad == 's') || (cad == 'S')) {
                    cadNovClien();
                    return;
                } else if ((cad == 'n') || (cad == 'N')) {
                    return;
                } else {
                    printf("Comando inválido! \n");
                }
            } while (1);
        }
    }
    else
    {
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}