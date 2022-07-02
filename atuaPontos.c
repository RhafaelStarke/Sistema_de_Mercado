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
    arq = fopen("../Clientes.dat", "rb");
    if(arq != NULL)
    {
        char cpf;

        printf("Entre com o CPF do cliente que quer alterar os pontos: ");
        scanf(" %[^\n]s", cpf);
        do{

        } while(feof(arq)==false);
    }
    else
    {
        system("cls");
        printf("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
        atuaPontos();
    }
}
