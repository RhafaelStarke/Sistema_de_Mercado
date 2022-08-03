//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funcoes.h"
#include "registros.h"
#include <time.h>

void cadNovProd()
{
    char cad;
    int set;
    int cod=1;
    FILE *arq;
    TProduto produtos, prodLidos;
    time_t dataSist;
    dataSist = time(NULL);
    struct tm tm = *localtime(&dataSist);

    arq = fopen ("../arquivos/Produtos.dat", "ab+");
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
                        printf("\nCOMANDO INVÁLIDO! \n");
                        break;
                }
            } while ((set<1)||(set>5));
            system("cls");
            printf("\n\nNome: ");
            scanf(" %[^\n]s", produtos.nome);
            do {
                printf("Preço: ");
                scanf(" %lf", &produtos.preco);
                if(produtos.preco < 0){
                    printf("\nPREÇO INVÁLIDO!\n\n");
                }
            }while(produtos.preco < 0);
            do
            {
                printf("Data de vencimento (dd/mm/aaaa): ");
                scanf(" %d/%d/%d", &produtos.dataVal.dia, &produtos.dataVal.mes, &produtos.dataVal.ano);
                if ((produtos.dataVal.dia <= 0)||(produtos.dataVal.dia > 31))
                {
                    printf("\nDIA INVÁLIDO!\n\n");
                }
                else if ((produtos.dataVal.mes < 0)||(produtos.dataVal.mes > 12))
                {
                    printf("\nMÊS INVÁLIDO!\n\n");
                }
                else if ((produtos.dataVal.ano < 0)||(produtos.dataVal.ano < (tm.tm_year+1900)))
                {
                    printf("\nANO INVÁLIDO!\n\n");
                }
            }while((produtos.dataVal.dia <= 0)||(produtos.dataVal.dia > 31)||(produtos.dataVal.mes <= 0)||(produtos.dataVal.mes > 12)
                ||(produtos.dataVal.ano <= 0)||(produtos.dataVal.ano < (tm.tm_year+1900)));
            do
            {
                printf("Quantidade no estoque: ");
                scanf(" %d", &produtos.qtdEstoq);
                if(produtos.qtdEstoq < 0)
                {
                    printf("\nESTOQUE INVÁLIDO!\n\n");
                }
            }while(produtos.qtdEstoq < 0);

            //GRAVANDO AS INFORMAÇÕES NO ARQUIVO
            fwrite(&produtos, sizeof(TProduto), 1, arq);
            fflush (arq);

            system("cls");
            printf("\nPRODUTO CADASTRADO COM SUCESSO! \n\n");
            do {
                printf("Quer cadastrar outro produto? [S]im / [N]ão\n");
                scanf(" %c", &cad);
                if((cad != 's')&&(cad != 'S')&&(cad != 'n')&&(cad != 'N')){
                    printf("\nCOMANDO INVÁLIDO!\n\n");
                }
            }while((cad != 's')&&(cad != 'S')&&(cad != 'n')&&(cad != 'N'));
            cod+=1;
        } while((cad == 's')||(cad == 'S'));
        fclose (arq);
    }
    else
    {
        system("cls");
        printf ("\n\nERRO NA ABERTURA DO ARQUIVO! \n\n");
        system("pause");
    }
}
