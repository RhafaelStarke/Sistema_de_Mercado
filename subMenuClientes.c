#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void subMenuClientes()
{
    int subMenu2;

    do
    {
        system("cls");
        printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t*************MENU CLIENTES*************\n");
        printf ("\n\t\t\t\t\t\t\t\t\t1. Cadastrar Novo Cliente \n");
        printf ("\t\t\t\t\t\t\t\t\t2. Atualizar Pontuação \n");
        printf ("\t\t\t\t\t\t\t\t\t3. Atualizar Cliente \n");
        printf ("\t\t\t\t\t\t\t\t\t4. Listar Clientes Entre 18 a 25 \n");
        printf ("\t\t\t\t\t\t\t\t\t5. Listar Clientes acima de 1000 pontos \n");
        printf ("\t\t\t\t\t\t\t\t\t9. Sair \n");
        printf ("\n\t\t\t\t\t\t\t\t\t***************************************\n");
        printf ("\n\t\t\t\t\t\t\t\t\tSelecione o número correspondente: ");
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
                printf("\n");
                system("pause");
                break;
        }
    } while (1);
}