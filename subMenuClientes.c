#include <stdio.h>
#include "Estruturas.h"
#include <stdlib.h>
#include <windows.h>

void subMenuClientes()
{
    int subMenu2;
    TCliente clientes;

    do
    {
        system("cls");
        printf ("\n\n*************MENU CLIENTES*************\n");
        printf ("1. Cadastrar de Novo Cliente \n");
        printf ("2. Atualizar Pontuação \n");
        printf ("3. Atualizar Cliente \n");
        printf ("4. Listar Clientes Entre 18 a 25 \n");
        printf ("5. Listar Clientes acima de 200 pontos \n");
        printf ("9. Sair \n");
        printf ("***************************************\n");
        printf ("\nSelecione o número correspondente: ");
        scanf (" %d", &subMenu2);
        switch (subMenu2)
        {
            case 1:
                system("cls");
                printf ("\n\nCadastro de Novo Cliente: \n");

                system("pause");
                break;
            case 2:
                system("cls");
                printf ("\n\nAtualização de Pontos: \n");

                system( "pause");
                break;
            case 3:
                system("cls");
                printf ("\n\nAtualização de Dados dos Cliente: \n");

                system("pause");
                break;
            case 4:
                system("cls");
                printf ("\n\nLista de Clientes Entre 18 a 25 Anos: \n");

                system("pause");
                break;
            case 5:
                system("cls");
                printf ("\n\nLista de Clientes Acima de 200 Pontos: \n");

                system("pause");
                break;
            case 9:
                system("cls");
                printf("Voltando para o menu principal... \n");
                system("pause");
                return;
            default:
                system("cls");
                printf ("Comando Inválido! \n");
                system("pause");
                break;
        }
    } while (1);
}