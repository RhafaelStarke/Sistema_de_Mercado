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

        system("cls");
        printf("\nCLIENTES:");
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            while (fread(&cliente, sizeof(TCliente), 1, arq)){
                printf("CPF: %s; Nome: %s; Nascimento: %d/%d/%d; Idade: %d anos; End: %s; Cidade: %s; Estado: %s; Pontos: %d \n\n",
                       cliente.cpf, cliente.nomeClien, cliente.nasc.dia, cliente.nasc.mes,
                       cliente.nasc.ano, cliente.idade, cliente.end, cliente.cid, cliente.est,
                       cliente.pontos);
            }
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        printf("\n\nATUALIZAÇÃO DE DADOS DO CLIENTE: \n");
        printf("\n\nEntre com o CPF do cliente que quer modificar as informações: ");
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
                printf("\n\nCPF ENCONTRADO! \n");
                printf("\nCPF: %s \n", cliente.cpf);
                printf("Nome: %s \n", cliente.nomeClien);
                printf("Data de nascimento: %d/%d/%d \n", cliente.nasc.dia, cliente.nasc.mes, cliente.nasc.ano);
                printf("Idade: %d Anos \n", cliente.idade);
                printf("Endereço: %s \n", cliente.end);
                printf("Cidade: %s \n", cliente.cid);
                printf("Estado: %s \n", cliente.est);
                printf("Pontos: %d \n", cliente.pontos);
                do {
                    printf("\nQUER MESMO EDITAR INFORMAÇÕES DESTE CLIENTE? [S]im / [N]ão\n");
                    scanf(" %c", &edit);
                    if ((edit == 's') || (edit == 'S')) {

                        //ATUALIZAÇÃO DOS DADOS DO CLIENTE
                        system("cls");
                        printf("\n\nATUALIZAÇÃO DOS DADOS DO CLIENTE: %s \n", cliente.nomeClien);
                        printf("\nCPF: ");
                        scanf(" %[^\n]s", cliente.cpf);
                        printf("Nome: ");
                        scanf(" %[^\n]s", cliente.nomeClien);
                        do {
                            printf("Data de nascimento (dd/mm/aaaa): ");
                            scanf(" %d/%d/%d", &cliente.nasc.dia, &cliente.nasc.mes, &cliente.nasc.ano);
                            if ((cliente.nasc.dia < 0) || (cliente.nasc.dia > 31)) {
                                printf("\nDIA INVÁLIDO!\n\n");
                            } else if ((cliente.nasc.mes < 0) || (cliente.nasc.mes > 12)) {
                                printf("\nMÊS INVÁLIDO!\n\n");
                            } else if ((cliente.nasc.ano < 0)) {
                                printf("\nANO INVÁLIDO!\n\n");
                            }
                        } while ((cliente.nasc.dia <= 0) || (cliente.nasc.dia > 31) || (cliente.nasc.mes <= 0) ||
                                 (cliente.nasc.mes > 12) || (cliente.nasc.ano <= 0));
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
                        printf("\nDADOS DO CLIENTE ATUALIZADO COM SUCESSO! \n\n");
                        system("pause");
                        fclose(arq);
                        return;
                    } else if ((edit == 'n') || (edit == 'N')) {
                        fclose(arq);
                        return;
                    } else {
                        printf("\nCOMANDO INVÁLIDO! \n");
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
            printf ("\nNENHUM CPF ENCONTRADO!\n\n");
            do {
                printf("Deseja cadastrar um novo cliente? [S]im / [N]ão\n");
                scanf(" %c", &cad);
                if ((cad == 's') || (cad == 'S')) {
                    cadNovClien();
                    return;
                } else if ((cad == 'n') || (cad == 'N')) {
                    return;
                } else {
                    printf("\nCOMANDO INVÁLIDO!\n\n");
                }
            } while (1);
        }
    }
    else
    {
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        printf("\n");
        system("pause");
    }
}