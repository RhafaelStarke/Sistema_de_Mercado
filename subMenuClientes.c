#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void subMenuClientes()
{
    int subMenu2;

    do
    {
        system("cls");
        printf ("\n\n*************MENU CLIENTES*************\n");
        printf ("1. Cadastrar Novo Cliente \n");
        printf ("2. Atualizar Pontuação \n");
        printf ("3. Atualizar Cliente \n");
        printf ("4. Listar Clientes Entre 18 a 25 \n");
        printf ("5. Listar Clientes acima de 1000 pontos \n");
        printf ("9. Sair \n");
        printf ("***************************************\n");
        printf ("\nSelecione o número correspondente: ");
        scanf (" %d", &subMenu2);
        switch (subMenu2)
        {
            case 1:
                cadNovClien();
                break;
            case 2:
                atuaPontos();
                break;
            case 3:
                atualClien();
                break;
            case 4:
                listar18a25();
                break;
            case 5:
                listar1000();
                break;
            case 9:
                return;
            default:
                system("cls");
                printf ("COMANDO INVÁLIDO! \n");
                system("pause");
                break;
        }
    } while (1);
}