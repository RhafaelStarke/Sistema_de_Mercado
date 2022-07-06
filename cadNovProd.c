//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funcoes.h"
#include "registros.h"

void cadNovProd()
{
    char cad;
    int set;
    int cod=1;
    FILE *arq;
    TProduto produtos, prodLidos;

    arq = fopen ("../Produtos.dat", "ab+");
    if (arq != NULL)
    {
        while (fread(&produtos, sizeof(TProduto), 1, arq)){
            cod+=1;
        }

        do
        {
            //COLETA DE INFORMAÇÕES DO NOVO PRODUTO
            system("cls");
            printf ("\n\nCADASTRO DE NOVO PRODUTO: \n\n");
            produtos.idenProd=cod;
            printf("Setores:\n");
            printf("1. Higiene e Limpeza \n");
            printf("2. Bebidas \n");
            printf("3. Frios \n");
            printf("4. Padaria \n");
            printf("5. Açougue \n");
            do{
                printf("\nCadastrar novo produto no setor: ");
                scanf(" %d", &set);
                switch (set) {
                    case 1:
                        strcpy(produtos.setor, "Higiene e limpeza");
                        break;
                    case 2:
                        strcpy(produtos.setor, "Bebidas");
                        break;
                    case 3:
                        strcpy(produtos.setor, "Frios");
                        break;
                    case 4:
                        strcpy(produtos.setor, "Padaria");
                        break;
                    case 5:
                        strcpy(produtos.setor, "Acougue");
                        break;
                    default:
                        printf("COMANDO INVÁLIDO! \n");
                        break;
                }
            } while ((set<1)||(set>5));
            system("cls");
            printf("Nome: ");
            scanf(" %[^\n]s", produtos.nome);
            printf("Preço: ");
            scanf(" %lf", &produtos.preco);
            printf("Data de validade (dd/mm/aaaa): ");
            scanf(" %d/%d/%d", &produtos.dataVal.dia, &produtos.dataVal.mes, &produtos.dataVal.ano);
            do
            {
                printf("Quantidade no estoque: ");
                scanf(" %d", &produtos.qtdEstoq);
                if(produtos.qtdEstoq < 0)
                {
                    printf("DIGITE UMA QUANTIDADE POSITIVA! \n");
                }
            }while(produtos.qtdEstoq < 0);

            //GRAVANDO AS INFORMAÇÕES NO ARQUIVO
            fwrite(&produtos, sizeof(TProduto), 1, arq);
            fflush (arq);

            system("cls");
            printf("PRODUTO CADASTRADO COM SUCESSO! \n");
            printf("Quer cadastrar outro produto? [S/N] ");
            scanf(" %c", &cad);
            cod+=1;
        } while((cad == 's')||(cad == 'S'));
        fclose (arq);
    }
    else
    {
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}
