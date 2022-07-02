//
// Created by rh4f4 on 27/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "registros.h"
#include "funcoes.h"

void cadNovClien()
{
    FILE *arq;

    arq = fopen ("../Clientes.dat", "ab+");
    if (arq != NULL)
    {
        TCliente cliente;
        char cad;
        time_t dataSist;
        dataSist = time(NULL);
        struct tm tm = *localtime(&dataSist);
        do
        {
            //Coleta de informações do cliente.
            system("cls");
            printf("\n\nCADASTRO DE NOVO CLIENTE: \n");
            printf("CPF: ");
            scanf(" %[^\n]s", cliente.cpf);
            printf("Nome completo: ");
            scanf(" %[^\n]s", cliente.nomeClien);
            do
            {
                printf("Data de nascimento (dd/mm/aaaa): ");
                scanf(" %d/%d/%d", &cliente.nasc.dia, &cliente.nasc.mes, &cliente.nasc.ano);
                if ((cliente.nasc.dia < 0)||(cliente.nasc.dia > 31))
                {
                    printf("DIGITE UM DIA VÁLIDO! \n");
                }
                else if ((cliente.nasc.mes < 0)||(cliente.nasc.mes > 12))
                {
                    printf("DIGITE UM MÊS VÁLIDO! \n");
                }
                else if ((cliente.nasc.ano < 0))
                {
                    printf("DIGITE UM ANO VÁLIDO! \n");
                }
            }while((cliente.nasc.dia < 0)||(cliente.nasc.dia > 31)||(cliente.nasc.mes < 0)||(cliente.nasc.mes > 12)||(cliente.nasc.ano < 0));

            if ((cliente.nasc.dia <= tm.tm_mday)||(cliente.nasc.mes <= (tm.tm_mon+1)))
            {
                cliente.idade = (tm.tm_year+1900)-cliente.nasc.ano;
            }
            else
            {
                cliente.idade = ((tm.tm_year+1900)-cliente.nasc.ano)-1;
            }
            printf("Idade: %d Anos \n", cliente.idade);
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
            printf("Quer cadastrar outro cliente? [S/N] ");
            scanf(" %c", &cad);
        }while((cad == 's')||(cad == 'S'));
        fclose(arq);
    }
    else
    {
        system("cls");
        printf("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}