//
// Created by rh4f4 on 30/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "subMenu.h"
#include "registros.h"
#include "funcoes.h"

void atuaPontos(){
    FILE *arq;

    system("cls");
    printf("ATUALIZAR PONTUAÇÃO DO CLIENTE: \n");
    arq = fopen("../Clientes.dat", "r+b");
    if(arq != NULL)
    {
        int flag=0;
        bool flag2=false;
        char cpf[13];
        char edit;
        TCliente cliente;

        //USUÁRIO ENTRA COM O CPF QUE TERÁ SEUS PONTOS EDITADOS
        printf("Entre com o CPF do cliente que quer alterar os pontos: ");
        scanf(" %[^\n]s", cpf);
        do{
            //PROCURAR CPF COMPATÍVEL
            fseek(arq, sizeof(TCliente)*flag, SEEK_SET);
            fread(&cliente, sizeof(TCliente), 1, arq);
            if(strcmp(cpf, cliente.cpf) == 0){
                flag2=true;

                //MOSTRAR, CASO ENCONTRE, OS DADOS DO CLIENTE QUE TERÁ SEUS PONTOS EDITADOS
                system("cls");
                printf("CPF encontrado! \n");
                printf("CPF: %s \n", cliente.cpf);
                printf("Nome: %s \n", cliente.nomeClien);
                printf("Pontos: %d \n", cliente.pontos);
                do {
                    printf("QUER MESMO EDITAR OS PONTOS DESTE CLIENTE [S/N]? ");
                    scanf(" %c", &edit);
                    if ((edit == 's') || (edit == 'S')) {

                        //ATUALIZAÇÃO DOS PONTOS DO CLIENTE
                        system("cls");
                        printf("\n\nATUALIZANDO PONTOS DO CLIENTE: %s \n", cliente.nomeClien);
                        printf("Pontos: ");
                        scanf(" %d", &cliente.pontos);

                        //GRAVANDO OS DADOS ATUALIZADO NO ARQUIVO
                        fseek(arq, sizeof(TCliente) * flag, SEEK_SET);
                        fwrite(&cliente, sizeof(TCliente), 1, arq);
                        fflush(arq);
                        system("cls");
                        printf("PONTOS DO CLIENTE ATUALIZADO COM SUCESSO! \n");
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
            flag+=1;
        } while(feof(arq)==false);
        fclose(arq);

        //CASO NÃO ENCONTRE NENHUM CPF, PODE SER REDIRECIONADO PARA A FUNÇÃO QUE CADASTRA CLIENTE
        if (flag2==false)
        {
            char cad;
            system("cls");
            printf ("NENHUM CPF ENCONTRADO! \n");
            printf ("Deseja cadastrar um novo cliente [S/N]? ");
            scanf(" %c", &cad);
            if ((cad=='s')||(cad=='S'))
            {
                cadNovClien();
            }
        }
    }
    else
    {
        system("cls");
        printf("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
        atuaPontos();
    }
}
