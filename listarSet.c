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
            case 1:
                listarHigiene();
                break;
            case 2:
                listarBebs();
                break;
            case 3:
                listarFrios();
                break;
            case 4:
                listarPad();
                break;
            case 5:
                listarAco();
                break;
            case 9:
                return;
            default:
                system("cls");
                printf("COMANDO INVÁLIDO! \n");
                system("pause");
                break;
        }
    } while (1);
}