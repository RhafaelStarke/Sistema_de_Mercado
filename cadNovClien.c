//
// Created by rh4f4 on 27/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "registros.h"
#include "funcoes.h"
#include <stdbool.h>

void cadNovClien()
{
    FILE *arq;

    arq = fopen ("../Clientes.dat", "ab+");
    if (arq != NULL)
    {
        TCliente cliente, comp;
        char cad;
        int cod;
        time_t dataSist;
        dataSist = time(NULL);
        struct tm tm = *localtime(&dataSist);
        int flag = 0;

        while (fread(&cliente, sizeof(TCliente), 1, arq)){
            cod+=1;
        }

        do
        {
            //COLETA DE INFORMAÇÕES DO CLIENTE
            system("cls");
            printf("\n\nCADASTRO DE NOVO CLIENTE: \n");
            cliente.cod=cod;
            printf("\nCPF: ");
            scanf(" %[^\n]s", cliente.cpf);

            //VERIFICA SE O CLIENTE JÁ ESTÁ CADASTRADO
            do{
                fseek(arq, sizeof(TCliente)*flag, SEEK_SET);
                fread(&comp, sizeof(TCliente), 1, arq);
                if(strcmp(cliente.cpf, comp.cpf) == 0){
                    printf("\nCLIENTE JÁ CADASTRADO!\n\n");
                    system("pause");
                    return;
                }
                flag+=1;
            }while(feof(arq)==false);

            printf("Nome completo: ");
            scanf(" %[^\n]s", cliente.nomeClien);
            do
            {
                printf("Data de nascimento (dd/mm/aaaa): ");
                scanf(" %d/%d/%d", &cliente.nasc.dia, &cliente.nasc.mes, &cliente.nasc.ano);
                if ((cliente.nasc.dia < 0)||(cliente.nasc.dia > 31))
                {
                    printf("\nDIA INVÁLIDO!\n\n");
                }
                else if ((cliente.nasc.mes < 0)||(cliente.nasc.mes > 12))
                {
                    printf("\nMÊS INVÁLIDO!\n\n");
                }
                else if ((cliente.nasc.ano < 0))
                {
                    printf("\nANO INVÁLIDO!\n\n");
                }
            }while((cliente.nasc.dia < 0)||(cliente.nasc.dia > 31)||(cliente.nasc.mes < 0)||(cliente.nasc.mes > 12)||
                (cliente.nasc.ano < 0));

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

            //GRAVANDO AS INFORMAÇÕES DO CLIENTE NO ARQUIVO
            fwrite(&cliente, sizeof(TCliente), 1, arq);
            fflush(arq);

            system("cls");
            printf("\nCLIENTE CADASTRADO COM SUCESSO!\n\n");
            do {
                printf("Quer cadastrar outro cliente? [S]im / [N]ão\n");
                scanf(" %c", &cad);
                if((cad != 's')&&(cad != 'S')&&(cad != 'n')&&(cad != 'N')){
                    printf("\nCOMANDO INVÁLIDO\n\n");
                }
            }while((cad != 's')&&(cad != 'S')&&(cad != 'n')&&(cad != 'N'));
            cod+=1;
        }while((cad == 's')||(cad == 'S'));
        fclose(arq);
    }
    else
    {
        system("cls");
        printf("\nERRO NA ABERTURA DO ARQUIVO!\n\n");
        system("pause");
    }
}