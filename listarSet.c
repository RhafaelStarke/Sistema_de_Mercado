//
// Created by rh4f4 on 02/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "funcoesListaSet.h"
#include "funcoes.h"

void listarSet(){
    int estoq;
    do {

        //MENU PARA ESCOLHA DE LISTA POR ESTOQUE
        system("cls");
        printf("\n\n**********ESTOQUES**********\n");
        printf("1. Higiene e Limpeza \n");
        printf("2. Bebidas \n");
        printf("3. Frios \n");
        printf("4. Padaria \n");
        printf("5. Açougue \n");
        printf("9. Sair\n");
        printf("****************************\n");
        printf("\nSelecione o número correspondente: ");
        scanf(" %d", &estoq);

        switch (estoq) {
            case 1: //CHAMA A FUNÇÃO PARA LISTAR O ESTOQUE DE HIGIENE E LIMPEZA
                listarHigiene();
                break;
            case 2: //CHAMA A FUNÇÃO PARA LISTAR O ESTOQUE DE BEBIDAS
                listarBebs();
                break;
            case 3: //CHAMA A FUNÇÃO PARA LISTAR O ESTOQUE DE FRIOS
                listarFrios();
                break;
            case 4: //CHAMA A FUNÇÃO PARA LISTAR O ESTOQUE DE PADARIA
                listarPad();
                break;
            case 5: //CHAMA A FUNÇÃO PARA LISTAR O ESTOQUE DE AÇOUGUE
                listarAco();
                break;
            case 9: //VOLTA PARA O SUBMENU DE PRODUTOS
                return;
            default: //OPÇÃO CASO ENTRE COM O VALOR DESCONHECIDO
                system("cls");
                printf("COMANDO INVÁLIDO! \n");
                system("pause");
                break;
        }
    } while (1);
}